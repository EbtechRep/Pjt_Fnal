#ifndef BUZZER_H
#define BUZZER_H

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// Definição das notas musicais
#define REST 0
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
//----------------------------------------------------------------------------------------------------------------
// Definição da estrutura para uma música
// Estrutura para uma música
typedef struct {
    const uint *notes;
    const uint *durations;
    size_t num_notes;
    int tempo;
} Music;

// Definição das músicas
extern const Music mario_music;
extern const Music zelda_music;
extern const Music harry_music;
extern const Music sonic_music;
extern const Music got_music;
extern const Music undertale_music;
extern const Music pirates_music;
extern const Music tetris_music;
extern const Music yakuza_music;
//-------------------------------------------------------------------------------------------------------------------
// Música do Mario
const uint mario_notes[] = {
    NOTE_E4, NOTE_E4, REST, NOTE_E4, REST, NOTE_C4, NOTE_E4, 
NOTE_G4, REST, NOTE_G3, REST, 
NOTE_C4, NOTE_G3, REST, NOTE_E3, 
NOTE_A3, NOTE_B3, NOTE_AS3, NOTE_A3,
NOTE_G3, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_F4, NOTE_G4,
REST, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_B3,
NOTE_C4, NOTE_G3, REST, NOTE_E3,
NOTE_A3, NOTE_B3, NOTE_AS3, NOTE_A3,
NOTE_G3, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_F4, NOTE_G4,
REST, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_B3,

REST, NOTE_G4, NOTE_FS4, NOTE_F4, NOTE_DS4, NOTE_E4,
REST, NOTE_GS3, NOTE_A3, NOTE_C3, REST, NOTE_A3, NOTE_C4, NOTE_D4,
REST, NOTE_DS4, REST, NOTE_D4,
NOTE_C4, REST,

REST, NOTE_G4, NOTE_FS4, NOTE_F4, NOTE_DS4, NOTE_E4,
REST, NOTE_GS3, NOTE_A3, NOTE_C3, REST, NOTE_A3, NOTE_C4, NOTE_D4,
REST, NOTE_DS4, REST, NOTE_D4,
NOTE_C4, REST,

NOTE_C4, NOTE_C4, NOTE_C4, REST, NOTE_C4, NOTE_D4,
NOTE_E4, NOTE_C4, NOTE_A3, NOTE_G3,

NOTE_C4, NOTE_C4, NOTE_C4, REST, NOTE_C4, NOTE_D4, NOTE_E4,
REST,
NOTE_C4, NOTE_C4, NOTE_C4, REST, NOTE_C4, NOTE_D4,
NOTE_E4, NOTE_C4, NOTE_A3, NOTE_G3,
NOTE_E4, NOTE_E4, REST, NOTE_E4, REST, NOTE_C4, NOTE_E4,
NOTE_G4, REST, NOTE_G3, REST, 
NOTE_C4, NOTE_G3, REST, NOTE_E3,

NOTE_A3, NOTE_B3, NOTE_AS3, NOTE_A3,
NOTE_G3, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_F4, NOTE_G4,
REST, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_B3,

NOTE_C4, NOTE_G3, REST, NOTE_E3,
NOTE_A3, NOTE_B3, NOTE_AS3, NOTE_A3,
NOTE_G3, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_F4, NOTE_G4,
REST, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_B3,

NOTE_E4, NOTE_C4, NOTE_G3, REST, NOTE_GS3,
NOTE_A3, NOTE_F4, NOTE_F4, NOTE_A3,
NOTE_D4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4,

NOTE_E4, NOTE_C4, NOTE_A3, NOTE_G3,
NOTE_E4, NOTE_C4, NOTE_G3, REST, NOTE_GS3,
NOTE_A3, NOTE_F4, NOTE_F4, NOTE_A3,
NOTE_B3, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_D4,
NOTE_C4, NOTE_E3, NOTE_E3, NOTE_C3,

NOTE_E4, NOTE_C4, NOTE_G3, REST, NOTE_GS3,
NOTE_A3, NOTE_F4, NOTE_F4, NOTE_A3,
NOTE_D4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4,

NOTE_E4, NOTE_C4, NOTE_A3, NOTE_G3,
NOTE_E4, NOTE_C4, NOTE_G3, REST, NOTE_GS3,
NOTE_A3, NOTE_F4, NOTE_F4, NOTE_A3,
NOTE_B3, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_D4,
NOTE_C4, NOTE_E3, NOTE_E3, NOTE_C3,
NOTE_C4, NOTE_C4, NOTE_C4, REST, NOTE_C4, NOTE_D4, NOTE_E4,
REST,

NOTE_C4, NOTE_C4, NOTE_C4, REST, NOTE_C4, NOTE_D4,
NOTE_E4, NOTE_C4, NOTE_A3, NOTE_G3,
NOTE_E4, NOTE_E4, REST, NOTE_E4, REST, NOTE_C4, NOTE_E4,
NOTE_G4, REST, NOTE_G3, REST,
NOTE_E4, NOTE_C4, NOTE_G3, REST, NOTE_GS3,
NOTE_A3, NOTE_F4, NOTE_F4, NOTE_A3,
NOTE_D4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4,

NOTE_E4, NOTE_C4, NOTE_A3, NOTE_G3,
NOTE_E4, NOTE_C4, NOTE_G3, REST, NOTE_GS3,
NOTE_A3, NOTE_F4, NOTE_F4, NOTE_A3,
NOTE_B3, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_D4,
NOTE_C4, NOTE_E3, NOTE_E3, NOTE_C3,

NOTE_C4, NOTE_G3, NOTE_E3,
NOTE_A3, NOTE_B3, NOTE_A3, NOTE_GS3, NOTE_AS3, NOTE_GS3,
NOTE_G3, NOTE_D3, NOTE_E3,
};

