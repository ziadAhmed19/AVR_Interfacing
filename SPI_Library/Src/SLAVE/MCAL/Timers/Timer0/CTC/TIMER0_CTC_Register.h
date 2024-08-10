/*
 * TIMER0_CTC_Register.h
 *
 * Created: 6/14/2024 4:58:01 PM
 *  Author: zizoz
 */ 


#ifndef TIMER0_CTC_REGISTER_H_
#define TIMER0_CTC_REGISTER_H_

#include "CPU_Configs.h"
#include "Periphrials.h"

#define _T0_CTC_OCR0  (* (volatile uint8_t*)(0x5C))
#define _T0_CTC_TIFR  (* (volatile uint8_t*)(0x58))
#define _T0_CTC_TCCR0 (* (volatile uint8_t*)(0x53))
#define _T0_CTC_TCNT0 (* (volatile uint8_t*)(0x52))
#define _T0_CTC_TIMSK (* (volatile uint8_t*)(0x59))



#endif /* TIMER0_CTC_REGISTER_H_ */