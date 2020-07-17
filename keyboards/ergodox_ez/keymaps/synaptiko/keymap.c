#include QMK_KEYBOARD_H
#include "synaptiko.h"

// TODO jprokop: get rid of comments and implement some automatic "UI" generator (based on the code)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* .----------------------------------------------. .----------------------------------------------.
     * |   `~   |  1! |  2@ |  3# |  4$ |  5% |       | |       |  6^ |  7& |  8* |  9( |  0) |   -_   |
     * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
     * |  Tab   |  qQ |  wW |  eE |  rR |  tT |  Top  | |       |  yY |  uU |  iI |  oO |  pP |   +    |
     * |--------+-----+-----+-----+-----+-----|Monitor| |       |-----+-----+-----+-----+-----+--------|
     * |  Esc   |  aA |  sS |  dD |  fF |  gG |-------| |-------|  hH |  jJ |  kK |  lL |  ;: |   =+   |
     * |--------+-----+-----+-----+-----+-----| Bottom| |       |-----+-----+-----+-----+-----+--------|
     * | LShift |  zZ |  xX |  cC |  vV |  bB |Monitor| |       |  nN |  mM |  ,< |  .> |  /? | RShift |
     * '--------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+--------'
     * \  LCtrl|      |  ⯅  |  ⯆  | LAlt|                             | Prog|  ⯇  |  ⯈  |     |   '"   /
     *  `-------------------------------'                             '-------------------------------'
     *                               .---------------.   .---------------.
     *                               |        | Enter|   |  PM1  |  RMS  |
     *                       .-------+-------+-------|   |-------+-------+-------.
     *                       |       |       |       |   |  PM2  |       |       |
     *                       | Space | Misc  |-------|   |-------| Enter |⌫  /Del|
     *                       |       |      |BaseDiac|   | AltGr |       |       |
     *                       '-----------------------'   '-----------------------'
     */
    [L_BASE] = LAYOUT_ergodox(
        // left hand
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRANSPARENT,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, LCTL(LALT(KC_T)),
        KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G,
        KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, LCTL(LALT(KC_B)),
        KC_LCTRL, KC_TRANSPARENT, KC_UP, KC_DOWN, KC_LALT,
        KC_TRANSPARENT, KC_ENTER, KC_TRANSPARENT,
        KC_SPACE, TO(L_MISC), TO(L_BASE_DIAC),

        // right hand
        KC_TRANSPARENT, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS,
        KC_TRANSPARENT, KC_Y, KC_U, KC_I, KC_O, KC_P, LSFT(KC_EQUAL),
        KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_EQUAL,
        KC_TRANSPARENT, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
        MO(L_PROG), KC_LEFT, KC_RIGHT, KC_TRANSPARENT, KC_QUOTE,
        DYN_MACRO_PLAY1, DYN_REC_STOP, DYN_MACRO_PLAY2,
        KC_RALT, KC_ENTER, KC_BSPACE
    ),

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
     *                       |       | DiacCZ|-------|   |-------|       |       |
     *                       |       |       | Base  |   |       |       |       |
     *                       '-----------------------'   '-----------------------'
     */
    [L_BASE_DIAC] = LAYOUT_ergodox(
        // left hand
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, OSL(L_DIAC_CZ), TO(L_BASE),

        // right hand
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

    /* .----------------------------------------------. .----------------------------------------------.
     * |        |     |     |     |     |     |       | |       |     |     |     |     |     |        |
     * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
     * |        |     |     |     |     |     |       | |       |     |     |     |     |     |        |
     * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
     * |        |  [  |  ]  |  (  |  )  |  &  |-------| |-------|  |  |  {  |  }  |     |  -_ |        |
     * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
     * |        |     |     |     |LC+PU|LC+PD|       | |       |     |     |  <  |  >  |  \| |        |
     * '--------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+--------'
     * \        |     | PgUp| PgDn|     |                             |     | Home| End |     |        /
     *  `-------------------------------'                             '-------------------------------'
     *                               .---------------.   .---------------.
     *                               |       |       |   |       |       |
     *                       .-------+-------+-------|   |-------+-------+-------.
     *                       |       |       |       |   |       |       |       |
     *                       |       |       |-------|   |-------|       |       |
     *                       |       |       |       |   |       |       |       |
     *                       '-----------------------'   '-----------------------'
     */
    [L_PROG] = LAYOUT_ergodox(
        // left hand
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_LBRACKET, KC_RBRACKET, KC_LPRN, KC_RPRN, KC_AMPR,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_PGUP), LCTL(KC_PGDOWN), KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_PGUP, KC_PGDOWN, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        // right hand
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        LSFT(KC_BSLASH), KC_LCBR, KC_RCBR, KC_TRANSPARENT, KC_MINUS, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LABK, KC_RABK, KC_BSLASH, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_HOME, KC_END, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

    /* .----------------------------------------------. .----------------------------------------------.
     * |        |     |     |     |     |     |       | |       |     |     |     |     |     |        |
     * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
     * |        |     |  ěĚ |  éÉ |  řŘ |  ťŤ |       | |       |  ýÝ |  ůŮ |  íÍ |  óÓ |     |        |
     * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
     * |        |  áÁ |  šŠ |  ďĎ |     |     |-------| |-------|     |  úÚ |     |     |     |        |
     * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
     * |        |  žŽ |     |  čČ |     |     |       | |       |  ňŇ |     |     |     |     |        |
     * '--------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+--------'
     * \        |     |     |     |     |                             |     |     |     |     |        /
     *  `-------------------------------'                             '-------------------------------'
     *                               .---------------.   .---------------.
     *                               |       |       |   |       |       |
     *                       .-------+-------+-------|   |-------+-------+-------.
     *                       |       |       |       |   |       |       |       |
     *                       |       |BaseDiac|------|   |-------|       |       |
     *                       |       |       |       |   |       |       |       |
     *                       '-----------------------'   '-----------------------'
     */
    [L_DIAC_CZ] = LAYOUT_ergodox(
        // left hand
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_CARON_E, MC_CK_ACUTE_E, MC_CK_CARON_R, MC_CK_CARON_T, KC_TRANSPARENT,
        KC_TRANSPARENT, MC_CK_ACUTE_A, MC_CK_CARON_S, MC_CK_CARON_D, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, MC_CK_CARON_Z, KC_TRANSPARENT, MC_CK_CARON_C, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, TO(L_BASE_DIAC), KC_TRANSPARENT,

        // right hand
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, MC_CK_ACUTE_Y, MC_CK_RING_ABOVE_U, MC_CK_ACUTE_I, MC_CK_ACUTE_O, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, MC_CK_ACUTE_U, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, MC_CK_CARON_N, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

    /* .----------------------------------------------. .----------------------------------------------.
     * |  Reset | RM1 | RM2 |     |     |     |       | | RGBTg |     |     |     |     |     |        |
     * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
     * |        | MWU | MWL | MWR |     |     |       | | Bri+  | Menu| MCM | MCL | MCR |Pause|        |
     * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
     * |        | MWD | MCL | MCR | MCM |Enter|-------| |-------| M⯇  | M⯆  | M⯅  | M⯈  | MWU |        |
     * |--------+-----+-----+-----+-----+-----|       | | Bri-  |-----+-----+-----+-----+-----+--------|
     * |        |     |CtrlX|CtrlC|CtrlV|⌫  /D|       | |       |     |     |     |     | MWD |        |
     * '--------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+--------'
     * \        |     |     |     |     |                             |     |     |     |     |        /
     *  `-------------------------------'                             '-------------------------------'
     *                               .---------------.   .---------------.
     *                               |       |       |   |       |       |
     *                       .-------+-------+-------|   |-------+-------+-------.
     *                       |       |       | FKeys |   |       |       |       |
     *                       |       | Base  |-------|   |-------|       |       |
     *                       |       |      |FKeysMod|   |       |       |       |
     *                       '-----------------------'   '-----------------------'
     */
    [L_MISC] = LAYOUT_ergodox(
        // left hand
        RESET, DYN_REC_START1, DYN_REC_START2, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_MS_WH_UP, KC_MS_WH_LEFT, KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_MS_WH_DOWN, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, KC_ENTER,
        KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_BSPACE, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, OSL(L_FKEYS),
        KC_TRANSPARENT, TO(L_BASE), LM(L_FKEYS, MOD_LCTL | MOD_LALT),

        // right hand
        MC_RGB_TOG, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        MC_RGB_VAI, KC_APPLICATION, KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2, LALT(LSFT(KC_P)), KC_TRANSPARENT,
        KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_MS_WH_UP, KC_TRANSPARENT,
        MC_RGB_VAD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

    /* .----------------------------------------------. .----------------------------------------------.
     * |        |  F1 |  F2 |  F3 |  F4 |  F5 |       | |       |  F6 |  F7 |  F8 |  F9 | F10 |        |
     * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
     * |        |     |     |     |     |     |       | |       | F12 | F11 |     |     |     |        |
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
    [L_FKEYS] = LAYOUT_ergodox(
        // left hand
        KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        // right hand
        KC_TRANSPARENT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_F12, KC_F11, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

};

uint16_t idle_timer = 0;
uint8_t halfmin_counter = 0;

uint8_t rgblight_val = 0;
bool rgblight_enabled = true;
bool rgblight_on = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool is_left_shift_pressed = false;
    static bool is_shift_pressed = false;

    if (rgblight_enabled) {
        if (rgblight_on == false) {
            rgblight_enable_noeeprom();
            rgblight_on = true;
        }

        idle_timer = timer_read();
        halfmin_counter = 0;
    }

    switch (keycode) {
        case KC_LSHIFT:
            is_left_shift_pressed = record->event.pressed;
        case KC_RSHIFT:
            is_shift_pressed = record->event.pressed;
            break;
        case KC_BSPACE:
            if (is_left_shift_pressed) {
                unregister_code(KC_LSHIFT);
                if (record->event.pressed) {
                    register_code(KC_DELETE);
                } else {
                    unregister_code(KC_DELETE);
                }
                register_code(KC_LSHIFT);
                return false;
            }
            break;
    }

    if (!process_compose_key(keycode, record, is_left_shift_pressed, is_shift_pressed)) {
        return false;
    }

    if (record->event.pressed) {
        switch (keycode) {
            case KC_F1:
            case KC_F2:
            case KC_F3:
            case KC_F4:
            case KC_F5:
            case KC_F6:
            case KC_F7:
            case KC_F8:
            case KC_F9:
            case KC_F10:
            case KC_F11:
            case KC_F12:
                layer_off(L_MISC);
                return true;
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

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();

    switch (layer) {
        case L_BASE:
            rgblight_sethsv_noeeprom(233, 255, rgblight_val);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT);
            ergodox_right_led_2_off();
            ergodox_right_led_3_off();
            break;
        case L_BASE_DIAC:
            rgblight_sethsv_noeeprom(233, 255, rgblight_val);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT);
            ergodox_right_led_2_off();
            ergodox_right_led_3_on();
            break;
        case L_PROG:
            rgblight_sethsv_noeeprom(11, 176, rgblight_val);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            ergodox_right_led_2_off();
            ergodox_right_led_3_off();
            break;
        case L_DIAC_CZ:
            rgblight_sethsv_noeeprom(131, 102, rgblight_val);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            ergodox_right_led_2_off();
            ergodox_right_led_3_on();
            break;
        case L_MISC:
            rgblight_sethsv_noeeprom(36, 255, rgblight_val);
            rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
            ergodox_right_led_2_on();
            ergodox_right_led_3_off();
            break;
        default:
            ergodox_right_led_2_off();
            ergodox_right_led_3_off();
            break;
    }

    return state;
};

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
