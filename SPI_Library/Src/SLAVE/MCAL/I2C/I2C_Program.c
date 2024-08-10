/*
 * I2C_Program.c
 *
 * Created: 7/7/2024 12:16:27 PM
 *  Author: zizoz
 */ 
#include "I2C_Interface.h"

void I2C_Init(I2C_Prescaler prescaler)
{
	TWBR = 0x12 ;
		
	switch(prescaler)
	{
		case Prescaler_1 : // SCL = 100KHz
		CLR_BIT(TWSR,TWPS0);
		CLR_BIT(TWSR,TWPS1);	
		break;
		
		case Prescaler_4 :
		SET_BIT(TWSR,TWPS0);
		CLR_BIT(TWSR,TWPS1);
		break;
		
		case Prescaler_16 :
		CLR_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);
		break;
		
		case Prescaler_64 :
		SET_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);
		break ;
		
		default:
		CLR_BIT(TWSR,TWPS0);
		CLR_BIT(TWSR,TWPS1);		
		break;		
	}
	
	
}

void I2C_Start()
{	
	/*
	* 1- Set the TWINT bit to be clear by hardware once a task is done
	* 2- Set the TWSTA to start the START Condition
	* 3- Enable Two Wire communication
	*/
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN) ;

	/*
	* Waits Until TWINT Flag is Cleared by hardware
	*/
	
	while (!(TWCR & (1<<TWINT)))
	;
}

void I2C_Send(uint8_t data)
{	
	/*
	* 1- Put the desired data in the Data register 
	* 2- Set the TWINT bit to be clear by hardware once a task is done
	* 3- Enable Two Wire communication
	*/
	TWDR = data ;
	TWCR = (1<<TWINT) | (1<<TWEN);	
	
	/*
	* Waits Until TWINT Flag is Cleared by hardware
	*/
		while (!(TWCR & (1<<TWINT)))
		;
}

void I2C_Send_Address(uint8_t slaveAddress, RW_Bit rw)
{
	
	slaveAddress = slaveAddress << 1 ;
	switch(rw)
	{
		case Read :
		SET_BIT(slaveAddress,0);
		TWDR = slaveAddress ;	
		break;
		
		case Write :
		CLR_BIT(slaveAddress,0);
		TWDR = slaveAddress ;
		break;
		
		default://Write
		CLR_BIT(slaveAddress,0);
		TWDR = slaveAddress ;
		break;	
	}
	
	/*
	* Waits Until TWINT Flag is Cleared by hardware
	*/
		while (!(TWCR & (1<<TWINT)))
		;
}

void I2C_Stop()
{
	/*
	* 1- Set the TWINT bit to be clear by hardware once a task is done
	* 2- Set the TWSTO to start the STOP Condition
	* 3- Enable Two Wire communication
	*/
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	
}

void I2C_ACK()
{

	/*
	* 1- Set the TWINT bit to be clear by hardware once a task is done
	* 2- Set the TWEA to Enable Acknowledge Bit
	* 3- Enable Two Wire communication
	*/
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	
	
	/*
	* Waits Until TWINT Flag is Cleared by hardware
	*/
		while (!(TWCR & (1<<TWINT)))
		;
}

uint8_t I2C_Recive_ACK()
{
	
	/*
	* 1- Set the TWINT bit to be clear by hardware once a task is done
	* 2- Set the TWEA to Enable Acknowledge Bit
	* 3- Enable Two Wire communication
	* 4- wait until TWINT Flag was cleared by hardware 
	* 5- return received data
	*/
	
	uint8_t Rdata = 0 ; 
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while (!(TWCR & (1<<TWINT)))
	;
	Rdata = TWDR ;
	
	return Rdata ;

}
