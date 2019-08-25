#include QMK_KEYBOARD_H
#include "eeprom.h"
#include "synaptiko.h"

// TODO jprokop todo-list:
// 1. solve setting and saving of brightness of LED in planck
// 2. solve dynamic macros
// 3. improve RGB handling below (see the todo below)
// 4. unify/refactor Ergodox keymaps, so it's similar to planck
// 5. generalize as much as possible to my "users" folder
// 6. clean-up process_layer_event (hold_layer etc.) is not needed anymore
// 6a. maybe I can get rid of hold_modifier as well (just call register/unregister_code directly from process_record_user)
// 6b. update functionality for switching VTTYS (especially for Ergodox)
// 7. get rid of comments and implement some automatic "UI" generator (based on the code)
// 8. wrap some global variables into functions which uses them (with static)
// 9. check this: https://github.com/qmk/qmk_firmware/issues/6118#issuecomment-500889522

void update_leds_for_lang(bool is_active);

// TODO jprokop: add dynamic macro support for planck later (it will require more work because I cannot have a dedicated key for it)
/* enum { */
  // SAFE_RANGE must be used to tag the first element of the enum.
  // DYNAMIC_MACRO_RANGE must always be the last element of the enum if other
  // values are added (as its value is used to create a couple of other keycodes
  // after it).
  /* DYNAMIC_MACRO_RANGE = SAFE_RANGE, */
