//-----------------------------------------------------------------------------------------
// HallEffect.c
// Created: Mar 29, 2011
// Author: Philip Weir 
// Description: Implements the methods declared in HallEffect.h     
//-----------------------------------------------------------------------------------------

#include "HallEffect.h"


//--------------------------------------------------------
// Global Variable Declarations
//--------------------------------------------------------
unsigned int  WheelRotationTime;
volatile unsigned int  TPWM2PosEdgeCounter;
unsigned int HallEffectCountsPerTime = (HALL_EFFECT_SCALE_FACTOR / HALL_EFFECT_TIME_TO_WAIT);


//------------------------------------
// Initialize the TPWM2 
//------------------------------------
void InitHallEffectTimer(void)
{
	// Reset the Timer
	clearAll(TPM2SC);
	
	// Enable Interrupts
	set(TPM2SC, TPM2SC_TOIE_MASK);
	
	// Set up the Clock
	set(  TPM2SC, TPM2SC_CLKSA_MASK);
	clear(TPM2SC, TPM2SC_CLKSB_MASK);
	
	// Set the Clock Prescaler Factor
	set(TPM2SC, TPM2SC_PS0_MASK);
	set(TPM2SC, TPM2SC_PS1_MASK);
	set(TPM2SC, TPM2SC_PS2_MASK);
	
	// Set the Overflow Count
	TPM2MOD = (word) (HALL_EFFECT_TIME_TO_WAIT * (PERIPHERAL_CLOCK / HALL_EFFECT_PRESCALE));
	
	// Setup TPWM2 Ch1 to positive edge input capture mode
	clearAll(TPM2C1SC);
	set(TPM2C1SC, TPM2C1SC_ELS1A_MASK);
	
	// Enable interrupts when a positive edge is detected
	set(TPM2C1SC, TPM2C1SC_CH1IE_MASK);
}




//--------------------------------------------------------------
// Calculate the elapsed time (in seconds) from the clock ticks
//--------------------------------------------------------------
void CalculateRotationTime(void)
{
	WheelRotationTime = (int) (TPWM2PosEdgeCounter * HallEffectCountsPerTime);
}



//---------------------------------------------------------
// Interrupt for positive edge detected on TPWM2 Ch1 
//---------------------------------------------------------
interrupt VectorNumber_Vtpm2ch1 void TPM2CH1Interrupt(void)
{
	// Clear the interrupt
	clear(TPM2C1SC,TPM2C1SC_CH1F_MASK);
	
	// Increment the Positive Edge Counter
	TPWM2PosEdgeCounter++;
	
}


//-------------------------------------------------------------
// Interrupt for TPWM2 Overflow
//-------------------------------------------------------------
interrupt VectorNumber_Vtpm2ovf void TPM2OverflowInterrupt(void)
{
	// Calculate the rotation time
	CalculateRotationTime();
	
	// Reset the Positive Edge Counter
	TPWM2PosEdgeCounter = 0;
	
//	PTCD ^= ~0x20;
	
	// Clear the interrupt
	clear(TPM2SC,TPM2SC_TOF_MASK);	
}




