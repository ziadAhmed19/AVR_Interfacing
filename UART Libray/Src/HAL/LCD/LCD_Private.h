/*
 * LCD_Private.h
 *
 * Created: 5/11/2024 1:03:19 PM
 *  Author: zizoz
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#include "LCD_Config.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* ---------------------------Function Prototypes-----------*/
void reverse(char* str, int len);
int intToStr(int x, char str[], int d);
void ftoa(float n, char* res, int afterpoint);
/* ---------------------------END---------------------------*/

#endif /* LCD_PRIVATE_H_ */