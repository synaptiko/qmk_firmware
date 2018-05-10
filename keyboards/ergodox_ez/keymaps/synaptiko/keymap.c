#include "../../ergodox_ez.h"

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  RGB_SLD,

  // TODO jprokop: rename; add some prefix?

  DIACRITICS_LOCK,
  DIACRITICS_SHIFT,

  OSL_1_OR_2, // if it 1 or 2 layer is based on DIACRITICS_LOCK
  TO_BASE_LAYER, // cancel one-shot & go to base layer

  // macros for typing czech diacritics with compose key on linux (AltGr)
  A_ACUTE, E_ACUTE, I_ACUTE, O_ACUTE, Y_ACUTE, U_ACUTE,
  E_CARON, Z_CARON, C_CARON, S_CARON, R_CARON, T_CARON, D_CARON, N_CARON,
  U_RING_ABOVE,

  // useful compose key combos
  X_TIMES, TRIPLE_DOT, TM,

  // other macros
  TURBO_DELETE,
  // TODO jprokop: implement
  /* SELECTION_PASTE, MUSIC_PAUSE, MUSIC_VOLUME, CALL_VOLUME, KEYBOARD_CHEATSHEET */
};

enum layers {
  L_BASE, // base
  L_PROG, // programming
  L_DIAC, // czech diacritics
  L_MISC  // miscellaneous functions
};

// TODO jprokop: implement One-Shot-Double-Tap-Toggle (Tap for One-Shot key or Toggle; fast Double-Tap to turn the layer on)
//               => can be used for all 1st, 2nd and 3rd layer
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
 *                               |DIACR_L|       |   |       |       |
 *                       .-------+-------+-------|   |-------+-------+-------.
 *                       |       |       |       |   |       |       |       |
 *                       | Space | (1/2) |-------|   |-------| Enter |  ⌫    |
 *                       |       |       |  [4]  |   | AltGr |       |       |
 *                       '-----------------------'   '-----------------------'
 */
