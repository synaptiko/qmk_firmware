# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LINK_TIME_OPTIMIZATION_ENABLE = yes
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
NKRO_ENABLE = yes
QMK_KEYS_PER_SCAN = yes

AUDIO_ENABLE = no
RGBLIGHT_ANIMATION = no
RGBLIGHT_ENABLE = no
UNICODE_ENABLE = no
API_SYSEX_ENABLE = no
AUTOLOG_ENABLE = no
BOOTMAGIC_ENABLE = no
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
DEBUG_ENABLE = no
FORCE_NKRO = no
KEY_LOCK_ENABLE = no
KEYLOGGER_ENABLE = no
SLEEP_LED_ENABLE = no
SWAP_HANDS_ENABLE = no
TAP_DANCE_ENABLE = no

# Following is needed so sprintf can be used properly
TMK_COMMON_SRC += $(CHIBIOS)/os/various/syscalls.c
