//---------------------------------------------------------------------------------------------
// main.h
// Author: Brian Stack
// Description: Defines the methods and variables for the main
//---------------------------------------------------------------------------------------------

#ifndef MAIN_H_
#define MAIN_H_



#define KILL_THE_DOG SOPT1 &=~SOPT1_COPE_MASK


void CheckDiagnostics(void);
void CheckLine(void);
void KillAll(void);
void WaitForStart(void);

extern unsigned char SystemTick;
	
#endif /* MAIN_H_ */
