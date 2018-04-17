// Copyright 2018 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)
/// @file main.c
///
/// Blink demo for EFM8UB2
///
/// Blinks LEDs on pins P2.2 and P2.3

#include "efm8_util/delay.h"
#include "efm8_util/watchdog.h"

#define LED0 P2_B2
#define LED1 P2_B3

/// Time between blinks
#define BLINK_DELAY 1000

#if 0
// SDCC startup routine, runs before main
uint8_t _sdcc_external_startup () {
#if 0
    PCA0MD    &= ~0x40;
    PCA0MD    = 0x00;
    // disable_watchdog();
#else
    PCA0MD    &= ~0x40;
    PCA0MD    = 0x00;
    PCA0CPM0  = 0x21;
    PCA0CPM1  = 0x21;
#endif
    return 0;
}
#endif

void io_init() {
    // P0    -  Skipped,     Open-Drain, Digital
    // P1    -  Skipped,     Open-Drain, Digital
    // P2.2  -  Unassigned,  Push-Pull,  Digital
    // P2.3  -  Unassigned,  Push-Pull,  Digital
#if 1
    P2MDOUT   = PIN2_bm | PIN3_bm;
    P0SKIP    = 0xFF;
    P1SKIP    = 0xFF;
    // P2SKIP    = 0xFF;
    XBR1      = 0x40;
#else
    P2MDOUT   = 0x0C;
    P1MDIN 	  = 0xC0;
    P0SKIP    = 0xFF;
    P1SKIP    = 0xFF;
    XBR1      = 0x42;
#endif
}

// Setup oscillator and flash read timings
void oscillator_init() {
#if 1
    FLSCL  = (
        FLSCL_FOSE__ENABLED
        | FLSCL_FLRT__SYSCLK_BELOW_48_MHZ
    );
    CLKSEL = (
        (CLKSEL_CLKSL__HFOSC << CLKSEL_CLKSL__SHIFT)
    );
#else
    FLSCL     = 0x90;
    CLKSEL    = 0x03;
#endif
}

void setup(void) {
    PCA0MD    &= ~0x40;
    PCA0MD    = 0x00;

    oscillator_init();
    io_init();

    // Disable interrupts
    IE_EA = 0;
}

void main(void) {
    setup();

    LED0 = 1;
    LED1 = 0;

    while (1) {
        LED0 = !LED0;
        efm8_delay_ms(BLINK_DELAY);
        LED1 = !LED1;
        efm8_delay_ms(BLINK_DELAY);
    }
}