const uint mario_durations[] = {
    8, 8, 8, 8, 8, 8, 8, 
    4, 4, 8, 4, 
    -4, 8, 4, -4, 
    4, 4, 8, 4, 
    -8, -8, -8, 4, 8, 8,
    8, 4, 8, 8, -4,
    -4, 8, 4, -4,
    4, 4, 8, 4,
    -8, -8, -8, 4, 8, 8,
    8, 4, 8, 8, -4,
    
    4, 8, 8, 8, 4, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    4, 4, 8, -4,
    2, 2,
    
    4, 8, 8, 8, 4, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    4, 4, 8, -4,
    2, 2,
    
    8, 4, 8, 8, 8, 4,
    8, 4, 8, 2,
    
    8, 4, 8, 8, 8, 8, 8,
    1,
    8, 4, 8, 8, 8, 4,
    8, 4, 8, 2,
    8, 8, 8, 8, 8, 4,
    4, 4, 4, 4,
    -4, 8, 4, -4,
    
    4, 4, 8, 4,
    -8, -8, -8, 4, 8, 8,
    8, 4, 8, 8, -4,
    
    -4, 8, 4, -4,
    4, 4, 8, 4,
    -8, -8, -8, 4, 8, 8,
    8, 4, 8, 8, -4,
    
    8, 4, 8, 4, 4,
    8, 4, 8, 2,
    -8, -8, -8, -8, -8, -8,
    
    8, 4, 8, 2,
    8, 4, 8, 4, 4,
    8, 4, 8, 2,
    8, 4, 8, -8, -8, -8,
    8, 4, 8, 2,
    
    8, 4, 8, 4, 4,
    8, 4, 8, 2,
    -8, -8, -8, -8, -8, -8,
    
    8, 4, 8, 2,
    8, 4, 8, 4, 4,
    8, 4, 8, 2,
    8, 4, 8, -8, -8, -8,
    8, 4, 8, 2,
    
    -4, -4, 4,
    -8, -8, -8, -8, -8, -8,
    8, 8, -2,
    };

const Music mario_music = {
    .notes = mario_notes,
    .durations = mario_durations,
    .num_notes = sizeof(mario_notes) / sizeof(mario_notes[0]),
    .tempo = 124 // BPM do Mario
};

// Música do Zelda (notas mais graves)
const uint zelda_notes[] = {
    NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_GS4, NOTE_FS4, NOTE_F4, NOTE_F4,
    NOTE_DS4, NOTE_F4, NOTE_FS4, NOTE_F4, NOTE_DS4, NOTE_CS4, NOTE_DS4, NOTE_F4, NOTE_DS4, NOTE_CS4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3,
    NOTE_AS3, NOTE_F3, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_FS4, NOTE_GS4, NOTE_AS4, NOTE_CS5, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_FS4, NOTE_AS4, NOTE_A4, NOTE_F4,
    NOTE_FS4, NOTE_AS4, NOTE_A4, NOTE_F4, NOTE_D4, NOTE_DS4, NOTE_FS4, NOTE_F4, NOTE_CS4, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4, NOTE_F4, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3,
    NOTE_F3, NOTE_F3};

