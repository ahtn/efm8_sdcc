// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

// Useful defines for pin
#ifndef PIN0_bm
#  define PIN0_bm (1<<0)
#  define PIN1_bm (1<<1)
#  define PIN2_bm (1<<2)
#  define PIN3_bm (1<<3)
#  define PIN4_bm (1<<4)
#  define PIN5_bm (1<<5)
#  define PIN6_bm (1<<6)
#  define PIN7_bm (1<<7)
#endif

#if defined(MCU_EFM8UB1)
#  include "EFM8UB1/inc/SI_EFM8UB1_Defs.h"
#  include "EFM8UB1/inc/SI_EFM8UB1_Devices.h"
#  include "EFM8UB1/inc/SI_EFM8UB1_Register_Enums.h"
#elif defined(MCU_EFM8UB2)
#  include "EFM8UB2/inc/SI_EFM8UB2_Defs.h"
#  include "EFM8UB2/inc/SI_EFM8UB2_Devices.h"
#  include "EFM8UB2/inc/SI_EFM8UB2_Register_Enums.h"
#elif defined(MCU_EFM8UB3)
#  include "EFM8UB3/inc/SI_EFM8UB3_Defs.h"
#  include "EFM8UB3/inc/SI_EFM8UB3_Devices.h"
#  include "EFM8UB3/inc/SI_EFM8UB3_Register_Enums.h"
#else
#  warning "Device type not defined"
#endif
