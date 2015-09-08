//
// This file is part of the GNU ARM Eclipse Plug-ins project.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include <stdio.h>
#include "Arduino.h"
#include "diag/Trace.h"

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

// parte presa da esempio atmel
int main(int argc, char* argv[]) {

    WDT->WDT_MR = WDT_MR_WDDIS;
    pinMode(13,OUTPUT);
    digitalWrite(13,LOW);

}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
