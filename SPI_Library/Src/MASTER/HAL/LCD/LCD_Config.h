/*
 * LCD_Config.h
 *
 * Created: 5/11/2024 10:24:13 AM
 *  Author: zizoz
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "CPU_Config.h"
#include "peripherals.h"

/*new data type*/
typedef enum{
	ROW0 = 0,
	ROW1 = 1
	}row;

typedef enum
{
	COL0  = 0,
	COL1  = 1,
	COL2  = 2,
	COL3  = 3,
	COL4  = 4,
	COL5  = 5,
	COL6  = 6,
	COL7  = 7,
	COL8  = 8,
	COL9  = 9,
	COL10 = 10,
	COL11 = 11,
	COL12 = 12,
	COL13 = 13,
	COL14 = 14,
	COL15 = 15
}column;
/*End*/


/*Renaming Pins & Ports*/
#define LCD_PORT _DIO_PORTA
#define LCD_DATA_PORT DIO_PORTA
#define LCD_CONTROL_PORT DIO_PORTC

#define LCD_DATA_D0     DIO_PIN0
#define LCD_DATA_D1     DIO_PIN1
#define LCD_DATA_D2     DIO_PIN2
#define LCD_DATA_D3     DIO_PIN3
#define LCD_DATA_D4     DIO_PIN4
#define LCD_DATA_D5     DIO_PIN5
#define LCD_DATA_D6     DIO_PIN6
#define LCD_DATA_D7     DIO_PIN7

#define LCD_CONTROL_RS  DIO_PIN4
#define LCD_CONTROL_RW  DIO_PIN2
#define LCD_CONTROL_EN  DIO_PIN3
/*End*/

/*Renaming State*/
#define LCD_OUTPUT DIO_OUTPUT
/*End*/

/*Renaming Status*/
#define LCD_LOW DIO_LOW
#define LCD_HIGH DIO_HIGH

#endif /* LCD_CONFIG_H_ */