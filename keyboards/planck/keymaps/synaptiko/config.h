#pragma once

/*
 * Set any config.h overrides for your specific keymap here.
 * See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
 */

#define NO_MUSIC_MODE
#define RGB_DISABLE_WHEN_USB_SUSPENDED true
#define EECONFIG_RGB_MATRIX (uint32_t *)16
#define RGB_MATRIX_LED_FLUSH_LIMIT 100
#define RGB_DISABLE_AFTER_TIMEOUT 50 // about a minute
