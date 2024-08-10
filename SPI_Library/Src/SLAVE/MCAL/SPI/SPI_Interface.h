/*
 * SPI_Interface.h
 *
 * Created: 7/29/2024 4:24:11 PM
 *  Author: zizoz
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "SPI_Private.h"
/************************************************************************/
/*					  Master Function(s)                                */
/************************************************************************/
void SPI_Master_Init(Data_Order order,SPI_Mode MODE ,SCK_Rate rate, Intrput interput);
void SPI_Master_SS(SlaveAddress Address, Selection_State state);
void SPI_Master_Transmit(uint8_t data);
void SPI_Master_Transmit_String(uint8_t* string);
uint8_t SPI_Master_Receive();
/************************************************************************/
/*					  Slave Function(s)                                 */
/************************************************************************/
void SPI_Slave_Init(Data_Order order, Intrput interput);
void SPI_Slave_Transmit(uint8_t data);
void SPI_Slave_Transmit_String(uint8_t* string);
uint8_t SPI_SLave_Receive();
uint8_t* SPI_SLave_Receive_String();

#endif /* SPI_INTERFACE_H_ */