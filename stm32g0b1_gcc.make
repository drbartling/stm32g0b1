STM32G0B1_PATH := $(abspath $(lastword  $(MAKEFILE_LIST)))
STM32G0B1_DIR := $(dir $(STM32G0B1_PATH))

VPATH += $(STM32G0B1_DIR)src
INCLUDE_DIRS += -I $(STM32G0B1_DIR)src

SRCS +=           \
	stm32g0b1.c   \
	stm_adc.c     \
	stm_flash.c   \
	stm_reset.c   \
	uart.c        \
	stm_vrefbuf.c \


# Build toolchain #############################################################
PREFIX = arm-none-eabi-
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S

# All system calls error out except for those available in newlib-nano
HOSTING    := --specs=nosys.specs --specs=nano.specs

# STM32G0B1 Uses T32 (thumb) instruction set, m0plus core, and no FPU
ARCH_FLAGS := -mthumb -mcpu=cortex-m0plus -mfloat-abi=soft

# Programming toolchain #######################################################
OPENOCD_FLAGS = -f interface/stlink.cfg -f target/stm32g0x.cfg