/* }; */
// This file must be included after DYNAMIC_MACRO_RANGE is defined...
/* #include "dynamic_macro.h" */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* .-----------------------------------------------------------------------------------------------------------------------------------.
     * |    Tab   |    qQ    |    wW    |    eE    |    rR    |    tT    |    yY    |    uU    |    iI    |    oO    |    pP    |  ⌫  /Del |
     * |----------+----------+----------+----------+----------+---------------------+----------+----------+----------+----------+----------|
     * |    Esc   |    aA    |    sS    |    dD    |    fF    |    gG    |    hH    |    jJ    |    kK    |    lL    |    ;:    |  Enter   |
     * |----------+----------+----------+----------+----------+----------|----------+----------+----------+----------+----------+----------|
     * |  LShift  |    zZ    |    xX    |    cC    |    vV    |    bB    |    nN    |    mM    |    ,<    |    .>    |    /?    |  RShift  |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |  LCtrl   |  Extend  |    ⯅     |    ⯆     |   LAlt   |        Space        |   Prog   |    ⯇     |    ⯈     |   Misc   |    '"    |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [L_BASE] = LAYOUT_planck_mit(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPACE,
        KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_ENTER,
        KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
        KC_LCTRL, MC_T_EXTEND, KC_UP, KC_DOWN, KC_LALT, KC_SPACE, MC_T_PROG, KC_LEFT, KC_RIGHT, MC_T_MISC, KC_QUOTE
    ),

    /* .-----------------------------------------------------------------------------------------------------------------------------------.
     * |    `~    |    1!    |    2@    |    3#    |    4$    |    5%    |    6^    |    7&    |    8*    |    9(    |    0)    |          |
     * |----------+----------+----------+----------+----------+---------------------+----------+----------+----------+----------+----------|
     * |          |    &     |     [    |     {    |     (    |     <    |     >    |     )    |     }    |     ]    |    -_    |    =+    |
     * |----------+----------+----------+----------+----------+----------|----------+----------+----------+----------+----------+----------|
     * |          |    |     |     ×    |          |LCtrl+PgUp|LCtrl+PgDn|          |     ™    |          |     …    |    \|    |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |   PgUp   |   PgDn   |          |                     |          |   Home   |   End    |          |          |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [L_PROG] = LAYOUT_planck_mit(
        KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_AMPR, KC_LBRACKET, KC_LCBR, KC_LPRN, KC_LABK, KC_RABK, KC_RPRN, KC_RCBR, KC_RBRACKET, KC_MINUS, KC_EQUAL,
        KC_TRANSPARENT, LSFT(KC_BSLASH), MC_CK_X_TIMES, KC_TRANSPARENT, LCTL(KC_PGUP), LCTL(KC_PGDOWN), KC_TRANSPARENT, MC_CK_TM, KC_TRANSPARENT, MC_CK_TRIPLE_DOT, KC_BSLASH, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_PGUP, KC_PGDOWN, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME, KC_END, KC_TRANSPARENT, KC_TRANSPARENT
    ),

    /* .-----------------------------------------------------------------------------------------------------------------------------------.
     * |          |          |    ěĚ    |    éÉ    |    řŘ    |    ťŤ    |    ýÝ    |    ůŮ    |    íÍ    |    óÓ    |          |          |
     * |----------+----------+----------+----------+----------+---------------------+----------+----------+----------+----------+----------|
     * |          |    áÁ    |    šŠ    |    ďĎ    |          |          |          |    úÚ    |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------|----------+----------+----------+----------+----------+----------|
     * |          |    žŽ    |          |    čČ    |          |          |    ňŇ    |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |                     |          |          |          |          |          |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [L_DIAC_CZ] = LAYOUT_planck_mit(
        KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_CARON_E, MC_CK_ACUTE_E, MC_CK_CARON_R, MC_CK_CARON_T, MC_CK_ACUTE_Y, MC_CK_RING_ABOVE_U, MC_CK_ACUTE_I, MC_CK_ACUTE_O, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, MC_CK_ACUTE_A, MC_CK_CARON_S, MC_CK_CARON_D, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_ACUTE_U, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, MC_CK_CARON_Z, KC_TRANSPARENT, MC_CK_CARON_C, KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_CARON_N, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

    /* .-----------------------------------------------------------------------------------------------------------------------------------.
     * |          |          |          |    ęĘ    |          |          |          |          |          |    óÓ    |          |          |
     * |----------+----------+----------+----------+----------+---------------------+----------+----------+----------+----------+----------|
     * |          |    ąĄ    |    śŚ    |          |          |          |          |          |          |    łŁ    |          |          |
     * |----------+----------+----------+----------+----------+----------|----------+----------+----------+----------+----------+----------|
     * |          |    źŹ    |    żŻ    |    ćĆ    |          |          |    ńŃ    |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |                     |          |          |          |          |          |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [L_DIAC_PL] = LAYOUT_planck_mit(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_OGON_E, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_ACUTE_O, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, MC_CK_OGON_A, MC_CK_ACUTE_S, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_STROK_L, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, MC_CK_ACUTE_Z, MC_CK_DOT_Z, MC_CK_ACUTE_C, KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_ACUTE_N, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

    /* .-----------------------------------------------------------------------------------------------------------------------------------.
     * |  Reset   |          |          |          |          |          |   Menu   |    MCM   |    MCL   |    MCR   |   Pause  |          |
     * |----------+----------+----------+----------+----------+---------------------+----------+----------+----------+----------+----------|
     * |          |  RGBTg   |   Bri+   |   Bri-   |          |          |    M⯇    |    M⯆    |    M⯅    |    M⯈    |    MWU   |          |
     * |----------+----------+----------+----------+----------+----------|----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |LCtrl+PgUp|LCtrl+PgDn|          |          |          |          |    MWD   |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          | DiacLock |          |          |          |                     |          |          |          |          |          |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [L_MISC] = LAYOUT_planck_mit(
        RESET, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_APPLICATION, KC_MS_BTN3, KC_MS_BTN1, KC_MS_BTN2, LALT(LSFT(KC_P)), KC_TRANSPARENT,
        KC_TRANSPARENT, RGB_TOG, RGB_VAI, RGB_VAD, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_MS_WH_UP, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_PGUP), LCTL(KC_PGDOWN), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN, KC_TRANSPARENT,
        KC_TRANSPARENT, MC_DIACRITICS_LOCK, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

    /* .-----------------------------------------------------------------------------------------------------------------------------------.
     * |          |    F1    |    F2    |    F3    |    F4    |    F5    |    F6    |    F7    |    F8    |    F9    |    F10   |          |
     * |----------+----------+----------+----------+----------+---------------------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |          |    F12   |    F11   |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------|----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |          |          |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |                     |          |          |          |          |          |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [L_FKEYS] = LAYOUT_planck_mit(
        KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F12, KC_F11, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool is_left_shift_pressed = false;
    static bool is_shift_pressed = false;

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
        case MC_T_EXTEND:
            process_layer_event(&T_EXTEND, record->event.pressed, false);
            return false;
        case MC_T_MISC:
            process_layer_event(&T_MISC, record->event.pressed, false);
            return false;
        case MC_T_PROG:
            process_layer_event(&T_PROG, record->event.pressed, false);
            return false;
        case MC_DIACRITICS_LOCK:
            if (record->event.pressed) {
                alternate_main_layer(&T_EXTEND);
            }
            update_leds_for_lang(record->event.pressed);
            clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            return false;
    }

    if (!process_compose_key(keycode, record, is_left_shift_pressed, is_shift_pressed)) {
        return false;
    }

    return true;
}

void update_leds_for_lang(bool is_active) {
    // TODO jprokop: make this configurable later; LED_LEVEL from Planck EZ doesn't work without Oryx configurator
    planck_ez_left_led_level(32);
    planck_ez_right_led_level(32);
    planck_ez_left_led_off();
    planck_ez_right_led_off();

    if (is_active) {
        switch (T_EXTEND.main_layer) {
            case L_DIAC_CZ:
                planck_ez_left_led_on();
                break;
            case L_DIAC_PL:
                planck_ez_right_led_on();
                break;
            default:
                planck_ez_left_led_on();
                planck_ez_right_led_on();
                break;
        }
    }
}

// Template for layout
/* .-----------------------------------------------------------------------------------------------------------------------------------.
 * |          |          |          |          |          |          |          |          |          |          |          |          |
 * |----------+----------+----------+----------+----------+---------------------+----------+----------+----------+----------+----------|
 * |          |          |          |          |          |          |          |          |          |          |          |          |
 * |----------+----------+----------+----------+----------+----------|----------+----------+----------+----------+----------+----------|
 * |          |          |          |          |          |          |          |          |          |          |          |          |
 * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
 * |          |          |          |          |          |                     |          |          |          |          |          |
 * `-----------------------------------------------------------------------------------------------------------------------------------'
 */

