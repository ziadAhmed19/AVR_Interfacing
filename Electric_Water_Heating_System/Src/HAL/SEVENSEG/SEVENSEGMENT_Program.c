/*
* SEVENSEGMENT_Program.c
*
* Created: 4/27/2024 10:12:48 PM
*  Author: karim
*/
#include "SEVENSEGMENT_Interface.h"

/* ---------------------------Function----------------------*/
void SEVENSEGMENT_Initialize(void)
{
	Timer0_CTC_WithoutInterrupt_Initialize();
	Timer0_CTC_WithoutInterrupt_Start();
	DIO_SetPinDirection(SEVSEG_DATA_PORT, SEVSEG_DATA_A, DIO_OUTPUT);
	DIO_SetPinDirection(SEVSEG_DATA_PORT, SEVSEG_DATA_B, DIO_OUTPUT);
	DIO_SetPinDirection(SEVSEG_DATA_PORT, SEVSEG_DATA_C, DIO_OUTPUT);
	DIO_SetPinDirection(SEVSEG_DATA_PORT, SEVSEG_DATA_D, DIO_OUTPUT);
	
	DIO_SetPinDirection(SEVSEG_CONTROL_PORT, SEVSEG_CONTROL_EN1, DIO_OUTPUT);
	DIO_SetPinDirection(SEVSEG_CONTROL_PORT, SEVSEG_CONTROL_EN2, DIO_OUTPUT);
	
}

void SEVENSEGMENT_Enable1(void)
{
	DIO_SetPinValue(SEVSEG_CONTROL_PORT, SEVSEG_CONTROL_EN1, DIO_HIGH);
}

void SEVENSEGMENT_Disable1(void)
{
	DIO_SetPinValue(SEVSEG_CONTROL_PORT, SEVSEG_CONTROL_EN1, DIO_LOW);
}

void SEVENSEGMENT_Enable2(void)
{
	DIO_SetPinValue(SEVSEG_CONTROL_PORT, SEVSEG_CONTROL_EN2, DIO_HIGH);
}

void SEVENSEGMENT_Disable2(void)
{
	DIO_SetPinValue(SEVSEG_CONTROL_PORT, SEVSEG_CONTROL_EN2, DIO_LOW);
}

void SEVENSEGMENT_Display_Number(uint8_t number)
{
	uint8_t units = number % 10;
	uint8_t tenth = number / 10;
	SEVSEG_PORT = units ;
	SEVENSEGMENT_Enable1();
	SEVENSEGMENT_Disable2();
	Timer0_CTC_WithoutInterrupt_SetDelay(50,250);
	//_delay_ms(500);
	SEVSEG_PORT = tenth ;
	SEVENSEGMENT_Enable2();
	SEVENSEGMENT_Disable1();
	Timer0_CTC_WithoutInterrupt_SetDelay(50,250);
	//_delay_ms(500);
}

void SEVENSEGMENT_Disable()
{
	SEVENSEGMENT_Disable1();
	SEVENSEGMENT_Disable2();
}
/* ---------------------------Function End-------------------*/