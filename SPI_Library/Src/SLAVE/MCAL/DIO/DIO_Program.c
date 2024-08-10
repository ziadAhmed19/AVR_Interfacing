/*
 * DIO_Program.c
 *
 * Created: 5/5/2024 4:50:37 PM
 *  Author: zizoz
 
	set pin dirction  : bet7aded hay 7atkon input wala output.
	
	set pin value : bet-OUTPUT HIGH aw LOW , tab leeh beta5od status as a parameter?
	- badal ma te3mel two functions w7da bet set wel tnya bet clear 
	
 */ 
#include "DIO_Interface.h"

void DIO_SetPinDirection(dioPort port, dioPin pin, dioState state)
{
	switch (state)
	{
		
		case DIO_INPUT:
		switch(port)
		{
			case DIO_PORTA:
			CLR_BIT(_DIO_DDRA, pin);
			break;
			case DIO_PORTB:
			CLR_BIT(_DIO_DDRB, pin);
			break;
			case DIO_PORTC:
			CLR_BIT(_DIO_DDRC, pin);
			break;
			case DIO_PORTD:
			CLR_BIT(_DIO_DDRD, pin);
			break;
		}
		break;
		
		case DIO_OUTPUT:
		switch(port)
		{
			case DIO_PORTA:
			SET_BIT(_DIO_DDRA, pin);
			break;
			case DIO_PORTB:
			SET_BIT(_DIO_DDRB, pin);
			break;
			case DIO_PORTC:
			SET_BIT(_DIO_DDRC, pin);
			break;
			case DIO_PORTD:
			SET_BIT(_DIO_DDRD, pin);
			break;
		}
		break;
		
		default://Error
		break;
	}
}

void DIO_SetPinValue(dioPort port, dioPin pin, dioStatus status)
{
	switch (status)
	{
		case DIO_LOW:
		switch(port)
		{
			case DIO_PORTA:
			CLR_BIT(_DIO_PORTA, pin);
			break;
			case DIO_PORTB:
			CLR_BIT(_DIO_PORTB, pin);
			break;
			case DIO_PORTC:
			CLR_BIT(_DIO_PORTC, pin);
			break;
			case DIO_PORTD:
			CLR_BIT(_DIO_PORTD, pin);
			break;
		}
		break;
		
		case DIO_HIGH:
		switch(port)
		{
			case DIO_PORTA:
			SET_BIT(_DIO_PORTA, pin);
			break;
			case DIO_PORTB:
			SET_BIT(_DIO_PORTB, pin);
			break;
			case DIO_PORTC:
			SET_BIT(_DIO_PORTC, pin);
			break;
			case DIO_PORTD:
			SET_BIT(_DIO_PORTD, pin);
			break;
		}
		break;
		
		default://Error
		break;
	}
	
}

void DIO_TogglePinValue(dioPort port, dioPin pin)
{
	switch(port)
	{
		case DIO_PORTA:
		TGL_BIT(_DIO_PORTA, pin);
		break;
		case DIO_PORTB:
		TGL_BIT(_DIO_PORTB, pin);
		break;
		case DIO_PORTC:
		TGL_BIT(_DIO_PORTC, pin);
		break;
		case DIO_PORTD:
		TGL_BIT(_DIO_PORTD, pin);
		break;
	}
}

uint8_t DIO_GetPinValue(dioPort port, dioPin pin)
{
	uint8_t val = 0;
	switch(port)
	{
		case DIO_PORTA:
		val = GET_BIT(_DIO_PINA, pin);
		break;
		
		case DIO_PORTB:
		val = GET_BIT(_DIO_PINB, pin);
		break;
		
		case DIO_PORTC:
		val = GET_BIT(_DIO_PINC, pin);
		break;
		
		case DIO_PORTD:
		val = GET_BIT(_DIO_PIND, pin);
		break;
		
	}
	return val;
}

void DIO_SetPinPullUp(dioPort port, dioPin pin)
{
	switch(port)
	{
		case DIO_PORTA:
		SET_BIT(_DIO_PORTA, pin);
		break;
		
		case DIO_PORTB:
		SET_BIT(_DIO_PORTB, pin);
		break;
		
		case DIO_PORTC:
		SET_BIT(_DIO_PORTC, pin);
		break;
		
		case DIO_PORTD:
		SET_BIT(_DIO_PORTD, pin);
		break;
		
	}
}

void DIO_SetPinPullDown(dioPort port, dioPin pin)
{
	switch(port)
	{
		case DIO_PORTA:
		CLR_BIT(_DIO_PORTA, pin);
		break;
		
		case DIO_PORTB:
		CLR_BIT(_DIO_PORTB, pin);
		break;
		
		case DIO_PORTC:
		CLR_BIT(_DIO_PORTC, pin);
		break;
		
		case DIO_PORTD:
		CLR_BIT(_DIO_PORTD, pin);
		break;
		
	}
}
