//---------------------------------------------------------------------------------------------
// CPUDebug.h
// Author: Brian Stack
// Description: Defines the methods and variables for the CPUDebug functionality
//---------------------------------------------------------------------------------------------

#ifndef _CPU_DEBUG_H_
#define _CPU_DEBUG_H_

#define CMD_PREAMBLE 	   0xAA
#define CMD_END			   0xAF

#define DEBUG_MSG_TIME 0x1A; // a value of 1 = 20ms

extern unsigned char DiagMode;

extern volatile unsigned char DiagMsgRx;
extern volatile unsigned char DiagMsgRxTime;

void InitCPUDebug(void);

unsigned char DebugSend(unsigned char data);

// Processes the received data from the SCI
void DebugDataIn(unsigned char);

// Sends data out
void DebugDataOut(void);

void ProcessCommand(void);

extern volatile unsigned char WaitForBreak;
void SendBreak(void);

enum CommandType { Set = 0x00, Request = 0x01, Ack = 0x02 };

// Command structure
struct CommandStruct
{
	volatile unsigned char Type;
	volatile unsigned char Number;
	volatile unsigned char DataBytes;
	volatile unsigned char Checksum;
	union
	{
		volatile struct
		{
			volatile word Data0;
			volatile word Data1;
			volatile word Data2;
			volatile word Data3;
			volatile word Data4;
			volatile word Data5;
			volatile word Data6;
			volatile word Data7;
			volatile word Data8;
			volatile word Data9;
			volatile word Data10;
			volatile word Data11;
			volatile word Data12;
			volatile word Data13;
			volatile word Data14;
			volatile word Data15;
		} Words;		
		volatile unsigned char Data[32];
	} Payload;	
};



extern volatile struct CommandStruct CommandIn;
extern volatile struct CommandStruct CommandOut;


unsigned char CheckChecksum(void);

// List of all Get functions
void GetIRSensor(void);
void GetAllSensors(void);
void GetPWMSpeed(void);
void GetTurn(void);
void GetAllData(void);
void GetAccelerometer(void);
void SetAutoStopMode(void);
void GetAutoStopMode(void);
void SetSpeedLimit(void);
void GetSpeedLimit(void);
void GetRPM(void);
void SetPIDCoefficients(void);
void GetPIDCoefficients(void);
void SetSensorWeights(void);
void GetSensorWeights(void);

#endif