const uint zelda_durations[] = {
    4, -4, 8, 16, 16, 16, 2, 8, 8, 8, 8, 16, 16, -2, 8, 8, 8, 16, -8, 16, 2, 4,
    -8, 16, 2, 8, 8, -8, 16, 2, 8, 8, -8, 16, 16, 16, 16, 16, 16, 16, 16, 8, 16, 8,
    4, -4, 8, 16, 16, 16, 2, 8, 8, 8, 16, 16, -2, 4, 4, 2, 4, -2, 4, 4, 2, 4,
    -2, 4, 4, 2, 4, 4, 2, 4, 4, 2, 8, 16, 2, 8, 16, 16, 16, 16, 16, 16, 16, 16, 8

};

const Music zelda_music = {
    .notes = zelda_notes,
    .durations = zelda_durations,
    .num_notes = sizeof(zelda_notes) / sizeof(zelda_notes[0]),
    .tempo = 115 // BPM do Zelda
};

// Música do Harry Potter
const uint harry_notes[] = {
    NOTE_D4, NOTE_G4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_C5, NOTE_A4,
    NOTE_G4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_G4,
    NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_AS4,
    NOTE_A4, NOTE_G4, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_G4, NOTE_AS4, NOTE_A4};

const uint harry_durations[] = {
    4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 4, 4, 4};

const Music harry_music = {
    .notes = harry_notes,
    .durations = harry_durations,
    .num_notes = sizeof(harry_notes) / sizeof(harry_notes[0]),
    .tempo = 144 // BPM do Harry Potter
};

// Música do Sonic
const uint sonic_notes[] = {
    REST, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4,
    REST, NOTE_A4, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4,
    REST, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4,
    REST, NOTE_B4, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_D4,
    REST, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4,
    REST, NOTE_A4, NOTE_FS5, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4,
    REST, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_A4,
    REST, NOTE_B4, NOTE_B4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_D4, NOTE_D4, NOTE_FS4,
    NOTE_E4, REST, NOTE_D4, NOTE_E4, NOTE_FS4, REST, NOTE_D4, NOTE_D4, NOTE_FS4, NOTE_F4,
    REST, NOTE_D4, NOTE_F4, NOTE_E4};

const uint sonic_durations[] = {
    8, 8, 4, 8, 4, 8, 4, 8,
    8, 8, 8, 4, 8, 4, 8, 4, 8,
    8, 8, 4, 8, 4, 8, 4, 8,
    8, 8, 8, 4, 8, 4, 8, 4, 8,
    8, 8, 4, 8, 4, 8, 4, 8,
    8, 8, 8, 4, 8, 4, 8, 4, 8,
    8, 8, 4, 8, 4, 8, 4, 8,
    8, 8, 8, 4, 8, 4, 8, 4, 8, 8, 8,
    4, 8, 8, 8, 4, 8, 8, 8, 8, 4,
    8, 8, 8, 4};

const Music sonic_music = {
    .notes = sonic_notes,
    .durations = sonic_durations,
    .num_notes = sizeof(sonic_notes) / sizeof(sonic_notes[0]),
    .tempo = 124 // BPM do Sonic
};

// Música do Game of Thrones
const uint got_notes[] = {
    NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
    NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
    NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4,
    NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_E4, NOTE_F4,
    NOTE_G4, NOTE_C4,

    NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
    NOTE_D4,
    NOTE_F4, NOTE_AS3,
    NOTE_DS4, NOTE_D4, NOTE_F4, NOTE_AS3,
    NOTE_DS4, NOTE_D4, NOTE_C4,

    NOTE_G4, NOTE_C4,

    NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,
    NOTE_D4,
    NOTE_F4, NOTE_AS3,
    NOTE_DS4, NOTE_D4, NOTE_F4, NOTE_AS3,
    NOTE_DS4, NOTE_D4, NOTE_C4,
    NOTE_G4, NOTE_C4,
    NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_DS4, NOTE_F4,

    NOTE_D4,
    NOTE_F4, NOTE_AS3,
    NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_AS3,
    NOTE_C4,
    NOTE_C5,
    NOTE_AS4,
    NOTE_C4,
    NOTE_G4,
    NOTE_DS4,
    NOTE_DS4, NOTE_F4,
    NOTE_G4,

    NOTE_C5,
    NOTE_AS4,
    NOTE_C4,
    NOTE_G4,
    NOTE_DS4,
    NOTE_DS4, NOTE_D4,
    NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4,
    NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_C5, NOTE_G4, NOTE_GS4, NOTE_AS4,

    REST, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_G5, NOTE_GS5, NOTE_AS5,
    NOTE_C6, NOTE_G5, NOTE_GS5, NOTE_AS5, NOTE_C6, NOTE_G5, NOTE_GS5, NOTE_AS5};

