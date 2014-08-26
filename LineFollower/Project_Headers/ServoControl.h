//---------------------------------------------------------------------------------------------------
// ServoControl.h
// Created: Feb 10, 2011
// Author: Andy Gula, Brian Stack, Philip Weir
// Description: Defines the methods and variables for the Servo interface with TPWM1 CH0   
//--------------------------------------------------------------------------------------------------

#ifndef SERVO_CONTROL_H_
#define SERVO_CONTROL_H_

#include "Clock.h"
#include "Support.h"
#include "derivative.h"
#include "main.h"


#define SERVO_DUTY_CYCLE_MIN 	   1200
#define SERVO_DUTY_CYCLE_MAX 	   1900
#define SERVO_DUTY_CYCLE_STRAIGHT 1550

#define TIME_TO_WAIT 0.02 /* In Seconds */
#define PRESCALE_FACTOR 16 


//--------------------------------------------------------
// Function Declarations
//--------------------------------------------------------
void InitServoTimer(void);
void ServoSetDutyCycle(volatile word dutyCycle);
unsigned short* ServoGetDutyCycle(void);


#endif /* SERVO_CONTROL_H_ */
