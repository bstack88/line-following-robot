//---------------------------------------------------------------------------------------------
// Support.h
// Author: Andy Gula, Brian Stack, Phil Weir
// Description: Defines several useful macros for setting registers and other useful data
//---------------------------------------------------------------------------------------------

#ifndef _SUPPORT_H_
#define _SUPPORT_H_


#define set(reg,mask)      reg |=  mask
#define clear(reg, mask)   reg &= ~mask
#define clearAll(reg)	   reg  =  0


#define true	1
#define false 	0



#endif
