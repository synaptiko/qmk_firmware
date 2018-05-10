#include "../../ergodox_ez.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,
  // macros for typing czech diacritics with compose key on linux (AltGr)
  a_ACUTE, e_ACUTE, i_ACUTE, o_ACUTE, y_ACUTE, u_ACUTE,
  e_CARON, z_CARON, c_CARON, s_CARON, r_CARON, t_CARON, d_CARON, n_CARON,
  u_RING_ABOVE,

  A_ACUTE, E_ACUTE, I_ACUTE, O_ACUTE, Y_ACUTE, U_ACUTE,
  E_CARON, Z_CARON, C_CARON, S_CARON, R_CARON, T_CARON, D_CARON, N_CARON,
  U_RING_ABOVE,

  // useful compose key combos
  X_TIMES, TRIPLE_DOT, TM
};

/* Layer switch keys legend:
 * [Tap-Toggle]
 *  If you hold the key down, the layer becomes active,
 *  and then deactivates when you let go. And if you tap it,
 *  the layer simply becomes active (toggles on).
 *
 * (One-Shot)
 *  Flips a layer on, but only for one keypress.
 *  Once you press a key in the new layer,
 *  the layer is then deactivated.
 *  You can keep the layer active by holding the key down.
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
 * \  LCtrl | Win |  ⯅  |  ⯆  | LAlt|                             |  ⯇  |  ⯈  |  [{ | ]}  |RCtrl/↵ /
 *  `-------------------------------'                             '-------------------------------'
 *                               .---------------.   .---------------.
 *                               |  [2]  |  [3]  |   |       |       |
 *                       .-------+-------+-------|   |-------+-------+-------.
 *                       |       |       |       |   |       |       |       |
 *                       | Space |  (1)  |-------|   |-------| Enter |  ⌫    |
 *                       |       |       |  (4)  |   | AltGr |       |       |
 *                       '-----------------------'   '-----------------------'
 */
[0] = KEYMAP(
    // left hand
    KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_DELETE,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_HOME,
    KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_END,
    CTL_T(KC_NO), GUI_T(KC_NO), KC_UP, KC_DOWN, KC_LALT,
    TT(2), TT(3), KC_TRANSPARENT,
    KC_SPACE, OSL(1), OSL(4),

    // right hand
    KC_BSLASH, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS,
    KC_PGUP, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQUAL,
    KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
    KC_PGDOWN, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
    KC_LEFT, KC_RIGHT, KC_LBRACKET, KC_RBRACKET, RCTL_T(KC_ENTER),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_RALT, KC_ENTER, KC_BSPACE
),

