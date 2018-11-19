#include "../../ergodox_ez.h"

enum custom_keycodes {
  MC_RGB_SLD = SAFE_RANGE,

  // layer macros
  MC_TO_BASE_LAYER, // cancel one-shot & go to base layer
  MC_TO_PROG_LAYER, // go to programming layer directly
  MC_TO_PROG_OR_DIAC_LAYER, // if it's 1 or 2 layer is based on MC_DIACRITICS_LOCK
  MC_TO_MISC_LAYER, // go to misc layer

  // diacritics switching macros
  MC_DIACRITICS_LOCK,
  MC_DIACRITICS_SHIFT,

  // macros for typing czech diacritics with compose key on linux (AltGr)
  MC_CK_ACUTE_A, MC_CK_ACUTE_E, MC_CK_ACUTE_I, MC_CK_ACUTE_O, MC_CK_ACUTE_Y, MC_CK_ACUTE_U,
  MC_CK_CARON_E, MC_CK_CARON_Z, MC_CK_CARON_C, MC_CK_CARON_S, MC_CK_CARON_R, MC_CK_CARON_T, MC_CK_CARON_D, MC_CK_CARON_N,
  MC_CK_RING_ABOVE_U,

  // useful compose key combos
  MC_CK_X_TIMES, MC_CK_TRIPLE_DOT, MC_CK_TM,

  // other macros
  // TODO jprokop: improve those macros
  MC_TURBO_DELETE, MC_SELECTION_PASTE, MC_KEYBOARD_CHEATSHEET,
  // TODO jprokop: add macros for time tracking
};

enum layers {
  L_BASE, // base
  L_PROG, // programming
  L_DIAC, // czech diacritics
  L_MISC  // miscellaneous functions
};

enum DIACRITIC_CHARS {
  CK_ACUTE = '\'',
  CK_CARON = '<',
  CK_RING_ABOVE = '*'
};

/* Layer switch keys legend:
 * (One-Shot-Double-Tap-Toggle)
 *  For details see comment for process_layer_event function
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
   * \  LCtrl | Win |  ⯅  |  ⯆  | LAlt|                             |  ⯇  |  ⯈  |  [{ | ]}  |  (1)   /
   *  `-------------------------------'                             '-------------------------------'
   *                               .---------------.   .---------------.
   *                               |DIACR_L|       |   |       |       |
   *                       .-------+-------+-------|   |-------+-------+-------.
   *                       |       |       |       |   |       |       |       |
   *                       | Space | (1/2) |-------|   |-------| Enter |  ⌫    |
   *                       |       |       |  (4)  |   | AltGr |       |       |
   *                       '-----------------------'   '-----------------------'
   */
  [L_BASE] = LAYOUT_ergodox(
    // left hand
    KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_DELETE,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_HOME,
    KC_ESCAPE, KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_END,
    CTL_T(KC_NO), GUI_T(KC_NO), KC_UP, KC_DOWN, KC_LALT,
    MC_DIACRITICS_LOCK, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_SPACE, MC_TO_PROG_OR_DIAC_LAYER, MC_TO_MISC_LAYER,

    // right hand
    KC_BSLASH, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS,
    KC_PGUP, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQUAL,
    KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
    KC_PGDOWN, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
    KC_LEFT, KC_RIGHT, KC_LBRACKET, KC_RBRACKET, MC_TO_PROG_LAYER,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_RALT, KC_ENTER, KC_BSPACE
  ),

  /* .----------------------------------------------. .----------------------------------------------.
   * |        |  F1 |  F2 |  F3 |  F4 |  F5 |TurbDel| |       |  F6 |  F7 |  F8 |  F9 | F10 |        |
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
    KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, MC_TURBO_DELETE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    MC_TO_BASE_LAYER, KC_TRANSPARENT, KC_LBRACKET, KC_LPRN, KC_LCBR, KC_LABK,
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
   * |        |     |     |  ěĚ |     |     |TurbDel| |       |     |     |  ůŮ |     |     |        |
   * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
   * |        |     |     |  éÉ |  řŘ |  ťŤ |       | |       |  ýÝ |  úÚ |  íÍ |  óÓ |     |        |
   * |--------+-----+-----+-----+-----+-----|       | |       |-----+-----+-----+-----+-----+--------|
   * |   <0>  |  áÁ |  šŠ |  ďĎ |     |     |-------| |-------|     |     |     |     |     |        |
   * |--------+-----+-----+-----+-----+-----| Enter | |       |-----+-----+-----+-----+-----+--------|
   * |DiacShft|  žŽ |     |  čČ |     |     |       | |       |  ňŇ |     |     |     |     |DiacShft|
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
  [L_DIAC] = LAYOUT_ergodox(
    // left hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_CARON_E, KC_TRANSPARENT, KC_TRANSPARENT, MC_TURBO_DELETE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_ACUTE_E, MC_CK_CARON_R, MC_CK_CARON_T, KC_TRANSPARENT,
    MC_TO_BASE_LAYER, MC_CK_ACUTE_A, MC_CK_CARON_S, MC_CK_CARON_D, KC_TRANSPARENT, KC_TRANSPARENT,
    MC_DIACRITICS_SHIFT, MC_CK_CARON_Z, KC_TRANSPARENT, MC_CK_CARON_C, KC_TRANSPARENT, KC_TRANSPARENT, KC_ENTER,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    // right hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MC_CK_RING_ABOVE_U, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, MC_CK_ACUTE_Y, MC_CK_ACUTE_U, MC_CK_ACUTE_I, MC_CK_ACUTE_O, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, MC_CK_CARON_N, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MC_DIACRITICS_SHIFT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  /* .----------------------------------------------. .----------------------------------------------.
   * |  Reset |     |     |     |     |     |TurbDel| |       |     |     |     |     |     |        |
   * |--------+-----+-----+-----+-----+-------------| |-------+-----+-----+-----+-----+-----+--------|
   * |        |     |     |     |     |     | Win+  | |       |     |     |     |     |Pause|        |
   * |--------+-----+-----+-----+-----+-----| PrntS | |       |-----+-----+-----+-----+-----+--------|
   * |   <0>  |Hue⯇ |Hue⯈ |     |     |     |-------| |-------| M⯇  | M⯆  | M⯅  | M⯈  | MWU |  VolUp |
   * |--------+-----+-----+-----+-----+-----| PrntS | |       |-----+-----+-----+-----+-----+--------|
   * | Toggle | Bri+| Bri-|     |     |     |       | |       |KbChs|     |     |     | MWD |  VolDn |
   * '--------+-----+-----+-----+-----+-------------' '-------------+-----+-----+-----+-----+--------'
   * \StopAnim| Anim|     |     |     |                             |     |     |     |     |  Mute  /
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
    RESET, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MC_TURBO_DELETE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LGUI(KC_PSCREEN),
    MC_TO_BASE_LAYER, RGB_HUI, RGB_HUD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    RGB_TOG, RGB_VAI, RGB_VAD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PSCREEN,
    MC_RGB_SLD, RGB_MOD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    // right hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LSFT(KC_P)), KC_TRANSPARENT,
    KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_MS_WH_UP, KC_AUDIO_VOL_UP,
    KC_TRANSPARENT, MC_KEYBOARD_CHEATSHEET, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN, KC_AUDIO_VOL_DOWN,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_MUTE,
    KC_APPLICATION, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_MS_BTN3, KC_MS_BTN2, KC_MS_BTN1
  )
};

/* My implementation of "One-Shot-Double-Tap-Toggle":
 * - Tap for One-Shot key or Toggle
 * - Fast Double-Tap to turn the layer on "permanently"
 *
 * Here's how One-Shot key works on it's own:
 * - Flips a layer on, but only for one keypress.
 * - Once you press a key in the new layer, the layer is then deactivated.
 * - You can keep the layer active by holding the key down.
 */
