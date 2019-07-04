#include <stdio.h>
#include <string.h>
#include "synaptiko.h"

// NOTE: keep in sync with header file!
hold_one_shot_double_tap_toggle_def T_BASE = { .main_layer = L_BASE };
hold_one_shot_double_tap_toggle_def T_ALT_NUM = {
    .main_layer = L_ALT_NUM,
    .hold_modifiers = MOD_LALT
};
uint8_t alternate_main_layers_for_T_EXTEND[] = { L_PROG, L_DIAC_CZ, L_DIAC_PL };
hold_one_shot_double_tap_toggle_def T_EXTEND = {
    .main_layer = L_PROG,
    .alternate_main_layers = alternate_main_layers_for_T_EXTEND,
    .alternate_main_layers_count = 3,
    .current_alternate_main_layer_idx = 0
};
hold_one_shot_double_tap_toggle_def T_MISC = { .main_layer = L_MISC };
void on_after_hold_tap_fn_for_T_VTTYS(void) {
    static bool is_first_desktop_active = true;

    register_code(KC_LCTL);
    register_code(KC_LALT);
    if (is_first_desktop_active) {
        SEND_STRING(SS_TAP(X_F2));
    } else {
        SEND_STRING(SS_TAP(X_F1));
    }
    unregister_code(KC_LALT);
    unregister_code(KC_LCTL);

    is_first_desktop_active = !is_first_desktop_active;
}
hold_one_shot_double_tap_toggle_def T_VTTYS = {
    .main_layer = L_BASE,
    .hold_layer = L_FKEYS,
    .hold_modifiers = MOD_LALT | MOD_LCTL,
    .on_after_hold_tap_fn = on_after_hold_tap_fn_for_T_VTTYS
};
hold_one_shot_double_tap_toggle_def T_FKEYS = { .main_layer = L_FKEYS };

void alternate_main_layer(hold_one_shot_double_tap_toggle_def* toggle_def) {
    toggle_def->current_alternate_main_layer_idx = (toggle_def->current_alternate_main_layer_idx + 1) % toggle_def->alternate_main_layers_count;
    toggle_def->main_layer = toggle_def->alternate_main_layers[toggle_def->current_alternate_main_layer_idx];
}

void apply_modifiers(const uint8_t modifiers, void (*fn)(uint8_t)) {
    const uint8_t mods[] = { MOD_LCTL, MOD_LSFT, MOD_LALT, MOD_LGUI };
    const uint8_t kcs[] =  { KC_LCTL,  KC_LSFT,  KC_LALT,  KC_LGUI  };

    for (size_t i = 0; i < 4; i += 1) {
        if (modifiers & mods[i]) fn(kcs[i]);
    }
}

// TODO jprokop: simplify/split to multiple functions; make it more understandable
// TODO jprokop: update the documentation and comments in regard of newly added *_when_hold params
/* My implementation of "One-Shot-Double-Tap-Toggle":
 * - Tap for One-Shot key or Toggle
 * - Fast Double-Tap to turn the layer on "permanently"
 *
 * Here's how One-Shot key works on it's own:
 * - Flips a layer on, but only for one keypress.
 * - Once you press a key in the new layer, the layer is then deactivated.
 * - You can keep the layer active by holding the key down.
 */
