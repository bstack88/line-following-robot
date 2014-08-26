//---------------------------------------------------------------------------------------------------
// ADC.c
// Author: Andy Gula, Brian Stack, Philip Weir
// Description: Implements the methods declared in ADC.h        
//--------------------------------------------------------------------------------------------------
#include "Support.h"
#include "derivative.h"
#include "ServoControl.h"
#include "ADC.h"
#include "Accelerometer.h"
#include "Mux.h"

unsigned char AdcCurrentState, AdcNextState;

void InitADC()
{
	// Set ADC to default config
	set(ADCCFG1, 0x00);
	set(ADCCFG2, 0x00);	
	set(ADCSC2, 0x00);	
	set(ADCSC3, 0x00);
	
	// Disable ADC channel 8
	set(APCTL1, APCTL2_ADPC8_MASK);

	
	// Enable conversion complete interrupts
	set(ADCSC1, ADCSC1_AIEN_MASK);
	
	// Set the current state of the ADC state machien
	AdcCurrentState = ADC_IDLE;
	AdcNextState = ADC_IDLE;
	
}

// Reads the accelerometer data
void AdcReadAcc()
{
	// Only read the accelerometer if the ADC is idle
	if(AdcCurrentState != ADC_IDLE)
		return;
	
	AdcCurrentState = ADC_READ_ACCELEROMETER_X;
	AdcSetChannel(ACCELEROMETER_X);
}

// Called when the ADC complete interrupt is triggered
// It really only matters for the accelerometer
void AdcComplete()
{
	// Determine which state the ADC FSM is in
	switch(AdcCurrentState)
	{
		case ADC_READ_ACCELEROMETER_X: 
			AdcNextState = ADC_READ_ACCELEROMETER_Y;
			SetAccelerometerX((unsigned char)ADCR);
			AdcSetChannel(ACCELEROMETER_Y);
			
		break;
		case ADC_READ_ACCELEROMETER_Y:
			AdcNextState = ADC_READ_ACCELEROMETER_Z;
			SetAccelerometerY((unsigned char)ADCR);
			AdcSetChannel(ACCELEROMETER_Z);
		break;
		case ADC_READ_ACCELEROMETER_Z:
			AdcNextState = ADC_IDLE;
			
			// Disable the ADC
			AdcSetChannel(0x1F);
			
			SetAccelerometerZ((unsigned char)ADCR);
		break;
		case ADC_READ_SENSOR:			
		break;
	}
	AdcCurrentState = AdcNextState;	
}

// Updates the channel to read from the ADC
void AdcSetChannel(unsigned char channel)
{
	// clear all bits except for first three
	ADCSC1_ADCH = channel;
}

