#include "main.h"

bool_t screen_flag00 = FALSE ;
bool_t screen_flag01 = FALSE ;

int main(void)
{	
	/* Initialization Phase */
	LCD_init();
 	External_Interrupt_Initialization(EXT_INT0, EXT_INTERRUPT_SENSE_FALLING);
 	External_Interrupt_Initialization(EXT_INT1, EXT_INTERRUPT_SENSE_FALLING);	
 	External_Interrupt_Initialization(EXT_INT2, EXT_INTERRUPT_SENSE_RISING);

	/* Setting Up Buttons */
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN7,DIO_INPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN5,DIO_INPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN6,DIO_INPUT);

	while (1)
	{
/*---------------------- Home ----------------------*/
		if(screen_flag00 == 0 && screen_flag01 == 0)
		{
			LCD_Clear_Screen();
			while (screen_flag00 == 0 && screen_flag01 == 0)
			{
				//Display

			LCD_Write_Location(ROW0,COL2);
			LCD_Write_String((uint8_t*)"Home Screen");
			
			LCD_Write_Location(ROW1,COL0);
			LCD_Write_String((uint8_t*)"1)TMR");
			
			
			LCD_Write_Location(ROW1,COL11);
			LCD_Write_String((uint8_t*)"2)SW");
			}
		}
/*---------------------- Timer ----------------------*/
	else if (screen_flag00 == 0 && screen_flag01 == 1)
	{
		//Display
		LCD_Clear_Screen();
		uint8_t num  = 0 ; 
		while(screen_flag00 == 0 && screen_flag01 == 1)
		{
			LCD_Write_Location(ROW0,COL2);
			LCD_Write_String((uint8_t*)"TMR Screen");
			
			
			//selection phase 
			while( DIO_GetPinValue(DIO_PORTC,DIO_PIN5) == 0)
			{
				LCD_Write_Location(ROW0,COL2);
				LCD_Write_String((uint8_t*)"TMR Screen");
				
				LCD_Write_Location(ROW1,COL0);
				LCD_Write_IntegerNumber((uint32_t*)num);
				
				if (DIO_GetPinValue(DIO_PORTC,DIO_PIN6))
				{
					LCD_Clear_Screen();
					num-- ;
				}
				else if (DIO_GetPinValue(DIO_PORTC,DIO_PIN7))
				{
					LCD_Clear_Screen();
					num++ ;				
				}
			}
			//processing phase
			while(num != 0)
			{
				LCD_Clear_Screen();
				LCD_Write_Location(ROW0,COL2);
				LCD_Write_String((uint8_t*)"TMR Screen");
				LCD_Write_Location(ROW1,COL0);
				LCD_Write_IntegerNumber(num);
				_delay_ms(1000);
				num--;
			}
			//Return to home
			screen_flag00 = 0 ;
			screen_flag01 = 0 ;
		}
	}
/*---------------------- StopWatch ----------------------*/
	else if (screen_flag00 == 1 && screen_flag01 == 0)
	{
		//Display
		LCD_Clear_Screen();
		bool_t stopwatch_flag = FALSE ;
		uint8_t cntr = 0 ;
		
		LCD_Write_Location(ROW0,COL3);
		LCD_Write_String((uint8_t*)"SW Screen");
		LCD_Write_Location(ROW1,COL0);
		LCD_Write_IntegerNumber(cntr);
		
		while (screen_flag00 == 1 && screen_flag01 == 0)
		{
							if ( DIO_GetPinValue(DIO_PORTC,DIO_PIN7) )
							{
								stopwatch_flag = FALSE ;
							}
							
							if (DIO_GetPinValue(DIO_PORTC,DIO_PIN6))
							{
								stopwatch_flag = TRUE ;
							}
							
							if (DIO_GetPinValue(DIO_PORTC,DIO_PIN5))
							{
								screen_flag00 = FALSE;
								screen_flag01 = FALSE;
							}
			while (stopwatch_flag == TRUE)
			{
				cntr++;
				LCD_Write_Location(ROW1,COL0);
				LCD_Write_IntegerNumber(cntr);
							if (DIO_GetPinValue(DIO_PORTC,DIO_PIN7))
							{
								stopwatch_flag = FALSE ;
							}
							
							if (DIO_GetPinValue(DIO_PORTC,DIO_PIN5))
							{
								screen_flag00 = FALSE;
								screen_flag01 = FALSE;
							}
							_delay_ms(1000);
			}
		}
	}
	
	
	
  }
}


/*---------------------- Timer ----------------------*/
ISR(INT0_vect)
{
		screen_flag00 = FALSE ;
	    screen_flag01 = TRUE  ;
}
/*---------------------- StopWatch ----------------------*/
ISR(INT1_vect)
{
		screen_flag00 = TRUE  ;
		screen_flag01 = FALSE ;		
}
/*---------------------- Home ----------------------*/
ISR(INT2_vect)
{
		screen_flag00 = FALSE ;
		screen_flag01 = FALSE ;	
}