// #include "inc/buzzer.h"
// #include "hardware/gpio.h"
// #include "hardware/pwm.h"
// #include "pico/stdlib.h"

// // Variáveis globais para controle
// volatile bool change_display = false;
// volatile bool music_playing = false;

// void play_music(const Music *music) {
//     int wholenote = (60000 * 4) / music->tempo; // Calcula a duração de uma nota inteira
//     music_playing = true;

//     for (size_t i = 0; i < music->num_notes; i++) {
//         if (change_display) {
//             change_display = false;
//             music_playing = false;
//             return;
//         }

//         if (music->notes[i] != REST) {
//             play_sound(music->notes[i], (wholenote / music->durations[i]));
//         } else {
//             sleep_ms(wholenote / music->durations[i]); // Pausa
//         }
//     }

//     music_playing = false;
// }

// void play_sound(uint frequency, uint duration_ms) {
//     // Configura o pino do buzzer como saída PWM
//     gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);

//     // Obtém o slice e o canal do PWM para o pino do buzzer
//     uint slice = pwm_gpio_to_slice_num(BUZZER_PIN);
//     uint channel = pwm_gpio_to_channel(BUZZER_PIN);

//     // Configura o divisor de clock para o PWM
//     pwm_set_clkdiv(slice, 16.0);

//     // Configura o valor de wrap (frequência do PWM)
//     pwm_set_wrap(slice, 1000000 / frequency);

//     // Configura o nível do PWM (duty cycle de 50%)
//     pwm_set_chan_level(slice, channel, 500000 / frequency);

//     // Habilita o PWM
//     pwm_set_enabled(slice, true);

//     // Mantém o som pelo tempo especificado
//     sleep_ms(duration_ms);

//     // Desabilita o PWM
//     pwm_set_enabled(slice, false);
// }