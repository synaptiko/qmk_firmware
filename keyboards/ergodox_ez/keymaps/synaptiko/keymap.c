#include QMK_KEYBOARD_H
#include "synaptiko.h"

enum {
  // SAFE_RANGE must be used to tag the first element of the enum.
  // DYNAMIC_MACRO_RANGE must always be the last element of the enum if other
  // values are added (as its value is used to create a couple of other keycodes
  // after it).
  DYNAMIC_MACRO_RANGE = SAFE_RANGE,
};
// This file must be included after DYNAMIC_MACRO_RANGE is defined...
#include "dynamic_macro.h"

/* Layer switch keys legend:
 * (One-Shot-Double-Tap-Toggle)
 *  For details see comment for process_layer_event function in users/synaptiko/synaptiko.c
 *
 * <To-Layer>
 *  Direct switch to a layer. Works for switching to
 *  lower layers as well.
 *
 * ~ sign indicates that this key cannot be used
 *  in this layer as it's blocked by "layer key"
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* .----------------------------------------------. .----------------------------------------------.
     * |   `~   |  1! |  2@ |  3# |  4$ |  5% |  Del  | |  \|   |  6^ |  7& |  8* |  9( |  0) |   -_   |
     * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
     * |  Tab   |  qQ |  wW |  eE |  rR |  tT |  Home | | PgUp  |  yY |  uU |  iI |  oO |  pP |   =+   |
     * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
     * |  Esc   |  aA |  sS |  dD |  fF |  gG |-------| |-------|  hH |  jJ |  kK |  lL |  ;: |   '"   |
     * |--------+-----+-----+-----+-----+-----|  End  | | PgDn  |-----+-----+-----+-----+-----+--------|
     * | LShift |  zZ |  xX |  cC |  vV |  bB |       | |       |  nN |  mM |  ,< |  .> |  /? | RShift |
     * '--------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+--------'
     * \  LCtrl |     |  ⯅  |  ⯆  | LAlt|                             |  ⯇  |  ⯈  |  [{ | ]}  | C+A+(1)/
     *  `-------------------------------'                             '-------------------------------'
     *                               .---------------.   .---------------.
     *                               |DIACR_L|       |   |  PM1  |  RMS  |
     *                       .-------+-------+-------|   |-------+-------+-------.
     *                       |       |       |       |   |  PM2  |       |       |
     *                       | Space |(1/2/3)|-------|   |-------| Enter |  ⌫    |
     *                       |       |       |  (4)  |   | AltGr |       |       |
     *                       '-----------------------'   '-----------------------'
     */
    [L_BASE] = LAYOUT_ergodox(
        // left hand
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_DELETE,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_HOME,
        KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_END,
        CTL_T(KC_NO), KC_TRANSPARENT, KC_UP, KC_DOWN, KC_LALT,
        MC_DIACRITICS_LOCK, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_SPACE, MC_T_ALT, MC_T_MISC,

        // right hand
        KC_BSLASH, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS,
        KC_PGUP, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQUAL,
        KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
        KC_PGDOWN, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
        KC_LEFT, KC_RIGHT, KC_LBRACKET, KC_RBRACKET, MC_T_VTTYS,
        DYN_MACRO_PLAY1, DYN_REC_STOP, DYN_MACRO_PLAY2,
        KC_RALT, KC_ENTER, KC_BSPACE
    ),

    /* .----------------------------------------------. .----------------------------------------------.
     * |        |  F1 |  F2 |  F3 |  F4 |  F5 |       | |       |  F6 |  F7 |  F8 |  F9 | F10 |        |
     * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
     * |        |     |     |     |     |     |       | |       | F12 | F11 |  !  |  -  |  +  |   =    |
     * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
     * |   <0>  |     |  [  |  (  |  {  |  <  |-------| |-------|  >  |  }  |  )  |  ]  |  &  |   |    |
     * |--------+-----+-----+-----+-----+-----| Enter | |       |-----+-----+-----+-----+-----+--------|
     * |        |     |  ×  |     |SelPs|     |       | |       |     |  ™  |     |  …  |  \  |        |
     * '--------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+--------'
     * \        |     |     |     |     |                             |     |     |     |     |        /
     *  `-------------------------------'                             '-------------------------------'
     *                               .---------------.   .---------------.
     *                               |       |       |   |       |       |
     *                       .-------+-------+-------|   |-------+-------+-------.
     *                       |       |       |       |   |       |       |       |
     *                       |       |  (~1) |-------|   |-------|       |       |
     *                       |       |       |       |   |       |       |       |
     *                       '-----------------------'   '-----------------------'
     */
    [L_PROG] = LAYOUT_ergodox(
        // left hand
        KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        MC_T_BASE, KC_TRANSPARENT, KC_LBRACKET, KC_LPRN, KC_LCBR, KC_LABK,
        KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_X_TIMES, KC_TRANSPARENT, MC_SELECTION_PASTE, KC_TRANSPARENT, KC_ENTER,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        // right hand
        KC_TRANSPARENT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_F12, KC_F11, KC_EXLM, KC_MINUS, KC_PLUS, KC_EQUAL,
        KC_RABK, KC_RCBR, KC_RPRN, KC_RBRACKET, KC_AMPR, KC_PIPE,
        KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_TM, KC_TRANSPARENT, MC_CK_TRIPLE_DOT, KC_BSLASH, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

    /* .----------------------------------------------. .----------------------------------------------.
     * |        |     |     |     |     |     |       | |       |     |     |     |     |     |        |
     * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
     * |        |     |  ěĚ |  éÉ |  řŘ |  ťŤ |       | |       |  ýÝ |  ůŮ |  íÍ |  óÓ |     |        |
     * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
     * |   <0>  |  áÁ |  šŠ |  ďĎ |     |     |-------| |-------|     |  úÚ |     |     |     |        |
     * |--------+-----+-----+-----+-----+-----| Enter | |       |-----+-----+-----+-----+-----+--------|
     * |        |  žŽ |     |  čČ |     |     |       | |       |  ňŇ |     |     |  …  |     |        |
     * '--------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+--------'
     * \        |     |     |     |     |                             |     |     |     |     |        /
     *  `-------------------------------'                             '-------------------------------'
     *                               .---------------.   .---------------.
     *                               |       |       |   |       |       |
     *                       .-------+-------+-------|   |-------+-------+-------.
     *                       |       |       |       |   |       |       |       |
     *                       |       |  (~2) |-------|   |-------|       |       |
     *                       |       |       |       |   |       |       |       |
     *                       '-----------------------'   '-----------------------'
     */
    [L_DIAC_CZ] = LAYOUT_ergodox(
        // left hand
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_CARON_E, MC_CK_ACUTE_E, MC_CK_CARON_R, MC_CK_CARON_T, KC_TRANSPARENT,
        MC_T_BASE, MC_CK_ACUTE_A, MC_CK_CARON_S, MC_CK_CARON_D, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, MC_CK_CARON_Z, KC_TRANSPARENT, MC_CK_CARON_C, KC_TRANSPARENT, KC_TRANSPARENT, KC_ENTER,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        // right hand
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, MC_CK_ACUTE_Y, MC_CK_RING_ABOVE_U, MC_CK_ACUTE_I, MC_CK_ACUTE_O, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, MC_CK_ACUTE_U, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, MC_CK_CARON_N, KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_TRIPLE_DOT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

    /* .----------------------------------------------. .----------------------------------------------.
     * |        |     |     |     |     |     |       | |       |     |     |     |     |     |        |
     * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
     * |        |     |     |  ęĘ |     |     |       | |       |     |     |     |  óÓ |     |        |
     * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
     * |   <0>  |  ąĄ |  śŚ |     |     |     |-------| |-------|     |     |     |  łŁ |     |        |
     * |--------+-----+-----+-----+-----+-----| Enter | |       |-----+-----+-----+-----+-----+--------|
     * |        |  źŹ |  żŻ |  ćĆ |     |     |       | |       |  ńŃ |     |     |  …  |     |        |
     * '--------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+--------'
     * \        |     |     |     |     |                             |     |     |     |     |        /
     *  `-------------------------------'                             '-------------------------------'
     *                               .---------------.   .---------------.
     *                               |       |       |   |       |       |
     *                       .-------+-------+-------|   |-------+-------+-------.
     *                       |       |       |       |   |       |       |       |
     *                       |       |  (~3) |-------|   |-------|       |       |
     *                       |       |       |       |   |       |       |       |
     *                       '-----------------------'   '-----------------------'
     */
    [L_DIAC_PL] = LAYOUT_ergodox(
        // left hand
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_OGON_E, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        MC_T_BASE, MC_CK_OGON_A, MC_CK_ACUTE_S, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, MC_CK_ACUTE_Z, MC_CK_DOT_Z, MC_CK_ACUTE_C, KC_TRANSPARENT, KC_TRANSPARENT, KC_ENTER,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        // right hand
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_ACUTE_O, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_STROK_L, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, MC_CK_ACUTE_N, KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_TRIPLE_DOT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

    /* .----------------------------------------------. .----------------------------------------------.
     * |  Reset | RM1 | RM2 |     |     |     |       | |       |     |     |     |     |RGBTg|  Bri+  |
     * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
     * |        |     |     |     |     |     | Win+  | |       |     |     |     |     |Pause|  Bri-  |
     * |--------+-----+-----+-----+-----+-----| PrntS | |       |-----+-----+-----+-----+-----+--------|
     * |   <0>  |     |     |     |     |     |-------| |-------| M⯇  | M⯆  | M⯅  | M⯈  | MWU |  VolUp |
     * |--------+-----+-----+-----+-----+-----| PrntS | |       |-----+-----+-----+-----+-----+--------|
     * |        |     |     |     |     |     |       | |       |KbChs|     |     |     | MWD |  VolDn |
     * '--------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+--------'
     * \        |     |     |     |     |                             |     |     |     |     |  Mute  /
     *  `-------------------------------'                             '-------------------------------'
     *                               .---------------.   .---------------.
     *                               |       |       |   |       |       |
     *                       .-------+-------+-------|   |-------+-------+-------.
     *                       |       |       |       |   |  Menu |       |       |
     *                       |       |       |-------|   |-------|  MCR  |  MCL  |
     *                       |       |       |  (~4) |   |  MCM  |       |       |
     *                       '-----------------------'   '-----------------------'
     */
    [L_MISC] = LAYOUT_ergodox(
        // left hand
        RESET, DYN_REC_START1, DYN_REC_START2, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_PSCREEN),
        MC_T_BASE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PSCREEN,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        // right hand
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MC_RGB_TOG, MC_RGB_VAI,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LSFT(KC_P)), MC_RGB_VAD,
        KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_MS_WH_UP, KC_AUDIO_VOL_UP,
        KC_TRANSPARENT, MC_KEYBOARD_CHEATSHEET, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN, KC_AUDIO_VOL_DOWN,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_MUTE,
        KC_APPLICATION, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN1
    )
};

