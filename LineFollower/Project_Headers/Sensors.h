//---------------------------------------------------------------------------------------------
// Sensors.h
// Author: Brian Stack
// Description: Defines the methods and variables for the Sensors
//---------------------------------------------------------------------------------------------

#ifndef SENSORS_H_
#define SENSORS_H_


#define SENSOR_COUNT 8

extern volatile unsigned char SensorArray[8];

unsigned char* GetSensor(unsigned char sensor);

#endif