/* .----------------------------------------------. .----------------------------------------------.
 * |        |     |     |     |     |     |       | |       |     |     |     |     |     |        |
 * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
 * |        |     |     |     |     |     |       | |       |     |     |  !  |     |  +  |   =    |
 * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
 * |   <0>  |     |  [  |  {  |  (  |  <  |-------| |-------|  >  |  )  |  }  |  ]  |  &  |   |    |
 * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
 * |        |     |     |     |     |     |       | |       |     |     |     |     |  \  |        |
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
[1] = KEYMAP(
    // left hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    TO(0), KC_TRANSPARENT, KC_LBRACKET, KC_LCBR, KC_LPRN, KC_LABK,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    // right hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_EXLM, KC_TRANSPARENT, KC_PLUS, KC_EQUAL,
    KC_RABK, KC_RPRN, KC_RCBR, KC_RBRACKET, KC_AMPR, KC_PIPE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSLASH, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

/* .----------------------------------------------. .----------------------------------------------.
 * |        |  F1 |  F2 |  F3 |  F4 |  F5 |       | |       |  F6 |  F7 |  F8 |  F9 | F10 |  Mute  |
 * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
 * |        |     | MCL | M⯅  | MCR | Menu| Win+  | |       |     |     | F11 | F12 |Pause| VolUp  |
 * |--------+-----+-----+-----+-----+-----| PrntS | |       |-----+-----+-----+-----+-----+--------|
 * |   <0>  |     | M⯇  | M⯆  | M⯈  | MWU |-------| |-------|     |     |     |     |     | VolDn  |
 * |--------+-----+-----+-----+-----+-----| PrntS | |       |-----+-----+-----+-----+-----+--------|
 * |        |     | MWL | MCM | MWR | MWD |       | |       |     |     |     |     |     |        |
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
[2] = KEYMAP(
    // left hand
    KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, KC_APPLICATION, LGUI(KC_PSCREEN),
    TO(0), KC_TRANSPARENT, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_UP,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT, KC_MS_BTN3, KC_MS_WH_RIGHT, KC_MS_WH_DOWN, KC_PSCREEN,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    // right hand
    KC_TRANSPARENT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_AUDIO_MUTE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F11, KC_F12, LALT(LSFT(KC_P)), KC_AUDIO_VOL_UP,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

/* .----------------------------------------------. .----------------------------------------------.
 * |        |     |     |     |     |     |       | |       |     |     |     |     |     |        |
 * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
 * |        |     |     |     |Reset|     |       | |       |APaus| Anim|     |     |     |        |
 * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
 * |   <0>  |     |     |     |     |     |-------| |-------|LTogg| Bri+| Bri-|     |     |        |
 * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
 * |        |     |     |     |     |     |       | |       |     | Hue+| Hue-|     |     |        |
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
[3] = KEYMAP(
    // left hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET, KC_TRANSPARENT, KC_TRANSPARENT,
    TO(0), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    // right hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, RGB_SLD, RGB_MOD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    RGB_TOG, RGB_VAI, RGB_VAD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, RGB_HUI, RGB_HUD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

// Reference: https://en.wikiversity.org/wiki/Typing_Czech
/* .----------------------------------------------. .----------------------------------------------.
 * |        |     |     |  e  |     |     |       | |       |     |     |  u  |     |     |        |
 * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
 * |        |     |     |  e  |  r  |  t  |       | |       |  y  |  u  |  i  |  o  |     |        |
 * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
 * |   <0>  |  a  |  s  |  d  |     |     |-------| |-------|     |     |     |     |     |        |
 * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
 * |   (5)  |  z  |  ×  |  c  |     |     |       | |       |  n  |  ™  |     |  …  |     |  (5)   |
 * '--------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+--------'
 * \        |     |     |     |     |                             |     |     |     |     |        /
 *  `-------------------------------'                             '-------------------------------'
 *                               .---------------.   .---------------.
 *                               |       |       |   |       |       |
 *                       .-------+-------+-------|   |-------+-------+-------.
 *                       |       |       |       |   |       |       |       |
 *                       |       |       |-------|   |-------|       |       |
 *                       |       |       |  (~4) |   |       |       |       |
 *                       '-----------------------'   '-----------------------'
 */
