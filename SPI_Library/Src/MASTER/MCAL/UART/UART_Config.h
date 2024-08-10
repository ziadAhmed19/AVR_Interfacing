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

typedef enum{
	BAUD_2400 =   0 ,
	BAUD_4800 =   1 ,
	BAUD_9600 =   2 ,
	BAUD_14400 =  3 ,
	BAUD_19200 =  4 ,
	BAUD_28800 =  5 ,
	BAUD_38400 =  6 ,
	BAUD_57600 =  7 ,
	BAUD_76800 =  8 ,
	BAUD_115200 = 9 ,
	BAUD_230400 = 10,
	BAUD_250000 = 11,
	BAUD_500k =   12,
	BAUD_1M =     13
	}BaudRate;

typedef enum{
	FALSE = 0,
	TRUE =  1, 
	}Double_Speed;
/*End*/



#endif /* UART_CONFIG_H_ */