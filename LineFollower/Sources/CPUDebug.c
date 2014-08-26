//---------------------------------------------------------------------------------------------------
// CPUDebug.c
// Author: Andy Gula, Brian Stack, Philip Weir
// Description: Implements the methods declared in CPUDebug.h        
//--------------------------------------------------------------------------------------------------

#include <hidef.h>
#include "main.h"
#include "derivative.h" 
#include "CPUDebug.h"
#include "Support.h"
#include "Commands.h"
#include "ServoControl.h"
#include "MotorController.h"
#include "Sensors.h"
#include "Accelerometer.h"
#include "Steering.h"

// Incoming data states
#define WAIT_FOR_PREAMBLE	0
#define WAIT_FOR_TYPE		1
#define WAIT_FOR_NUMBER		2
#define WAIT_FOR_COUNT		3
#define WAIT_FOR_DATA		4
#define WAIT_FOR_CHECKSUM   5
#define WAIT_FOR_END		6

// Outgoing data states
#define SEND_PREAMBLE		0
#define SEND_TYPE			1
#define SEND_NUMBER			2
#define SEND_COUNT			3
#define SEND_DATA			4
#define SEND_CHECKSUM		5
#define SEND_END			6

// Store the commands coming in and going out
volatile struct CommandStruct CommandIn;
volatile struct CommandStruct CommandOut;

// Set up the states for the FSMs
unsigned char CurrentStateIn = WAIT_FOR_PREAMBLE;
unsigned char NextStateIn;

unsigned char CurrentStateOut = SEND_PREAMBLE;
unsigned char NextStateOut;

// Store the current command that is being processed
struct CommandStruct Command;
unsigned char SendingCommand = 0x00;

volatile unsigned char WaitForBreak;

// Is the car in diagnostics mode
unsigned char DiagMode = 0;
volatile unsigned char DiagMsgRx = 0;
volatile unsigned char DiagMsgRxTime = DEBUG_MSG_TIME;

void InitCPUDebug(void)
{
	// Set the SCI Baud Rate Register
	  clearAll(SCI1BD);
	  set(SCI1BD, (word)9); // baud rate = 115200

	  set(SCI1C1, 0x00 );
	  
	  // Enable UART interrupts
	  set(SCI1C2, SCI1C2_TCIE_MASK | SCI1C2_RIE_MASK | SCI1C2_RE_MASK | SCI1C2_TE_MASK);
}

// Sends a UART break
// Used when programming the bluetooth module
void SendBreak(void)
{
	// Set and clear the SBK mask bit to queue a break character
	set(SCI1C2,SCI1C2_SBK_MASK);
	
	clear(SCI1C2,SCI1C2_SBK_MASK);
}

// Attempts to send data over the UART
unsigned char DebugSend(unsigned char data)
{
	// check to make sure the previous transmit was completed
	if(SCI1S1_TC == 1)
	{
		SCI1D = data;
		return true;
	}
	return false;
}

// Reads incoming data and parses it into the command structure
void DebugDataIn(unsigned char dataIn)
{
	// Stores the data bytes
	static unsigned char dataBytesReceived;

	switch(CurrentStateIn)
	{
		// Wait for the command preamble to be received
		case WAIT_FOR_PREAMBLE:
		{
			if(dataIn == CMD_PREAMBLE)
				NextStateIn = WAIT_FOR_TYPE;
			else
				NextStateIn = WAIT_FOR_PREAMBLE;		
		}
		break;
		// wait for the command type to be received
		case WAIT_FOR_TYPE:
		{
			CommandIn.Type = dataIn;
			NextStateIn = WAIT_FOR_NUMBER;
		}
		break;
		// wait for the command number to be received
		case WAIT_FOR_NUMBER:
		{
			CommandIn.Number = dataIn;
			NextStateIn = WAIT_FOR_COUNT;
		}
		break;
		// wait for the number of data bytes
		case WAIT_FOR_COUNT:
		{
			CommandIn.DataBytes = dataIn;			
			NextStateIn = WAIT_FOR_DATA;
			dataBytesReceived = 0;
			
			if(CommandIn.DataBytes == 0)
				NextStateIn = WAIT_FOR_CHECKSUM;
		}
		break;
		// wait for the data
		case WAIT_FOR_DATA:
		{
			if( CommandIn.DataBytes > 0 && dataBytesReceived < CommandIn.DataBytes - 1 && dataBytesReceived < 32)
			{
				CommandIn.Payload.Data[dataBytesReceived++] = dataIn;
				NextStateIn = WAIT_FOR_DATA;
			}
			else
			{
				CommandIn.Payload.Data[dataBytesReceived] = dataIn;
				NextStateIn = WAIT_FOR_CHECKSUM;
			}
		}
		break;
		// wait for the checksum
		case WAIT_FOR_CHECKSUM:
		{
			CommandIn.Checksum = dataIn;
			NextStateIn = WAIT_FOR_END;
		}
		break;
		// wait for the end of command
		case WAIT_FOR_END:
		{
			if( dataIn == CMD_END)
			{
				NextStateIn = WAIT_FOR_PREAMBLE;
				
				// Determine what the command was
				ProcessCommand();
			}
			else
				NextStateIn = WAIT_FOR_END;
		}
		break;		
	}
		
	// Update the state machine
	CurrentStateIn = NextStateIn;	
}


