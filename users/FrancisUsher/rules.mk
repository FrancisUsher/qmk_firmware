SRC += FrancisUsher.c 

LINK_TIME_OPTIMIZATION_ENABLE = yes
SPACE_CADET_ENABLE            = no

ifeq ($(strip $(MAKE_BOOTLOADER)), yes)
    OPT_DEFS += -DMAKE_BOOTLOADER
endif
