/*
 * Timer0_CTC_Configuration.h
 *
 * Created: 2/16/2024 5:41:12 PM
 *  Author: karim
 */ 


#ifndef TIMER0_CTC_CONFIGURATION_H_
#define TIMER0_CTC_CONFIGURATION_H_

#include "Timer0_CTC_Address.h"


typedef enum
{
	T0_CTC_0    = 0,
	T0_CTC_1    = 1,
	T0_CTC_8    = 2,
	T0_CTC_64   = 3,
	T0_CTC_256  = 4,
	T0_CTC_1024 = 5
}timer0CTC_prescalar;

#define _T0_CTC_BITS         256
#define _T0_CTC_PRESCALER    1024
#define _T0_CTC_FREQUENCY    16
#define _T0_CTC_MICROSECOND  1000


#endif /* TIMER0_CTC_CONFIGURATION_H_ */