const uint got_durations[] = {
    8, 8, 16, 16, 8, 8, 16, 16,
    8, 8, 16, 16, 8, 8, 16, 16,
    8, 8, 16, 16, 8, 8, 16, 16,
    8, 8, 16, 16, 8, 8, 16, 16,
    4, 4,

    16, 16, 4, 4, 16, 16,
    1,
    4, 4,
    16, 16, 4, 4,
    16, 16, 1,

    4, 4,

    16, 16, 4, 4, 16, 16,
    1,
    4, 4,
    16, 16, 4, 4,
    16, 16, 1,
    4, 4,
    16, 16, 4, 4, 16, 16,

    2,
    4, 4,
    8, 8, 8, 8,
    1,
    2,
    2,
    2,
    2,
    2,
    4, 4,
    1,

    2,
    2,
    2,
    2,
    2,
    4, 4,
    8, 8, 16, 16, 8, 8, 16, 16,
    8, 8, 16, 16, 8, 8, 16, 16,

    4, 16, 16, 8, 8, 16, 16,
    8, 16, 16, 16, 8, 8, 16, 16};

const Music got_music = {
    .notes = got_notes,
    .durations = got_durations,
    .num_notes = sizeof(got_notes) / sizeof(got_notes[0]),
    .tempo = 85 // BPM do Game of Thrones
};

// Música do Undertale
const uint undertale_notes[] = {
    NOTE_D3, NOTE_D3, NOTE_D4, NOTE_A3, 0, NOTE_GS3, NOTE_G3, NOTE_F3, NOTE_D3, NOTE_F3, NOTE_G3, NOTE_C3, NOTE_C3, NOTE_D4, NOTE_A3, 0, NOTE_GS3, NOTE_G3, NOTE_F3, NOTE_D3, NOTE_F3, NOTE_G3, NOTE_B2, NOTE_B2, NOTE_D4, NOTE_A3, 0, NOTE_GS3, NOTE_G3, NOTE_F3, NOTE_D3, NOTE_F3, NOTE_G3, NOTE_AS2, NOTE_AS2, NOTE_D4, NOTE_A3, 0, NOTE_GS3, NOTE_G3, NOTE_F3, NOTE_D3, NOTE_F3, NOTE_G3, NOTE_D3, NOTE_D3, NOTE_D4, NOTE_A3, 0, NOTE_GS3, NOTE_G3, NOTE_F3, NOTE_D3, NOTE_F3, NOTE_G3, NOTE_C3, NOTE_C3, NOTE_D4, NOTE_A3, 0, NOTE_GS3, NOTE_G3, NOTE_F3, NOTE_D3, NOTE_F3, NOTE_G3, NOTE_B2, NOTE_B2, NOTE_D4, NOTE_A3, 0, NOTE_GS3, NOTE_G3, NOTE_F3, NOTE_D3, NOTE_F3, NOTE_G3, NOTE_AS2, NOTE_AS2, NOTE_D4, NOTE_A3, 0, NOTE_GS3, NOTE_G3, NOTE_F3, NOTE_D3, NOTE_F3, NOTE_G3, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_A4, 0, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_C4, NOTE_D5, NOTE_A4, 0, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_B3, NOTE_B3, NOTE_D5, NOTE_A4, 0, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_AS3, NOTE_AS3, NOTE_D5, NOTE_A4, 0, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_A4, 0, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_C4, NOTE_C4, NOTE_D5, NOTE_A4, 0, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_B3, NOTE_B3, NOTE_D5, NOTE_A4, 0, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_AS3, NOTE_AS3, NOTE_D5, NOTE_A4, 0, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, 0, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_A4, NOTE_D5, NOTE_C5, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_C4, 0, NOTE_G4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_F3, NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_F4, NOTE_C5, 0, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_GS4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_CS5, NOTE_GS4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_CS4, NOTE_DS4, 0, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_GS4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_CS5, NOTE_GS4, NOTE_GS4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_F3, NOTE_G3, NOTE_A3, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_CS4, NOTE_DS4};

