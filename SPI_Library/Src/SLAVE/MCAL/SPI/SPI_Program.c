/*
 * SPI_Program.c
 *
 * Created: 7/29/2024 4:24:29 PM
 *  Author: zizoz
 */ 
#include "SPI_Interface.h"

/************************************************************************/
/*					  Master Function(s)                                */
/************************************************************************/
void SPI_Master_Init(Data_Order order,SPI_Mode MODE ,SCK_Rate rate, Intrput interput)
{
	//Setting up pin directions
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN4,DIO_OUTPUT);//~SS
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);//MOSI
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN6,DIO_INPUT);//MISO
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);//SCK
	//Control Pins DEMUX
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_OUTPUT);//Control Pin 1
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);//Control Pin 2
	//Master Mode
	SET_BIT(SPCR,MSTR);
	//Enabling SPI
	SET_BIT(SPCR,SPE);
	//Selecting data order transmission
	switch(order)
	{
		case MSB : CLR_BIT(SPCR,DORD);
		break;
		
		case LSB : SET_BIT(SPCR,DORD);
		break;
	} 
	//Selecting SPI's Mode of operation
	switch(MODE)
	{	//You can directly write the number of the mode of if u r uncertain 
		//you can manually write down the Leading and Trailing Edges 
		//polarity and phase
		case LeadingEdge_Sample_Rising_TrailingEdge_Setup_Falling :
		CLR_BIT(SPCR,CPOL);CLR_BIT(SPCR,CPHA);
		break;
		
		case LeadingEdge_Setup_Rising_TrailingEdge_Sample_Falling :
		CLR_BIT(SPCR,CPOL);SET_BIT(SPCR,CPHA);
		break; 
		
		case LeadingEdge_Sample_Falling_TrailingEdge_Setup_Rising : 
		SET_BIT(SPCR,CPOL);CLR_BIT(SPCR,CPHA);
		break;
		
		case LeadingEdge_Setup_Falling_TrailingEdge_Sample_Rising :
		SET_BIT(SPCR,CPOL);SET_BIT(SPCR,CPHA);
		break; 
	}
	//Selecting SCK Rate
	switch(rate)
	{
		/*Normal Speeds*/
		case Fosc_4 : CLR_BIT(SPCR,SPR0);CLR_BIT(SPCR,SPR1);CLR_BIT(SPSR,SPI2X);
		break;
		
		case Fosc_16 : SET_BIT(SPCR,SPR0);CLR_BIT(SPCR,SPR1);CLR_BIT(SPSR,SPI2X);
		break;		
		
		case Fosc_64 : CLR_BIT(SPCR,SPR0);SET_BIT(SPCR,SPR1);CLR_BIT(SPSR,SPI2X);
		break;
		
		case Fosc_128 : SET_BIT(SPCR,SPR0);SET_BIT(SPCR,SPR1);CLR_BIT(SPSR,SPI2X);
		break;
		/*Doubled Speeds*/
		case DS_Fosc_2 : CLR_BIT(SPCR,SPR0);CLR_BIT(SPCR,SPR1);SET_BIT(SPSR,SPI2X);
		break;
		
		case DS_Fosc_8 : SET_BIT(SPCR,SPR0);CLR_BIT(SPCR,SPR1);SET_BIT(SPSR,SPI2X);
		break;
		
		case DS_Fosc_32 : CLR_BIT(SPCR,SPR0);SET_BIT(SPCR,SPR1);SET_BIT(SPSR,SPI2X);
		break;
		
		case DS_Fosc_64 : SET_BIT(SPCR,SPR0);SET_BIT(SPCR,SPR1);SET_BIT(SPSR,SPI2X);
		break;
	}
	
		switch(interput)
		{
			case Interruput_Enabled : SET_BIT(SPCR,SPIE);sei();
			break;
			
			case Interruput_Disabled : CLR_BIT(SPCR,SPIE);
			break;
		}
	//In case of wanting more control over the SCK's Polarity or/and Phase
	/*
	//Selecting SCK polarity
	switch(polarity)
	{
		case LeadingEdge_Rising_TrailingEdge_Falling :
		CLR_BIT(SPCR,CPOL);
		break;
		
		case LeadingEdge_Falling_TrailingEdge_Rising :
		SET_BIT(SPCR,CPOL);
		break;
	}
	//Selecting SCK Phase
	switch(phase)
	{
		case LeadingEdge_Sample_TrailingEdge_Setup :
		CLR_BIT(SPCR,CPHA);
		break;
		
		case LeadingEdge_Setup_TrailingEdge_Sample :
		SET_BIT(SPCR,CPHA);
		break;
	}
	*/	
}

