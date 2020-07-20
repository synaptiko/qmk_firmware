#pragma once

#include "quantum.h"

// RGBLight timeout feature
#define RGBLIGHT_TIMEOUT 5 // in minutes

bool process_compose_key(uint16_t keycode, keyrecord_t *record, bool is_left_shift_pressed, bool is_shift_pressed);

enum layers {
    L_BASE = 0,      // base
    L_BASE_DIAC = 1, // base adjusted with diacritics switch
    L_PROG = 2,      // programming
    L_DIAC_CZ = 3,   // czech diacritics
    L_FKEYS = 4,     // F1-12
    L_MISC = 5,      // miscellaneous functions (and mouse-related keys)
    L_MPORT = 6,     // Mouse Teleport (bound to sway's mode)
};

enum custom_keycodes {
    MC_DUMMY = SAFE_RANGE,

    // macros for typing czech diacritics with compose key on linux (AltGr)
    MC_CK_ACUTE_A, MC_CK_ACUTE_E, MC_CK_ACUTE_I, MC_CK_ACUTE_O, MC_CK_ACUTE_Y, MC_CK_ACUTE_U,
    MC_CK_CARON_E, MC_CK_CARON_Z, MC_CK_CARON_C, MC_CK_CARON_S, MC_CK_CARON_R, MC_CK_CARON_T, MC_CK_CARON_D, MC_CK_CARON_N,
    MC_CK_RING_ABOVE_U,

    // L_MPORT keys
    MC_MPORT_ACTIVATE, MC_MPORT_DEACTIVATE, MC_MPORT_DEACTIVATE_TO_BASE,

    // RGB brightness
    MC_RGB_VAI, MC_RGB_VAD, MC_RGB_TOG,
};
