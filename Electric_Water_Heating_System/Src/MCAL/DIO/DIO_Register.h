/*
 * DIO_Register.h
 *
 * Created: 5/5/2024 2:32:16 PM
 * 
 *	Making my own Library in order to make the code portable, why?
 *	
 *	if i want this code to work on another MC for example a PIC, I will just adjust the Config and the 
 *	
 *	Register file of the DIO, instead of going to every function in the whole code and adjust it manually
 */ 


#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

#include "CPU_Config.h"

#define _DIO_PORTA (*(volatile uint8_t*)(0x3B))
#define _DIO_DDRA  (*(volatile uint8_t*)(0x3A))
#define _DIO_PINA  (*(volatile uint8_t*)(0x39))

#define _DIO_PORTB (*(volatile uint8_t*)(0x38))
#define _DIO_DDRB  (*(volatile uint8_t*)(0x37))
#define _DIO_PINB  (*(volatile uint8_t*)(0x36))

#define _DIO_PORTC (*(volatile uint8_t*)(0x35))
#define _DIO_DDRC  (*(volatile uint8_t*)(0x34))
#define _DIO_PINC  (*(volatile uint8_t*)(0x33))

#define _DIO_PORTD (*(volatile uint8_t*)(0x32))
#define _DIO_DDRD  (*(volatile uint8_t*)(0x31))
#define _DIO_PIND  (*(volatile uint8_t*)(0x30))

#endif /* DIO_REGISTER_H_ */