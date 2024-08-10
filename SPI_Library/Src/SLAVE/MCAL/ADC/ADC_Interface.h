/*
 * ADC_Interface.h
 *
 * Created: 5/18/2024 5:27:03 PM
 *  Author: zizoz
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_Private.h"

void ADC_initWithInterrupt(vRef selectionBit, preScaler prescalerValue);
void ADC_initWithoutInterrupt(vRef selectionBit, preScaler prescalerValue);

uint16_t ADC_Read(channel Channel);

#endif /* ADC_INTERFACE_H_ */