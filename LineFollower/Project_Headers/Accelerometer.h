//---------------------------------------------------------------------------------------------
// Accelerometer.h
// Author: Brian Stack
// Description: Defines the methods and variables for the accelerometer  
//---------------------------------------------------------------------------------------------

#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

void ReadAccelerometer(void);

void SetAccelerometerX(unsigned char);
void SetAccelerometerY(unsigned char);
void SetAccelerometerZ(unsigned char);

unsigned char* GetAccelerometerX(void);
unsigned char* GetAccelerometerY(void);
unsigned char* GetAccelerometerZ(void);

#endif /* ACCELEROMETER_H_ */
