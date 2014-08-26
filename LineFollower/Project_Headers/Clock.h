//---------------------------------------------------------------------------------------------
// ADC.h
// Description: Defines the methods and variables for the Clock
//---------------------------------------------------------------------------------------------

#ifndef CLOCK_H_
#define CLOCK_H_


void InitClock(void);

#define ICS_OUT          33554432
#define CPU_CLOCK        ICS_OUT

#define PERIPHERAL_CLOCK (CPU_CLOCK/2)

#endif
