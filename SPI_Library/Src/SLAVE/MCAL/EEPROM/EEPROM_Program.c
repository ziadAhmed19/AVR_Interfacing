/*
 * EEPROM_Program.c
 *
 * Created: 7/8/2024 7:16:42 PM
 *  Author: zizoz
 */ 
#include "EEPROM_Interface.h"

void EEPROM_write(uint32_t uiAddress, uint8_t ucData)
{
		/* Wait for completion of previous write */
		while(EECR & (1<<EEWE))
		;
		/* Set up address and data registers */
		EEAR = uiAddress;
		EEDR = ucData;
		/* Write logical one to EEMWE */
		EECR |= (1<<EEMWE);
		/* Start eeprom write by setting EEWE */
		EECR |= (1<<EEWE);
}

uint8_t EEPROM_read(uint32_t uiAddress)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}