const uint16_t PROGMEM fn_actions[] = {};

void update_leds_for_lang(void);

uint8_t rgblight_val = 0;

// RGBLight timeout feature
#define RGBLIGHT_TIMEOUT 5 // in minutes
uint16_t idle_timer = 0;
uint8_t halfmin_counter = 0;
bool rgblight_enabled = true;
bool rgblight_on = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool is_shift_pressed = false;

    if (rgblight_enabled) {
        if (rgblight_on == false) {
            rgblight_enable_noeeprom();
            rgblight_on = true;
        }

        idle_timer = timer_read();
        halfmin_counter = 0;
    }

    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case KC_LSHIFT:
        case KC_RSHIFT:
            is_shift_pressed = record->event.pressed;
            return false;
        case MC_DIACRITICS_LOCK:
            if (record->event.pressed) {
                alternate_main_layer(&T_ALT);
                process_layer_event(&T_ALT, record->event.pressed, true);
                update_leds_for_lang();
            }
            return false;
        case MC_T_ALT:
            process_layer_event(&T_ALT, record->event.pressed, false);
            return false;
        case MC_T_MISC:
            process_layer_event(&T_MISC, record->event.pressed, false);
            return false;
        case MC_T_BASE:
            process_layer_event(&T_BASE, record->event.pressed, false);
            return false;
        case MC_T_VTTYS:
            process_layer_event(&T_VTTYS, record->event.pressed, false);
            return false;
        case KC_AUDIO_MUTE:
            // this particular key doesn't clear oneshot layer state properly
            // => do it manually
            if (record->event.pressed) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            }
            return true;
    }

    if (!process_compose_key(keycode, record, is_shift_pressed)) {
        return false;
    }

    if (record->event.pressed) {
        switch (keycode) {
            // RGB brightness
            case MC_RGB_VAI:
                if (record->event.pressed) {
                    rgblight_sethsv_noeeprom(233, 255, rgblight_val);
                    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT);
                    // following call will save new color + value to eeprom,
                    // that's why above it's switched to the base layer color
                    rgblight_increase_val();
                    rgblight_val = rgblight_get_val();
                    // and here we switch back to misc layer color
                    rgblight_sethsv_noeeprom(36, 255, rgblight_val);
                    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
                }
                return false;
            case MC_RGB_VAD:
                if (record->event.pressed) {
                    rgblight_sethsv_noeeprom(233, 255, rgblight_val);
                    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT);
                    // following call will save new color + value to eeprom,
                    // that's why above it's switched to the base layer color
                    rgblight_decrease_val();
                    rgblight_val = rgblight_get_val();
                    // and here we switch back to misc layer color
                    rgblight_sethsv_noeeprom(36, 255, rgblight_val);
                    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
                }
                return false;
            case MC_RGB_TOG:
                if (record->event.pressed) {
                    rgblight_enabled = !rgblight_enabled;

                    if (rgblight_enabled) {
                        rgblight_enable_noeeprom();

                        idle_timer = timer_read();
                        halfmin_counter = 0;
                    } else {
                        rgblight_disable_noeeprom();
                    }
                    // we have to clear layer state manually (similar to mute)
                    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                }
                return false;

            // other macros
            case MC_SELECTION_PASTE:
                SEND_STRING(SS_TAP(X_F15)); // handled in my i3 config
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                return false;
            case MC_KEYBOARD_CHEATSHEET:
                SEND_STRING(SS_TAP(X_F16)); // handled in my i3 config
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                return false;
        }
    }

    return true;
}

