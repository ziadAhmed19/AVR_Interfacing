/*
* TIMER0_OVF_Program.c
*
* Created: 5/25/2024 9:19:10 PM
*  Author: zizoz
*/
#include "TIMER0_OVF_Interface.h"


void TIMER0_OVF_WithInterrput_Init(Prescaler_OVF selection)
{

	
	sei();
}

void TIMER0_OVF_WithInterrput_Stop()
{

}

void TIMER0_OVF_WithInterrput_SetDelay(uint32_t delay)
{

}

/************************************************************************/
/*									                                    */
/************************************************************************/

void TIMER0_OVF_WithoutInterrput_Init(Prescaler_OVF selection)
{
	/*
	1-Select Normal mode WGM00 -WGM01 Clear
	2- Select toggle mode on OC0 Set COM00
	3- user select prescaler 
	*/
	switch(selection)
	{
		case OVF_no_prescaling :
		TCCR0 = 0x17;
		break;
		
		case OVF_prescaler_8 :
		TCCR0 = 0x18 ;
		break ;
		
		case OVF_prescaler_64 :
		TCCR0 = 0x19 ;
		break; 
		
		case OVF_prescaler_256 :
		TCCR0 = 0x20 ;
		break;
		
		case OVF_prescaler_1024 :
		TCCR0 = 0x21 ;
		break ;
		
		default:
		TCCR0 = 0x21 ;
		break ; 
	}
	
}

void TIMER0_OVF_WithoutInterrput_Stop()
{
	TCCR0 = 0x16;
}

void TIMER0_OVF_WithoutInterrput_Delay(uint32_t delay)
{
	/*
	1- Create counter
	2- Create tick = 1 * Prescaler / frequency
	3- Create Count = delay * 10^k / Tick
	4- Create OVF = Count / 2^8 + 1
	5- Create Initial value = 2^8 - (Count % 2^8)
	6- Set initial value
	7- Wait until flag raise
	8- Re-Initialize flag
	9- Increment counter
	*/
	uint32_t counter = 0;
	uint8_t Tick = ((1*_T0_OVF_PRESCALER)/_T0_OVF_FREQUENCY);
	uint32_t Count = ((delay * _T0_OVF_MICROSECOND) / Tick);
	uint32_t OVF = (Count / _T0_OVF_BITS) + 1;
	uint8_t iValue = _T0_OVF_BITS - (Count % _T0_OVF_BITS);
	TCNT0 = iValue;
	while (counter != OVF)
	{
		while (GET_BIT(TIFR, TOV0) != 1);
		TIFR |= (1<<TOV0);
		counter++;
	}
}