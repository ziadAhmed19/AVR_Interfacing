/*
* ADC_Program.c
*
* Created: 2/10/2024 4:20:49 PM
*  Author: karim
*/

#include "ADC_Interface.h"


void ADC_init(void) {
	// Set ADC reference voltage to AVcc (5V), left-adjust result, select ADC0
	 ADMUX = (1 << REFS0) | (1 << MUX2);  // REFS1 = 0, REFS0 = 1 --> AVcc as reference
                                         


	// Enable ADC, enable ADC interrupt, and set prescaler to 128
	ADCSRA = (1 << ADEN)  |   // ADC Enable
	(1 << ADIE)  |   // ADC Interrupt Enable
	(1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Prescaler 128

	// Enable global interrupts
	sei();
}

void ADC_start(void) {
	// Start the ADC conversion by setting the ADSC bit
	ADCSRA |= (1 << ADSC);  // Start conversion
}