void process_layer_event(hold_one_shot_double_tap_toggle_def* toggle_def, bool pressed, bool swap) {
    static uint16_t oneshot_layer_switch_time;
    static bool ignore_next_oneshot_layer_switch = false;

    bool released = !pressed;

    if (pressed && toggle_def->hold_modifiers) apply_modifiers(toggle_def->hold_modifiers, register_code);
    if (released && toggle_def->hold_modifiers) apply_modifiers(toggle_def->hold_modifiers, unregister_code);

    if (released && toggle_def->on_after_hold_tap_fn != 0 && IS_LAYER_ON(toggle_def->hold_layer) && (get_oneshot_layer_state() & ONESHOT_OTHER_KEY_PRESSED) != 0) {
        toggle_def->on_after_hold_tap_fn();
    }

    if (released && toggle_def->hold_layer && IS_LAYER_ON(toggle_def->hold_layer) && ignore_next_oneshot_layer_switch) {
        reset_oneshot_layer();
        layer_clear();
        ignore_next_oneshot_layer_switch = false;
        return;
    }

    // switch back to base layer
    if (toggle_def->main_layer == L_BASE && ((toggle_def->hold_layer && released) || (!toggle_def->hold_layer && pressed))) {
        reset_oneshot_layer();
        layer_clear();
    }
    // swap layers and preserve their oneshot state
    else if (swap) {
        layer_clear();
        set_oneshot_layer(toggle_def->main_layer, get_oneshot_layer_state());
    }
    // handle oneshot state, move to the layer permanently or switch back to base layer
    else if (IS_LAYER_ON(toggle_def->main_layer) || IS_LAYER_ON(toggle_def->hold_layer)) {
        if (toggle_def->hold_layer && IS_LAYER_ON(toggle_def->hold_layer)) {
            layer_clear();
            set_oneshot_layer(toggle_def->main_layer, get_oneshot_layer_state());
        }

        // layer is in oneshot mode
        if (get_oneshot_layer() == toggle_def->main_layer) {
            // and was just release, handle oneshot state properly
            if (released) {
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
            // it was pressed again; we need to decide what to do based on timing
            else if (pressed) {
                reset_oneshot_layer();

                // if it was pressed quickly again => move to the layer permanently
                if (timer_elapsed(oneshot_layer_switch_time) < 250) {
                    layer_move(toggle_def->main_layer);
                }
                // or switch back to base layer (works as toggle)
                else {
                    if (toggle_def->hold_layer) {
                        reset_oneshot_layer();
                        layer_clear();
                        set_oneshot_layer(toggle_def->hold_layer, ONESHOT_START);
                        ignore_next_oneshot_layer_switch = true;
                    }
                    else {
                        layer_clear();
                    }
                }
            }
        }
        // layer is in permanent mode and was pressed again => switch back to base layer (works as toggle)
        else if (pressed) {
            if (toggle_def->hold_layer) {
                reset_oneshot_layer();
                layer_clear();
                set_oneshot_layer(toggle_def->hold_layer, ONESHOT_START);
                ignore_next_oneshot_layer_switch = true;
            }
            else {
                layer_clear();
            }
        }
    }
    // layer is off, switch it on as oneshot layer for now
    else if (pressed) {
        reset_oneshot_layer();
        layer_clear();
        oneshot_layer_switch_time = timer_read();

        if (toggle_def->hold_layer) {
            set_oneshot_layer(toggle_def->hold_layer, ONESHOT_START);
        } else {
            set_oneshot_layer(toggle_def->main_layer, ONESHOT_START);
        }
    }
}

bool process_compose_key(uint16_t keycode, keyrecord_t *record, bool is_left_shift_pressed, bool is_shift_pressed) {
    if (record->event.pressed) {
        // diacritics macros
        switch (keycode) {
            case MC_CK_ACUTE_A:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_ACUTE, shift_letter('A', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_ACUTE_E:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_ACUTE, shift_letter('E', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_ACUTE_I:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_ACUTE, shift_letter('I', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_ACUTE_O:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_ACUTE, shift_letter('O', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_ACUTE_Y:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_ACUTE, shift_letter('Y', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_ACUTE_U:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_ACUTE, shift_letter('U', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_CARON_E:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_CARON, shift_letter('E', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_CARON_Z:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_CARON, shift_letter('Z', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_CARON_C:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_CARON, shift_letter('C', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_CARON_S:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_CARON, shift_letter('S', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_CARON_R:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_CARON, shift_letter('R', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_CARON_T:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_CARON, shift_letter('T', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_CARON_D:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_CARON, shift_letter('D', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_CARON_N:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_CARON, shift_letter('N', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_RING_ABOVE_U:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_RING_ABOVE, shift_letter('U', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_OGON_E:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_OGON, shift_letter('E', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_OGON_A:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_OGON, shift_letter('A', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_ACUTE_S:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_ACUTE, shift_letter('S', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_STROK_L:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_STROK, shift_letter('L', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_ACUTE_Z:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_ACUTE, shift_letter('Z', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_ACUTE_C:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_ACUTE, shift_letter('C', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_ACUTE_N:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_ACUTE, shift_letter('N', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_DOT_Z:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo(CK_DOT, shift_letter('Z', is_shift_pressed));
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;

            // other useful compose key combos
            case MC_CK_X_TIMES:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo('x', 'x');
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_TRIPLE_DOT:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo('.', '.');
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
            case MC_CK_TM:
                if (is_shift_pressed) unregister_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                type_compose_key_combo('t', 'm');
                if (is_shift_pressed) register_code(is_left_shift_pressed ? KC_LSHIFT : KC_RSHIFT);
                return false;
        }
    }

    return true;
}

void type_compose_key_combo(char first_char, char second_char) {
    char key_combo[7];
    /* it's de-facto this: SEND_STRING(SS_RALT(key_combo)); */
    /* the problem is that SEND_STRING macro can use only static strings */
    /* \2\xe6{string}\3\xe6 is equivalent of SS_RALT(string) */
    sprintf(key_combo, "\2\xe6%c%c\3\xe6", first_char, second_char);
    send_string(key_combo);
    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
}

char shift_letter(char letter, bool shift) {
    return letter + (shift ? 0 : 32);
}
