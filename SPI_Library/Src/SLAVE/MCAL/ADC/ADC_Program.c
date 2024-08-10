/*
* ADC_Program.c
*
* Created: 5/18/2024 5:27:37 PM
*  Author: zizoz
*/
#include "ADC_Interface.h"

void ADC_initWithInterrupt(vRef selectionBit, preScaler prescalerValue)
{
	switch(selectionBit)
	{
		//case ARef
		case 0 :
		_ADC_ADMUX = 0x00 ;
		break ;
		//End
		
		//Case AVCC
		case 1 :
		_ADC_ADMUX = 0x40 ;
		break ;
		//End
		
		//Case Reverse
		case 2 :
		_ADC_ADMUX = 0x80 ;
		break ;
		//End
		
		//Case Internal
		case 3 :
		_ADC_ADMUX = 0x90 ;
		break;
		//End
	}
	
	switch(prescalerValue)
	{
		//Division Factor 2
		case 0 :
		_ADC_ADCSRA = 0xA9 ;
		break;
		//End
		
		//Division Factor 4
		case 1 :
		_ADC_ADCSRA = 0xAA ;
		break;
		//End
		
		//Division Factor 8
		case 2 :
		_ADC_ADCSRA = 0xAB ;
		break;
		//End
		
		//Division Factor 16
		case 3 :
		_ADC_ADCSRA = 0xAC ;
		break;
		//End
		
		//Division Factor 32
		case 4 :
		_ADC_ADCSRA = 0xAD ;
		break;
		//End
		
		//Division Factor 64
		case 5 :
		_ADC_ADCSRA = 0xAE ;
		break;
		//End
		
		//Division Factor 128
		case 6 :
		_ADC_ADCSRA = 0xAF ;
		break;
		//End
		
	}
}

void ADC_initWithoutInterrupt(vRef selectionBit, preScaler prescalerValue)
{
	switch(selectionBit)
	{
		//case ARef
		case 0 :
		_ADC_ADMUX = 0x00 ;
		break ;
		//End
		
		//Case AVCC
		case 1 :
		_ADC_ADMUX = 0x40 ;
		break ;
		//End
		
		//Case Reverse
		case 2 :
		_ADC_ADMUX = 0x80 ;
		break ;
		//End
		
		//Case Internal
		case 3 :
		_ADC_ADMUX = 0x90 ;
		break;
		//End
	}
	
		switch(prescalerValue)
		{
			//Division Factor 2
			case 0 :
			_ADC_ADCSRA = 0xA1 ;
			break;
			//End
			
			//Division Factor 4
			case 1 :
			_ADC_ADCSRA = 0xA2 ;
			break;
			//End
			
			//Division Factor 8
			case 2 :
			_ADC_ADCSRA = 0xA3 ;
			break;
			//End
			
			//Division Factor 16
			case 3 :
			_ADC_ADCSRA = 0xA4 ;
			break;
			//End
			
			//Division Factor 32
			case 4 :
			_ADC_ADCSRA = 0xA5 ;
			break;
			//End
			
			//Division Factor 64
			case 5 :
			_ADC_ADCSRA = 0xA6 ;
			break;
			//End
			
			//Division Factor 128
			case 6 :
			_ADC_ADCSRA = 0xA7 ;
			break;
			//End
			
		}
}

uint16_t ADC_Read(channel Channel)
{
	 uint16_t read = 0 ;
	_ADC_ADMUX = 0xF0 ; //clear all channels	
	
	//Selecting Channel
	switch (Channel)
	{
		case ADC_channel_0:
		_ADC_ADMUX = 0x40;//0b 010 00000
		break;
		
		case ADC_channel_1:
		_ADC_ADMUX = 0x41;//0b 010 00001
		
		break;
		case ADC_channel_2:
		_ADC_ADMUX = 0x42;//0b 010 00010
		break;
		
		case ADC_channel_3:
		_ADC_ADMUX = 0x43;//0b 010 00011
		break;
		
		case ADC_channel_4:
		_ADC_ADMUX = 0x44;//0b 010 00100
		break;
		
		case ADC_channel_5:
		_ADC_ADMUX = 0x45;//0b 010 00101
		break;
		
		case ADC_channel_6:
		_ADC_ADMUX = 0x46;//0b 010 00110
		break;
		
		case ADC_channel_7:
		_ADC_ADMUX = 0x47;//0b 0100 0111
		break;
		
		default:
		_ADC_ADMUX = 0x40;
		break;
	}
	//End
	
	//Starting a new conversion
	SET_BIT(_ADC_ADCSRA,ADSC);
	
	//Getting Data
	while (GET_BIT(_ADC_ADCSRA, ADIF) != 1);//ADIF will set after the reading is completed
	
	read = _ADC_DATA;
	
	return read;
}