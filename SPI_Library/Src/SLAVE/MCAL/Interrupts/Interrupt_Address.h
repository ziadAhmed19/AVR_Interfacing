/*
 * Interrupt_Address.h
 *
 * Created: 5/11/2024 9:49:16 PM
 *  Author: karim
 */ 


#ifndef INTERRUPT_ADDRESS_H_
#define INTERRUPT_ADDRESS_H_

#include "CPU_Configs.h"

#define _INTERRUPT_GICR   (*(volatile uint8_t*)(0x5B))
#define _INTERRUPT_GIFR   (*(volatile uint8_t*)(0x5A))
#define _INTERRUPT_MCUCR  (*(volatile uint8_t*)(0x55))
#define _INTERRUPT_MCUCSR (*(volatile uint8_t*)(0x54))
#define _INTERRUPT_SREG   (*(volatile uint8_t*)(0x5F))

#endif /* INTERRUPT_ADDRESS_H_ */