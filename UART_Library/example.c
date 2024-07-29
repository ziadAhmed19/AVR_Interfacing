/*
 * Exploring_AVR's.c
 *
 * Created: 7/26/2024 2:59:03 PM
 * Author : zizoz
 */ 

#include "main.h"


int main(void)
{
    /*Initialization Function(s)*/
	
	/*
	* 1- Setting BaudRate to 9600
	* 2- Disabling Double Speed
	* 3- Disabling Parity
	* 4- Setting up Asynchronous UART
	* 5- Setting Stop bit(s) to 1 bit
	* 6- Setting Data bits to 8 bits
	* 7- ! Clock Polarity is Synchronous mode only ! Write this bit to zero since Asynchronous is selected 
	*							Rising_XCK_Edge = 0 , Falling_XCK_Edge = 1
	*/
	
	uart_init(BAUD_9600,FALSE, DISABLE_PARITY,Asynchronous,ONE_BIT,EIGHT_BIT,Rising_XCK_Edge);
	LCD_init();

    while (1) 
    {
		/*Writing To Serial Monitor*/
		uart_Transmit_String((uint8_t*)"Hello World...");
		_delay_ms(500);
    }
}

