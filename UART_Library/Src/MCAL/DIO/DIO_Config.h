/*
 * DIO_Config.h
 *
 * Created: 5/5/2024 4:25:08 PM
 *  Author: zizoz
	Why did we use enum?
	
	- in order to use a switch case to make the coder more readable and extremely fast and efficient
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#include "DIO_Register.h"

/* Renaming Ports */
typedef enum
{
	DIO_PORTA = 0,
	DIO_PORTB = 1,
	DIO_PORTC = 2,
	DIO_PORTD = 3
}dioPort;
/* Renaming Pins */
typedef enum
{
	DIO_PIN0 = 0,
	DIO_PIN1 = 1,
	DIO_PIN2 = 2,
	DIO_PIN3 = 3,
	DIO_PIN4 = 4,
	DIO_PIN5 = 5,
	DIO_PIN6 = 6,
	DIO_PIN7 = 7
}dioPin;
/* Renaming States */
typedef enum
{
	DIO_INPUT  = 0,
	DIO_OUTPUT = 1
}dioState;
/* Renaming Status */
typedef enum
{
	DIO_LOW  = 0,
	DIO_HIGH = 1
}dioStatus;
/* Renaming Return */
typedef enum
{
	DIO_FALSE  = 0,
	DIO_TRUE   = 1
}dioReturn;
#endif /* DIO_CONFIG_H_ */