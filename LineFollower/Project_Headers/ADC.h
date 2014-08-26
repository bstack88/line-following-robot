//---------------------------------------------------------------------------------------------
// ADC.h
// Author: Andy Gula, Brian Stack, Phil Weir
// Description: Defines the methods and variables for the ADC
//---------------------------------------------------------------------------------------------

#ifndef ADC_H_
#define ADC_H_


#define ACCELEROMETER_X				5
#define ACCELEROMETER_Y				6
#define ACCELEROMETER_Z				7

#define ADC_IDLE					0
#define ADC_READ_ACCELEROMETER_X	1
#define ADC_READ_ACCELEROMETER_Y	2
#define ADC_READ_ACCELEROMETER_Z	3
#define ADC_READ_SENSOR				4

void InitADC(void);

void AdcComplete(void);
void AdcSetChannel(unsigned char);
void AdcReadAcc(void);

#endif /* ADC_H_ */
