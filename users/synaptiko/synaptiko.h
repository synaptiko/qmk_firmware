#pragma once

#include "quantum.h"

typedef struct {
    uint8_t main_layer;
    uint8_t hold_layer;
    uint8_t hold_modifiers;
    uint8_t* alternate_main_layers;
    size_t alternate_main_layers_count;
    uint8_t current_alternate_main_layer_idx;
    void (*on_after_hold_tap_fn)(void);
} hold_one_shot_double_tap_toggle_def;

void alternate_main_layer(hold_one_shot_double_tap_toggle_def* toggle_def);
void process_layer_event(hold_one_shot_double_tap_toggle_def* toggle_def, bool pressed, bool swap);
bool process_compose_key(uint16_t keycode, keyrecord_t *record, bool is_left_shift_pressed, bool is_shift_pressed);
void type_compose_key_combo(char first_char, char second_char);
char shift_letter(char letter, bool shift);

enum layers {
    L_BASE = 0,    // base
    L_DIAC_CZ = 1, // czech diacritics
    L_PROG = 2,    // programming
    L_MISC = 3,    // miscellaneous functions
    L_FKEYS = 4,   // F1-12
};

extern hold_one_shot_double_tap_toggle_def T_BASE;
extern hold_one_shot_double_tap_toggle_def T_EXTEND;
extern hold_one_shot_double_tap_toggle_def T_MISC;
extern hold_one_shot_double_tap_toggle_def T_PROG;

enum DIACRITIC_CHARS {
    CK_ACUTE = '\'',
    CK_CARON = '<',
    CK_RING_ABOVE = '*'
};

enum custom_keycodes {
    MC_DUMMY = SAFE_RANGE,

    // layer+modifier toggles
    MC_T_BASE, // cancel one-shot & go to base layer
    MC_T_EXTEND, // it's L_FKEYS, L_DIAC_CZ based on MC_DIACRITICS_LOCK
    MC_T_MISC, // go to misc layer
    MC_T_PROG, // numbers and useful keys for programming

    // diacritics switching macros
    MC_DIACRITICS_LOCK,

    // macros for typing czech diacritics with compose key on linux (AltGr)
    MC_CK_ACUTE_A, MC_CK_ACUTE_E, MC_CK_ACUTE_I, MC_CK_ACUTE_O, MC_CK_ACUTE_Y, MC_CK_ACUTE_U,
    MC_CK_CARON_E, MC_CK_CARON_Z, MC_CK_CARON_C, MC_CK_CARON_S, MC_CK_CARON_R, MC_CK_CARON_T, MC_CK_CARON_D, MC_CK_CARON_N,
    MC_CK_RING_ABOVE_U,

    // RGB brightness
    MC_RGB_VAI, MC_RGB_VAD, MC_RGB_TOG,

    // other macros
    // TODO jprokop: improve those macros
    MC_SELECTION_PASTE, MC_KEYBOARD_CHEATSHEET
    // TODO jprokop: add macros for time tracking
};