[L_BASE] = KEYMAP(
    // left hand
    KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_DELETE,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_HOME,
    KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_END,
    CTL_T(KC_NO), GUI_T(KC_NO), KC_UP, KC_DOWN, KC_LALT,
    DIACRITICS_LOCK, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_SPACE, OSL_1_OR_2, TT(L_MISC),

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
 * |        |  F1 |  F2 |  F3 |  F4 |  F5 |TurbDel| |       |  F6 |  F7 |  F8 |  F9 | F10 |        |
 * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
 * |        |     |     |     |     |     |       | |       | F11 | F12 |  !  |     |  +  |   =    |
 * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
 * |   <0>  |     |  [  |  {  |  (  |  <  |-------| |-------|  >  |  )  |  }  |  ]  |  &  |   |    |
 * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
 * |        |     |  ×  |     |     |     |       | |       |     |  ™  |     |  …  |  \  |        |
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
[L_PROG] = KEYMAP(
    // left hand
    KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, TURBO_DELETE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    TO_BASE_LAYER, KC_TRANSPARENT, KC_LBRACKET, KC_LCBR, KC_LPRN, KC_LABK,
    KC_TRANSPARENT, KC_TRANSPARENT, X_TIMES, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    // right hand
    KC_TRANSPARENT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F11, KC_F12, KC_EXLM, KC_TRANSPARENT, KC_PLUS, KC_EQUAL,
    KC_RABK, KC_RPRN, KC_RCBR, KC_RBRACKET, KC_AMPR, KC_PIPE,
    KC_TRANSPARENT, KC_TRANSPARENT, TM, KC_TRANSPARENT, TRIPLE_DOT, KC_BSLASH, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

// Reference: https://en.wikiversity.org/wiki/Typing_Czech
/* .----------------------------------------------. .----------------------------------------------.
 * |        |     |     |  ěĚ |     |     |TurbDel| |       |     |     |  ůŮ |     |     |        |
 * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
 * |        |     |     |  éÉ |  řŘ |  ťŤ |       | |       |  ýÝ |  úÚ |  íÍ |  óÓ |     |        |
 * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
 * |   <0>  |  áÁ |  šŠ |  ďĎ |     |     |-------| |-------|     |     |     |     |     |        |
 * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
 * |DIACR_SH|  žŽ |  ×  |  čČ |     |     |       | |       |  ňŇ |  ™  |     |  …  |     |DIACR_SH|
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
[L_DIAC] = KEYMAP(
    // left hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, E_CARON, KC_TRANSPARENT, KC_TRANSPARENT, TURBO_DELETE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, E_ACUTE, R_CARON, T_CARON, KC_TRANSPARENT,
    TO_BASE_LAYER, A_ACUTE, S_CARON, D_CARON, KC_TRANSPARENT, KC_TRANSPARENT,
    DIACRITICS_SHIFT, Z_CARON, X_TIMES, C_CARON, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    // right hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, U_RING_ABOVE, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, Y_ACUTE, U_ACUTE, I_ACUTE, O_ACUTE, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, N_CARON, TM, KC_TRANSPARENT, TRIPLE_DOT, KC_TRANSPARENT, DIACRITICS_SHIFT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

/* .----------------------------------------------. .----------------------------------------------.
 * |  Reset |  F1 |  F2 |  F3 |  F4 |  F5 |TurbDel| |       |  F6 |  F7 |  F8 |  F9 | F10 |  Mute  |
 * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
 * |        |     | MCL | M⯅  | MCR | Menu| Win+  | |       | F11 | F12 |     |     |Pause| VolUp  |
 * |--------+-----+-----+-----+-----+-----| PrntS | |       |-----+-----+-----+-----+-----+--------|
 * |   <0>  |     | M⯇  | M⯆  | M⯈  | MWU |-------| |-------|     |     |     |     |     | VolDn  |
 * |--------+-----+-----+-----+-----+-----| PrntS | |       |-----+-----+-----+-----+-----+--------|
 * |        |     | MWL | MCM | MWR | MWD |       | |       |     |     |     |     |     |        |
 * '--------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+--------'
 * \StopAnim| Anim| Bri+| Bri-|Toggl|                             |Hue⯇ |Hue⯈ |     |     |        /
 *  `-------------------------------'                             '-------------------------------'
 *                               .---------------.   .---------------.
 *                               |       |       |   |       |       |
 *                       .-------+-------+-------|   |-------+-------+-------.
 *                       |       |       |       |   |       |       |       |
 *                       |       |       |-------|   |-------|       |       |
 *                       |       |       |       |   |       |       |       |
 *                       '-----------------------'   '-----------------------'
 */
[L_MISC] = KEYMAP(
    // left hand
    RESET, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, TURBO_DELETE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, KC_APPLICATION, LGUI(KC_PSCREEN),
    TO_BASE_LAYER, KC_TRANSPARENT, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_UP,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT, KC_MS_BTN3, KC_MS_WH_RIGHT, KC_MS_WH_DOWN, KC_PSCREEN,
    RGB_SLD, RGB_MOD, RGB_VAI, RGB_VAD, RGB_TOG,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    // right hand
    KC_TRANSPARENT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_AUDIO_MUTE,
    KC_TRANSPARENT, KC_F11, KC_F12, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LSFT(KC_P)), KC_AUDIO_VOL_UP,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    RGB_HUI, RGB_HUD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
),

};

const uint16_t PROGMEM fn_actions[] = {
  /* TODO jprokop: figure why is it here */
  /* [1] = ACTION_LAYER_TAP_TOGGLE(1) */
};

void matrix_init_user(void) {};

