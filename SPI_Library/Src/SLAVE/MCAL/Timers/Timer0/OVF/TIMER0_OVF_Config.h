/*
 * TIMER0_OVF_Config.h
 *
 * Created: 5/25/2024 9:11:54 PM
 *  Author: zizoz
 */ 


#ifndef TIMER0_OVF_CONFIG_H_
#define TIMER0_OVF_CONFIG_H_

#include "CPU_Configs.h"
#include "Periphrials.h"

//Clock Select 
typedef enum{
	
	OVF_no_prescaling =  1,
	OVF_prescaler_8 =    2,
	OVF_prescaler_64 =   3,
	OVF_prescaler_256 =  4,
	OVF_prescaler_1024 = 5
}Prescaler_OVF;

#define _T0_OVF_BITS         256
#define _T0_OVF_PRESCALER    1024
#define _T0_OVF_FREQUENCY    16
#define _T0_OVF_MICROSECOND  1000

#endif /* TIMER0_OVF_CONFIG_H_ */