const uint undertale_durations[] = {
    16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16, 16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16, 16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16, 16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16, 16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16, 16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16, 16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16, 16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16, 16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16, 16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16, 16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16, 16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16, 16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16, 16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16, 16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16, 16, 16, 8, 6, 32, 8, 8, 8, 16, 16, 16, 8, 16, 8, 8, 8, 8, 4, 16, 8, 16, 8, 8, 8, 16, 16, 16, 16, 16, 8, 8, 16, 8, 8, 8, 8, 8, 8, 8, 8, 16, 16, 16, 2, 8, 16, 8, 8, 8, 8, 4, 16, 8, 16, 8, 8, 8, 8, 8, 16, 8, 16, 8, 8, 8, 8, 8, 8, 8, 16, 8, 15, 8, 8, 2, 3, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 2, 16, 8, 16, 8, 16, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 8, 16, 16, 16, 2, 8, 8, 8, 8, 4, 4, 4, 4, 4, 4, 2, 8, 8, 8, 8, 2, 2, 3, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 8, 2, 16, 8, 16, 8, 16, 16, 16, 16, 16, 16, 8, 8, 8, 8, 8, 8, 16, 16, 16, 2, 8, 8, 8, 8, 4, 4, 4, 4, 4, 4, 2, 8, 8, 8, 8, 2, 1};

const Music undertale_music = {
    .notes = undertale_notes,
    .durations = undertale_durations,
    .num_notes = sizeof(undertale_notes) / sizeof(undertale_notes[0]),
    .tempo = 120 // BPM
};

// Música do Piratas do caribe
const uint pirates_notes[] = {
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
    NOTE_A4, NOTE_G4, NOTE_A4, REST,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
    NOTE_A4, NOTE_G4, NOTE_A4, REST,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,

    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_D5, NOTE_E5, NOTE_A4, REST,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
    NOTE_C5, NOTE_A4, NOTE_B4, REST,

    NOTE_A4, NOTE_A4,
    // Repeat of first part
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
    NOTE_A4, NOTE_G4, NOTE_A4, REST,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
    NOTE_A4, NOTE_G4, NOTE_A4, REST,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,

    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_D5, NOTE_E5, NOTE_A4, REST,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
    NOTE_C5, NOTE_A4, NOTE_B4, REST,
    // End of Repeat

    NOTE_E5, REST, REST, NOTE_F5, REST, REST,
    NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST,
    NOTE_D5, REST, REST, NOTE_C5, REST, REST,
    NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4,

    NOTE_E5, REST, REST, NOTE_F5, REST, REST,
    NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST,
    NOTE_D5, REST, REST, NOTE_C5, REST, REST,
    NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4};

const uint pirates_durations[] = {
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8,

    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8,

    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 8, 4, 8,

    8, 8, 4, 8, 8,
    4, 8, 4, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 4,

    4, 8,
    // Repeat of First Part
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8,

    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8,

    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 8, 4, 8,

    8, 8, 4, 8, 8,
    4, 8, 4, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 4,
    // End of Repeat

    4, 8, 4, 4, 8, 4,
    8, 8, 8, 8, 8, 8, 8, 8, 4,
    4, 8, 4, 4, 8, 4,
    8, 8, 8, 8, 8, 2,

    4, 8, 4, 4, 8, 4,
    8, 8, 8, 8, 8, 8, 8, 8, 4,
    4, 8, 4, 4, 8, 4,
    8, 8, 8, 8, 8, 2};

const Music pirates_music = {
    .notes = pirates_notes,
    .durations = pirates_durations,
    .num_notes = sizeof(pirates_notes) / sizeof(pirates_notes[0]),
    .tempo = 125 // BPM
};

