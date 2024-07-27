/*
 * UART_Interface.h
 *
 * Created: 7/26/2024 5:15:47 PM
 *  Author: zizoz
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "UART_Private.h"

void uart_init(uint32_t BAUD, Parity parity, Mode_Of_Operation mod, Stop_Bit bit, Data_Size packet_size, Clock_Polarity polarity);

void uart_Transmit(uint8_t data);

void uart_Transmit_Plus(uint8_t data);

uint8_t uart_Receive(void);

uint8_t uart_Receive_Plus(void);

void uart_Flush(void);


#endif /* UART_INTERFACE_H_ */