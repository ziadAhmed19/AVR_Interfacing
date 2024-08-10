/*
 * ADC_Register.h
 *
 * Created: 5/20/2024 5:33:09 PM
 *  Author: zizoz
 */ 


#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#include "CPU_Configs.h"
#include "Periphrials.h"

/*Renaming Registers*/

#define _ADC_ADCL    (*(volatile uint8_t*)(0x24))
#define _ADC_ADCH    (*(volatile uint8_t*)(0x25))
#define _ADC_ADMUX   (*(volatile uint8_t*)(0x27))
#define _ADC_ADCSRA  (*(volatile uint8_t*)(0x26))
#define _ADC_SFIOR   (*(volatile uint8_t*)(0x50))

#define _ADC_DATA    (*(volatile uint16_t*)(0x24))

/*End*/

#endif /* ADC_REGISTER_H_ */