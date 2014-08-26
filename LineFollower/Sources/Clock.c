//---------------------------------------------------------------------------------------------------
// Clock.c
// Author: Eli Hughes
// Modidifed By: Brian Stack
// Description: Implements the methods declared in Clock.h        
//--------------------------------------------------------------------------------------------------

#include "derivative.h" /* include peripheral declarations */
#include "Clock.h"

void InitClock()
{

  //Enable our external clock (32.768Khz Crystal)

  ICSC2 |= ICSC2_ERCLKEN_MASK | ICSC2_EREFSTEN_MASK;
   //Request Oscillator for external reference
  ICSC2 |= ICSC2_EREFS_MASK;
  
    
  while(!(ICSSC & ICSSC_OSCINIT_MASK))
  {
    //Wait for External Oscillator to come up.  
  }
  
  // Set the prescaler to 1216
    ICSSC |= ICSSC_DRST_DRS0_MASK;
    //ICSSC |= ICSSC_DMX32_MASK;
    
  //Make sure the FLL is not divided (FLL/1)
  ICSC2 &= ~(ICSC2_BDIV0_MASK | ICSC2_BDIV1_MASK);


  //Use the external reference for the FLL
  ICSC1 &= ~ICSC1_IREFS_MASK;

  //Select the FLL for ICS_OUT 
  ICSC1 &= ~(ICSC1_CLKS0_MASK |ICSC1_CLKS1_MASK);

  //The main CPU bus is running at 32.768KHZ * 512   = 33554432
  //The peripheral bus is running at CPU Bus / 2 = 16777216

}
