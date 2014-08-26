//---------------------------------------------------------------------------------------------------
// Mux.c
// Author: Andy Gula, Brian Stack, Philip Weir
// Description: Implements the methods declared in Mux.h        
//--------------------------------------------------------------------------------------------------

#include "Mux.h"
#include "Support.h"
#include "derivative.h"
#include "ADC.h"
#include "Sensors.h"

volatile unsigned char MuxNumber;
volatile unsigned char ResetCounter;

#define ADC_MUX_CHANNEL		0x08

void InitMux()
{
	
	//Set SPI Control Register 1
	SPIC1 |= SPIC1_SPE_MASK;
	SPIC1 |= SPIC1_SPTIE_MASK;
	SPIC1 |= SPIC1_MSTR_MASK;
	SPIC1 |= SPIC1_SSOE_MASK;
	SPIC1 |= SPIC1_CPHA_MASK;
	
	SPIC2 |= SPIC2_MODFEN_MASK;
	
	SOPT2 |= SOPT2_SPIPS_MASK;
	
	// divide the lock by 8...there is a default divide by 2 so this
	// divides by an effective 16
	SPIBR |= (SPIBR_SPPR2_MASK | SPIBR_SPPR1_MASK | SPIBR_SPPR0_MASK);
	

	MuxNumber = 1;
	ResetCounter = 0;
}

// write to the SPI to control the mux channel
void SPIWrite()
{	
	unsigned char temp;
	
	if (ResetCounter > 7)
	{
		MuxNumber = 1;
		ResetCounter = 0;
	}
	
	if(SPIS_SPTEF == 1)
	{
		// Read the status register to clear the interrupt
		temp = SPIS;
	}
	SPID = MuxNumber;	
}

// interrupt called when spi raises an interrupt
interrupt VectorNumber_Vspi void SPI(void)
{
	unsigned char temp;

	// if the interrupt is a transmit complete
	if( SPIS_SPTEF == 1)
	{
		// Disable SPI transmit interrupt
		SPIC1 &= ~SPIC1_SPTIE_MASK;
		
		temp = SPIS;
		
		// set the mux channel
		AdcSetChannel(ADC_MUX_CHANNEL);	
	}
}

// interrupt called when ADC completes a read
interrupt VectorNumber_Vadc void ADCread(void)
{
	// Store the value in the sensors
	// NOTE: 255 - ADCR allows the black line to be viewed as a peak
	//       instead of a valley which works better for the PID algorithm
	SensorArray[ResetCounter++] = 255-(volatile unsigned char)ADCR;
	MuxNumber = MuxNumber << 1; //bit shift to left
	
	// clear the mux so that we don't short circuit anything
	//SPID = 0x00;
	
	// turn SPI transmit interrupt back on
	SPIC1 |= SPIC1_SPTIE_MASK;
	SPIWrite();
	
	AdcComplete();	
}



