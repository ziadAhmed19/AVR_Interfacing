/*
 * ADC_Config.h
 *
 * Created: 5/18/2024 5:27:12 PM
 *  Author: zizoz
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#include "ADC_Register.h"



/*Renaming Reference selection bits*/
typedef enum {
	AREF     = 0,
	AVCC	 = 1,
	Reversed = 2,
	Internal = 3
}vRef;
/*End*/

/*Renaming precaler bits*/
typedef enum{
	prescaler_2   =  0,
	prescaler_4   =  1,
	prescaler_8   =  2,
	prescaler_16  =  3,
	prescaler_32  =  4,
	prescaler_64  =  5,
	prescaler_128 =  6
	}preScaler;
	
/*Renaming channels*/
typedef enum{
	ADC_channel_0 = 0,
	ADC_channel_1 = 1,
	ADC_channel_2 = 2,
	ADC_channel_3 = 3,
	ADC_channel_4 = 4,
	ADC_channel_5 = 5,
	ADC_channel_6 = 6,
	ADC_channel_7 = 7
	}channel;
/*End*/
#endif /* ADC_CONFIG_H_ */