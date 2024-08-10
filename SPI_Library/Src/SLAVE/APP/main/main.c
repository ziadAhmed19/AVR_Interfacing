/*
 * Exploring_AVR's.c
 *
 * Created: 7/26/2024 2:59:03 PM
 * Author : zizoz
 */ 

#include "main.h"

uint8_t data = 0 ;

int main(void)
{	
	/* Initialization Phase */
	LCD_init();
	SPI_Slave_Init(MSB, Interruput_Enabled);
	
	while (1)
	{
		/*Slave Code*/
		LCD_Write_String((uint8_t*)"Device Passive...");
		_delay_ms(1000);
		LCD_Clear_Screen();
		
	}
}

ISR(SPI_STC_vect)
{
	data = SPI_SLave_Receive();	
	LCD_Clear_Screen();
	LCD_Write_String((uint8_t*)"Slv RX :");
	LCD_Write_Location(ROW1,COL0);
	LCD_Write_Character(data);

}