void matrix_init_user(void) {
    rgblight_init();
    rgblight_val = rgblight_get_val();
}

void matrix_scan_user(void) {
    if (rgblight_enabled) {
        // idle_timer needs to be set one time
        if (idle_timer == 0) idle_timer = timer_read();

        if (rgblight_on) {
            if (timer_elapsed(idle_timer) > 30000) {
                    halfmin_counter++;
                    idle_timer = timer_read();
            }

            if (halfmin_counter >= RGBLIGHT_TIMEOUT * 2) {
                    rgblight_disable_noeeprom();
                    rgblight_on = false;
                    halfmin_counter = 0;
            }
        }
    }
}

uint32_t layer_state_set_rgb(uint32_t state) {
    uint8_t layer = biton32(state);

    switch (layer) {
        case L_BASE:
            rgblight_sethsv_noeeprom(233, 255, rgblight_val);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT);
            break;
        case L_PROG:
            rgblight_sethsv_noeeprom(11, 176, rgblight_val);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case L_DIAC_CZ:
            rgblight_sethsv_noeeprom(131, 102, rgblight_val);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case L_DIAC_PL:
            rgblight_sethsv_noeeprom(106, 255, rgblight_val);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
        case L_MISC:
            rgblight_sethsv_noeeprom(36, 255, rgblight_val);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            break;
    }

    return state;
}