void SPI_Master_SS(SlaveAddress Address, Selection_State state)
{
	switch(state)
	{
		case Select :
			switch(Address)
			{
				case Slave_One :
				//DIO_SetPinValue(DIO_PORTB, DIO_PIN2, DIO_LOW);
				//DIO_SetPinValue(DIO_PORTB, DIO_PIN3, DIO_LOW);
				//Pulling ~SS low
				DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_LOW);
				break;
				
				case Slave_Two :
				//DIO_SetPinValue(DIO_PORTB, DIO_PIN2, DIO_HIGH);
				//DIO_SetPinValue(DIO_PORTB, DIO_PIN3, DIO_LOW);
				//Pulling ~SS low
				DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_LOW);
				break;
			}
		break;
		
		case DeSelect :
			switch(Address)
			{
				case Slave_One :
				DIO_SetPinValue(DIO_PORTB, DIO_PIN2, DIO_LOW);
				DIO_SetPinValue(DIO_PORTB, DIO_PIN3, DIO_LOW);
				//Pulling ~SS low
				DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_HIGH);
				break;
				
				case Slave_Two :
				DIO_SetPinValue(DIO_PORTB, DIO_PIN2, DIO_HIGH);
				DIO_SetPinValue(DIO_PORTB, DIO_PIN3, DIO_LOW);
				//Pulling ~SS low
				DIO_SetPinValue(DIO_PORTB, DIO_PIN4, DIO_HIGH);

				break;
			}
		break;
	}
}

void SPI_Master_Transmit(uint8_t data)
{
	
	/* Start transmission */
	SPDR = data;
	/* Wait for transmission complete */
	while((!(SPSR & (1<<SPIF))) && GET_BIT(SPSR,WCOL))
	;
}

void SPI_Master_Transmit_String(uint8_t* string)
{
	while(*string != '\0')
	{
		SPI_Master_Transmit(*string);
		string++;
	}
}

uint8_t SPI_Master_Receive()
{
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)))
	;
	/* Return data register */
	return SPDR;
}

/************************************************************************/
/*					  Slave Function(s)                                 */
/************************************************************************/
void SPI_Slave_Init(Data_Order order, Intrput interput)
{
	//Setting up pin directions
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN4,DIO_INPUT);//~SS
	
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN5,DIO_INPUT);//MOSI
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN6,DIO_OUTPUT);//MISO
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN7,DIO_INPUT);//SCK	
	//Slave Mode
	CLR_BIT(SPCR,MSTR);
	//Enabling SPI
	SET_BIT(SPCR,SPE);
	//Selecting data order transmission
	switch(order)
	{
		case MSB : CLR_BIT(SPCR,DORD);
		break;
		
		case LSB : SET_BIT(SPCR,DORD);
		break;
	}
	
	switch(interput)
	{
		case Interruput_Enabled : SET_BIT(SPCR,SPIE);sei();
		break;
		
		case Interruput_Disabled : CLR_BIT(SPCR,SPIE);
		break;
		}
	//In case of wanting more control over the SCK's Polarity or/and Phase
	/*
	//Selecting SCK polarity
	switch(polarity)
	{
		case LeadingEdge_Rising_TrailingEdge_Falling :
		CLR_BIT(SPCR,CPOL);
		break;
		
		case LeadingEdge_Falling_TrailingEdge_Rising :
		SET_BIT(SPCR,CPOL);
		break;
	}
	//Selecting SCK Phase
	switch(phase)
	{
		case LeadingEdge_Sample_TrailingEdge_Setup :
		CLR_BIT(SPCR,CPHA);
		break;
		
		case LeadingEdge_Setup_TrailingEdge_Sample :
		SET_BIT(SPCR,CPHA);
		break;
	}
	*/
}

uint8_t SPI_SLave_Receive()
{
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)))
	;
	/* Return data register */
	return SPDR;
}

void SPI_Slave_Transmit(uint8_t data)
{
	/* Start transmission */
	SPDR = data;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	;
}

void SPI_Slave_Transmit_String(uint8_t* string)
{
	while(*string != '\0')
	{
		SPI_Slave_Transmit(*string);
		string++;
	}
}