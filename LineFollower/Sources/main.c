//---------------------------------------------------------------------------------------------------
// main.c
// Author: Andy Gula, Brian Stack, Philip Weir
// Description: Implements the methods declared in main.h        
//--------------------------------------------------------------------------------------------------

#include "Support.h"
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "main.h"
#include "Clock.h"
#include "ServoControl.h"
#include "CPUDebug.h"
#include "MotorController.h"
#include "Accelerometer.h"
#include "HallEffect.h"
#include "ADC.h"
#include "Mux.h"
#include "HallEffect.h"
#include "Steering.h"

unsigned char SystemTick = 0;
unsigned char SystemStop = 0;

void main(void) {

	// used to control when to execute tasks
	unsigned char tickCount = 0;
	
	// disable the interrupts during the initialization sequence
	DisableInterrupts;
	KILL_THE_DOG;	
	
	InitClock(); // set the clock
	InitServoTimer();  // initialize the timer to control sterring
	InitCPUDebug(); // initialize the CPU debugger
	InitMotorTimer(); // initialize the timer to control the motor
	InitADC(); // initialize the ADC to read sensors
	InitMux(); // initialize the analog mux
	//InitHallEffectTimer(); 
	InitSteeringAlgorithm(); // initialize the steering algorithm
	
	// enable the interrupts now that initialize is complete
	EnableInterrupts; 
	
	SPIWrite();
	
	// Wait until the user tells the car to begin moving
	WaitForStart();
	
	// set some input and output
	PTCDD = PTCDD_PTCDD7_MASK;
	PTCD = 0;
		
	
	
	// main loop for the car	
	for(;;) 
	{ 	
		// SystemTick goes high every 20ms
		if(SystemTick == 1)
		{
			// SystemStop is an override to prevent the car from moving
			if(SystemStop == 1)
			{
				KillAll();
				return;
			}
			
			// Increment the number of ticks
			// this allows tasks that do not have to run every 20 ms 
			// to run less frequently
			tickCount++;
			
			set(PTCD,PTCD_PTCD7_MASK);
			
			// Initializes the reading sensor process
			SPIWrite();
			
			// Update the steering based on the sensor values
			UpdateSteering();		
			
			// Check to make sure the car has communications with the computer
			// debugger if diagnostic mode is enabled
			CheckDiagnostics();
			
			// check how long the car has not seen the line for
			CheckLine();
			
			// clear the system tick
			SystemTick = 0;
			
			clear(PTCD,PTCD_PTCD7_MASK);
		}
		
	}
}

// loop that waits until the user presses a button the car
// to begin moving the car
void WaitForStart()
{
	while(PTCD_PTCD7 == 1);
	
	MotorSetDutyCycle(SPEED_STANDARD);
}

void CheckLine()
{
	// if the time since line is greater than 2 seconds, the car stops
	// this is viewed as a safety feature
	if(TimeSinceLine > 100)
	{
		KillAll();
		TimeSinceLine = 0;
	}
}

void CheckDiagnostics()
{
	if(DiagMode == 1)
	{  
	  // Check that debug signals are alive
	  if( DiagMsgRx > DiagMsgRxTime)
	  { 
		  KillAll();
		  DiagMsgRx = 0;
	   }
	}
}

void KillAll()
{
	SystemStop = 1;
	
	// Don't let interrupts occur
	  DisableInterrupts;
	  
	  // Stop the car
	  MotorSetDutyCycle(SPEED_ZERO);
	  ServoSetDutyCycle(SERVO_DUTY_CYCLE_STRAIGHT);
	 
	  //Just wait here
	  while(PTCD_PTCD7 == 1);

	  EnableInterrupts;
	  
}








