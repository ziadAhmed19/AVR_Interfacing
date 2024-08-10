/*
 * SPI_Config.h
 *
 * Created: 7/29/2024 4:23:59 PM
 *  Author: zizoz
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

#include "CPU_Configs.h"
#include "Periphrials.h"

typedef enum{
	MSB = 0,
	LSB = 1 
	}Data_Order;

typedef enum{
	LeadingEdge_Sample_Rising_TrailingEdge_Setup_Falling = 0,
	LeadingEdge_Setup_Rising_TrailingEdge_Sample_Falling = 1,
	LeadingEdge_Sample_Falling_TrailingEdge_Setup_Rising = 2,
	LeadingEdge_Setup_Falling_TrailingEdge_Sample_Rising = 3
	}SPI_Mode;

typedef enum{
	/*Normal Speeds*/
	Fosc_4 =   0,
	Fosc_16 =  1,
	Fosc_64 =  2,
	Fosc_128 = 3,
	/*Doubled Speeds*/
	DS_Fosc_2 =  4,
	DS_Fosc_8 =  5,
	DS_Fosc_32 = 6,
	DS_Fosc_64 = 7,
	}SCK_Rate;

typedef enum{
	Slave_One = 0,
	Slave_Two = 1,
	}SlaveAddress;

typedef enum{
	Select = 0,
	DeSelect = 1
	}Selection_State;

typedef enum{
	Interruput_Disabled = 0,
	Interruput_Enabled = 1
}Intrput;
/*
typedef enum{
	LeadingEdge_Rising_TrailingEdge_Falling = 0,
	LeadingEdge_Falling_TrailingEdge_Rising = 1
	
	}SCK_Polarity;

typedef enum{
	LeadingEdge_Sample_TrailingEdge_Setup = 0,
	LeadingEdge_Setup_TrailingEdge_Sample = 1
	}SCK_Phase;
*/

#endif /* SPI_CONFIG_H_ */