[4] = KEYMAP(
    // left hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, e_CARON, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, e_ACUTE, r_CARON, t_CARON, KC_TRANSPARENT,
    TO(0), a_ACUTE, s_CARON, d_CARON, KC_TRANSPARENT, KC_TRANSPARENT,
    OSL(5), z_CARON, X_TIMES, c_CARON, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    // right hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, u_RING_ABOVE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, y_ACUTE, u_ACUTE, i_ACUTE, o_ACUTE, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, n_CARON, TM, KC_TRANSPARENT, TRIPLE_DOT, KC_TRANSPARENT, OSL(5),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

/* .----------------------------------------------. .----------------------------------------------.
 * |        |     |     |  E  |     |     |       | |       |     |     |  U  |     |     |        |
 * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
 * |        |     |     |  E  |  R  |  T  |       | |       |  Y  |  U  |  I  |  O  |     |        |
 * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
 * |   <0>  |  A  |  S  |  D  |     |     |-------| |-------|     |     |     |     |     |        |
 * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
 * |   (~5) |  Z  |     |  C  |     |     |       | |       |  N  |     |     |     |     |  (~5)  |
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
[5] = KEYMAP(
    // left hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, E_CARON, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, E_ACUTE, R_CARON, T_CARON, KC_TRANSPARENT,
    TO(0), A_ACUTE, S_CARON, D_CARON, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, Z_CARON, KC_TRANSPARENT, C_CARON, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    // right hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, U_RING_ABOVE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, Y_ACUTE, U_ACUTE, I_ACUTE, O_ACUTE, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, N_CARON, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case RGB_SLD:
        rgblight_mode(1);
        return false;
    }

    // diacritics macros
    switch (keycode) {
      case a_ACUTE:
        SEND_STRING(SS_RALT("'a"));
        layer_off(4);
        return false;
      case e_ACUTE:
        SEND_STRING(SS_RALT("'e"));
        layer_off(4);
        return false;
      case i_ACUTE:
        SEND_STRING(SS_RALT("'i"));
        layer_off(4);
        return false;
      case o_ACUTE:
        SEND_STRING(SS_RALT("'o"));
        layer_off(4);
        return false;
      case y_ACUTE:
        SEND_STRING(SS_RALT("'y"));
        layer_off(4);
        return false;
      case u_ACUTE:
        SEND_STRING(SS_RALT("'u"));
        layer_off(4);
        return false;
      case e_CARON:
        SEND_STRING(SS_RALT("<e"));
        layer_off(4);
        return false;
      case z_CARON:
        SEND_STRING(SS_RALT("<z"));
        layer_off(4);
        return false;
      case c_CARON:
        SEND_STRING(SS_RALT("<c"));
        layer_off(4);
        return false;
      case s_CARON:
        SEND_STRING(SS_RALT("<s"));
        layer_off(4);
        return false;
      case r_CARON:
        SEND_STRING(SS_RALT("<r"));
        layer_off(4);
        return false;
      case t_CARON:
        SEND_STRING(SS_RALT("<t"));
        layer_off(4);
        return false;
      case d_CARON:
        SEND_STRING(SS_RALT("<d"));
        layer_off(4);
        return false;
      case n_CARON:
        SEND_STRING(SS_RALT("<n"));
        layer_off(4);
        return false;
      case u_RING_ABOVE:
        SEND_STRING(SS_RALT("*u"));
        layer_off(4);
        return false;

      case A_ACUTE:
        SEND_STRING(SS_RALT("'A"));
        layer_off(5);
        return false;
      case E_ACUTE:
        SEND_STRING(SS_RALT("'E"));
        layer_off(5);
        return false;
      case I_ACUTE:
        SEND_STRING(SS_RALT("'I"));
        layer_off(5);
        return false;
      case O_ACUTE:
        SEND_STRING(SS_RALT("'O"));
        layer_off(5);
        return false;
      case Y_ACUTE:
        SEND_STRING(SS_RALT("'Y"));
        layer_off(5);
        return false;
      case U_ACUTE:
        SEND_STRING(SS_RALT("'U"));
        layer_off(5);
        return false;
      case E_CARON:
        SEND_STRING(SS_RALT("<E"));
        layer_off(5);
        return false;
      case Z_CARON:
        SEND_STRING(SS_RALT("<Z"));
        layer_off(5);
        return false;
      case C_CARON:
        SEND_STRING(SS_RALT("<C"));
        layer_off(5);
        return false;
      case S_CARON:
        SEND_STRING(SS_RALT("<S"));
        layer_off(5);
        return false;
      case R_CARON:
        SEND_STRING(SS_RALT("<R"));
        layer_off(5);
        return false;
      case T_CARON:
        SEND_STRING(SS_RALT("<T"));
        layer_off(5);
        return false;
      case D_CARON:
        SEND_STRING(SS_RALT("<D"));
        layer_off(5);
        return false;
      case N_CARON:
        SEND_STRING(SS_RALT("<N"));
        layer_off(5);
        return false;
      case U_RING_ABOVE:
        SEND_STRING(SS_RALT("*U"));
        layer_off(5);
        return false;
    }

    // useful compose key combos
    switch (keycode) {
      case X_TIMES:
        SEND_STRING(SS_RALT("xx"));
        layer_off(4);
        return false;
      case TRIPLE_DOT:
        SEND_STRING(SS_RALT(".."));
        layer_off(4);
        return false;
      case TM:
        SEND_STRING(SS_RALT("tm"));
        layer_off(4);
        return false;
    }
  }

  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
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
