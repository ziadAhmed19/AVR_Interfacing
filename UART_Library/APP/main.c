/*
 * Exploring_AVR's.c
 *
 * Created: 7/26/2024 2:59:03 PM
 * Author : zizoz
 */ 

#include "main.h"


int main(void)
{
    /* Replace with your application code */
	LCD_init();
	uart_init(9600,DISABLE_PARITY,Asynchronous,ONE_BIT,EIGHT_BIT,Falling_XCK_Edge);
	
	uint8_t messsage = "Hello" ;
	uint8_t data ;


    while (1) 
    {
			uart_Transmit(messsage);
			LCD_Write_Location(ROW0,COL0);
			LCD_Write_String("UART TRANSMIT :");
			LCD_Write_Location(ROW1,COL0);
			LCD_Write_String(messsage);
			
			_delay_ms(500);
			LCD_Clear_Screen();
			
			data = uart_Receive();
			LCD_Write_Location(ROW0,COL0);
			LCD_Write_String("UART RECIVE :");
			LCD_Write_Location(ROW1,COL0);
			LCD_Write_String(data);
			
			_delay_ms(500);
			LCD_Clear_Screen();
			uart_Flush();
    }
}