uint16_t oneshot_layer_switch_time;
void process_layer_event(uint8_t layer, bool pressed, bool swap) {
	bool released = !pressed;

  // switch back to base layer
  if (layer == L_BASE) {
    if (pressed) {
      reset_oneshot_layer();
      layer_clear();
    }
  }
  // swap diacritics and programming layer (and preserve their oneshot state)
  else if (swap) {
    if ((IS_LAYER_ON(L_DIAC) && layer == L_PROG)
        || (IS_LAYER_ON(L_PROG) && layer == L_DIAC)
    ) {
      layer_clear();
      set_oneshot_layer(layer, get_oneshot_layer_state());
    }
  }
  // handle oneshot state, move to the layer permanently or switch back to base layer
  else if (IS_LAYER_ON(layer)) {
    // layer is in oneshot mode
    if (get_oneshot_layer() == layer) {
      // and was just release, handle oneshot state properly
			if (released) {
				clear_oneshot_layer_state(ONESHOT_PRESSED);
			}
      // it was pressed again; we need to decide what to do based on timing
			else if (pressed) {
				reset_oneshot_layer();

        // if it was pressed quickly again => move to the layer permanently
        if (timer_elapsed(oneshot_layer_switch_time) < 250) {
          layer_move(layer);
        }
        // or switch back to base layer (works as toggle)
        else {
          layer_clear();
        }
			}
    }
    // layer is in permanent mode and was pressed again => switch back to base layer (works as toggle)
    else if (pressed) {
      layer_clear();
    }
  }
  // layer is off, switch it on as oneshot layer for now
  else if (pressed) {
    reset_oneshot_layer();
    layer_clear();
    oneshot_layer_switch_time = timer_read();
    set_oneshot_layer(layer, ONESHOT_START);
  }
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

const uint16_t PROGMEM fn_actions[] = {};

void matrix_init_user(void) {};

bool is_diacritics_active = false;
bool is_diacritics_shift_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MC_DIACRITICS_LOCK:
      if (record->event.pressed) {
        is_diacritics_active = !is_diacritics_active;

        process_layer_event(is_diacritics_active ? L_DIAC : L_PROG, record->event.pressed, true);

        if (is_diacritics_active
            && (layer_state == 0 || IS_LAYER_ON(L_DIAC) || IS_LAYER_ON(L_PROG))
        ) {
          ergodox_right_led_3_on();
        }
        else {
          ergodox_right_led_3_off();
        }
      }
      return false;
    case MC_DIACRITICS_SHIFT:
      is_diacritics_shift_pressed = record->event.pressed;
      return false;
    case MC_TO_PROG_LAYER:
      process_layer_event(L_PROG, record->event.pressed, false);
      return false;
    case MC_TO_PROG_OR_DIAC_LAYER:
      process_layer_event(is_diacritics_active ? L_DIAC : L_PROG, record->event.pressed, false);
      return false;
    case MC_TO_MISC_LAYER:
      process_layer_event(L_MISC, record->event.pressed, false);
      return false;
    case MC_TO_BASE_LAYER:
      process_layer_event(L_BASE, record->event.pressed, false);
      return false;
    case KC_AUDIO_MUTE:
      // for some freaking reason this particular key doesn't clear oneshot layer state properly
      // => do it manually; on our own
      if (record->event.pressed) {
        register_code(KC_AUDIO_MUTE);
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      }
      else {
        return true;
      }
  }

  if (record->event.pressed) {
    switch (keycode) {
      case MC_RGB_SLD:
        rgblight_mode(1);
        return false;
    }

    // diacritics macros
    switch (keycode) {
      case MC_CK_ACUTE_A:
        type_compose_key_combo(CK_ACUTE, shift_letter('A', is_diacritics_shift_pressed));
        return false;
      case MC_CK_ACUTE_E:
        type_compose_key_combo(CK_ACUTE, shift_letter('E', is_diacritics_shift_pressed));
        return false;
      case MC_CK_ACUTE_I:
        type_compose_key_combo(CK_ACUTE, shift_letter('I', is_diacritics_shift_pressed));
        return false;
      case MC_CK_ACUTE_O:
        type_compose_key_combo(CK_ACUTE, shift_letter('O', is_diacritics_shift_pressed));
        return false;
      case MC_CK_ACUTE_Y:
        type_compose_key_combo(CK_ACUTE, shift_letter('Y', is_diacritics_shift_pressed));
        return false;
      case MC_CK_ACUTE_U:
        type_compose_key_combo(CK_ACUTE, shift_letter('U', is_diacritics_shift_pressed));
        return false;
      case MC_CK_CARON_E:
        type_compose_key_combo(CK_CARON, shift_letter('E', is_diacritics_shift_pressed));
        return false;
      case MC_CK_CARON_Z:
        type_compose_key_combo(CK_CARON, shift_letter('Z', is_diacritics_shift_pressed));
        return false;
      case MC_CK_CARON_C:
        type_compose_key_combo(CK_CARON, shift_letter('C', is_diacritics_shift_pressed));
        return false;
      case MC_CK_CARON_S:
        type_compose_key_combo(CK_CARON, shift_letter('S', is_diacritics_shift_pressed));
        return false;
      case MC_CK_CARON_R:
        type_compose_key_combo(CK_CARON, shift_letter('R', is_diacritics_shift_pressed));
        return false;
      case MC_CK_CARON_T:
        type_compose_key_combo(CK_CARON, shift_letter('T', is_diacritics_shift_pressed));
        return false;
      case MC_CK_CARON_D:
        type_compose_key_combo(CK_CARON, shift_letter('D', is_diacritics_shift_pressed));
        return false;
      case MC_CK_CARON_N:
        type_compose_key_combo(CK_CARON, shift_letter('N', is_diacritics_shift_pressed));
        return false;
      case MC_CK_RING_ABOVE_U:
        type_compose_key_combo(CK_RING_ABOVE, shift_letter('U', is_diacritics_shift_pressed));
        return false;

      // other useful compose key combos
      case MC_CK_X_TIMES:
        type_compose_key_combo('x', 'x');
        return false;
      case MC_CK_TRIPLE_DOT:
        type_compose_key_combo('.', '.');
        return false;
      case MC_CK_TM:
        type_compose_key_combo('t', 'm');
        return false;

      // other macros
      case MC_TURBO_DELETE:
        SEND_STRING(SS_LCTRL(SS_LSFT(SS_TAP(X_BSPACE)))SS_LCTRL(SS_LSFT(SS_TAP(X_DELETE))));
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
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

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  switch (layer) {
    case L_BASE:
    case L_PROG:
    case L_DIAC:
      if (is_diacritics_active) {
        ergodox_right_led_3_on();
      }
      break;
  }

  switch (layer) {
    case L_PROG:
    case L_DIAC:
      ergodox_right_led_1_on();
      break;
    case L_MISC:
      ergodox_right_led_2_on();
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
