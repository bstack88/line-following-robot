//---------------------------------------------------------------------------------------------------
// ServoControl.c
// Created: Feb 10, 2011
// Author: Andy Gula, Brian Stack, Philip Weir
// Description: Implements the methods declared in ServoControl.h        
//--------------------------------------------------------------------------------------------------

#include "ServoControl.h"
#include "CPUDebug.h"
#include "main.h"

//------------------------------------
// Initialize the TPWM1 
//------------------------------------
void InitServoTimer(void)
{
	// Reset the Timer
	clearAll(TPM1SC);
	
	// Enable Interrupts
	set(TPM1SC, TPM1SC_TOIE_MASK);
	
	// Set up the Clock
	set(TPM1SC, TPM1SC_CLKSA_MASK);
	clear(TPM1SC, TPM1SC_CLKSB_MASK);
	
	// Set the Clock Prescale Factor
	clear(TPM1SC, TPM1SC_PS0_MASK);
	clear(TPM1SC, TPM1SC_PS1_MASK);
	set(TPM1SC, TPM1SC_PS2_MASK);
	
	// Set the Overflow Count
	TPM1MOD = (word) (TIME_TO_WAIT * (PERIPHERAL_CLOCK / PRESCALE_FACTOR));
	
	// Setup up Timer Module 1 Channel 0 to be edge aligned PWM
	clearAll(TPM1C0SC);
	set(TPM1C0SC, TPM1C0SC_MS0B_MASK);
	set(TPM1C0SC, TPM1C0SC_ELS0B_MASK);
	
	// Make the car go straight at the start
	ServoSetDutyCycle(SERVO_DUTY_CYCLE_STRAIGHT);
}



//------------------------------------
// Set the duty cycle of TPM1 CH0 
//------------------------------------
void ServoSetDutyCycle(volatile word dutyCycle)
{
	// Give the duty cycle the proper offset
	if(dutyCycle < SERVO_DUTY_CYCLE_MIN)
		dutyCycle += SERVO_DUTY_CYCLE_MIN;
	
	// In case the duty cycle gets too large keep a maximum on it
	if(dutyCycle > SERVO_DUTY_CYCLE_MAX)
		dutyCycle = SERVO_DUTY_CYCLE_MAX;
	
	// Set the duty cycle
	TPM1C0V = dutyCycle;
}



//--------------------------------------------------------------
// Get the Duty Cycle value to be sent to the PC for debugging
//--------------------------------------------------------------
unsigned short* ServoGetDutyCycle(void)
{
	return (unsigned short*)&TPM1C0V;
}


//---------------------------------------------------------
// Interrupt for overflow of TPWM1  
//---------------------------------------------------------
interrupt VectorNumber_Vtpm1ovf void TPM1Overflow(void)
{
	// Clears the interrupt
	TPM1SC &= ~TPM1SC_TOF_MASK;
	
	DiagMsgRx++;	
	
	SystemTick = 1;
}



