/*
 * CPU_Configs.h
 *
 * Created: 5/2/2024 8:16:27 PM
 *  Author: zizoz
 */ 


#ifndef CPU_CONFIGS_H_
#define CPU_CONFIGS_H_

/* ---------------------------CPU Configuration--------------*/
#undef F_CPU               // Deactivate internal clock (1 MHz)
#define F_CPU 16000000     // Activate external clock (16 MHz)
#include <avr/io.h>        // AVR Libraries
#include <avr/interrupt.h> // AVR Interrupt Libraries
#include <util/delay.h>    // AVR Delay Functions

/* ---------------------------END---------------------------*/

/* --------------------------- User Defined ---------------------------*/

#include "bitMath.h"
#include "STD_Types.h"
/* ---------------------------END---------------------------*/

#endif /* CPU_CONFIGS_H_ */