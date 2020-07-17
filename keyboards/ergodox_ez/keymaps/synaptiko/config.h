#pragma once

/*
 * Set any config.h overrides for your specific keymap here.
 * See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
 */

#define RGBLIGHT_SLEEP

#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

// FIXME jprokop: following settings doesn't seem to have any effect, investigate later
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 5000

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 5000

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 1

#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 0
