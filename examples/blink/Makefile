# Copyright 2017 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

TARGET_BASE_NAME = blink
MCU              = EFM8UB20F32
MCU_SPECIFIC     = EFM8UB20F32G_QFP32
PIN_COUNT        = 32
F_CPU            = 48000000

EFM8_PATH        = ../../efm8
BASE_PATH        = .

# Provide install location of Simplicity Studio for CLI flashing tools
SIMPLICITY_STUDIO_PATH = $(HOME)/local/simplicity_studio/SimplicityStudio_v4

#######################################################################
#                             programing                              #
#######################################################################

ifndef SERIAL_NUM
  # The serial number of the device to program
  # Can also be passed on the command line
  SERIAL_NUM = EC3005481E8
endif

#######################################################################
#                               boards                                #
#######################################################################

include $(EFM8_PATH)/boards.mk

#######################################################################
#                            source files                             #
#######################################################################

include $(EFM8_PATH)/efm8.mk

# project source
C_SRC += \
	main.c \

# lib source
C_SRC += \
	efm8_util/delay.c \

ASM_SRC = \
	# crtxinit.S \

#######################################################################
#                          compiler settings                          #
#######################################################################

# Using optimize for speed can result in a smaller binary in sdcc
# OPTIMIZATION = --opt-code-speed
OPTIMIZATION = --opt-code-size

# Compiler, assembler and preprocessor to use
AS = sdas8051
CC = sdcc
PP = sdcpp

# Extra compiler options
CFLAGS += \
	--fomit-frame-pointer \
	--model-small \
	# --model-large \
	# --stack-auto \
	# --Werror \
	# --code-movx \
	# --disable-warning 85 \

# Extra linking options
LFLAGS += \
	--iram-size 0x100 \
	--stack-loc 0x080 \
	--stack-size 0x060 \
	# --parms-in-bank1

# Assembler options
ASFLAGS  = -xglospff

#######################################################################
#                              recipes                               #
#######################################################################

include $(EFM8_PATH)/sdcc.mk
include $(EFM8_PATH)/efm8_program.mk

-include $(DEP_FILES)

.PHONY: clean flash program all size
