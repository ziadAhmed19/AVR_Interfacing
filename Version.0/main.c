#include "main.h"

BUTTON2_reading button = BTN2_PRESSED ; //pulling to high

int main(void)
{	
	
	/* Initialization Phase */
	LED0_init();
	LED1_init();
	LED2_init();
	LCD_init();
	BUTTON1_init();
	BUTTON2_init();
	
	//interrupt initialization
	External_Interrupt_Initialization(EXT_INT0, EXT_INTERRUPT_SENSE_FALLING);
	External_Interrupt_Initialization(EXT_INT1, EXT_INTERRUPT_SENSE_RISING);
	uint32_t counter = 0 ;
	//end
	
	//functions init
	LED0_OFF();
	LED1_OFF();
	LED2_OFF();
	
	//app
	while (1)
	{
		if(counter == 3)
		{
			LED2_TGL();
			counter = 0 ;
		}
		
		LED0_ON();
		LCD_Write_String("LED0 ON");
		_delay_ms(1000);
		LED0_OFF();
		LCD_Clear_Screen();
		
		LED1_ON();
		LCD_Write_String("LED1 ON");
		_delay_ms(1000);
		LED1_OFF();
		LCD_Clear_Screen();
		
		counter++ ;
		
	}
}


//Interrupt for
ISR(INT0_vect)
{

	LCD_Clear_Screen();
	LCD_Write_Location(ROW0,COL0);
	LCD_Write_String("Error 1");
	_delay_ms(2000);

}

ISR(INT1_vect)
{
	LCD_Clear_Screen();
	LCD_Write_Location(ROW0,COL0);
	LCD_Write_String("Error 2");
	_delay_ms(2000);
	LED2_OFF();
	LCD_Clear_Screen();
}