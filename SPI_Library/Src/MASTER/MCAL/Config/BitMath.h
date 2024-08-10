/*
 * BitMath.h
 *
 * Created: 7/26/2024 3:00:59 PM
 *  Author: zizoz
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define CLR_BIT(REG,BIT) REG&=~(1<<BIT)
#define TGL_BIT(REG,BIT) REG^=(1<<BIT)
#define GET_BIT(REG,BIT) ((REG>>BIT)&0x01)

#endif /* BITMATH_H_ */