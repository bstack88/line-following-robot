//---------------------------------------------------------------------------------------------------
// Sensors.c
// Author: Andy Gula, Brian Stack, Philip Weir
// Description: Implements the methods declared in Sensors.h        
//--------------------------------------------------------------------------------------------------

#include "Sensors.h"

// Stores the values of the sensors
volatile unsigned char SensorArray[8];

// returns a value of the sensor
unsigned char* GetSensor(unsigned char sensor)
{
	return (unsigned char *)&SensorArray[sensor];
}

