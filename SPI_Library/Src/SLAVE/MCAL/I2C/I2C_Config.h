/*
 * I2C_Config.h
 *
 * Created: 7/7/2024 12:15:39 PM
 *  Author: zizoz
 */ 


#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_

#include "CPU_Configs.h"
#include "Periphrials.h"

typedef enum {
	Prescaler_1 =  0,
	Prescaler_4 =  1,
	Prescaler_16 = 2,
	Prescaler_64 = 3,
	}I2C_Prescaler;

typedef enum {
	Read = 1,
	Write = 0
	}RW_Bit;

#endif /* I2C_CONFIG_H_ */