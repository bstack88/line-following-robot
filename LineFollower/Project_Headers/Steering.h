//---------------------------------------------------------------------------------------------
// Steering.h
// Author: Andy Gula, Brian Stack, Phil Weir
// Description: Defines the methods and variables for the Steering algorithm
//---------------------------------------------------------------------------------------------

#ifndef STEERING_H_
#define STEERING_H_

#include "derivative.h"

struct CoefficientStruct
{
	signed int Kp;
	signed int Ki;
	signed int Kd;
};

void InitSteeringAlgorithm(void);

void UpdateSteering(void);
signed int CalcError(void);
signed int PID(void);

signed int GetPID(void);

void SetSensorWeight(unsigned char, signed int);
signed int GetSensorWeight(unsigned char);
void SetCoefficients(word,word,word);
word GetKp(void);
word GetKi(void);
word GetKd(void);

extern volatile unsigned char TimeSinceLine;

#endif /* STEERING_H_ */
