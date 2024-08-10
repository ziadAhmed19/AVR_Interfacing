/*
 * TIMER0_OVF_Interface.h
 *
 * Created: 5/25/2024 9:18:38 PM
 *  Author: zizoz
 */ 


#ifndef TIMER0_OVF_INTERFACE_H_
#define TIMER0_OVF_INTERFACE_H_

#include "TIMER0_OVF_Private.h"

void TIMER0_OVF_WithInterrput_Init(Prescaler_OVF selection);

void TIMER0_OVF_WithInterrput_Stop();

void TIMER0_OVF_WithInterrput_SetDelay(uint32_t delay);

void TIMER0_OVF_WithoutInterrput_Init(Prescaler_OVF selection);

void TIMER0_OVF_WithoutInterrput_Stop();

void TIMER0_OVF_WithoutInterrput_Delay(uint32_t delay);

#endif /* TIMER0_OVF_INTERFACE_H_ */