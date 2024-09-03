/*
 * ADC_Interface.h
 *
 * Created: 2/10/2024 4:20:32 PM
 *  Author: karim
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_Private.h"

void ADC_init();
void ADC_start(void) ;
uint16_t ADC_Read(adc_channel channel);

#endif /* ADC_INTERFACE_H_ */