#include "main.h"



int main(void)
{
	/* Initialization Phase */
	ADC_initWithoutInterrupt(AVCC,prescaler_128);
	LCD_init();
	
	uint16_t val = 0 ;
	
	LCD_Write_Location(ROW0,COL0);
	LCD_Write_String("POT Value :");
	//Analog Reading
	while (1)
	{
		_delay_ms(10);
		val = ADC_Read(ADC_channel_1);
		
		
		LCD_Write_Location(ROW1,COL0);
		LCD_Write_IntegerNumber(val);
	}
}


