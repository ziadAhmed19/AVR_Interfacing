/*
 * Exploring_AVR's.c
 *
 * Created: 7/26/2024 2:59:03 PM
 * Author : zizoz
 */ 

#include "main.h"

	uint8_t data = 'H' ;

int main(void)
{
    /*Initialization Function(s)*/
	SPI_Master_Init(MSB,LeadingEdge_Sample_Rising_TrailingEdge_Setup_Falling,Fosc_128,Interruput_Enabled);
	LCD_init();		
	
	/*Super-Loop*/
		while (1) 
		{	
			/*Master Code*/
			LCD_Clear_Screen();
			LCD_Write_String((uint8_t*)"Selecting Slv..");
			_delay_ms(500);
			
			SPI_Master_SS(Slave_One,Select);
			SPI_Master_Transmit(data);
			_delay_ms(500);
			SPI_Master_SS(Slave_One,DeSelect);
					
		}
}

ISR(SPI_STC_vect)
{
	LCD_Clear_Screen();
	LCD_Write_String((uint8_t*)"Master TX :");
	LCD_Write_Location(ROW1,COL0);
	LCD_Write_Character(data);
	data++;
}