void DebugDataOut()
{
	static unsigned commandSent;
	static unsigned char dataBytesSent;
	
	
	// Make sure to exit the when no data is left to write
	if(commandSent == true)
	{
		clear(SCI1C2, SCI1C2_TE_MASK);
		
		SCI1D = 0x00;
		
		commandSent = false;
		SendingCommand = false;
		
		return;
	}
	else
	{
		if(SendingCommand != true)
		{
			Command = CommandOut;
			SendingCommand = true;
		}
		set(SCI1C2, SCI1C2_TE_MASK);		
	}
	

	switch(CurrentStateOut)
	{
		case SEND_PREAMBLE:
		{
			if( DebugSend(0xAA) == 1)
				NextStateOut = SEND_TYPE;
			else
				NextStateOut = SEND_PREAMBLE;
		}
		break;
		case SEND_TYPE:
		{
			if( DebugSend(Command.Type) == 1)
				NextStateOut = SEND_NUMBER;
			else
				NextStateOut = SEND_TYPE;
		}
		break;
		case SEND_NUMBER:
		{
			if( DebugSend(Command.Number) == 1)
				NextStateOut = SEND_COUNT;
			else
				NextStateOut = SEND_NUMBER;
		}
		break;
		case SEND_COUNT:
		{
			if(DebugSend(Command.DataBytes) == 1)
			{
				NextStateOut = SEND_DATA;
				dataBytesSent = 0;
			}
			else
				NextStateOut = SEND_COUNT;
		}
		break;
		case SEND_DATA:
		{
			if(dataBytesSent < Command.DataBytes - 1)
			{
				if( DebugSend(Command.Payload.Data[dataBytesSent]) == 1)
				{
					dataBytesSent++;
					NextStateOut = SEND_DATA;
				}
			}
			else 
			{
				if( DebugSend(Command.Payload.Data[dataBytesSent]) == 1)
					NextStateOut = SEND_CHECKSUM;
				else
					NextStateOut = SEND_DATA;
			}			
		}		
		break;
		case SEND_CHECKSUM:
		{
			if(DebugSend(CommandOut.Checksum) == 1)
				NextStateOut = SEND_END;
			else
				NextStateOut = SEND_CHECKSUM;
		}
		break;
		case SEND_END:
			if(DebugSend(0xAF) == 1)
			{
				NextStateOut = SEND_PREAMBLE;
				commandSent = true;
			}
			else
				NextStateOut = SEND_END;
		break;
			
	}
	

	CurrentStateOut = NextStateOut;

}

// calculates the checksum for the command and determines if its accurate
unsigned char CheckChecksum()
{
	unsigned char i = 0;
	unsigned char rChecksum = 0;
	
	rChecksum = CommandIn.Type + CommandIn.Number + CommandIn.DataBytes;
	
	for( i = 0; i < CommandIn.DataBytes; i++)
	{
		rChecksum += CommandIn.Payload.Data[i];
	}
	
	if(rChecksum == CommandIn.Checksum)
		return true;
	else
		return false;
}

