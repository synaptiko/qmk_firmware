#include <stdio.h>
#include <string.h>
#include "synaptiko.h"

/* prefixes for compose key for czech language */
#define CK_ACUTE "'"
#define CK_CARON "<"
#define CK_RING_ABOVE "*"

/* it's de-facto this: SEND_STRING(SS_RALT(key_combo)); */
/* the problem is that SEND_STRING macro can use only static strings */
/* \2\xe6{string}\3\xe6 is equivalent of SS_RALT(string) */
#define compose_key(leader, letterLower, letterUpper) \
if (is_shift_pressed) { \
    unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT); \
    send_string("\2\xe6" leader letterUpper "\3\xe6"); \
    register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT); \
} else { \
    send_string("\2\xe6" leader letterLower "\3\xe6"); \
} \
clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED)

#define compose_key_case(mc, ck, letterLower, letterUpper) \
case mc: \
    compose_key(ck, letterLower, letterUpper); \
    return false

bool process_compose_key(uint16_t keycode, keyrecord_t *record, bool is_left_shift_pressed, bool is_shift_pressed) {
    if (record->event.pressed) {
        // diacritics macros
        switch (keycode) {
            compose_key_case (MC_CK_ACUTE_A, CK_ACUTE, "a", "A");
            compose_key_case (MC_CK_ACUTE_E, CK_ACUTE, "e", "E");
            compose_key_case (MC_CK_ACUTE_I, CK_ACUTE, "i", "I");
            compose_key_case (MC_CK_ACUTE_O, CK_ACUTE, "o", "O");
            compose_key_case (MC_CK_ACUTE_Y, CK_ACUTE, "y", "Y");
            compose_key_case (MC_CK_ACUTE_U, CK_ACUTE, "u", "U");
            compose_key_case (MC_CK_CARON_E, CK_CARON, "e", "E");
            compose_key_case (MC_CK_CARON_Z, CK_CARON, "z", "Z");
            compose_key_case (MC_CK_CARON_C, CK_CARON, "c", "C");
            compose_key_case (MC_CK_CARON_S, CK_CARON, "s", "S");
            compose_key_case (MC_CK_CARON_R, CK_CARON, "r", "R");
            compose_key_case (MC_CK_CARON_T, CK_CARON, "t", "T");
            compose_key_case (MC_CK_CARON_D, CK_CARON, "d", "D");
            compose_key_case (MC_CK_CARON_N, CK_CARON, "n", "N");
            compose_key_case (MC_CK_RING_ABOVE_U, CK_RING_ABOVE, "u", "U");
        }
    }

    return true;
}