bool isDiacriticsActive = false;
bool isDiacriticsShiftPressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DIACRITICS_LOCK:
      if (record->event.pressed) {
        isDiacriticsActive = !isDiacriticsActive;

        if (IS_LAYER_ON(isDiacriticsActive ? L_PROG : L_DIAC)) {
          layer_off(isDiacriticsActive ? L_PROG : L_DIAC);
          set_oneshot_layer(isDiacriticsActive ? L_DIAC : L_PROG, get_oneshot_layer_state());
        }
      }
      return false;
    case DIACRITICS_SHIFT:
      isDiacriticsShiftPressed = record->event.pressed;
      return false;
    case OSL_1_OR_2:
      if (record->event.pressed) {
        if (IS_LAYER_ON(isDiacriticsActive ? L_DIAC : L_PROG)) {
          reset_oneshot_layer();
          layer_move(L_BASE);
        }
        else {
          set_oneshot_layer(isDiacriticsActive ? L_DIAC : L_PROG, ONESHOT_START);
        }
      }
      else {
        if (IS_LAYER_ON(isDiacriticsActive ? L_DIAC : L_PROG)) {
          clear_oneshot_layer_state(ONESHOT_PRESSED);
        }
      }
      return false;
  }

  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      case TO_BASE_LAYER:
        reset_oneshot_layer();
        layer_move(L_BASE);
        return false;
    }

    // diacritics macros
    switch (keycode) {
      case A_ACUTE:
        if (isDiacriticsShiftPressed) {
          SEND_STRING(SS_RALT("'A"));
        }
        else {
          SEND_STRING(SS_RALT("'a"));
        }
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      case E_ACUTE:
        if (isDiacriticsShiftPressed) {
          SEND_STRING(SS_RALT("'E"));
        }
        else {
          SEND_STRING(SS_RALT("'e"));
        }
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      case I_ACUTE:
        if (isDiacriticsShiftPressed) {
          SEND_STRING(SS_RALT("'I"));
        }
        else {
          SEND_STRING(SS_RALT("'i"));
        }
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      case O_ACUTE:
        if (isDiacriticsShiftPressed) {
          SEND_STRING(SS_RALT("'O"));
        }
        else {
          SEND_STRING(SS_RALT("'o"));
        }
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      case Y_ACUTE:
        if (isDiacriticsShiftPressed) {
          SEND_STRING(SS_RALT("'Y"));
        }
        else {
          SEND_STRING(SS_RALT("'y"));
        }
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      case U_ACUTE:
        if (isDiacriticsShiftPressed) {
          SEND_STRING(SS_RALT("'U"));
        }
        else {
          SEND_STRING(SS_RALT("'u"));
        }
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      case E_CARON:
        if (isDiacriticsShiftPressed) {
          SEND_STRING(SS_RALT("<E"));
        }
        else {
          SEND_STRING(SS_RALT("<e"));
        }
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      case Z_CARON:
        if (isDiacriticsShiftPressed) {
          SEND_STRING(SS_RALT("<Z"));
        }
        else {
          SEND_STRING(SS_RALT("<z"));
        }
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      case C_CARON:
        if (isDiacriticsShiftPressed) {
          SEND_STRING(SS_RALT("<C"));
        }
        else {
          SEND_STRING(SS_RALT("<c"));
        }
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      case S_CARON:
        if (isDiacriticsShiftPressed) {
          SEND_STRING(SS_RALT("<S"));
        }
        else {
          SEND_STRING(SS_RALT("<s"));
        }
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      case R_CARON:
        if (isDiacriticsShiftPressed) {
          SEND_STRING(SS_RALT("<R"));
        }
        else {
          SEND_STRING(SS_RALT("<r"));
        }
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      case T_CARON:
        if (isDiacriticsShiftPressed) {
          SEND_STRING(SS_RALT("<T"));
        }
        else {
          SEND_STRING(SS_RALT("<t"));
        }
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      case D_CARON:
        if (isDiacriticsShiftPressed) {
          SEND_STRING(SS_RALT("<D"));
        }
        else {
          SEND_STRING(SS_RALT("<d"));
        }
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      case N_CARON:
        if (isDiacriticsShiftPressed) {
          SEND_STRING(SS_RALT("<N"));
        }
        else {
          SEND_STRING(SS_RALT("<n"));
        }
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      case U_RING_ABOVE:
        if (isDiacriticsShiftPressed) {
          SEND_STRING(SS_RALT("*U"));
        }
        else {
          SEND_STRING(SS_RALT("*u"));
        }
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;

      // other useful compose key combos
      case X_TIMES:
        SEND_STRING(SS_RALT("xx"));
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      case TRIPLE_DOT:
        SEND_STRING(SS_RALT(".."));
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      case TM:
        SEND_STRING(SS_RALT("tm"));
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;

      // other macros
      case TURBO_DELETE:
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_BSPACE)))SS_LCTRL(SS_LSFT(SS_TAP(X_DELETE))));
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
    }
  }

  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  // TODO jprokop: implement colors later
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
