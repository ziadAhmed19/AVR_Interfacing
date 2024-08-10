/*
 * UART_Program.c
 *
 * Created: 7/8/2024 6:42:22 PM
 *  Author: zizoz
 */ 
#include "UART_Interface.h"

void UART_Initialize(void)
{
	uint16_t UBRR_Val = 0;
	DDRD |= (1<<Tx);//Define direction as output, Transmit
	DDRD &=~(1<<Rx);//Define direction as input, Receive
	UCSRB |= ((1<<RXEN) | (1<<TXEN));//Enable transmit & receive
	UCSRC |= ((1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0));//Choose data length(8-Bits), mode, parity, stop
	UBRR_Val = (((UART_FREQ) / (16 * UART_BAUDRATE)) - 1);//Frequency calculations
	UBRRL = UBRR_Val;
	UBRRH = UBRR_Val >> 8;
}
void UART_Transmit_Character(uint8_t character)
{
	UDR = character;
	while (((UCSRA>>TXC)&0x01) != 1);//Wait until flag of transmitting received
	return;//Termination of transmit function
}
uint8_t UART_Receive_Character(void)
{
	uint8_t character = 0;
	while (((UCSRA>>TXC)&0x01) != 1);//Wait until flag of transmitting received
	character = UDR;
	return character;
}
void UART_Transmit_String(uint8_t* str)
{
	while (*str != '\0')
	{
		UART_Transmit_Character(*str);
		str++;
	}
}
uint8_t* UART_Receive_String (void)
{
	uint8_t characters = 'D';
	uint8_t* str = '\0';
	while (characters != '\0')
	{
		characters = UART_Receive_Character();
		*str += characters;
	}
	return str;
}