// TODO jprokop: wrap to some better form and improve colors for diacritics
void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

const uint8_t PROGMEM matrix_to_led_map[MATRIX_ROWS][MATRIX_COLS] = LAYOUT_planck_mit(
    0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c,
    0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18,
    0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24,
    0x25, 0x26, 0x27, 0x28, 0x29,    0x2a   , 0x2b, 0x2c, 0x2d, 0x2e, 0x2f
);

uint16_t get_layer_keycode(uint8_t layer) {
    switch (layer) {
        case L_FKEYS:
            return MC_T_EXTEND;
        case L_DIAC_CZ:
            return MC_T_EXTEND;
        case L_DIAC_PL:
            return MC_T_EXTEND;
        case L_MISC:
            return MC_T_MISC;
        case L_PROG:
            return MC_T_PROG;
    }

    return 0;
}

RGB layout_colors[] = {
    // L_BASE
    { .r = 58, .g = 151, .b = 182 },
    // L_PROG
    { .r = 0, .g = 255, .b = 0 },
    // L_FKEYS
    { .r = 0, .g = 255, .b = 0 },
    // L_DIAC_CZ
    { .r = 0, .g = 0, .b = 255 },
    // L_DIAC_PL
    { .r = 255, .g = 0, .b = 0 },
    // L_MISC
    { .r = 229, .g = 227, .b = 35 },
};
RGB no_color = { .r = 0, .g = 0, .b = 0 };
RGB reset_color = { .r = 255, .g = 0, .b = 0 };

RGB* get_layer_color(uint8_t layer) {
    switch (layer) {
        case L_PROG:
            return &(layout_colors[1]);
        case L_FKEYS:
            return &(layout_colors[2]);
        case L_DIAC_CZ:
            return &(layout_colors[3]);
        case L_DIAC_PL:
            return &(layout_colors[4]);
        case L_MISC:
            return &(layout_colors[5]);
        case L_BASE:
        default:
            return &(layout_colors[0]);
    }
}

void rgb_matrix_indicators_user(void) {
    uint8_t layer = biton32(layer_state);
    uint16_t layer_keycode = get_layer_keycode(layer);
    RGB* layer_color = get_layer_color(layer);

    switch (layer) {
        case L_BASE:
            for (int y = 0; y < MATRIX_ROWS; y++) {
                for (int x = 0; x < MATRIX_COLS; x++) {
                    uint16_t key = pgm_read_word(&(keymaps[layer][y][x]));
                    uint8_t led_i = pgm_read_byte(&(matrix_to_led_map[y][x]));
                    RGB* led_color = layer_color;

                    if (led_i) {
                        switch (key) {
                            case MC_T_EXTEND:
                                led_color = get_layer_color(T_EXTEND.main_layer);
                                break;
                            case MC_T_MISC:
                                led_color = get_layer_color(L_MISC);
                                break;
                            case MC_T_PROG:
                                led_color = get_layer_color(L_PROG);
                                break;
                        }
                        led_i = led_i - 1; // indexes of leds are 1-based so we can easily check it's presence
                        rgb_matrix_set_color(led_i, led_color->r, led_color->g, led_color->b);
                    }
                }
            }
            break;
        case L_DIAC_CZ:
        case L_DIAC_PL:
        case L_PROG:
        case L_MISC:
        case L_FKEYS:
            for (int y = 0; y < MATRIX_ROWS; y++) {
                for (int x = 0; x < MATRIX_COLS; x++) {
                    uint16_t base_layer_key = pgm_read_word(&(keymaps[L_BASE][y][x]));
                    uint16_t key = pgm_read_word(&(keymaps[layer][y][x]));
                    uint8_t led_i = pgm_read_byte(&(matrix_to_led_map[y][x]));
                    RGB* led_color;

                    if (led_i) {
                        if (base_layer_key == layer_keycode) {
                            continue;
                        }

                        led_i = led_i - 1; // indexes of leds are 1-based so we can easily check it's presence
                        if (key == KC_TRANSPARENT) {
                            led_color = &no_color;
                        }
                        else if (key == RESET) {
                            led_color = &reset_color;
                        } else {
                            led_color = layer_color;
                        }

                        rgb_matrix_set_color(led_i, led_color->r, led_color->g, led_color->b);
                    }
                }
            }
            break;
  }
}
