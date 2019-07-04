SRC += synaptiko.c

# Following is needed so sprintf can be used properly
TMK_COMMON_SRC += $(CHIBIOS)/os/various/syscalls.c
