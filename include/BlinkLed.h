//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

#ifndef BLINKLED_H_
#define BLINKLED_H_

#include "sam3x_conf.h"

// ----- LED definitions ------------------------------------------------------

// Adjust these definitions for your own board.

// Arduino Due: LED on PIOB bit 27
// (SEGGER J-Link device name: ???).

#define LED0_PIO		PIOB
#define LED0_MASK		(0x01u << 27)

#define BLINK_ACTIVE_LOW                (0)

// ----------------------------------------------------------------------------

class BlinkLed {
public:
    BlinkLed() = default;

    void
    powerUp();

    inline void
    __attribute__((always_inline))
    turnOn() {
#if (BLINK_ACTIVE_LOW)
        LED0_PIO->PIO_CODR = LED0_MASK;
#else
        LED0_PIO->PIO_SODR = LED0_MASK;
#endif
    }

    inline void
    __attribute__((always_inline))
    turnOff() {
#if (BLINK_ACTIVE_LOW)
        LED0_PIO->PIO_SODR = LED0_MASK;
#else
        LED0_PIO->PIO_CODR = LED0_MASK;
#endif
    }
};

// ----------------------------------------------------------------------------

#endif // BLINKLED_H_