// Música do tetris
const uint tetris_notes[] = {
    NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4,
    NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_C5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_C5,

    NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5,
    NOTE_E5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_C5, NOTE_A4, NOTE_A4, REST,

    NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4,
    NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_C5, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_C5,

    NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_F5,
    NOTE_E5, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_C5, NOTE_A4, NOTE_A4, REST,

    NOTE_E5, NOTE_C5,
    NOTE_D5, NOTE_B4,
    NOTE_C5, NOTE_A4,
    NOTE_GS4, NOTE_B4, REST,
    NOTE_E5, NOTE_C5,
    NOTE_D5, NOTE_B4,
    NOTE_C5, NOTE_E5, NOTE_A5,
    NOTE_GS5};

const uint tetris_durations[] = {
    4, 8, 8, 4, 8, 8,
    4, 8, 8, 4, 8, 8,
    4, 8, 4, 4,
    4, 4, 8, 4, 8, 8,

    4, 8, 4, 8, 8,
    4, 8, 4, 8, 8,
    4, 8, 8, 4, 4,
    4, 4, 4, 4,

    4, 8, 8, 4, 8, 8,
    4, 8, 8, 4, 8, 8,
    4, 8, 4, 4,
    4, 4, 8, 4, 8, 8,

    4, 8, 4, 8, 8,
    4, 8, 4, 8, 8,
    4, 8, 8, 4, 4,
    4, 4, 4, 4,

    2, 2,
    2, 2,
    2, 2,
    2, 4, 8,
    2, 2,
    2, 2,
    4, 4, 2,
    2};

const Music tetris_music = {
    .notes = tetris_notes,
    .durations = tetris_durations,
    .num_notes = sizeof(tetris_notes) / sizeof(tetris_notes[0]),
    .tempo = 135 // BPM
};


// Música do Yakuza
const uint yakuza_notes[] = {
    NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_D4, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_AS3, NOTE_A3, NOTE_AS3, NOTE_G3, NOTE_A3, NOTE_G4, NOTE_F4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_AS3, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_DS4, NOTE_G3, NOTE_AS3, NOTE_A3, NOTE_A3, NOTE_G3, NOTE_G3, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_AS3, NOTE_AS3, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_A3, NOTE_AS3, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_G3, NOTE_A3, NOTE_AS3, NOTE_AS3, NOTE_A3, NOTE_G3, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_DS4, NOTE_AS3, NOTE_G3, NOTE_AS3, NOTE_F4, NOTE_D4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_B3, NOTE_C4, NOTE_E4, NOTE_E4, NOTE_FS4, NOTE_B4, NOTE_FS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_D4, NOTE_A4, NOTE_G4, NOTE_B3, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_B3, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_G4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_C4, NOTE_B3, NOTE_C4, NOTE_E4, NOTE_E4, NOTE_FS4, NOTE_B4, NOTE_FS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_D4, NOTE_A4, NOTE_G4, NOTE_B3, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_B3, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_G4
};

const uint yakuza_durations[] = {
    8, 8, 8, 8, 2, 4, 4, 4, 8, 8, 2, 8, 8, 2, 4, 4, 4, 4, 4, 8, 8, 2, 8, 8, 2, 4, 4, 4, 8, 2, 2, 8, 8, 8, 8, 2, 4, 2, 2, 8, 8, 2, 8, 8, 8, 8, 4, 2, 4, 4, 2, 4, 8, 2, 8, 8, 8, 8, 4, 2, 4, 4, 8, 8, 2, 4, 8, 2, 4, 4, 4, 2, 4, 2, 8, 8, 8, 8, 2, 4, 4, 2, 2, 8, 8, 8, 2, 8, 8, 8, 2, 8, 8, 2, 4, 4, 8, 8, 2, 8, 8, 8, 2, 8, 8, 2, 4, 4, 8, 8, 2, 8, 2, 2, 8, 8, 8, 8, 2, 8, 8, 8, 8, 2, 8, 8, 8, 8, 2, 8, 8, 8, 2, 8, 8, 2, 4, 4, 8, 8, 2, 8, 8, 8, 8, 2, 8, 8, 8, 8, 2
};

const Music yakuza_music = {
    .notes = yakuza_notes,
    .durations = yakuza_durations,
    .num_notes = sizeof(yakuza_notes) / sizeof(yakuza_notes[0]),
    .tempo = 120 // BPM
};




//-------------------------------------------------------------------------------------------------------------
// Funções
void play_music(const Music *music);
void play_sound(uint frequency, uint duration_ms);

#endif // BUZZER_H