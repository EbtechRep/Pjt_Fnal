#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "inc/ssd1306.h"
#include "hardware/i2c.h"
#include "inc/animation.h"
#include "inc/buzzer.h"


volatile uint8_t display_state_a = 0; // Estado para o botão A
volatile uint8_t display_state_b = 0; // Estado para o botão B

const uint I2C_SDA = 14;
const uint I2C_SCL = 15;
const uint BUTTON_A_PIN = 5; // Botão A no GPIO 5
const uint BUTTON_B_PIN = 6; // Botão B no GPIO 6
const uint BUZZER_PIN = 10;

// Variáveis globais para controle
volatile bool music_playing = false;
volatile bool change_display = false;
volatile bool button_pressed = false;
volatile uint8_t display_state = 0; // Estado para alternar entre displays no mesmo botão

// Função para tocar uma música
void play_music(const Music *music) {
    music_playing = true;

    // Calcula a duração de uma semibreve (nota inteira) em ms
    int wholenote = (60000 * 4) / music->tempo;

    for (size_t i = 0; i < music->num_notes; i++) {
        if (change_display) {
            change_display = false;
            music_playing = false;
            return;
        }

        int divider = music->durations[i];
        int noteDuration;

        if (divider > 0) {
            // Nota regular
            noteDuration = wholenote / divider;
        } else if (divider < 0) {
            // Nota pontuada (aumenta a duração em 50%)
            noteDuration = (wholenote / abs(divider)) * 1.5;
        }

        if (music->notes[i] != REST) {
            play_sound(music->notes[i], noteDuration * 0.9); // Toca a nota por 90% da duração
        }
        sleep_ms(noteDuration * 0.1); // Pausa de 10% da duração
    }

    music_playing = false;
}

// Função para tocar um som com frequência e duração específicas
void play_sound(uint frequency, uint duration_ms) {
    gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(BUZZER_PIN);
    pwm_set_clkdiv(slice, 16.0); // Divisor de clock
    pwm_set_wrap(slice, 1000000 / frequency); // Configura a frequência
    pwm_set_gpio_level(BUZZER_PIN, 500000 / frequency); // Duty cycle de 50%
    pwm_set_enabled(slice, true);
    sleep_ms(duration_ms);
    pwm_set_enabled(slice, false);
}

// Função de interrupção para os botões
void button_callback(uint gpio, uint32_t events) {
    if (gpio == BUTTON_A_PIN || gpio == BUTTON_B_PIN) {
        button_pressed = true;
        if (music_playing) {
            change_display = true; // Interrompe a música atual
        }
    }
}

int main() {
    stdio_init_all(); // Inicializa os tipos stdio padrão presentes ligados ao binário

    // Configuração dos pinos dos botões como entrada com pull-up
    gpio_init(BUTTON_A_PIN);
    gpio_init(BUTTON_B_PIN);
    gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
    gpio_set_dir(BUTTON_B_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_A_PIN);
    gpio_pull_up(BUTTON_B_PIN);

    // Configura interrupções para os botões
    gpio_set_irq_enabled_with_callback(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true, &button_callback);
    gpio_set_irq_enabled_with_callback(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    // Inicialização do i2c
    i2c_init(i2c1, ssd1306_i2c_clock * 9000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    // Processo de inicialização completo do OLED SSD1306
    ssd1306_init();

    // Preparar área de renderização para o display (ssd1306_width pixels por ssd1306_n_pages páginas)
    struct render_area frame_area = {
        start_column : 0,
        end_column : ssd1306_width - 1,
        start_page : 0,
        end_page : ssd1306_n_pages - 1
    };

    calculate_render_area_buffer_length(&frame_area);

    // Zera o display inteiro
    uint8_t ssd[ssd1306_buffer_length];
    memset(ssd, 0, ssd1306_buffer_length);
    render_on_display(ssd, &frame_area);

    char *text[] = {
        "  Embarcatech,   ",
        "  Projeto Final    ",
        "  Bruno Flores   ",
        "  tic370100483  ",
    };

    int y = 0;
    for (uint i = 0; i < count_of(text); i++) {
        ssd1306_draw_string(ssd, 5, y, text[i]);
        y += 8;
    }
    render_on_display(ssd, &frame_area);

    while (true) {
        if (button_pressed) {
            button_pressed = false; // Reseta o flag do botão
    
            if (gpio_get(BUTTON_A_PIN) == 0) {
                ssd1306_t ssd_bm;
                ssd1306_init_bm(&ssd_bm, 128, 64, false, 0x3C, i2c1);
                ssd1306_config(&ssd_bm);
    
                // Alterna entre os displays ao pressionar o botão A
                if (display_state_a == 0) {
                    ssd1306_draw_bitmap(&ssd_bm, mario);
                    play_music(&mario_music);  // Toca a música do Mario
                    display_state_a = 1; // Próximo estado
                } else if (display_state_a == 1) {
                    ssd1306_draw_bitmap(&ssd_bm, tetris);
                    play_music(&tetris_music);  // Toca a música do tetris
                    display_state_a = 3; // Próximo estado
                } else if (display_state_a == 3) {
                    ssd1306_draw_bitmap(&ssd_bm, zelda);
                    play_music(&zelda_music);  // Toca a música do Zelda
                    display_state_a = 4; // Próximo estado
                } else if (display_state_a == 4) {
                    ssd1306_draw_bitmap(&ssd_bm, undertale);
                    play_music(&undertale_music);  // Toca a música do Undertale
                    display_state_a = 5; // Próximo estado
                } else {
                    ssd1306_draw_bitmap(&ssd_bm, sonic);
                    play_music(&sonic_music);  // Toca a música do Sonic
                    display_state_a = 0; // Volta ao estado inicial
                }
            } else if (gpio_get(BUTTON_B_PIN) == 0) {
                ssd1306_t ssd_bm;
                ssd1306_init_bm(&ssd_bm, 128, 64, false, 0x3C, i2c1);
                ssd1306_config(&ssd_bm);
    
                // Alterna entre Series e Animes
                if (display_state_b == 0) {
                    ssd1306_draw_bitmap(&ssd_bm, harry);
                    play_music(&harry_music);  // Toca a música do Harry Potter
                    display_state_b = 1; // Próximo estado
                } else if (display_state_b == 1) {
                    ssd1306_draw_bitmap(&ssd_bm, pirates);
                    play_music(&pirates_music);  // Toca a música do pirates
                    display_state_b = 2; // Próximo estado
                } else {
                    ssd1306_draw_bitmap(&ssd_bm, got);
                    play_music(&got_music);  // Toca a música do Game of Thrones
                    display_state_b = 0; // Volta ao estado inicial
                }
            }
        }
    }

    return 0;
}