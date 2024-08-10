/*
 * I2C_Interface.h
 *
 * Created: 7/7/2024 12:15:58 PM
 *  Author: zizoz
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include "I2C_Private.h"

void I2C_Init(I2C_Prescaler prescaler);
void I2C_Start();
void I2C_Send(uint8_t data);

void I2C_Stop();
void I2C_ACK();
uint8_t I2C_Recive_ACK();

bool_t I2C_Check_TWINTflag();
void I2C_Send_Address(uint8_t slaveAddress, RW_Bit rw);

#endif /* I2C_INTERFACE_H_ */