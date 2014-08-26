//---------------------------------------------------------------------------------------------------
// Steering.c
// Author: Andy Gula, Brian Stack, Philip Weir
// Description: Implements the methods declared in Steering.h        
//--------------------------------------------------------------------------------------------------

#include "derivative.h"
#include "Steering.h"
#include "Sensors.h"
#include "ServoControl.h"
#include "MotorController.h"
#include <hidef.h>

// Macros to control how long the car has been off the line
#define LINE_TIME_RESET     TimeSinceLine = 0
#define LINE_TIME_INCREASE 	TimeSinceLine++

// Scale factors for fixed point numbers
// Numbers are binary scaled 
#define COEFFICIENT_SCALE 10
#define SENSOR_SCALE	   7
#define ERROR_SCALE		   7

// error for when only the edge sensor is over the track
#define EDGE_ERROR		25
// error for when the line has been lost
#define LINE_LOST_ERROR 35

// Value the sensor must be higher than to be considered over the black line
#define SENSOR_THRESHOLD 210

volatile unsigned char TimeSinceLine = 0;

signed int ErrorLast;
signed int ErrorLastLast;

signed int PIDCurrent;

// variables used in the control loop
signed long ProportionalTemp = 0 , IntegralTemp = 0, DerivativeTemp = 0;
signed long Proportional = 0, Integral = 0, Derivative = 0, Diff = 0, DiffPrev = 0, Output = 0;

// structure to store the PID coefficients
struct CoefficientStruct Coefficients;
// array to store the current sensor weights
signed int SensorWeight[8];

// Used to control car speed around corners
//unsigned char MotorSlowedCycles = 0;

signed int PIDPrevious = 0;
signed int PIDCurrent = 0;

void InitSteeringAlgorithm()
{
	Coefficients.Kp = (signed int)(1 << COEFFICIENT_SCALE);
	Coefficients.Ki = (signed int)(0<< COEFFICIENT_SCALE);
	Coefficients.Kd = (signed int)(1);// << COEFFICIENT_SCALE);
	
	SensorWeight[0] = (signed int)-(15 << SENSOR_SCALE);
	SensorWeight[1] = (signed int)-(7 << SENSOR_SCALE);
	SensorWeight[2] = (signed int)-(3 << SENSOR_SCALE);
	SensorWeight[3] = (signed int)-(1 << SENSOR_SCALE);
	SensorWeight[4] = (signed int)(1 << SENSOR_SCALE);
	SensorWeight[5] = (signed int)(3 << SENSOR_SCALE);
	SensorWeight[6] = (signed int)(7 << SENSOR_SCALE);
	SensorWeight[7] = (signed int)(15 << SENSOR_SCALE);

}

void UpdateSteering()
{
	signed short servoDir = 0;
	signed short errorDiff;
	
	
	DisableInterrupts;
	
	PIDCurrent = PID();	
	servoDir = 10*(PIDCurrent >> ERROR_SCALE);
		
	
	ServoSetDutyCycle((word)(SERVO_DUTY_CYCLE_STRAIGHT - servoDir));
	EnableInterrupts;

	/* Used to control car speed around corners
	 * Actually reduced performance in testing and was thus removed
	 * May need to be tweeked more to provide better results
	
	errorDiff = PIDPrevious - PIDCurrent;
	
	if( (errorDiff >> ERROR_SCALE) < -40 || (errorDiff >> ERROR_SCALE) > 40)
		MotorSlowedCycles = 5;
	
	if(MotorSlowedCycles > 0 && MotorSlowedCycles < 6)
	{
		MotorSlowedCycles--;
		MotorSetDutyCycle(SPEED_ZERO);
	}
	else
		MotorSetDutyCycle(SPEED_STANDARD);
	*/
}

// return the current PID value
signed int GetPID()
{
	return PIDCurrent;
}

// calculate the current PID value
signed int PID()
{
	/*
	 * PID = Proportional + Integral + Derivative
	 * Each section of the PID value is computed separately below
	 */
	
	Diff = CalcError();
	ProportionalTemp = Coefficients.Kp *( Diff);
	Proportional = (signed int)(ProportionalTemp >> COEFFICIENT_SCALE);
	
	IntegralTemp += Diff;
	IntegralTemp *= Coefficients.Ki;
	Integral = (signed int)(IntegralTemp >> COEFFICIENT_SCALE);
	
	DerivativeTemp = Diff - DiffPrev;
	DerivativeTemp *= Coefficients.Kd;
	Derivative = (signed int)(DerivativeTemp >> COEFFICIENT_SCALE);
	
	
	Output = Proportional + Integral + Derivative;
	
	DiffPrev = Diff;
	
	return (signed int)Output;
}

signed int ErrorPrevious = 0;
signed int CalcError()
{
	signed int error = 0;

	unsigned char i = 0;
	
	// If only the left or right edge sensor is on the black line
	// set the error accordingly
	if(SensorArray[7] > SENSOR_THRESHOLD && SensorArray[6] < SENSOR_THRESHOLD)
	{
		error = EDGE_ERROR << ERROR_SCALE;
		LINE_TIME_RESET;
	}
	else if(SensorArray[0] > SENSOR_THRESHOLD && SensorArray[1] < SENSOR_THRESHOLD)
	{
		error = -(EDGE_ERROR << ERROR_SCALE);
		LINE_TIME_RESET;
	}
	else // More than one sensor is over the line, or no sensors are over the line
	{
		// Loop through all of the sensors
		for(i = 0; i < SENSOR_COUNT; i++)
		{
			// if the sensor is greater than the threshold,
			// add its weight to the error
			if(SensorArray[i] > SENSOR_THRESHOLD)
			{
				error += SensorWeight[i];
				LINE_TIME_RESET;
			}
		}
		
		// if the error is zero and the center two sensors are not over the line,
		// determine which way the car needs to turn to find the line again
		if(error == 0 && SensorArray[3] < SENSOR_THRESHOLD && SensorArray[4] < SENSOR_THRESHOLD)
		{
			// increase the time since the car has seen the line
			LINE_TIME_INCREASE; 
			
			// if the previous error was greater than zero, set the error to 35
			if(ErrorPrevious < (LINE_LOST_ERROR << ERROR_SCALE) && ErrorPrevious >= 0)
			{
				error = LINE_LOST_ERROR << ERROR_SCALE;
			}
			// if the previous error was less than zero, set the error to -35
			else if(ErrorPrevious > -(LINE_LOST_ERROR << ERROR_SCALE) && ErrorPrevious < 0)
			{
				error = -(LINE_LOST_ERROR << ERROR_SCALE);
			}
			// otherwise set the error to the previous error
			else
				error = ErrorPrevious;					
		 }
	}
	
	ErrorPrevious = error;
	
	return error;
	
}

// Set the sensor weights
void SetSensorWeight(unsigned char sensor, signed int weight)
{
	SensorWeight[sensor] = weight;
}
// returns the sensor weight
signed int GetSensorWeight(unsigned char sensor)
{
	return SensorWeight[sensor];
}
void SetCoefficients(word kp, word ki, word kd)
{
	
	Coefficients.Kp = kp;
	Coefficients.Ki = ki;
	Coefficients.Kd = kd;
}
word GetKp(void)
{
	return Coefficients.Kp;
}
word GetKi(void)
{
	return Coefficients.Ki;
}
word GetKd(void)
{
	return Coefficients.Kd;
}
