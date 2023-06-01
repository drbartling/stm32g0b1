MAIN_CONTROLLER_PATH := $(abspath $(lastword  $(MAKEFILE_LIST)))
MAIN_CONTROLLER_DIR := $(dir $(MAIN_CONTROLLER_PATH))

include ../board_support/ep04188_x1_thunderbird/bsp.make
include ../common/common.make

NOW         := $(shell date +%s)
BUILD_DATE  := $(NOW)

BUILD_DIR = $(MAIN_CONTROLLER_DIR)build

VPATH += $(MAIN_CONTROLLER_DIR)src
INCLUDE_DIRS += -I $(MAIN_CONTROLLER_DIR)src

SRCS +=               \
	app_dev_api.c     \
	board_support.c   \
	laser.c           \
	main.c            \
	eeprom_cat25128.c \

C_DEFINES += -D__BUILD_DATE__=$(BUILD_DATE)
ifeq ($(MAKECMDGOALS), debug)
	C_OPT += -O0 -g -ggdb -gdwarf # Optimize for debug
else
	C_OPT += -Os -g -ggdb -gdwarf # Optimize for size
endif

C_FLAGS =           \
	$(C_STD)        \
	$(C_OPT)        \
	$(INCLUDE_DIRS) \
	$(C_WARNINGS)   \
	$(C_DEFINES)    \
	$(ARCH_FLAGS)   \

LD_FLAGS =                                                    \
	$(C_FLAGS)                                                \
	-lc -lm $(HOSTING)                                        \
	-Wl,-Map="$@.map",--gc-sections,--start-group,--end-group \

DEP_FLAGS = -MMD -MP -MF $(BUILD_DIR)/$*.Td

PRECOMPILE  ?=
COMPILE_C   = $(CC) $(DEP_FLAGS) $(C_FLAGS)
POSTCOMPILE = mv -f $(BUILD_DIR)/$*.Td $(BUILD_DIR)/$*.d

OBJECTS := $(patsubst %,$(BUILD_DIR)/%.o,$(basename $(SRCS)))
$(shell mkdir -p $(dir $(OBJECTS)))

DEPS := $(patsubst %,$(BUILD_DIR)/%.d,$(basename $(SRCS)))
$(shell mkdir -p $(dir $(DEPS)) >/dev/null)

LINKER_SCRIPTS =   \
	stand-alone.ld \
	bank-1.ld      \
	bank-2.ld      \

ELFS := $(patsubst %,$(BUILD_DIR)/%.elf,$(basename $(LINKER_SCRIPTS)))
HEXS := $(patsubst %,$(BUILD_DIR)/%.hex,$(basename $(LINKER_SCRIPTS)))
BINS := $(patsubst %,$(BUILD_DIR)/%.bin,$(basename $(LINKER_SCRIPTS)))
DISS := $(patsubst %,$(BUILD_DIR)/%.asm,$(basename $(LINKER_SCRIPTS)))

.PHONY: default
default: $(ELFS) $(HEXS) $(BINS) $(DISS)

.PHONY: flash
flash: $(BUILD_DIR)/stand-alone.elf default
	openocd $(OPENOCD_FLAGS) -c "program $< reset" -c "shutdown"

.PHONY: debug
debug: $(BUILD_DIR)/stand-alone.elf default
	openocd $(OPENOCD_FLAGS) -c "program $< reset" -c "shutdown"

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)/*

.PHONY: all
all: clean default

$(BUILD_DIR)/%.o: %.c
$(BUILD_DIR)/%.o: %.c $(BUILD_DIR)/%.d
	$(PRECOMPILE)
	$(COMPILE_C) -c $< -o $@
	$(POSTCOMPILE)

$(BUILD_DIR)/%.elf: %.ld $(OBJECTS)
	$(CC) $(LD_FLAGS) $(OBJECTS) -o $@  -T"$<"
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf |
	$(HEX) $< $@

$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf |
	$(BIN) $< $@
	poetry -C ../../tools run thunderbird-build sign-application -b $@

$(BUILD_DIR)/%.asm: $(BUILD_DIR)/%.elf |
	arm-none-eabi-objdump -drwCS $< > $@

.PRECIOUS: $(BUILD_DIR)/%.d
$(BUILD_DIR)/%.d: ;

-include $(DEPS)
