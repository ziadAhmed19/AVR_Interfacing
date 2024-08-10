/*
 * EEPROM_Interface.h
 *
 * Created: 7/8/2024 7:16:30 PM
 *  Author: zizoz
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#include "EEPROM_Private.h"

void EEPROM_write(uint32_t uiAddress, uint8_t ucData);
uint8_t EEPROM_read(uint32_t uiAddress);


#endif /* EEPROM_INTERFACE_H_ */