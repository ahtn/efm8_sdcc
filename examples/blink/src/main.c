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
#define BLINK_DELAY 250

/// Setup io pins
static void io_init() {
    // P0    -  Skipped,     Open-Drain, Digital
    // P1    -  Skipped,     Open-Drain, Digital
    // P2.2  -  Unassigned,  Push-Pull,  Digital
    // P2.3  -  Unassigned,  Push-Pull,  Digital

    P2MDOUT   = PIN2_bm | PIN3_bm;
    P0SKIP    = 0xFF;
    P1SKIP    = 0xFF;
    P2SKIP    = 0xFF;
    XBR1      = XBR1_XBARE__ENABLED;
}

/// Setup oscillator and flash read timings
static void oscillator_init() {
    // Flash settings
    FLSCL  = (
        FLSCL_FOSE__ENABLED
        | FLSCL_FLRT__SYSCLK_BELOW_48_MHZ
    );
    // Clock settings
    CLKSEL = CLKSEL_CLKSL__HFOSC;
}

/// Setup code
void setup(void) {
    efm8_watchdog_disable();

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
