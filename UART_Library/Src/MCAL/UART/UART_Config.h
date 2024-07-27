/*
 * UART_Config.h
 *
 * Created: 7/26/2024 5:15:13 PM
 *  Author: zizoz
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#include "CPU_Config.h"
#include "peripherals.h"

/*Defining new data types*/
typedef enum{
	Asynchronous = 0,
	Synchronous = 1
	}Mode_Of_Operation;

typedef enum{
	EVEN_PARITY   =  0,
	ODD_PARITY    =  1,
	DISABLE_PARITY=  2
	}Parity;

typedef enum{
	ONE_BIT = 0,
	TWO_BIT = 1
	}Stop_Bit;
	
typedef enum{
	FIVE_BIT = 0,
	SIX_BIT  = 1,
	SEVEN_BIT= 2,
	EIGHT_BIT= 3,
	NINE_BIT = 4
	}Data_Size;

typedef enum{
	Rising_XCK_Edge = 0,
	Falling_XCK_Edge= 1
	}Clock_Polarity;

/*End*/



#endif /* UART_CONFIG_H_ */