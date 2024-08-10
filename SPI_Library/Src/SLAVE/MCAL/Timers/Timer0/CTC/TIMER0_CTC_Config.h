/*
 * TIMER0_CTC_Config.h
 *
 * Created: 6/14/2024 5:01:16 PM
 *  Author: zizoz
 */ 


#ifndef TIMER0_CTC_CONFIG_H_
#define TIMER0_CTC_CONFIG_H_

#include "TIMER0_CTC_Register.h"

typedef enum{
	
	_no_prescaling_CTC =  1,
	_prescaler_8_CTC =    2,
	_prescaler_64_CTC =   3,
	_prescaler_256_CTC =  4,
	_prescaler_1024_CTC = 5
}Prescaler_CTC;



#endif /* TIMER0_CTC_CONFIG_H_ */