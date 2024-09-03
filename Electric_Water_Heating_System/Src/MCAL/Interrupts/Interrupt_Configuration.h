/*
 * Interrupt_Configuration.h
 *
 * Created: 5/11/2024 9:49:35 PM
 *  Author: karim
 */ 


#ifndef INTERRUPT_CONFIGURATION_H_
#define INTERRUPT_CONFIGURATION_H_

#include "Interrupt_Address.h"

typedef enum
{
	EXT_INTERRUPT_SENSE_LOW      = 0,
	EXT_INTERRUPT_SENSE_HIGH     = 1,
	EXT_INTERRUPT_SENSE_FALLING  = 2,
	EXT_INTERRUPT_SENSE_RISING   = 3
}interruptSense;

typedef enum
{
	EXT_INT0 = 0,
	EXT_INT1 = 1,
	EXT_INT2 = 2
}interruptPin;

#endif /* INTERRUPT_CONFIGURATION_H_ */