uint32_t layer_state_set_user(uint32_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();

    update_leds_for_lang();
    state = layer_state_set_rgb(state);

    return state;
};

void update_leds_for_lang(void) {
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (T_ALT.main_layer) {
        case L_DIAC_CZ:
            ergodox_right_led_3_on();
            break;
        case L_DIAC_PL:
            ergodox_right_led_2_on();
            break;
    }
}

// Template for layout
/* .----------------------------------------------. .----------------------------------------------.
 * |        |     |     |     |     |     |       | |       |     |     |     |     |     |        |
 * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
 * |        |     |     |     |     |     |       | |       |     |     |     |     |     |        |
 * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
 * |        |     |     |     |     |     |-------| |-------|     |     |     |     |     |        |
 * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
 * |        |     |     |     |     |     |       | |       |     |     |     |     |     |        |
 * '--------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+--------'
 * \        |     |     |     |     |                             |     |     |     |     |        /
 *  `-------------------------------'                             '-------------------------------'
 *                               .---------------.   .---------------.
 *                               |       |       |   |       |       |
 *                       .-------+-------+-------|   |-------+-------+-------.
 *                       |       |       |       |   |       |       |       |
 *                       |       |       |-------|   |-------|       |       |
 *                       |       |       |       |   |       |       |       |
 *                       '-----------------------'   '-----------------------'
 */
