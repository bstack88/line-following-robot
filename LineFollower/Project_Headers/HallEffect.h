//---------------------------------------------------------------------------------------------
// HallEffect.h
// Created: Mar 29, 2011
// Author: Philip Weir 
// Description: Defines the methods and variables for the Hall Effect interface with TPWM2 CH1   
//---------------------------------------------------------------------------------------------

#ifndef HALLEFFECT_H_
#define HALLEFFECT_H_

#include "Clock.h"
#include "Support.h"
#include "derivative.h"



#define HALL_EFFECT_TIME_TO_WAIT 0.2 /* In Seconds */
#define HALL_EFFECT_PRESCALE 128
#define HALL_EFFECT_SCALE_FACTOR 10000


//--------------------------------------------------------
// Global Variable Declarations
//--------------------------------------------------------
extern unsigned int  WheelRotationTime;
extern volatile unsigned int  TPWM2PosEdgeCounter;



//--------------------------------------------------------
// Function Declarations
//--------------------------------------------------------
void InitHallEffectTimer(void);
void CalculateRotationTime(void);


#endif /* HALLEFFECT_H_ */
