//---------------------------------------------------------------------------------------------------
// MotorController.c
// Created: Feb 10, 2011
// Author: Andy Gula, Brian Stack, Philip Weir
// Description: Implements the methods declared in MotorController.h        
//--------------------------------------------------------------------------------------------------

#include "MotorController.h"

unsigned short MaxSpeed = 500;
unsigned char SpeedLimit = 1;


//--------------------------------------------------------
// Global Variable Declarations
//--------------------------------------------------------
unsigned short* MotorGetPhysicalSpeed(void);
unsigned short* MotorGetRPM(void);


//----------------------------------------------------------------
// Initialize the TPWM1 Channel 1
// *Note: Overall TPWM1 initialization handled in ServoControl.c*
//----------------------------------------------------------------
void InitMotorTimer(void)
{
	// Setup up Timer Module 1 Channel 1 to be edge aligned PWM
	clearAll(TPM1C1SC);
	set(TPM1C1SC, TPM1C1SC_MS1B_MASK);
	set(TPM1C1SC, TPM1C1SC_ELS1B_MASK);	
	
	// Run through the Motor Controller Initialization Routine
	MotorSetDutyCycle(SPEED_ZERO);
	Delay();	
	MotorSetDutyCycle(SPEED_DUTY_CYCLE_MAX);
	Delay();
	MotorSetDutyCycle(SPEED_DUTY_CYCLE_MIN);
	Delay();
	Delay();
	MotorSetDutyCycle(SPEED_ZERO);
	
	MotorSetSpeedLimit(170);
}



//------------------------------------
// Set the duty cycle of TPM1 CH1 
//------------------------------------
void MotorSetDutyCycle(volatile unsigned short dutyCycle)
{
	// Don't allow the duty cycle to drop below the minimum
	if(dutyCycle <= SPEED_DUTY_CYCLE_MIN)
		dutyCycle += SPEED_DUTY_CYCLE_MIN;
	
	// Don't allow the duty cycle to go above the maximum
	if(dutyCycle > SPEED_DUTY_CYCLE_MAX)
		dutyCycle = SPEED_DUTY_CYCLE_MAX;
	

	// if the speedlimit is enabled, prevent the car from
	// exceeding the speed limit
	if(SpeedLimit == 1)
	{
		if(dutyCycle > SPEED_ZERO + MaxSpeed)
			dutyCycle = SPEED_ZERO + MaxSpeed;
		if(dutyCycle < SPEED_ZERO - MaxSpeed)
			dutyCycle = SPEED_ZERO - MaxSpeed;
	}
	

	// Set the duty cycle
	TPM1C1V = dutyCycle;
}



//--------------------------------------------------------------
// Get the Duty Cycle value to be sent to the PC for debugging
//--------------------------------------------------------------
unsigned short* MotorGetDutyCycle(void)
{
	return (unsigned short*)&TPM1C1V;
}


//-----------------------------------------------------------------
// Get the physical speed value to be sent to the PC for debugging
//-----------------------------------------------------------------
unsigned short* MotorGetPhysicalSpeed(void)
{
	unsigned short temp = 0xFFFF;
	return &temp;
}


//--------------------------------------------------------------
// Get the Motor's RPM value to be sent to the PC for debugging
//--------------------------------------------------------------
unsigned short* MotorGetRPM(void)
{
	return (unsigned short *) &WheelRotationTime;
}

void MotorSpeedLimitEnable()
{
	SpeedLimit = 1;
}
void MotorSpeedLimitDisable()
{
	SpeedLimit = 0;
}

unsigned char* MotorSpeedLimitSet()
{
	return &SpeedLimit;
}

void MotorSetSpeedLimit(unsigned short maxSpeed)
{
	MaxSpeed = maxSpeed;
}

unsigned short* MotorGetSpeedLimit()
{
	return &MaxSpeed;
}


//--------------------------------------------------------------------
// Delay Block to be used for Motor Controller Initialization Routine
//--------------------------------------------------------------------
void Delay()
{
	unsigned short x,y;
	
	for(x=0; x<4000 ; x++){
		for(y=0; y<139; y++){			
		}
	}
}

