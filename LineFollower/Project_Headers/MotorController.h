//---------------------------------------------------------------------------------------------------
// MotorController.h
// Created: Feb 10, 2011
// Author: Andy Gula, Brian Stack, Philip Weir
// Description: Defines the methods and variables for the Motor Controller interface with TPWM1 CH1   
//--------------------------------------------------------------------------------------------------

#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_

#include "Clock.h"
#include "derivative.h"
#include "Support.h"
#include "HallEffect.h"


#define SPEED_DUTY_CYCLE_MIN 1000
#define SPEED_DUTY_CYCLE_MAX 2000
#define SPEED_ZERO 1500

#define SPEED_STANDARD 1650
//--------------------------------------------------------
// Global Variable Declarations
//--------------------------------------------------------
extern unsigned short* MotorGetPhysicalSpeed(void);
extern unsigned short* MotorGetRPM(void);




//--------------------------------------------------------
// Function Declarations
//--------------------------------------------------------
void InitMotorTimer(void);
void MotorSetDutyCycle(volatile unsigned short dutyCycle);
unsigned short* MotorGetDutyCycle(void);
void MotorSetSpeedLimit(unsigned short);
unsigned short* MotorGetSpeedLimit(void);
unsigned char* MotorSpeedLimitSet(void);

void MotorSpeedLimitEnable(void);
void MotorSpeedLimitDisable(void);

unsigned short* MotorGetPhysicalSpeed(void);
unsigned short* MotorGetRPM(void);
void Delay(void);


#endif /* MOTORCONTROLLER_H_ */
