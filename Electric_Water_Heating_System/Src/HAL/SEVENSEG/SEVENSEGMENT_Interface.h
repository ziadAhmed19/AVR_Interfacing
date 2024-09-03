/*
 * LED0_Interface.h
 *
 * Created: 4/27/2024 10:12:33 PM
 *  Author: karim
 */ 


#ifndef SEVENSEGMENT_INTERFACE_H_
#define SEVENSEGMENT_INTERFACE_H_

#include "SEVENSEGMENT_Private.h"

/* ---------------------------Function Prototypes-----------*/
void SEVENSEGMENT_Initialize(void);
void SEVENSEGMENT_Display_Number(uint8_t number);
void SEVENSEGMENT_Disable();
/* ---------------------------END---------------------------*/

#endif /* SEVENSEGMENT_INTERFACE_H_ */