//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

#include "BlinkLed.h"

// ----------------------------------------------------------------------------

void BlinkLed::powerUp() {
    /* Set up LED pins. */
    LED0_PIO->PIO_PER = LED0_MASK;
    LED0_PIO->PIO_OER = LED0_MASK;
    LED0_PIO->PIO_PUDR = LED0_MASK;

    // Start with led turned off
    turnOff();
}

// ----------------------------------------------------------------------------
