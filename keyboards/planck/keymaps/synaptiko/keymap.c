#include QMK_KEYBOARD_H
#include "eeprom.h"

enum planck_keycodes {
    RGB_SLD = SAFE_RANGE,
    TOGGLE_LAYER_COLOR,
    EPRM,
};

enum planck_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* .-----------------------------------------------------------------------------------------------------------------------------------.
     * |    Tab   |    qQ    |    wW    |    eE    |    rR    |    tT    |    yY    |    uU    |    iI    |    oO    |    pP    |  ⌫       |
     * |----------+----------+----------+----------+----------+---------------------+----------+----------+----------+----------+----------|
     * |    Esc   |    aA    |    sS    |    dD    |    fF    |    gG    |    hH    |    jJ    |    kK    |    lL    |    ;:    |  Enter   |
     * |----------+----------+----------+----------+----------+----------|----------+----------+----------+----------+----------+----------|
     * |  LShift  |    zZ    |    xX    |    cC    |    vV    |    bB    |    nN    |    mM    |    ,<    |    .>    |    /?    |  RShift  |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |  LCtrl   |          |    ⯅     |    ⯆     |   LAlt   |        Space        |   Raise  |   Lower  |    ⯇     |    ⯈     |    '"    |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [_BASE] = LAYOUT_planck_grid(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPACE,
        KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_ENTER,
        KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
        KC_LCTRL, KC_TRANSPARENT, KC_UP, KC_DOWN, KC_LALT, KC_SPACE, KC_NO, RAISE, LOWER, KC_LEFT, KC_RIGHT, KC_QUOTE
    ),

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
    [_LOWER] = LAYOUT_planck_grid(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    ),

    /* .-----------------------------------------------------------------------------------------------------------------------------------.
     * |          |          |          |          |          |          |          |          |          |          |          |  Delete  |
     * |----------+----------+----------+----------+----------+---------------------+----------+----------+----------+----------+----------|
     * |          |    1!    |    2@    |    3#    |    4$    |    5%    |    6^    |    7&    |    8*    |    9(    |    0)    |          |
     * |----------+----------+----------+----------+----------+----------|----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |          |          |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |   PgUp   |   PgDn   |          |                     |          |          |   Home   |   End    |          |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE,
        KC_TRANSPARENT, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_PGUP, KC_PGDOWN, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME, KC_END, KC_TRANSPARENT
    ),

    /* .-----------------------------------------------------------------------------------------------------------------------------------.
     * |          |          |          |          |          |          |          |          |          |          |          |          |
     * |----------+----------+----------+----------+----------+---------------------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |          |          |  RGBTg   |   Bri+   |   Bri-   |          |  Reset   |
     * |----------+----------+----------+----------+----------+----------|----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |          |          |  RGBMod  |   Hue+   |   Hue-   |          |          |
     * |----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------|
     * |          |          |          |          |          |                     |          |          |          |          |          |
     * `-----------------------------------------------------------------------------------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT_planck_grid(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_TOG, RGB_VAI, RGB_VAD, KC_TRANSPARENT, RESET,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_MOD, RGB_HUI, RGB_HUD, KC_TRANSPARENT, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return false;
        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}

uint32_t layer_state_set_user(uint32_t state) {
    palClearPad(GPIOB, 8);
    palClearPad(GPIOB, 9);
    uint8_t layer = biton32(state);
    switch (layer) {
        case _LOWER:
            palSetPad(GPIOB, 9);
            break;
        case _RAISE:
            palSetPad(GPIOB, 8);
            break;
        case _ADJUST:
            palSetPad(GPIOB, 9);
            palSetPad(GPIOB, 8);
            break;
        default:
            break;
    }
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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
