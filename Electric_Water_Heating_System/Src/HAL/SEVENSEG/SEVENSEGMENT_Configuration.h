/*
 * SEVENSEGMENT_Configuration.h
 *
 * Created: 4/27/2024 10:12:20 PM
 *  Author: karim
 */ 


#ifndef SEVENSEGMENT_CONFIGURATION_H_
#define SEVENSEGMENT_CONFIGURATION_H_
#include "CPU_Config.h"
#include "peripherals.h"
/* ---------------------------Renaming Pins & Ports---------*/
//Renaming Port
#define SEVSEG_PORT         PORTC
#define SEVSEG_DATA_PORT    DIO_PORTC
#define SEVSEG_CONTROL_PORT DIO_PORTC
//Renaming pin
#define SEVSEG_DATA_A       DIO_PIN0
#define SEVSEG_DATA_B       DIO_PIN1
#define SEVSEG_DATA_C       DIO_PIN2
#define SEVSEG_DATA_D       DIO_PIN3
#define SEVSEG_CONTROL_EN1  DIO_PIN5
#define SEVSEG_CONTROL_EN2  DIO_PIN6
/* ---------------------------END---------------------------*/
#endif /* SEVENSEGMENT_CONFIGURATION_H_ */