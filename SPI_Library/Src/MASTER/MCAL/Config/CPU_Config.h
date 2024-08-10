/*
 * CPU_Config.h
 *
 * Created: 7/26/2024 3:00:31 PM
 *  Author: zizoz
 */ 


#ifndef CPU_CONFIG_H_
#define CPU_CONFIG_H_

#undef  F_CPU              // Deactivate internal clock (1 MHz)
#define F_CPU 16000000     // Activate external clock (16 MHz)
#include <avr/io.h>        // AVR Libraries
#include <avr/eeprom.h>    // AVR EEPROM Libraries
#include <avr/interrupt.h> // AVR Interrupt Libraries
#include <util/delay.h>    // AVR Delay Functions
#include <stdint.h>
#include "BitMath.h"


#endif /* CPU_CONFIG_H_ */