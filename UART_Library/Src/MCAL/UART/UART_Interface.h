/*
 * UART_Interface.h
 *
 * Created: 7/26/2024 5:15:47 PM
 *  Author: zizoz
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "UART_Private.h"

/************************************************************************/
/*					Initialization Function(s)                          */
/************************************************************************/
void uart_init(BaudRate BAUD, Double_Speed speed, Parity parity, Mode_Of_Operation mod, Stop_Bit bit, Data_Size packet_size, Clock_Polarity polarity);
/************************************************************************/
/*					Transmission Function(s)                            */
/************************************************************************/
void uart_Transmit(uint8_t data);
void uart_Transmit_String(uint8_t* string);
void uart_Transmit_Plus(uint8_t data);
/************************************************************************/
/*					Reception Function(s)                               */
/************************************************************************/
uint8_t uart_Receive(void);
uint8_t uart_Receive_Plus(void);
/************************************************************************/
/*					Flush Function(s)	                                */
/************************************************************************/
void uart_Flush(void);


#endif /* UART_INTERFACE_H_ */