// determines what to do with an incoming command
void ProcessCommand(void)
{
	// If the checksum is not correct, discard the command
	if( CheckChecksum() == false )
		return;
	
	// reset the diagnostic mode counter to prevent car from stopping
	// if diagnostic mode is enabled
	DiagMsgRx = 0;
	
	switch(CommandIn.Number)
	{
		case SET_TURN:
		{				
			ServoSetDutyCycle(CommandIn.Payload.Words.Data0);
			
			GetTurn();
		}
		break;		
		case GET_TURN:
		{
			GetTurn();
		}
		break;
		case SET_PWM_SPEED:
		{
			MotorSetDutyCycle(CommandIn.Payload.Words.Data0);
			
			GetPWMSpeed();
		}
		break;
		case GET_PWM_SPEED:
		{
			GetPWMSpeed();
		}
		break;
		case ALIVE:
			DiagMsgRx = 0;
		break;
		case GET_IR_SENSOR:
		{
			GetIRSensor();
		}			
		break;
		case GET_ALL_DATA:
		{
			GetAllData();
		}
		break;
		case SET_AUTOSTOP_MODE:
		{
			SetAutoStopMode();
		}
		break;
		case SET_SPEED_LIMIT:
		{
			SetSpeedLimit();
		}
		break;
		case GET_SPEED_LIMIT:
		{
			GetSpeedLimit();
		}
		break;
		case SET_SENSOR_WEIGHTS:
		{
			SetSensorWeights();
		}
		break;
		case GET_SENSOR_WEIGHTS:
		{
			GetSensorWeights();
		}
		break;
		case SET_COEFFICIENTS:
		{
			SetPIDCoefficients();
		}
		break;
		case GET_COEFFICIENTS:
		{
			GetPIDCoefficients();
		}
		break;
	}
}

// Sends the current PWM value for turning
void GetTurn()
{
	CommandOut.Type = Ack;
	CommandOut.Number = GET_TURN;
	CommandOut.DataBytes = 2;
	CommandOut.Payload.Words.Data0 = *ServoGetDutyCycle() - SERVO_DUTY_CYCLE_MIN;
	DebugDataOut();
}
// Sends the current PWM value for speed
void GetPWMSpeed()
{
	CommandOut.Type = Ack;
	CommandOut.Number = SET_PWM_SPEED;
	CommandOut.DataBytes = 2;
	CommandOut.Payload.Words.Data0 = *MotorGetDutyCycle() - SPEED_DUTY_CYCLE_MIN;
	DebugDataOut();
}
// Sends the value of an IR sensor based on the received command
void GetIRSensor()
{
	CommandOut.Type = Ack;
	CommandOut.Number = GET_IR_SENSOR;
	CommandOut.DataBytes = 1;
	CommandOut.Payload.Data[0]= *GetSensor(CommandIn.Payload.Data[0]);
	DebugDataOut();
}
// returns all of the sensor values
void GetAllSensors()
{
	CommandOut.Type = Ack;
	CommandOut.Number = GET_ALL_SENSORS;
	CommandOut.DataBytes = 8;
	CommandOut.Payload.Data[0] = *GetSensor(0);
	CommandOut.Payload.Data[1] = *GetSensor(1);
	CommandOut.Payload.Data[2] = *GetSensor(2);
	CommandOut.Payload.Data[3] = *GetSensor(3);
	CommandOut.Payload.Data[4] = *GetSensor(4);
	CommandOut.Payload.Data[5] = *GetSensor(5);
	CommandOut.Payload.Data[6] = *GetSensor(6);
	CommandOut.Payload.Data[7] = *GetSensor(7);
	DebugDataOut();
}

// returns all of the diagnostic data in a single command
void GetAllData()
{
	CommandOut.Type = Ack;
	CommandOut.Number = GET_ALL_DATA;
	CommandOut.DataBytes = 22;
	CommandOut.Payload.Words.Data0 = *ServoGetDutyCycle() - SERVO_DUTY_CYCLE_MIN;
	CommandOut.Payload.Words.Data1 = *MotorGetDutyCycle() - SPEED_DUTY_CYCLE_MIN;
	CommandOut.Payload.Words.Data2 = *MotorGetPhysicalSpeed();
	CommandOut.Payload.Words.Data3 = *MotorGetRPM();
	CommandOut.Payload.Data[8] = *GetSensor(0);
	CommandOut.Payload.Data[9] = *GetSensor(1);
	CommandOut.Payload.Data[10] = *GetSensor(2);
	CommandOut.Payload.Data[11] = *GetSensor(3);
	CommandOut.Payload.Data[12] = *GetSensor(4);
	CommandOut.Payload.Data[13] = *GetSensor(5);
	CommandOut.Payload.Data[14] = *GetSensor(6);
	CommandOut.Payload.Data[15] = *GetSensor(7);
	CommandOut.Payload.Data[16] = *GetAccelerometerX();
	CommandOut.Payload.Data[17] = *GetAccelerometerY();
	CommandOut.Payload.Data[18] = *GetAccelerometerZ();
	CommandOut.Payload.Words.Data10 = GetPID();
	DebugDataOut();

}

