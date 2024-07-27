/*
* CFile1.c
*
* Created: 5/11/2024 1:19:19 PM
*  Author: zizoz
*/

#include "LCD_Interface.h"

/*Private Functions*/

void reverse(char* str, int len)
{
	int i = 0, j = len - 1, temp;
	while (i < j) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}
int intToStr(int x, char str[], int d)
{
	int i = 0;
	while (x) {
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	
	// If number of digits required is more, then
	// add 0s at the beginning
	while (i < d)
	str[i++] = '0';
	
	reverse(str, i);
	str[i] = '\0';
	return i;
}
void ftoa(float n, char* res, int afterpoint)
{
	// Extract integer part
	int ipart = (int)n;
	
	// Extract floating part
	float fpart = n - (float)ipart;
	
	// convert integer part to string
	int i = intToStr(ipart, res, 0);
	
	// check for display option after point
	if (afterpoint != 0) {
		res[i] = '.'; // add dot
		
		// Get the value of fraction part up to given no.
		// of points after dot. The third parameter
		// is needed to handle cases like 233.007
		fpart = fpart * pow(10, afterpoint);
		
		intToStr((int)fpart, res + i + 1, afterpoint);
	}
}

/*End*/


void LCD_init(void){
// 	//Setting up data pins
// 	DIO_SetPinDirection(LCD_DATA_PORT, LCD_DATA_D4, LCD_OUTPUT);
// 	DIO_SetPinDirection(LCD_DATA_PORT, LCD_DATA_D5, LCD_OUTPUT);
// 	DIO_SetPinDirection(LCD_DATA_PORT, LCD_DATA_D6, LCD_OUTPUT);
// 	DIO_SetPinDirection(LCD_DATA_PORT, LCD_DATA_D7, LCD_OUTPUT);
	//End
	
	//Setting up control pins
	DIO_SetPinDirection(LCD_CONTROL_PORT, LCD_CONTROL_RS, LCD_OUTPUT);
	DIO_SetPinDirection(LCD_CONTROL_PORT, LCD_CONTROL_RW, LCD_OUTPUT);
	DIO_SetPinDirection(LCD_CONTROL_PORT, LCD_CONTROL_EN, LCD_OUTPUT);
	
	LCD_Write_Command(0x33);
	LCD_Write_Command(0x32);
	LCD_Write_Command(0x28);
	LCD_Write_Command(0x01);//Clear Screen
	LCD_Write_Command(0x02);//Return home
	LCD_Write_Command(0x06);//Shift cursor right
	LCD_Write_Command(0x0C);//Display On, Cursor Off
	
	_delay_ms(2);
}

void LCD_Write_Command(uint8_t command){
	
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_RS, LCD_LOW);//command code register
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_RW, LCD_LOW);// Writing
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_EN, LCD_LOW);//Disable the LCD
	
	//Sending High Nibble
	//LCD_i2c_Send( (command & 0xF0) );
	LCD_PORT = (command & 0xF0) ;
	
	//High to Low Pulse
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_EN, LCD_LOW);
	
	//Sending Low Nibble
	//LCD_i2c_Send( ((command & 0x0F) << 4) );
	LCD_PORT = ((command & 0x0F) << 4);
	
	//High to Low Pulse
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_EN, LCD_LOW);
	
	//delay
	_delay_ms(1);
}

void LCD_Clear_Screen(){
	LCD_Write_Command(0x01);
}

void LCD_Write_Character(uint8_t character)
{
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_RS, LCD_HIGH);//selecting data register
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_EN, LCD_LOW);//disable LCD
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_RW, LCD_LOW);//write mode
	
	//put the data on data pins
	
	//sending high nibble
	//LCD_i2c_Send( (character & 0xF0) );
	LCD_PORT = (character & 0xF0);
	
	//sending high to low pulse
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_EN, LCD_LOW);
	
	//sending low nibble
	//LCD_i2c_Send( (character & 0x0F) << 4 );
	LCD_PORT = ((character & 0x0F) << 4);
	
	//sending high to low pulse
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_EN, LCD_HIGH);
	_delay_ms(1);
	DIO_SetPinValue(LCD_CONTROL_PORT, LCD_CONTROL_EN, LCD_LOW);
	
	//shifting cursor to the right
	//LCD_Write_Command(0x14);
	
	//delay
	_delay_us(100);
}

void LCD_Write_String(uint8_t* string)
{
	while(*string != '\0'){
		LCD_Write_Character(*string);
		string++;
	}
}

void LCD_Write_IntegerNumber(uint32_t IntNumber)
{
	char INTtoSTR[10];
	ltoa(IntNumber, INTtoSTR, 10);//Long to Ascii
	LCD_Write_String((uint32_t*)INTtoSTR);
}

void LCD_Write_FloatNumber(uint64_t FltNumber)
{
	char FLOATtoSTR[10] ;
	ftoa(FltNumber, FLOATtoSTR, 3);
	LCD_Write_String((uint64_t*)FLOATtoSTR);
}

void LCD_Write_Location(row Rows, column Columns)
{
	switch(Rows)
	{
		/*---------------------------- ROW 0 ----------------------------*/
		case ROW0 :
		LCD_Write_Command( (0x80 + Columns) );//force cursor to the beginning of the 1st line
		break ;
		/*---------------------------- End ----------------------------*/
		
		/*---------------------------- ROW 1 ----------------------------*/
		case ROW1 :
		LCD_Write_Command( (0xC0 + Columns ) );//force cursor to the beginning of the 2nd line
		break ;
		/*---------------------------- End ----------------------------*/
		
		/*---------------------------- Default ----------------------------*/
		default: LCD_Write_String("Invalid Entry...");
		break ;
		/*---------------------------- End ----------------------------*/
	}
	
}

void LCD_Write_SpecialCharacter(uint8_t* customChatacter, uint8_t location)
{
	
}