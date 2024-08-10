/*
 * UART_Program.c
 *
 * Created: 7/26/2024 5:15:57 PM
 *  Author: zizoz
 */ 

#include "UART_Interface.h"

void uart_init(BaudRate BAUD, Double_Speed speed, Parity parity, Mode_Of_Operation mod, Stop_Bit bit, Data_Size packet_size, Clock_Polarity polarity)
{
	/* Selecting Baud Rate and Speed */
	uint16_t baud ;
	switch(speed)
	{
		case FALSE :  CLR_BIT(UCSRA,U2X); //Disabling Double Speed
		
		switch(BAUD)
		{
			case BAUD_2400 : baud = 416 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_4800 : baud = 207 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_9600 : baud = 103 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_14400 : baud = 68 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break ;
			
			case BAUD_19200 : baud = 51 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_28800 : baud = 34 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_38400 : baud = 25 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break; 
			
			case BAUD_57600 : baud = 16 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break ;
			
			case BAUD_76800 : baud = 12 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_115200 : baud = 8 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break; 
			
			case BAUD_230400 : baud = 3 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break; 
			
			case BAUD_250000 : baud = 3 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_500k : baud = 1 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_1M : baud = 0 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;			
		}
		break;
		
		case TRUE : SET_BIT(UCSRA,U2X); //Enabling Double Speed
		switch(BAUD)
		{
			case BAUD_2400 : baud = 832 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_4800 : baud = 416 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_9600 : baud = 207 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_14400 : baud = 138 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break ;
			
			case BAUD_19200 : baud = 103 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_28800 : baud = 68 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_38400 : baud = 51 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_57600 : baud = 34 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break ;
			
			case BAUD_76800 : baud = 25 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_115200 : baud = 16 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_230400 : baud = 8 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_250000 : baud = 7 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
			
			case BAUD_500k : baud = 3 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break; 
			
			case BAUD_1M : baud = 1 ;
			UBRRH = (uint8_t)(baud>>8);
			UBRRL = (uint8_t)baud;
			break;
		}
		break;
	}
	
		

 	/* Enable receiver and transmitter */
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/*Selecting Parity*/
	switch(parity)
	{
		case EVEN_PARITY : CLR_BIT(UCSRC,UPM0); SET_BIT(UCSRC,UPM1);
		break; 
		
		case ODD_PARITY : SET_BIT(UCSRC,UPM0); SET_BIT(UCSRC,UPM1); 
		break;
		
		case DISABLE_PARITY : CLR_BIT(UCSRC,UPM0); CLR_BIT(UCSRC,UPM1);
		break;
	}
	/*Selecting mode of operation*/
	switch(mod)
	{
		case Asynchronous : CLR_BIT(UCSRC,UMSEL);
		break;
		
		case Synchronous : SET_BIT(UCSRC,UMSEL);
		break;
	}
	/*Selecting Stop Bits*/
	switch(bit)
	{
		case ONE_BIT : CLR_BIT(UCSRC,USBS);
		break;
		
		case TWO_BIT : SET_BIT(UCSRC,USBS);
		break;
	}
	/*Selecting packet size*/
	switch(packet_size)
	{
		case FIVE_BIT : CLR_BIT(UCSRC,UCSZ0);CLR_BIT(UCSRC,UCSZ1);CLR_BIT(UCSRC,UCSZ2);
		break;
		
		case SIX_BIT : SET_BIT(UCSRC,UCSZ0);CLR_BIT(UCSRC,UCSZ1);CLR_BIT(UCSRC,UCSZ2);
		break;
		
		case SEVEN_BIT : CLR_BIT(UCSRC,UCSZ0);SET_BIT(UCSRC,UCSZ1);CLR_BIT(UCSRC,UCSZ2);
		break;
		
		case EIGHT_BIT : SET_BIT(UCSRC,UCSZ0);SET_BIT(UCSRC,UCSZ1);CLR_BIT(UCSRC,UCSZ2);
		break;
		
		case NINE_BIT : SET_BIT(UCSRC,UCSZ0);SET_BIT(UCSRC,UCSZ1);SET_BIT(UCSRC,UCSZ2);
		break;
	}
	/*Selecting CLK polarity with respect to TX*/
	switch(polarity)
	{
	case Rising_XCK_Edge : CLR_BIT(UCSRC,UCPOL);
	break;
	
	case Falling_XCK_Edge : SET_BIT(UCSRC,UCPOL);
	break;
	}
		
}

void uart_Transmit(uint8_t data)
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE)) )
	;
	/* Put data into buffer, sends the data */
	UDR = data;
}

void uart_Transmit_String(uint8_t* string)
{
	while (*string != '\0')
	{
		uart_Transmit(*string);
		string++;
	}
}

void uart_Transmit_Plus(uint8_t data)
{
	/* Wait for empty transmit buffer */
	while ( !( UCSRA & (1<<UDRE))) 
	;
	/* Copy 9th bit to TXB8 */
	UCSRB &= ~(1<<TXB8);
	if ( data & 0x0100 )
	UCSRB |= (1<<TXB8);
	/* Put data into buffer, sends the data */
	UDR = data;
}

uint8_t uart_Receive(void)
{
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get and return received data from buffer */
	return UDR;
}

uint8_t uart_Receive_Plus(void)
{
	uint8_t  resh, resl;
	/* Wait for data to be received */
	while ( !(UCSRA & (1<<RXC)) )
	;
	/* Get status and 9th bit, then data */
	/* from buffer */
	resh = UCSRB;
	resl = UDR;
	/* Filter the 9th bit, then return */
	resh = (resh >> 1) & 0x01;
	return ((resh << 8) | resl);
}

void uart_Flush(void)
{
	uint8_t dummy = 0x00;
	while ( UCSRA & (1<<RXC) ) dummy = UDR;
}