// returns the accelerometer data
// currently not implemented
void GetAcceleromater()
{
	/*
	CommandOut.Type = Ack;
	CommandOut.Number = GET_ACCELEROMETER;
	CommandOut.DataBytes = 3;
	*/
}

// controls the auto stop mode of the car
void SetAutoStopMode()
{
	if(CommandIn.Payload.Data[0] == 1)
	{
		DiagMode = 1;
		DiagMsgRxTime = CommandIn.Payload.Data[1];
	}
	else
	{
		DiagMode = 0;
	}	
	
}
// returns the current autostop mode of the car
void GetAutoStopMode()
{	
	CommandOut.Type = Ack;
	CommandOut.Number = SET_AUTOSTOP_MODE;
	CommandOut.DataBytes = 2;
	CommandOut.Payload.Data[0] = DiagMode;
	CommandOut.Payload.Data[1] = DiagMsgRxTime;
	DebugDataOut();
}
// sets the speed limit of the car
void SetSpeedLimit()
{
	if(CommandIn.Payload.Data[0] == 1)
	{
		MotorSpeedLimitEnable();
		MotorSetSpeedLimit(CommandIn.Payload.Words.Data1);
	}
	else
		MotorSpeedLimitDisable();
	
	GetSpeedLimit();
}
// returns the current speed limit of the car
void GetSpeedLimit()
{
	CommandOut.Type = Ack;
	CommandOut.Number = GET_SPEED_LIMIT;
	CommandOut.DataBytes = 4;
	CommandOut.Payload.Data[0] = *MotorSpeedLimitSet();
	CommandOut.Payload.Words.Data1 = *MotorGetSpeedLimit();
	DebugDataOut();
}
// sets the sensor weights
void SetSensorWeights()
{
	SetSensorWeight(0,CommandIn.Payload.Words.Data0);
	SetSensorWeight(1,CommandIn.Payload.Words.Data1);
	SetSensorWeight(2,CommandIn.Payload.Words.Data2);
	SetSensorWeight(3,CommandIn.Payload.Words.Data3);
	SetSensorWeight(4,CommandIn.Payload.Words.Data4);
	SetSensorWeight(5,CommandIn.Payload.Words.Data5);
	SetSensorWeight(6,CommandIn.Payload.Words.Data6);
	SetSensorWeight(7,CommandIn.Payload.Words.Data7);
	
	GetSensorWeights();
}

void GetSensorWeights()
{
	CommandOut.Type = Ack;
	CommandOut.Number = GET_SENSOR_WEIGHTS;
	CommandOut.DataBytes = 16;
	CommandOut.Payload.Words.Data0 = GetSensorWeight(0);
	CommandOut.Payload.Words.Data1 = GetSensorWeight(1);
	CommandOut.Payload.Words.Data2 = GetSensorWeight(2);
	CommandOut.Payload.Words.Data3 = GetSensorWeight(3);
	CommandOut.Payload.Words.Data4 = GetSensorWeight(4);
	CommandOut.Payload.Words.Data5 = GetSensorWeight(5);
	CommandOut.Payload.Words.Data6 = GetSensorWeight(6);
	CommandOut.Payload.Words.Data7 = GetSensorWeight(7);
	DebugDataOut();	
}
// sets the steering controller algorithm
void SetPIDCoefficients()
{
	SetCoefficients(CommandIn.Payload.Words.Data0, 
			        CommandIn.Payload.Words.Data1,
			        CommandIn.Payload.Words.Data2);
	
	GetPIDCoefficients();
}
// returns the current PID coefficients
void GetPIDCoefficients()
{
	CommandOut.Type = Ack;
	CommandOut.Number = GET_COEFFICIENTS;
	CommandOut.DataBytes = 6;
	CommandOut.Payload.Words.Data0 = GetKp();
	CommandOut.Payload.Words.Data1 = GetKi();
	CommandOut.Payload.Words.Data2 = GetKd();
	DebugDataOut();	
}

// interrupt called when UART receives data
interrupt VectorNumber_Vsci1rx void SCI1Receive(void)
{
	// Stores the value read by the SCI
	unsigned char dataIn;

	// clear the interrupt
	dataIn = SCI1S1;
	dataIn = SCI1D;
	
	// Process the data
	DebugDataIn(dataIn);
}

// interrupt called when UART transmits data
interrupt VectorNumber_Vsci1tx void SCI1Transmit(void)
{	
	unsigned char temp;
	temp = SCI1S1;

	DebugDataOut();
}
