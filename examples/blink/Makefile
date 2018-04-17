# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

TARGET	  = blink
OBJ_DIR	  = obj
MCU		  = EFM8UB20F32
PIN_COUNT = 32
F_CPU	  = 48000000

EFM8_PATH = ../../efm8
BASE_PATH = .

VPATH += $(BASE_PATH)/src
INC_PATHS += -I$(BASE_PATH)

#######################################################################
#                               content                               #
#######################################################################

include $(EFM8_PATH)/efm8.mk

#######################################################################
#                            source files                             #
#######################################################################

C_SRC += \
	main.c \
	$(EFM8_PATH)/efm8_util/delay.c \

ASM_SRC = \
	# crtxinit.S \

#######################################################################
#                          compiler settings                          #
#######################################################################

# Using optimize for speed can result in a smaller binary in sdcc
OPTIMIZATION = --opt-code-speed
# OPTIMIZATION = --opt-code-size

AS = /usr/local/bin/sdas8051
CC = /usr/local/bin/sdcc
PP = /usr/local/bin/sdcpp

CFLAGS += \
	--fomit-frame-pointer \
	--model-small \
	# --stack-auto \
	# --Werror \
	# --model-small \
	# --code-movx \
	# --disable-warning 85 \
	# --model-large \
	#

LFLAGS   = \
	--code-loc $(CODE_LOC) \
	--code-size $(CODE_SIZE) \
	--xram-loc  $(XRAM_LOC)\
	--xram-size $(XRAM_SIZE) \
	--iram-size 0x100 \
	--stack-loc 0x080 \
	--stack-size 0x060 \
	# --parms-in-bank1

ASFLAGS  = -xglospff

include $(EFM8_PATH)/sdcc.mk

-include $(DEP_FILES)

.PHONY: clean flash program all size
