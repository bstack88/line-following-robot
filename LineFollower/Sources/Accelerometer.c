//---------------------------------------------------------------------------------------------------
// Accelerometer.c
// Author: Andy Gula, Brian Stack, Philip Weir
// Description: Implements the methods declared in Accelerometer.h        
//--------------------------------------------------------------------------------------------------

#include "derivative.h"
#include "Accelerometer.h"
#include "ADC.h"


unsigned char Accleration[3];

//----------------------------
// Read the accelerometer through a state machine
//----------------------------
void ReadAccelerometer()
{	
	// Accelerometer is on ADC 5,6,7
	AdcReadAcc();
}

//----------------------------
// Store the accelerometer data
//----------------------------
void SetAccelerometerX(unsigned char x)
{
	Accleration[0] = x;
}
void SetAccelerometerY(unsigned char y)
{
	Accleration[1] = y;
}
void SetAccelerometerZ(unsigned char z)
{
	Accleration[2] = z;
}

//----------------------------
// Returns the accelerometer data
//----------------------------
unsigned char* GetAccelerometerX(void)
{
	return &Accleration[0];
}
unsigned char* GetAccelerometerY(void)
{
	return &Accleration[1];
}
unsigned char* GetAccelerometerZ(void)
{
	return &Accleration[2];
}
