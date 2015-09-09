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


int main(int argc, char* argv[]) {

	RingBuffer rx_buffer1;
	RingBuffer tx_buffer1;

	UARTClass Serial(UART, UART_IRQn, ID_UART, &rx_buffer1, &tx_buffer1);
	//init();

	  PIO_Configure(
	    g_APinDescription[PINS_UART].pPort,
	    g_APinDescription[PINS_UART].ulPinType,
	    g_APinDescription[PINS_UART].ulPin,
	    g_APinDescription[PINS_UART].ulPinConfiguration);
	  digitalWrite(0, HIGH); // Enable pullup for RX0

	SystemInit();
	Serial.begin(9600);
	pmc_enable_periph_clk(ID_ADC);
	adc_init(ADC, SystemCoreClock, ADC_FREQ_MAX, ADC_STARTUP_FAST);
	adc_configure_timing(ADC, 0, ADC_SETTLING_TIME_3, 1);
	adc_configure_trigger(ADC, ADC_TRIG_SW, 0); // Disable hardware trigger.
	adc_disable_interrupt(ADC, 0xFFFFFFFF); // Disable all ADC interrupts.
	adc_disable_all_channel(ADC);
	analogOutputInit();

    WDT->WDT_MR = WDT_MR_WDDIS;
    pinMode(A0,OUTPUT);
    pinMode(13,OUTPUT);
    analogWrite(A0,155);
    while(1){
    	digitalWrite(13,HIGH);
    	delayMicroseconds(1000000);
    	digitalWrite(13,LOW);
    	delay(1000);
    	Serial.write(55);
    }

}



// ----------------------------------------------------------------------------
