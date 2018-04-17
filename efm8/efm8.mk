# Copyright 2018 jem@seethis.link
# Licensed under the MIT license (http://opensource.org/licenses/MIT)

ifndef MCU
  $(error "MCU not defined")
endif

ifndef PIN_COUNT
  $(error "PIN_COUNT not defined")
endif

ifndef F_CPU
  $(error "F_CPU not defined")
else
  CDEFS += -DF_CPU=$(F_CPU)ULL
endif

ifeq ($(MCU), EFM8UB20F32)
  MCU_FAMILY := EFM8UB2
  CODE_SIZE := 0x4000 # 32kb
  XRAM_SIZE := 0x0800 #  2kb
else ifeq ($(MCU), EFM8UB20F64)
  MCU_FAMILY := EFM8UB2
  CODE_SIZE := 0xFC00 # 64kb
  XRAM_SIZE := 0x1000 #  4kb
else
  $(error "No definition for this MCU='$(MCU)' (NOTE: must be all CAPS)")
endif

# TODO: check if this is true for all micros
CODE_LOC := 0x0000
XRAM_LOC := 0x0000


CFLAGS += -DMCU_STRING=$(MCU_STRING)
CFLAGS += -DPIN_COUNT=$(PIN_COUNT)
CFLAGS += -DMCU_$(MCU_FAMILY)

INC_PATHS += -I$(EFM8_PATH)
INC_PATHS += -I$(EFM8_PATH)/mcu
INC_PATHS += -I$(EFM8_PATH)/mcu/$(MCU_FAMILY)/inc
INC_PATHS += -I$(EFM8_PATH)/mcu/$(MCU_FAMILY)/peripheral_driver/inc
INC_PATHS += -I$(EFM8_PATH)/si8051Base
