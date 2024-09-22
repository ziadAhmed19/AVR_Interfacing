/*
 * Exploring_AVR's.c
 *
 * Created: 7/26/2024 2:59:03 PM
 * Author : zizoz
 */ 

#include "main.h"

/*----------------- Electric Water Heater System -----------------*/

/*----------------- Global Variables ----------------- */
bool_t gState_flag1 = FALSE, gState_flag2 = FALSE;
uint8_t i = 0 ;
uint8_t Desired_Temperature = 60 ;
uint8_t Meaned_Actual_Temperature = 0 ;
uint8_t Actual_Temperature_Matrix[10] = {60,60,60,60,60,60,60,60,60,60};
/*----------------- END ----------------- */
#define EEPROM_ADDRESS 0x01


int main(void)
{
    /*Initialization Function(s)*/
	SEVENSEGMENT_Initialize();
	ADC_init();
	/*External Interrupt Initialization Function(s)*/
	External_Interrupt_Initialization(EXT_INT0,EXT_INTERRUPT_SENSE_FALLING);
	External_Interrupt_Initialization(EXT_INT1,EXT_INTERRUPT_SENSE_FALLING);
	External_Interrupt_Initialization(EXT_INT2,EXT_INTERRUPT_SENSE_FALLING);
	/*Setting Pin(s) Direction(s)*/
	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_INPUT);
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN4,DIO_OUTPUT);//Cooling Element
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN5,DIO_OUTPUT);//Heating Element
	/*Setting Up Initial Value*/
	DIO_SetPinValue(DIO_PORTD,DIO_PIN5,DIO_LOW);
	DIO_SetPinValue(DIO_PORTD,DIO_PIN4,DIO_LOW);
	
	/*Super-Loop*/
		while (1) 
		{
			/*------------------------------ ON-STATE ------------------------------ */
			while (!gState_flag1 && !gState_flag2)
			{
				DIO_SetPinValue(DIO_PORTD,DIO_PIN5,DIO_LOW) ;
				DIO_SetPinValue(DIO_PORTD,DIO_PIN4,DIO_LOW) ;
				SEVENSEGMENT_Display_Number(Desired_Temperature);
			}
			/*------------------------------ END ------------------------------ */
			
			/*------------------------------ OFF-STATE ------------------------------ */
			while (gState_flag1 && gState_flag2)
			{
 					
 				DIO_SetPinValue(DIO_PORTD,DIO_PIN5,DIO_LOW) ;
 				DIO_SetPinValue(DIO_PORTD,DIO_PIN4,DIO_LOW) ;
 				SEVENSEGMENT_Disable();
 				//Temperature Reading every 100ms
 				ADC_start();
 				Timer0_CTC_WithInterrupt_SetDelay(100,250);
				//Water Temperature Calibration 
				 while((eeprom_read_byte((uint8_t*)EEPROM_ADDRESS) > Meaned_Actual_Temperature) && (gState_flag1 && gState_flag2))
				 {
					 //Start Heating
					 DIO_SetPinValue(DIO_PORTD,DIO_PIN4,DIO_LOW);
					 DIO_SetPinValue(DIO_PORTD,DIO_PIN5,DIO_HIGH);
					 //Monitoring the temperature 
					ADC_start();
					Timer0_CTC_WithInterrupt_SetDelay(100,250);
				 }
				 while((eeprom_read_byte((uint8_t*)EEPROM_ADDRESS) < Meaned_Actual_Temperature) && (gState_flag1 && gState_flag2))
				 {
					 //Start Cooling 
					 DIO_SetPinValue(DIO_PORTD,DIO_PIN5,DIO_LOW);
					 DIO_SetPinValue(DIO_PORTD,DIO_PIN4,DIO_HIGH);
					 //Monitoring the temperature
					ADC_start();
					Timer0_CTC_WithInterrupt_SetDelay(100,250);
				 }
				
			}
			/*------------------------------ END ------------------------------ */
		}
}

/*------------------------------ DOWN-BTN ------------------------------ */
ISR(INT0_vect)
{
	if (Desired_Temperature > 35)
	{
		Desired_Temperature-=5;
	}
	else
	{
		//error
	}
}
/*------------------------------ END ------------------------------ */

/*------------------------------ UP-BTN ------------------------------ */
ISR(INT1_vect)
{
	if (Desired_Temperature < 75)
	{
		Desired_Temperature+=5;
	}
	else
	{
		//error
	}
}
/*------------------------------ END ------------------------------ */

/*------------------------------ ON/OFF-BTN ------------------------------ */
ISR(INT2_vect)
{	
	//Toggles between ON and OFF states by XORing the boolean values
	gState_flag1 ^= 1 ;
	gState_flag2 ^= 1;
	if (gState_flag1 && gState_flag2)
	{
		eeprom_write_byte((uint8_t*)EEPROM_ADDRESS, Desired_Temperature);
		_delay_ms(10);
	}	
}
/*------------------------------ END ------------------------------ */

/*------------------------------ LM35-ADC ------------------------------ */
ISR(ADC_vect)
{
	Actual_Temperature_Matrix[i] = ((0.4902 * ADC) - 0.2944 );
	if(i == 9)
 	{
		 Meaned_Actual_Temperature = (Actual_Temperature_Matrix[0]+Actual_Temperature_Matrix[1]+Actual_Temperature_Matrix[3]+Actual_Temperature_Matrix[4]+Actual_Temperature_Matrix[5]+Actual_Temperature_Matrix[6]+Actual_Temperature_Matrix[7]+Actual_Temperature_Matrix[8]+Actual_Temperature_Matrix[9])/10;
	}
	i = (i + 1) % 10  ;
}

/*------------------------------ END ------------------------------ */
