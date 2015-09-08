//
// This file is part of the GNU ARM Eclipse Plug-ins project.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include <stdio.h>

#include "diag/Trace.h"
#include "Timer.h"
#include "BlinkLed.h"
// ----------------------------------------------------------------------------
//
// Print a greeting message on the trace device and enter a loop
// to count seconds.
//
// Trace support is enabled by adding the TRACE macro definition.
// By default the trace messages are forwarded to the STDOUT output,
// but can be rerouted to any device or completely suppressed, by
// changing the definitions required in system/src/diag/trace_impl.c
// (currently OS_USE_TRACE_ITM, OS_USE_TRACE_SEMIHOSTING_DEBUG/_STDOUT).
//

// ----------------------------------------------------------------------------
// Definitions visible only within this translation unit.
namespace {
// ----- Timing definitions -------------------------------------------------

// Keep the LED on for 2/3 of a second.
constexpr Timer::ticks_t BLINK_ON_TICKS = Timer::FREQUENCY_HZ * 2 / 3;
constexpr Timer::ticks_t BLINK_OFF_TICKS = Timer::FREQUENCY_HZ - BLINK_ON_TICKS;
}

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

// parte presa da esempio atmel
int main(int argc, char* argv[]) {
    // Normally at this stage most of the microcontroller subsystems, including
    // the clock, were initialised by the CMSIS SystemInit() function invoked
    // from the startup file, before calling main().
    // (see system/src/cortexm/_initialize_hardware.c)
    // If further initialisations are required, customise __initialize_hardware()
    // or add the additional initialisation here, for example:
    //
    // HAL_Init();

    // In this sample the SystemInit() function is just a placeholder,
    // if you do not add the real one, the clock will remain configured with
    // the reset value, usually a relatively low speed RC clock (8-12MHz).

    // By customising __initialize_args() it is possible to pass arguments,
    // for example when running tests with semihosting you can pass various
    // options to the test.
    // trace_dump_args(argc, argv);

    // Disable watchdog timer
    WDT->WDT_MR = WDT_MR_WDDIS;

    // Send a greeting to the trace device (skipped on Release).
    trace_puts("Hello ARM World!");

    // The standard output and the standard error should be forwarded to
    // the trace device. For this to work, a redirection in _write.c is
    // required.
    puts("Standard output message.");
    fprintf(stderr, "Standard error message.\n");

    // At this stage the system clock should have already been configured
    // at high speed.
    trace_printf("System clock: %uHz\n", SystemCoreClock);

    Timer timer;
    timer.start();

    BlinkLed blinkLed;

    // Perform all necessary initialisations for the LED.
    blinkLed.powerUp();

    int seconds = 0;

    // Infinite loop
    while (1) {
        /* Turn On LED. */
        blinkLed.turnOn();
        timer.sleep(BLINK_ON_TICKS);

        blinkLed.turnOff();
        timer.sleep(BLINK_OFF_TICKS);

        // Count seconds on the trace device.
        trace_printf("Second %d\n", seconds);
    }
    // Infinite loop, never return.
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
