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

// NOTE: specific numbers are used to avoid LEDs to be activated by planck/ez.c:layer_state_set_kb
enum layers {
    L_BASE = 0, // base
    L_ALT_NUM = 1, // numbers (useful for workspaces in sway/i3)
    L_DIAC_CZ = 7, // czech diacritics
    L_DIAC_PL = 8, // polish diacritics
    L_PROG = 9, // programming
    L_MISC = 10,  // miscellaneous functions
    L_FKEYS = 11, // F1-12
};

extern hold_one_shot_double_tap_toggle_def T_BASE;
extern hold_one_shot_double_tap_toggle_def T_ALT_NUM;
extern hold_one_shot_double_tap_toggle_def T_EXTEND;
extern hold_one_shot_double_tap_toggle_def T_MISC;
extern hold_one_shot_double_tap_toggle_def T_VTTYS;
extern hold_one_shot_double_tap_toggle_def T_FKEYS;

enum DIACRITIC_CHARS {
    CK_ACUTE = '\'',
    CK_CARON = '<',
    CK_RING_ABOVE = '*',
    CK_OGON = ',',
    CK_STROK = '/',
    CK_DOT = '.'
};

enum custom_keycodes {
    MC_DUMMY = SAFE_RANGE,

    // layer+modifier toggles
    MC_T_BASE, // cancel one-shot & go to base layer
    MC_T_ALT_NUM, // first row turns into numbers
    MC_T_EXTEND, // it's L_PROG, L_DIAC_CZ or L_DIAC_PL based on MC_DIACRITICS_LOCK
    MC_T_MISC, // go to misc layer
    MC_T_VTTYS, // special combo for easier switching between virtual consoles

    // diacritics switching macros
    MC_DIACRITICS_LOCK,

    // macros for typing czech diacritics with compose key on linux (AltGr)
    MC_CK_ACUTE_A, MC_CK_ACUTE_E, MC_CK_ACUTE_I, MC_CK_ACUTE_O, MC_CK_ACUTE_Y, MC_CK_ACUTE_U,
    MC_CK_CARON_E, MC_CK_CARON_Z, MC_CK_CARON_C, MC_CK_CARON_S, MC_CK_CARON_R, MC_CK_CARON_T, MC_CK_CARON_D, MC_CK_CARON_N,
    MC_CK_RING_ABOVE_U,

    // macros for typing polish diacritics with compose key on linux (AltGr)
    MC_CK_OGON_A, MC_CK_ACUTE_C, MC_CK_OGON_E, MC_CK_STROK_L, MC_CK_ACUTE_N, /*MC_CK_ACUTE_O,*/
    MC_CK_ACUTE_S, MC_CK_ACUTE_Z, MC_CK_DOT_Z,

    // useful compose key combos
    MC_CK_X_TIMES, MC_CK_TRIPLE_DOT, MC_CK_TM,

    // RGB brightness
    MC_RGB_VAI, MC_RGB_VAD, MC_RGB_TOG,

    // other macros
    // TODO jprokop: improve those macros
    MC_SELECTION_PASTE, MC_KEYBOARD_CHEATSHEET
    // TODO jprokop: add macros for time tracking
};
