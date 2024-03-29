/* Based on CPU DB MC9S08LL64_80, version 3.00.031 (RegistersPrg V2.31) */
/*
** ###################################################################
**     Filename  : mc9s08ll64.h
**     Processor : MC9S08LL64CLK
**     FileFormat: V2.31
**     DataSheet : MC9S08LL64RM Rev. 5 10/2009
**     Compiler  : CodeWarrior compiler
**     Date/Time : 6.1.2010, 10:29
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**      - 20.02.2009, V3.00.0:
**              - Renamed VREFx module registers: VREFTRMx -> VREFxTRM, VREFSCx -> VREFxSC.
**              - Redefined ADC module to use 12-bit instead of 16-bit resolution. Removed bits SPMSC1[BGBE,BGBDS].
**              -   REASON: Changes in the Reference Manual (from Rev. 2 6/2008 to Rev.2 12/2008).
**      - 3.04.2009, V3.00.1:
**              - Added bits SPMSC1[BGBE,BGBDS].
**              -   REASON: Changes in the Reference Manual (from Rev.2 12/2008 to Rev. 3 03/2009).
**      - 25.9.2009, V3.00.2:
**              - Renamed register: ADCCV1[CV1] -> ADCCV[CV].
**              -   REASON: Bug-Fix (#7672 in Issue Manager).
**      - 27.11.2009, V3.00.3:
**              - Removed XA16 bit from PPAGE register. Updated the register DBGCAX, DBGCBX, DBGCCX. Added DBGFX register.
**              -   REASON: Bug-Fix (#7659 in Issue Manager).
**
**     File-Format-Revisions:
**      - 17.3.2009, V2.27 :
**               - Merged bit-group is not generated, if the name matches with another bit name in the register
**      - 6.4.2009, V2.28 :
**               - Fixed generation of merged bits for bit-groups with a digit at the end, if group-name is defined in CPUDB
**      - 3.8.2009, V2.29 :
**               - If there is just one bits group matching register name, single bits are not generated
**      - 10.9.2009, V2.30 :
**               - Fixed generation of registers arrays.
**      - 15.10.2009, V2.31 :
**               - HCS08 family: Bits and bit-groups are published for 16-bit registers: 8-bit overlay registers are required.
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user�s reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/

#ifndef _MC9S08LL64_H
#define _MC9S08LL64_H

/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

/* Watchdog reset macro */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() {asm sta SRS;}
#endif
#endif /* __RESET_WATCHDOG */

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */

/**************** interrupt vector numbers ****************/
#define VectorNumber_Vsci2tx            22
#define VectorNumber_Vsci2rx            21
#define VectorNumber_Vsci2err           20
#define VectorNumber_Vtod               19
#define VectorNumber_Vacmp              18
#define VectorNumber_Vadc               17
#define VectorNumber_Vkeyboard          16
#define VectorNumber_Viic               15
#define VectorNumber_Vsci1tx            14
#define VectorNumber_Vsci1rx            13
#define VectorNumber_Vsci1err           12
#define VectorNumber_Vspi               11
#define VectorNumber_Vlcd               10
#define VectorNumber_Vtpm2ovf           9
#define VectorNumber_Vtpm2ch1           8
#define VectorNumber_Vtpm2ch0           7
#define VectorNumber_Vtpm1ovf           6
#define VectorNumber_Vtpm1ch1           5
#define VectorNumber_Vtpm1ch0           4
#define VectorNumber_Vlvd               3
#define VectorNumber_Virq               2
#define VectorNumber_Vswi               1
#define VectorNumber_Vreset             0

/**************** interrupt vector table ****************/
#define Vsci2tx                         0x0000FFD2
#define Vsci2rx                         0x0000FFD4
#define Vsci2err                        0x0000FFD6
#define Vtod                            0x0000FFD8
#define Vacmp                           0x0000FFDA
#define Vadc                            0x0000FFDC
#define Vkeyboard                       0x0000FFDE
#define Viic                            0x0000FFE0
#define Vsci1tx                         0x0000FFE2
#define Vsci1rx                         0x0000FFE4
#define Vsci1err                        0x0000FFE6
#define Vspi                            0x0000FFE8
#define Vlcd                            0x0000FFEA
#define Vtpm2ovf                        0x0000FFEC
#define Vtpm2ch1                        0x0000FFEE
#define Vtpm2ch0                        0x0000FFF0
#define Vtpm1ovf                        0x0000FFF2
#define Vtpm1ch1                        0x0000FFF4
#define Vtpm1ch0                        0x0000FFF6
#define Vlvd                            0x0000FFF8
#define Virq                            0x0000FFFA
#define Vswi                            0x0000FFFC
#define Vreset                          0x0000FFFE

/**************** registers I/O map ****************/

/*** PTAD - Port A Data Register; 0x00000000 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAD0       :1;                                       /* Port A Data Register Bit 0 */
    byte PTAD1       :1;                                       /* Port A Data Register Bit 1 */
    byte PTAD2       :1;                                       /* Port A Data Register Bit 2 */
    byte PTAD3       :1;                                       /* Port A Data Register Bit 3 */
    byte PTAD4       :1;                                       /* Port A Data Register Bit 4 */
    byte PTAD5       :1;                                       /* Port A Data Register Bit 5 */
    byte PTAD6       :1;                                       /* Port A Data Register Bit 6 */
    byte PTAD7       :1;                                       /* Port A Data Register Bit 7 */
  } Bits;
} PTADSTR;
extern volatile PTADSTR _PTAD @0x00000000;
#define PTAD                            _PTAD.Byte
#define PTAD_PTAD0                      _PTAD.Bits.PTAD0
#define PTAD_PTAD1                      _PTAD.Bits.PTAD1
#define PTAD_PTAD2                      _PTAD.Bits.PTAD2
#define PTAD_PTAD3                      _PTAD.Bits.PTAD3
#define PTAD_PTAD4                      _PTAD.Bits.PTAD4
#define PTAD_PTAD5                      _PTAD.Bits.PTAD5
#define PTAD_PTAD6                      _PTAD.Bits.PTAD6
#define PTAD_PTAD7                      _PTAD.Bits.PTAD7

#define PTAD_PTAD0_MASK                 1
#define PTAD_PTAD1_MASK                 2
#define PTAD_PTAD2_MASK                 4
#define PTAD_PTAD3_MASK                 8
#define PTAD_PTAD4_MASK                 16
#define PTAD_PTAD5_MASK                 32
#define PTAD_PTAD6_MASK                 64
#define PTAD_PTAD7_MASK                 128


/*** PTADD - Port A Data Direction Register; 0x00000001 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADD0      :1;                                       /* Data Direction for Port A Bit 0 */
    byte PTADD1      :1;                                       /* Data Direction for Port A Bit 1 */
    byte PTADD2      :1;                                       /* Data Direction for Port A Bit 2 */
    byte PTADD3      :1;                                       /* Data Direction for Port A Bit 3 */
    byte PTADD4      :1;                                       /* Data Direction for Port A Bit 4 */
    byte PTADD5      :1;                                       /* Data Direction for Port A Bit 5 */
    byte PTADD6      :1;                                       /* Data Direction for Port A Bit 6 */
    byte PTADD7      :1;                                       /* Data Direction for Port A Bit 7 */
  } Bits;
} PTADDSTR;
extern volatile PTADDSTR _PTADD @0x00000001;
#define PTADD                           _PTADD.Byte
#define PTADD_PTADD0                    _PTADD.Bits.PTADD0
#define PTADD_PTADD1                    _PTADD.Bits.PTADD1
#define PTADD_PTADD2                    _PTADD.Bits.PTADD2
#define PTADD_PTADD3                    _PTADD.Bits.PTADD3
#define PTADD_PTADD4                    _PTADD.Bits.PTADD4
#define PTADD_PTADD5                    _PTADD.Bits.PTADD5
#define PTADD_PTADD6                    _PTADD.Bits.PTADD6
#define PTADD_PTADD7                    _PTADD.Bits.PTADD7

#define PTADD_PTADD0_MASK               1
#define PTADD_PTADD1_MASK               2
#define PTADD_PTADD2_MASK               4
#define PTADD_PTADD3_MASK               8
#define PTADD_PTADD4_MASK               16
#define PTADD_PTADD5_MASK               32
#define PTADD_PTADD6_MASK               64
#define PTADD_PTADD7_MASK               128


/*** PTBD - Port B Data Register; 0x00000002 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBD0       :1;                                       /* Port B Data Register Bit 0 */
    byte PTBD1       :1;                                       /* Port B Data Register Bit 1 */
    byte PTBD2       :1;                                       /* Port B Data Register Bit 2 */
    byte             :1; 
    byte PTBD4       :1;                                       /* Port B Data Register Bit 4 */
    byte PTBD5       :1;                                       /* Port B Data Register Bit 5 */
    byte PTBD6       :1;                                       /* Port B Data Register Bit 6 */
    byte PTBD7       :1;                                       /* Port B Data Register Bit 7 */
  } Bits;
  struct {
    byte grpPTBD :3;
    byte         :1;
    byte grpPTBD_4 :4;
  } MergedBits;
} PTBDSTR;
extern volatile PTBDSTR _PTBD @0x00000002;
#define PTBD                            _PTBD.Byte
#define PTBD_PTBD0                      _PTBD.Bits.PTBD0
#define PTBD_PTBD1                      _PTBD.Bits.PTBD1
#define PTBD_PTBD2                      _PTBD.Bits.PTBD2
#define PTBD_PTBD4                      _PTBD.Bits.PTBD4
#define PTBD_PTBD5                      _PTBD.Bits.PTBD5
#define PTBD_PTBD6                      _PTBD.Bits.PTBD6
#define PTBD_PTBD7                      _PTBD.Bits.PTBD7
#define PTBD_PTBD                       _PTBD.MergedBits.grpPTBD
#define PTBD_PTBD_4                     _PTBD.MergedBits.grpPTBD_4

#define PTBD_PTBD0_MASK                 1
#define PTBD_PTBD1_MASK                 2
#define PTBD_PTBD2_MASK                 4
#define PTBD_PTBD4_MASK                 16
#define PTBD_PTBD5_MASK                 32
#define PTBD_PTBD6_MASK                 64
#define PTBD_PTBD7_MASK                 128
#define PTBD_PTBD_MASK                  7
#define PTBD_PTBD_BITNUM                0
#define PTBD_PTBD_4_MASK                240
#define PTBD_PTBD_4_BITNUM              4


/*** PTBDD - Port B Data Direction Register; 0x00000003 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDD0      :1;                                       /* Data Direction for Port B Bit 0 */
    byte PTBDD1      :1;                                       /* Data Direction for Port B Bit 1 */
    byte PTBDD2      :1;                                       /* Data Direction for Port B Bit 2 */
    byte             :1; 
    byte PTBDD4      :1;                                       /* Data Direction for Port B Bit 4 */
    byte PTBDD5      :1;                                       /* Data Direction for Port B Bit 5 */
    byte PTBDD6      :1;                                       /* Data Direction for Port B Bit 6 */
    byte PTBDD7      :1;                                       /* Data Direction for Port B Bit 7 */
  } Bits;
  struct {
    byte grpPTBDD :3;
    byte         :1;
    byte grpPTBDD_4 :4;
  } MergedBits;
} PTBDDSTR;
extern volatile PTBDDSTR _PTBDD @0x00000003;
#define PTBDD                           _PTBDD.Byte
#define PTBDD_PTBDD0                    _PTBDD.Bits.PTBDD0
#define PTBDD_PTBDD1                    _PTBDD.Bits.PTBDD1
#define PTBDD_PTBDD2                    _PTBDD.Bits.PTBDD2
#define PTBDD_PTBDD4                    _PTBDD.Bits.PTBDD4
#define PTBDD_PTBDD5                    _PTBDD.Bits.PTBDD5
#define PTBDD_PTBDD6                    _PTBDD.Bits.PTBDD6
#define PTBDD_PTBDD7                    _PTBDD.Bits.PTBDD7
#define PTBDD_PTBDD                     _PTBDD.MergedBits.grpPTBDD
#define PTBDD_PTBDD_4                   _PTBDD.MergedBits.grpPTBDD_4

#define PTBDD_PTBDD0_MASK               1
#define PTBDD_PTBDD1_MASK               2
#define PTBDD_PTBDD2_MASK               4
#define PTBDD_PTBDD4_MASK               16
#define PTBDD_PTBDD5_MASK               32
#define PTBDD_PTBDD6_MASK               64
#define PTBDD_PTBDD7_MASK               128
#define PTBDD_PTBDD_MASK                7
#define PTBDD_PTBDD_BITNUM              0
#define PTBDD_PTBDD_4_MASK              240
#define PTBDD_PTBDD_4_BITNUM            4


/*** PTCD - Port C Data Register; 0x00000004 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCD0       :1;                                       /* Port C Data Register Bit 0 */
    byte PTCD1       :1;                                       /* Port C Data Register Bit 1 */
    byte PTCD2       :1;                                       /* Port C Data Register Bit 2 */
    byte PTCD3       :1;                                       /* Port C Data Register Bit 3 */
    byte PTCD4       :1;                                       /* Port C Data Register Bit 4 */
    byte PTCD5       :1;                                       /* Port C Data Register Bit 5 */
    byte PTCD6       :1;                                       /* Port C Data Register Bit 6 */
    byte PTCD7       :1;                                       /* Port C Data Register Bit 7 */
  } Bits;
} PTCDSTR;
extern volatile PTCDSTR _PTCD @0x00000004;
#define PTCD                            _PTCD.Byte
#define PTCD_PTCD0                      _PTCD.Bits.PTCD0
#define PTCD_PTCD1                      _PTCD.Bits.PTCD1
#define PTCD_PTCD2                      _PTCD.Bits.PTCD2
#define PTCD_PTCD3                      _PTCD.Bits.PTCD3
#define PTCD_PTCD4                      _PTCD.Bits.PTCD4
#define PTCD_PTCD5                      _PTCD.Bits.PTCD5
#define PTCD_PTCD6                      _PTCD.Bits.PTCD6
#define PTCD_PTCD7                      _PTCD.Bits.PTCD7

#define PTCD_PTCD0_MASK                 1
#define PTCD_PTCD1_MASK                 2
#define PTCD_PTCD2_MASK                 4
#define PTCD_PTCD3_MASK                 8
#define PTCD_PTCD4_MASK                 16
#define PTCD_PTCD5_MASK                 32
#define PTCD_PTCD6_MASK                 64
#define PTCD_PTCD7_MASK                 128


/*** PTCDD - Port C Data Direction Register; 0x00000005 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCDD0      :1;                                       /* Data Direction for Port C Bit 0 */
    byte PTCDD1      :1;                                       /* Data Direction for Port C Bit 1 */
    byte PTCDD2      :1;                                       /* Data Direction for Port C Bit 2 */
    byte PTCDD3      :1;                                       /* Data Direction for Port C Bit 3 */
    byte PTCDD4      :1;                                       /* Data Direction for Port C Bit 4 */
    byte PTCDD5      :1;                                       /* Data Direction for Port C Bit 5 */
    byte PTCDD6      :1;                                       /* Data Direction for Port C Bit 6 */
    byte PTCDD7      :1;                                       /* Data Direction for Port C Bit 7 */
  } Bits;
} PTCDDSTR;
extern volatile PTCDDSTR _PTCDD @0x00000005;
#define PTCDD                           _PTCDD.Byte
#define PTCDD_PTCDD0                    _PTCDD.Bits.PTCDD0
#define PTCDD_PTCDD1                    _PTCDD.Bits.PTCDD1
#define PTCDD_PTCDD2                    _PTCDD.Bits.PTCDD2
#define PTCDD_PTCDD3                    _PTCDD.Bits.PTCDD3
#define PTCDD_PTCDD4                    _PTCDD.Bits.PTCDD4
#define PTCDD_PTCDD5                    _PTCDD.Bits.PTCDD5
#define PTCDD_PTCDD6                    _PTCDD.Bits.PTCDD6
#define PTCDD_PTCDD7                    _PTCDD.Bits.PTCDD7

#define PTCDD_PTCDD0_MASK               1
#define PTCDD_PTCDD1_MASK               2
#define PTCDD_PTCDD2_MASK               4
#define PTCDD_PTCDD3_MASK               8
#define PTCDD_PTCDD4_MASK               16
#define PTCDD_PTCDD5_MASK               32
#define PTCDD_PTCDD6_MASK               64
#define PTCDD_PTCDD7_MASK               128


/*** PTDD - Port D Data Register; 0x00000006 ***/
typedef union {
  byte Byte;
  struct {
    byte PTDD0       :1;                                       /* Port D Data Register Bit 0 */
    byte PTDD1       :1;                                       /* Port D Data Register Bit 1 */
    byte PTDD2       :1;                                       /* Port D Data Register Bit 2 */
    byte PTDD3       :1;                                       /* Port D Data Register Bit 3 */
    byte PTDD4       :1;                                       /* Port D Data Register Bit 4 */
    byte PTDD5       :1;                                       /* Port D Data Register Bit 5 */
    byte PTDD6       :1;                                       /* Port D Data Register Bit 6 */
    byte PTDD7       :1;                                       /* Port D Data Register Bit 7 */
  } Bits;
} PTDDSTR;
extern volatile PTDDSTR _PTDD @0x00000006;
#define PTDD                            _PTDD.Byte
#define PTDD_PTDD0                      _PTDD.Bits.PTDD0
#define PTDD_PTDD1                      _PTDD.Bits.PTDD1
#define PTDD_PTDD2                      _PTDD.Bits.PTDD2
#define PTDD_PTDD3                      _PTDD.Bits.PTDD3
#define PTDD_PTDD4                      _PTDD.Bits.PTDD4
#define PTDD_PTDD5                      _PTDD.Bits.PTDD5
#define PTDD_PTDD6                      _PTDD.Bits.PTDD6
#define PTDD_PTDD7                      _PTDD.Bits.PTDD7

#define PTDD_PTDD0_MASK                 1
#define PTDD_PTDD1_MASK                 2
#define PTDD_PTDD2_MASK                 4
#define PTDD_PTDD3_MASK                 8
#define PTDD_PTDD4_MASK                 16
#define PTDD_PTDD5_MASK                 32
#define PTDD_PTDD6_MASK                 64
#define PTDD_PTDD7_MASK                 128


/*** PTDDD - Port D Data Direction Register; 0x00000007 ***/
typedef union {
  byte Byte;
  struct {
    byte PTDDD0      :1;                                       /* Data Direction for Port D Bit 0 */
    byte PTDDD1      :1;                                       /* Data Direction for Port D Bit 1 */
    byte PTDDD2      :1;                                       /* Data Direction for Port D Bit 2 */
    byte PTDDD3      :1;                                       /* Data Direction for Port D Bit 3 */
    byte PTDDD4      :1;                                       /* Data Direction for Port D Bit 4 */
    byte PTDDD5      :1;                                       /* Data Direction for Port D Bit 5 */
    byte PTDDD6      :1;                                       /* Data Direction for Port D Bit 6 */
    byte PTDDD7      :1;                                       /* Data Direction for Port D Bit 7 */
  } Bits;
} PTDDDSTR;
extern volatile PTDDDSTR _PTDDD @0x00000007;
#define PTDDD                           _PTDDD.Byte
#define PTDDD_PTDDD0                    _PTDDD.Bits.PTDDD0
#define PTDDD_PTDDD1                    _PTDDD.Bits.PTDDD1
#define PTDDD_PTDDD2                    _PTDDD.Bits.PTDDD2
#define PTDDD_PTDDD3                    _PTDDD.Bits.PTDDD3
#define PTDDD_PTDDD4                    _PTDDD.Bits.PTDDD4
#define PTDDD_PTDDD5                    _PTDDD.Bits.PTDDD5
#define PTDDD_PTDDD6                    _PTDDD.Bits.PTDDD6
#define PTDDD_PTDDD7                    _PTDDD.Bits.PTDDD7

#define PTDDD_PTDDD0_MASK               1
#define PTDDD_PTDDD1_MASK               2
#define PTDDD_PTDDD2_MASK               4
#define PTDDD_PTDDD3_MASK               8
#define PTDDD_PTDDD4_MASK               16
#define PTDDD_PTDDD5_MASK               32
#define PTDDD_PTDDD6_MASK               64
#define PTDDD_PTDDD7_MASK               128


/*** PTED - Port E Data Register; 0x00000008 ***/
typedef union {
  byte Byte;
  struct {
    byte PTED0       :1;                                       /* Port E Data Register Bit 0 */
    byte PTED1       :1;                                       /* Port E Data Register Bit 1 */
    byte PTED2       :1;                                       /* Port E Data Register Bit 2 */
    byte PTED3       :1;                                       /* Port E Data Register Bit 3 */
    byte PTED4       :1;                                       /* Port E Data Register Bit 4 */
    byte PTED5       :1;                                       /* Port E Data Register Bit 5 */
    byte PTED6       :1;                                       /* Port E Data Register Bit 6 */
    byte PTED7       :1;                                       /* Port E Data Register Bit 7 */
  } Bits;
} PTEDSTR;
extern volatile PTEDSTR _PTED @0x00000008;
#define PTED                            _PTED.Byte
#define PTED_PTED0                      _PTED.Bits.PTED0
#define PTED_PTED1                      _PTED.Bits.PTED1
#define PTED_PTED2                      _PTED.Bits.PTED2
#define PTED_PTED3                      _PTED.Bits.PTED3
#define PTED_PTED4                      _PTED.Bits.PTED4
#define PTED_PTED5                      _PTED.Bits.PTED5
#define PTED_PTED6                      _PTED.Bits.PTED6
#define PTED_PTED7                      _PTED.Bits.PTED7

#define PTED_PTED0_MASK                 1
#define PTED_PTED1_MASK                 2
#define PTED_PTED2_MASK                 4
#define PTED_PTED3_MASK                 8
#define PTED_PTED4_MASK                 16
#define PTED_PTED5_MASK                 32
#define PTED_PTED6_MASK                 64
#define PTED_PTED7_MASK                 128


/*** PTEDD - Port E Data Direction Register; 0x00000009 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEDD0      :1;                                       /* Data Direction for Port E Bit 0 */
    byte PTEDD1      :1;                                       /* Data Direction for Port E Bit 1 */
    byte PTEDD2      :1;                                       /* Data Direction for Port E Bit 2 */
    byte PTEDD3      :1;                                       /* Data Direction for Port E Bit 3 */
    byte PTEDD4      :1;                                       /* Data Direction for Port E Bit 4 */
    byte PTEDD5      :1;                                       /* Data Direction for Port E Bit 5 */
    byte PTEDD6      :1;                                       /* Data Direction for Port E Bit 6 */
    byte PTEDD7      :1;                                       /* Data Direction for Port E Bit 7 */
  } Bits;
} PTEDDSTR;
extern volatile PTEDDSTR _PTEDD @0x00000009;
#define PTEDD                           _PTEDD.Byte
#define PTEDD_PTEDD0                    _PTEDD.Bits.PTEDD0
#define PTEDD_PTEDD1                    _PTEDD.Bits.PTEDD1
#define PTEDD_PTEDD2                    _PTEDD.Bits.PTEDD2
#define PTEDD_PTEDD3                    _PTEDD.Bits.PTEDD3
#define PTEDD_PTEDD4                    _PTEDD.Bits.PTEDD4
#define PTEDD_PTEDD5                    _PTEDD.Bits.PTEDD5
#define PTEDD_PTEDD6                    _PTEDD.Bits.PTEDD6
#define PTEDD_PTEDD7                    _PTEDD.Bits.PTEDD7

#define PTEDD_PTEDD0_MASK               1
#define PTEDD_PTEDD1_MASK               2
#define PTEDD_PTEDD2_MASK               4
#define PTEDD_PTEDD3_MASK               8
#define PTEDD_PTEDD4_MASK               16
#define PTEDD_PTEDD5_MASK               32
#define PTEDD_PTEDD6_MASK               64
#define PTEDD_PTEDD7_MASK               128


/*** KBISC - KBI Status and Control Register; 0x0000000C ***/
typedef union {
  byte Byte;
  struct {
    byte KBIMOD      :1;                                       /* Keyboard Detection Mode */
    byte KBIE        :1;                                       /* Keyboard Interrupt Enable */
    byte KBACK       :1;                                       /* Keyboard Interrupt Acknowledge */
    byte KBF         :1;                                       /* Keyboard Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} KBISCSTR;
extern volatile KBISCSTR _KBISC @0x0000000C;
#define KBISC                           _KBISC.Byte
#define KBISC_KBIMOD                    _KBISC.Bits.KBIMOD
#define KBISC_KBIE                      _KBISC.Bits.KBIE
#define KBISC_KBACK                     _KBISC.Bits.KBACK
#define KBISC_KBF                       _KBISC.Bits.KBF

#define KBISC_KBIMOD_MASK               1
#define KBISC_KBIE_MASK                 2
#define KBISC_KBACK_MASK                4
#define KBISC_KBF_MASK                  8


/*** KBIPE - KBI Pin Enable Register; 0x0000000D ***/
typedef union {
  byte Byte;
  struct {
    byte KBIPE0      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 0 */
    byte KBIPE1      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 1 */
    byte KBIPE2      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 2 */
    byte KBIPE3      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 3 */
    byte KBIPE4      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 4 */
    byte KBIPE5      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 5 */
    byte KBIPE6      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 6 */
    byte KBIPE7      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 7 */
  } Bits;
} KBIPESTR;
extern volatile KBIPESTR _KBIPE @0x0000000D;
#define KBIPE                           _KBIPE.Byte
#define KBIPE_KBIPE0                    _KBIPE.Bits.KBIPE0
#define KBIPE_KBIPE1                    _KBIPE.Bits.KBIPE1
#define KBIPE_KBIPE2                    _KBIPE.Bits.KBIPE2
#define KBIPE_KBIPE3                    _KBIPE.Bits.KBIPE3
#define KBIPE_KBIPE4                    _KBIPE.Bits.KBIPE4
#define KBIPE_KBIPE5                    _KBIPE.Bits.KBIPE5
#define KBIPE_KBIPE6                    _KBIPE.Bits.KBIPE6
#define KBIPE_KBIPE7                    _KBIPE.Bits.KBIPE7

#define KBIPE_KBIPE0_MASK               1
#define KBIPE_KBIPE1_MASK               2
#define KBIPE_KBIPE2_MASK               4
#define KBIPE_KBIPE3_MASK               8
#define KBIPE_KBIPE4_MASK               16
#define KBIPE_KBIPE5_MASK               32
#define KBIPE_KBIPE6_MASK               64
#define KBIPE_KBIPE7_MASK               128


/*** KBIES - KBI Edge Select Register; 0x0000000E ***/
typedef union {
  byte Byte;
  struct {
    byte KBEDG0      :1;                                       /* Keyboard Edge Select Bit 0 */
    byte KBEDG1      :1;                                       /* Keyboard Edge Select Bit 1 */
    byte KBEDG2      :1;                                       /* Keyboard Edge Select Bit 2 */
    byte KBEDG3      :1;                                       /* Keyboard Edge Select Bit 3 */
    byte KBEDG4      :1;                                       /* Keyboard Edge Select Bit 4 */
    byte KBEDG5      :1;                                       /* Keyboard Edge Select Bit 5 */
    byte KBEDG6      :1;                                       /* Keyboard Edge Select Bit 6 */
    byte KBEDG7      :1;                                       /* Keyboard Edge Select Bit 7 */
  } Bits;
} KBIESSTR;
extern volatile KBIESSTR _KBIES @0x0000000E;
#define KBIES                           _KBIES.Byte
#define KBIES_KBEDG0                    _KBIES.Bits.KBEDG0
#define KBIES_KBEDG1                    _KBIES.Bits.KBEDG1
#define KBIES_KBEDG2                    _KBIES.Bits.KBEDG2
#define KBIES_KBEDG3                    _KBIES.Bits.KBEDG3
#define KBIES_KBEDG4                    _KBIES.Bits.KBEDG4
#define KBIES_KBEDG5                    _KBIES.Bits.KBEDG5
#define KBIES_KBEDG6                    _KBIES.Bits.KBEDG6
#define KBIES_KBEDG7                    _KBIES.Bits.KBEDG7

#define KBIES_KBEDG0_MASK               1
#define KBIES_KBEDG1_MASK               2
#define KBIES_KBEDG2_MASK               4
#define KBIES_KBEDG3_MASK               8
#define KBIES_KBEDG4_MASK               16
#define KBIES_KBEDG5_MASK               32
#define KBIES_KBEDG6_MASK               64
#define KBIES_KBEDG7_MASK               128


/*** IRQSC - Interrupt request status and control register; 0x0000000F ***/
typedef union {
  byte Byte;
  struct {
    byte IRQMOD      :1;                                       /* IRQ Detection Mode */
    byte IRQIE       :1;                                       /* IRQ Interrupt Enable */
    byte IRQACK      :1;                                       /* IRQ Acknowledge */
    byte IRQF        :1;                                       /* IRQ Flag */
    byte IRQPE       :1;                                       /* IRQ Pin Enable */
    byte IRQEDG      :1;                                       /* IRQ Edge Select */
    byte IRQPDD      :1;                                       /* IRQ Pull Device Disable */
    byte             :1; 
  } Bits;
} IRQSCSTR;
extern volatile IRQSCSTR _IRQSC @0x0000000F;
#define IRQSC                           _IRQSC.Byte
#define IRQSC_IRQMOD                    _IRQSC.Bits.IRQMOD
#define IRQSC_IRQIE                     _IRQSC.Bits.IRQIE
#define IRQSC_IRQACK                    _IRQSC.Bits.IRQACK
#define IRQSC_IRQF                      _IRQSC.Bits.IRQF
#define IRQSC_IRQPE                     _IRQSC.Bits.IRQPE
#define IRQSC_IRQEDG                    _IRQSC.Bits.IRQEDG
#define IRQSC_IRQPDD                    _IRQSC.Bits.IRQPDD

#define IRQSC_IRQMOD_MASK               1
#define IRQSC_IRQIE_MASK                2
#define IRQSC_IRQACK_MASK               4
#define IRQSC_IRQF_MASK                 8
#define IRQSC_IRQPE_MASK                16
#define IRQSC_IRQEDG_MASK               32
#define IRQSC_IRQPDD_MASK               64


/*** ADCSC1 - Status and Control Register 1A; 0x00000010 ***/
typedef union {
  byte Byte;
  struct {
    byte ADCH0       :1;                                       /* Input Channel Select Bit 0 */
    byte ADCH1       :1;                                       /* Input Channel Select Bit 1 */
    byte ADCH2       :1;                                       /* Input Channel Select Bit 2 */
    byte ADCH3       :1;                                       /* Input Channel Select Bit 3 */
    byte ADCH4       :1;                                       /* Input Channel Select Bit 4 */
    byte             :1; 
    byte AIEN        :1;                                       /* Interrupt Enable - AIEN enables conversion complete interrupts. When COCO becomes set while the respective AIEN is high, an interrupt is asserted */
    byte COCO        :1;                                       /* Conversion Complete Flag */
  } Bits;
  struct {
    byte grpADCH :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCSC1STR;
extern volatile ADCSC1STR _ADCSC1 @0x00000010;
#define ADCSC1                          _ADCSC1.Byte
#define ADCSC1_ADCH0                    _ADCSC1.Bits.ADCH0
#define ADCSC1_ADCH1                    _ADCSC1.Bits.ADCH1
#define ADCSC1_ADCH2                    _ADCSC1.Bits.ADCH2
#define ADCSC1_ADCH3                    _ADCSC1.Bits.ADCH3
#define ADCSC1_ADCH4                    _ADCSC1.Bits.ADCH4
#define ADCSC1_AIEN                     _ADCSC1.Bits.AIEN
#define ADCSC1_COCO                     _ADCSC1.Bits.COCO
#define ADCSC1_ADCH                     _ADCSC1.MergedBits.grpADCH

#define ADCSC1_ADCH0_MASK               1
#define ADCSC1_ADCH1_MASK               2
#define ADCSC1_ADCH2_MASK               4
#define ADCSC1_ADCH3_MASK               8
#define ADCSC1_ADCH4_MASK               16
#define ADCSC1_AIEN_MASK                64
#define ADCSC1_COCO_MASK                128
#define ADCSC1_ADCH_MASK                31
#define ADCSC1_ADCH_BITNUM              0


/*** ADCCFG1 - Configuration Register 1; 0x00000012 ***/
typedef union {
  byte Byte;
  struct {
    byte ADICLK0     :1;                                       /* Input Clock Select Bit 0 */
    byte ADICLK1     :1;                                       /* Input Clock Select Bit 1 */
    byte MODE0       :1;                                       /* Conversion Mode Selection Bit 0 */
    byte MODE1       :1;                                       /* Conversion Mode Selection Bit 1 */
    byte ADLSMP      :1;                                       /* Long Sample Time Configuration */
    byte ADIV0       :1;                                       /* Clock Divide Select Bit 0 */
    byte ADIV1       :1;                                       /* Clock Divide Select Bit 1 */
    byte ADLPC       :1;                                       /* Low Power Configuration */
  } Bits;
  struct {
    byte grpADICLK :2;
    byte grpMODE :2;
    byte         :1;
    byte grpADIV :2;
    byte         :1;
  } MergedBits;
} ADCCFG1STR;
extern volatile ADCCFG1STR _ADCCFG1 @0x00000012;
#define ADCCFG1                         _ADCCFG1.Byte
#define ADCCFG1_ADICLK0                 _ADCCFG1.Bits.ADICLK0
#define ADCCFG1_ADICLK1                 _ADCCFG1.Bits.ADICLK1
#define ADCCFG1_MODE0                   _ADCCFG1.Bits.MODE0
#define ADCCFG1_MODE1                   _ADCCFG1.Bits.MODE1
#define ADCCFG1_ADLSMP                  _ADCCFG1.Bits.ADLSMP
#define ADCCFG1_ADIV0                   _ADCCFG1.Bits.ADIV0
#define ADCCFG1_ADIV1                   _ADCCFG1.Bits.ADIV1
#define ADCCFG1_ADLPC                   _ADCCFG1.Bits.ADLPC
#define ADCCFG1_ADICLK                  _ADCCFG1.MergedBits.grpADICLK
#define ADCCFG1_MODE                    _ADCCFG1.MergedBits.grpMODE
#define ADCCFG1_ADIV                    _ADCCFG1.MergedBits.grpADIV

#define ADCCFG1_ADICLK0_MASK            1
#define ADCCFG1_ADICLK1_MASK            2
#define ADCCFG1_MODE0_MASK              4
#define ADCCFG1_MODE1_MASK              8
#define ADCCFG1_ADLSMP_MASK             16
#define ADCCFG1_ADIV0_MASK              32
#define ADCCFG1_ADIV1_MASK              64
#define ADCCFG1_ADLPC_MASK              128
#define ADCCFG1_ADICLK_MASK             3
#define ADCCFG1_ADICLK_BITNUM           0
#define ADCCFG1_MODE_MASK               12
#define ADCCFG1_MODE_BITNUM             2
#define ADCCFG1_ADIV_MASK               96
#define ADCCFG1_ADIV_BITNUM             5


/*** ADCCFG2 - Configuration Register 2; 0x00000013 ***/
typedef union {
  byte Byte;
  struct {
    byte ADLSTS0     :1;                                       /* Long Sample Time Select Bit 0 */
    byte ADLSTS1     :1;                                       /* Long Sample Time Select Bit 1 */
    byte ADHSC       :1;                                       /* High Speed Configuration */
    byte ADACKEN     :1;                                       /* Asynchronous Clock Output Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpADLSTS :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCCFG2STR;
extern volatile ADCCFG2STR _ADCCFG2 @0x00000013;
#define ADCCFG2                         _ADCCFG2.Byte
#define ADCCFG2_ADLSTS0                 _ADCCFG2.Bits.ADLSTS0
#define ADCCFG2_ADLSTS1                 _ADCCFG2.Bits.ADLSTS1
#define ADCCFG2_ADHSC                   _ADCCFG2.Bits.ADHSC
#define ADCCFG2_ADACKEN                 _ADCCFG2.Bits.ADACKEN
#define ADCCFG2_ADLSTS                  _ADCCFG2.MergedBits.grpADLSTS

#define ADCCFG2_ADLSTS0_MASK            1
#define ADCCFG2_ADLSTS1_MASK            2
#define ADCCFG2_ADHSC_MASK              4
#define ADCCFG2_ADACKEN_MASK            8
#define ADCCFG2_ADLSTS_MASK             3
#define ADCCFG2_ADLSTS_BITNUM           0


/*** ADCR - Data Result Register; 0x00000014 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCRH - Data Result High Register; 0x00000014 ***/
    union {
      byte Byte;
      struct {
        byte D8          :1;                                       /* ADC Result Data Bit 8 */
        byte D9          :1;                                       /* ADC Result Data Bit 9 */
        byte D10         :1;                                       /* ADC Result Data Bit 10 */
        byte D11         :1;                                       /* ADC Result Data Bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpD_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ADCRHSTR;
    #define ADCRH                       _ADCR.Overlap_STR.ADCRHSTR.Byte
    #define ADCRH_D8                    _ADCR.Overlap_STR.ADCRHSTR.Bits.D8
    #define ADCRH_D9                    _ADCR.Overlap_STR.ADCRHSTR.Bits.D9
    #define ADCRH_D10                   _ADCR.Overlap_STR.ADCRHSTR.Bits.D10
    #define ADCRH_D11                   _ADCR.Overlap_STR.ADCRHSTR.Bits.D11
    #define ADCRH_D_8                   _ADCR.Overlap_STR.ADCRHSTR.MergedBits.grpD_8
    #define ADCRH_D                     ADCRH_D_8
    
    #define ADCRH_D8_MASK               1
    #define ADCRH_D9_MASK               2
    #define ADCRH_D10_MASK              4
    #define ADCRH_D11_MASK              8
    #define ADCRH_D_8_MASK              15
    #define ADCRH_D_8_BITNUM            0
    

    /*** ADCRL - Data Result Low Register; 0x00000015 ***/
    union {
      byte Byte;
      struct {
        byte D0          :1;                                       /* ADC Result Data Bit 0 */
        byte D1          :1;                                       /* ADC Result Data Bit 1 */
        byte D2          :1;                                       /* ADC Result Data Bit 2 */
        byte D3          :1;                                       /* ADC Result Data Bit 3 */
        byte D4          :1;                                       /* ADC Result Data Bit 4 */
        byte D5          :1;                                       /* ADC Result Data Bit 5 */
        byte D6          :1;                                       /* ADC Result Data Bit 6 */
        byte D7          :1;                                       /* ADC Result Data Bit 7 */
      } Bits;
    } ADCRLSTR;
    #define ADCRL                       _ADCR.Overlap_STR.ADCRLSTR.Byte
    #define ADCRL_D0                    _ADCR.Overlap_STR.ADCRLSTR.Bits.D0
    #define ADCRL_D1                    _ADCR.Overlap_STR.ADCRLSTR.Bits.D1
    #define ADCRL_D2                    _ADCR.Overlap_STR.ADCRLSTR.Bits.D2
    #define ADCRL_D3                    _ADCR.Overlap_STR.ADCRLSTR.Bits.D3
    #define ADCRL_D4                    _ADCR.Overlap_STR.ADCRLSTR.Bits.D4
    #define ADCRL_D5                    _ADCR.Overlap_STR.ADCRLSTR.Bits.D5
    #define ADCRL_D6                    _ADCR.Overlap_STR.ADCRLSTR.Bits.D6
    #define ADCRL_D7                    _ADCR.Overlap_STR.ADCRLSTR.Bits.D7
    
    #define ADCRL_D0_MASK               1
    #define ADCRL_D1_MASK               2
    #define ADCRL_D2_MASK               4
    #define ADCRL_D3_MASK               8
    #define ADCRL_D4_MASK               16
    #define ADCRL_D5_MASK               32
    #define ADCRL_D6_MASK               64
    #define ADCRL_D7_MASK               128
    
  } Overlap_STR;

} ADCRSTR;
extern volatile ADCRSTR _ADCR @0x00000014;
#define ADCR                            _ADCR.Word


/*** LCDC0 - LCD Control Register 0; 0x00000018 ***/
typedef union {
  byte Byte;
  struct {
    byte DUTY0       :1;                                       /* LCD Duty Select Bit 0 */
    byte DUTY1       :1;                                       /* LCD Duty Select Bit 1 */
    byte DUTY2       :1;                                       /* LCD Duty Select Bit 2 */
    byte LCLK0       :1;                                       /* LCD Clock Prescaler Bit 0 */
    byte LCLK1       :1;                                       /* LCD Clock Prescaler Bit 1 */
    byte LCLK2       :1;                                       /* LCD Clock Prescaler Bit 2 */
    byte SOURCE      :1;                                       /* LCD Clock Source Select */
    byte LCDEN       :1;                                       /* LCD Driver Enable */
  } Bits;
  struct {
    byte grpDUTY :3;
    byte grpLCLK :3;
    byte         :1;
    byte         :1;
  } MergedBits;
} LCDC0STR;
extern volatile LCDC0STR _LCDC0 @0x00000018;
#define LCDC0                           _LCDC0.Byte
#define LCDC0_DUTY0                     _LCDC0.Bits.DUTY0
#define LCDC0_DUTY1                     _LCDC0.Bits.DUTY1
#define LCDC0_DUTY2                     _LCDC0.Bits.DUTY2
#define LCDC0_LCLK0                     _LCDC0.Bits.LCLK0
#define LCDC0_LCLK1                     _LCDC0.Bits.LCLK1
#define LCDC0_LCLK2                     _LCDC0.Bits.LCLK2
#define LCDC0_SOURCE                    _LCDC0.Bits.SOURCE
#define LCDC0_LCDEN                     _LCDC0.Bits.LCDEN
/* LCDC_ARR: Access 2 LCDCx registers in an array */
#define LCDC_ARR                        ((volatile byte * __far) &LCDC0)
#define LCDC0_DUTY                      _LCDC0.MergedBits.grpDUTY
#define LCDC0_LCLK                      _LCDC0.MergedBits.grpLCLK

#define LCDC0_DUTY0_MASK                1
#define LCDC0_DUTY1_MASK                2
#define LCDC0_DUTY2_MASK                4
#define LCDC0_LCLK0_MASK                8
#define LCDC0_LCLK1_MASK                16
#define LCDC0_LCLK2_MASK                32
#define LCDC0_SOURCE_MASK               64
#define LCDC0_LCDEN_MASK                128
#define LCDC0_DUTY_MASK                 7
#define LCDC0_DUTY_BITNUM               0
#define LCDC0_LCLK_MASK                 56
#define LCDC0_LCLK_BITNUM               3


/*** LCDC1 - LCD Control Register 1; 0x00000019 ***/
typedef union {
  byte Byte;
  struct {
    byte LCDSTP      :1;                                       /* LCD Module Driver and Charge Pump Stop While in Stop2 or Stop3 Mode */
    byte LCDWAI      :1;                                       /* LCD Module Driver and Charge Pump Stop While in Wait Mode */
    byte FCDEN       :1;                                       /* Full Complementary Drive Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LCDIEN      :1;                                       /* LCD Module Frame Frequency Interrupt Enable */
  } Bits;
} LCDC1STR;
extern volatile LCDC1STR _LCDC1 @0x00000019;
#define LCDC1                           _LCDC1.Byte
#define LCDC1_LCDSTP                    _LCDC1.Bits.LCDSTP
#define LCDC1_LCDWAI                    _LCDC1.Bits.LCDWAI
#define LCDC1_FCDEN                     _LCDC1.Bits.FCDEN
#define LCDC1_LCDIEN                    _LCDC1.Bits.LCDIEN

#define LCDC1_LCDSTP_MASK               1
#define LCDC1_LCDWAI_MASK               2
#define LCDC1_FCDEN_MASK                4
#define LCDC1_LCDIEN_MASK               128


/*** LCDSUPPLY - LCD Voltage Supply Register; 0x0000001A ***/
typedef union {
  byte Byte;
  struct {
    byte VSUPPLY0    :1;                                       /* Voltage Supply Control Bit 0 */
    byte VSUPPLY1    :1;                                       /* Voltage Supply Control Bit 1 */
    byte BBYPASS     :1;                                       /* Op Amp Control */
    byte             :1; 
    byte LADJ0       :1;                                       /* LCD Module Load Adjust Bit 0 */
    byte LADJ1       :1;                                       /* LCD Module Load Adjust Bit 1 */
    byte HREFSEL     :1;                                       /* High Reference Select */
    byte CPSEL       :1;                                       /* Charge Pump or Resistor Bias Select */
  } Bits;
  struct {
    byte grpVSUPPLY :2;
    byte         :1;
    byte         :1;
    byte grpLADJ :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} LCDSUPPLYSTR;
extern volatile LCDSUPPLYSTR _LCDSUPPLY @0x0000001A;
#define LCDSUPPLY                       _LCDSUPPLY.Byte
#define LCDSUPPLY_VSUPPLY0              _LCDSUPPLY.Bits.VSUPPLY0
#define LCDSUPPLY_VSUPPLY1              _LCDSUPPLY.Bits.VSUPPLY1
#define LCDSUPPLY_BBYPASS               _LCDSUPPLY.Bits.BBYPASS
#define LCDSUPPLY_LADJ0                 _LCDSUPPLY.Bits.LADJ0
#define LCDSUPPLY_LADJ1                 _LCDSUPPLY.Bits.LADJ1
#define LCDSUPPLY_HREFSEL               _LCDSUPPLY.Bits.HREFSEL
#define LCDSUPPLY_CPSEL                 _LCDSUPPLY.Bits.CPSEL
#define LCDSUPPLY_VSUPPLY               _LCDSUPPLY.MergedBits.grpVSUPPLY
#define LCDSUPPLY_LADJ                  _LCDSUPPLY.MergedBits.grpLADJ

#define LCDSUPPLY_VSUPPLY0_MASK         1
#define LCDSUPPLY_VSUPPLY1_MASK         2
#define LCDSUPPLY_BBYPASS_MASK          4
#define LCDSUPPLY_LADJ0_MASK            16
#define LCDSUPPLY_LADJ1_MASK            32
#define LCDSUPPLY_HREFSEL_MASK          64
#define LCDSUPPLY_CPSEL_MASK            128
#define LCDSUPPLY_VSUPPLY_MASK          3
#define LCDSUPPLY_VSUPPLY_BITNUM        0
#define LCDSUPPLY_LADJ_MASK             48
#define LCDSUPPLY_LADJ_BITNUM           4


/*** LCDRVC - LCD Regulated Voltage Control Register; 0x0000001B ***/
typedef union {
  byte Byte;
  struct {
    byte RVTRIM0     :1;                                       /* Regulated Voltage Trim Bit 0 */
    byte RVTRIM1     :1;                                       /* Regulated Voltage Trim Bit 1 */
    byte RVTRIM2     :1;                                       /* Regulated Voltage Trim Bit 2 */
    byte RVTRIM3     :1;                                       /* Regulated Voltage Trim Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RVEN        :1;                                       /* Regulated Voltage Enable */
  } Bits;
  struct {
    byte grpRVTRIM :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} LCDRVCSTR;
extern volatile LCDRVCSTR _LCDRVC @0x0000001B;
#define LCDRVC                          _LCDRVC.Byte
#define LCDRVC_RVTRIM0                  _LCDRVC.Bits.RVTRIM0
#define LCDRVC_RVTRIM1                  _LCDRVC.Bits.RVTRIM1
#define LCDRVC_RVTRIM2                  _LCDRVC.Bits.RVTRIM2
#define LCDRVC_RVTRIM3                  _LCDRVC.Bits.RVTRIM3
#define LCDRVC_RVEN                     _LCDRVC.Bits.RVEN
#define LCDRVC_RVTRIM                   _LCDRVC.MergedBits.grpRVTRIM

#define LCDRVC_RVTRIM0_MASK             1
#define LCDRVC_RVTRIM1_MASK             2
#define LCDRVC_RVTRIM2_MASK             4
#define LCDRVC_RVTRIM3_MASK             8
#define LCDRVC_RVEN_MASK                128
#define LCDRVC_RVTRIM_MASK              15
#define LCDRVC_RVTRIM_BITNUM            0


/*** LCDBCTL - LCD Blink Control Register; 0x0000001C ***/
typedef union {
  byte Byte;
  struct {
    byte BRATE0      :1;                                       /* Blink-Rate Configuration Bit 0 */
    byte BRATE1      :1;                                       /* Blink-Rate Configuration Bit 1 */
    byte BRATE2      :1;                                       /* Blink-Rate Configuration Bit 2 */
    byte BMODE       :1;                                       /* Blink Mode */
    byte             :1; 
    byte BLANK       :1;                                       /* Blank Display Mode */
    byte ALT         :1;                                       /* Alternate Display Mode */
    byte BLINK       :1;                                       /* Blink Command */
  } Bits;
  struct {
    byte grpBRATE :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} LCDBCTLSTR;
extern volatile LCDBCTLSTR _LCDBCTL @0x0000001C;
#define LCDBCTL                         _LCDBCTL.Byte
#define LCDBCTL_BRATE0                  _LCDBCTL.Bits.BRATE0
#define LCDBCTL_BRATE1                  _LCDBCTL.Bits.BRATE1
#define LCDBCTL_BRATE2                  _LCDBCTL.Bits.BRATE2
#define LCDBCTL_BMODE                   _LCDBCTL.Bits.BMODE
#define LCDBCTL_BLANK                   _LCDBCTL.Bits.BLANK
#define LCDBCTL_ALT                     _LCDBCTL.Bits.ALT
#define LCDBCTL_BLINK                   _LCDBCTL.Bits.BLINK
#define LCDBCTL_BRATE                   _LCDBCTL.MergedBits.grpBRATE

#define LCDBCTL_BRATE0_MASK             1
#define LCDBCTL_BRATE1_MASK             2
#define LCDBCTL_BRATE2_MASK             4
#define LCDBCTL_BMODE_MASK              8
#define LCDBCTL_BLANK_MASK              32
#define LCDBCTL_ALT_MASK                64
#define LCDBCTL_BLINK_MASK              128
#define LCDBCTL_BRATE_MASK              7
#define LCDBCTL_BRATE_BITNUM            0


/*** LCDS - LCD Status Register; 0x0000001D ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LCDIF       :1;                                       /* LCD Interrupt Flag */
  } Bits;
} LCDSSTR;
extern volatile LCDSSTR _LCDS @0x0000001D;
#define LCDS                            _LCDS.Byte
#define LCDS_LCDIF                      _LCDS.Bits.LCDIF

#define LCDS_LCDIF_MASK                 128


/*** ACMPSC - ACMP Status and Control Register; 0x0000001F ***/
typedef union {
  byte Byte;
  struct {
    byte ACMOD0      :1;                                       /* Analog Comparator Mode Bit 0 */
    byte ACMOD1      :1;                                       /* Analog Comparator Mode Bit 1 */
    byte ACOPE       :1;                                       /* Analog Comparator Output Pin Enable */
    byte ACO         :1;                                       /* Analog Comparator Output */
    byte ACIE        :1;                                       /* Analog Comparator Interrupt Enable */
    byte ACF         :1;                                       /* Analog Comparator Flag */
    byte ACBGS       :1;                                       /* Analog Comparator Bandgap Select */
    byte ACME        :1;                                       /* Analog Comparator Module Enable */
  } Bits;
  struct {
    byte grpACMOD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ACMPSCSTR;
extern volatile ACMPSCSTR _ACMPSC @0x0000001F;
#define ACMPSC                          _ACMPSC.Byte
#define ACMPSC_ACMOD0                   _ACMPSC.Bits.ACMOD0
#define ACMPSC_ACMOD1                   _ACMPSC.Bits.ACMOD1
#define ACMPSC_ACOPE                    _ACMPSC.Bits.ACOPE
#define ACMPSC_ACO                      _ACMPSC.Bits.ACO
#define ACMPSC_ACIE                     _ACMPSC.Bits.ACIE
#define ACMPSC_ACF                      _ACMPSC.Bits.ACF
#define ACMPSC_ACBGS                    _ACMPSC.Bits.ACBGS
#define ACMPSC_ACME                     _ACMPSC.Bits.ACME
#define ACMPSC_ACMOD                    _ACMPSC.MergedBits.grpACMOD

#define ACMPSC_ACMOD0_MASK              1
#define ACMPSC_ACMOD1_MASK              2
#define ACMPSC_ACOPE_MASK               4
#define ACMPSC_ACO_MASK                 8
#define ACMPSC_ACIE_MASK                16
#define ACMPSC_ACF_MASK                 32
#define ACMPSC_ACBGS_MASK               64
#define ACMPSC_ACME_MASK                128
#define ACMPSC_ACMOD_MASK               3
#define ACMPSC_ACMOD_BITNUM             0


/*** SCI1BD - SCI1 Baud Rate Register; 0x00000020 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI1BDH - SCI1 Baud Rate Register High; 0x00000020 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
        byte SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
        byte SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
        byte SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
        byte SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
        byte             :1; 
        byte RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
        byte LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI1BDHSTR;
    #define SCI1BDH                     _SCI1BD.Overlap_STR.SCI1BDHSTR.Byte
    #define SCI1BDH_SBR8                _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR8
    #define SCI1BDH_SBR9                _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR9
    #define SCI1BDH_SBR10               _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR10
    #define SCI1BDH_SBR11               _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR11
    #define SCI1BDH_SBR12               _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR12
    #define SCI1BDH_RXEDGIE             _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.RXEDGIE
    #define SCI1BDH_LBKDIE              _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.LBKDIE
    #define SCI1BDH_SBR_8               _SCI1BD.Overlap_STR.SCI1BDHSTR.MergedBits.grpSBR_8
    #define SCI1BDH_SBR                 SCI1BDH_SBR_8
    
    #define SCI1BDH_SBR8_MASK           1
    #define SCI1BDH_SBR9_MASK           2
    #define SCI1BDH_SBR10_MASK          4
    #define SCI1BDH_SBR11_MASK          8
    #define SCI1BDH_SBR12_MASK          16
    #define SCI1BDH_RXEDGIE_MASK        64
    #define SCI1BDH_LBKDIE_MASK         128
    #define SCI1BDH_SBR_8_MASK          31
    #define SCI1BDH_SBR_8_BITNUM        0
    

    /*** SCI1BDL - SCI1 Baud Rate Register Low; 0x00000021 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
        byte SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
        byte SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
        byte SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
      } Bits;
    } SCI1BDLSTR;
    #define SCI1BDL                     _SCI1BD.Overlap_STR.SCI1BDLSTR.Byte
    #define SCI1BDL_SBR0                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR0
    #define SCI1BDL_SBR1                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR1
    #define SCI1BDL_SBR2                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR2
    #define SCI1BDL_SBR3                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR3
    #define SCI1BDL_SBR4                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR4
    #define SCI1BDL_SBR5                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR5
    #define SCI1BDL_SBR6                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR6
    #define SCI1BDL_SBR7                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR7
    
    #define SCI1BDL_SBR0_MASK           1
    #define SCI1BDL_SBR1_MASK           2
    #define SCI1BDL_SBR2_MASK           4
    #define SCI1BDL_SBR3_MASK           8
    #define SCI1BDL_SBR4_MASK           16
    #define SCI1BDL_SBR5_MASK           32
    #define SCI1BDL_SBR6_MASK           64
    #define SCI1BDL_SBR7_MASK           128
    
  } Overlap_STR;

} SCI1BDSTR;
extern volatile SCI1BDSTR _SCI1BD @0x00000020;
#define SCI1BD                          _SCI1BD.Word


/*** SCI1C1 - SCI1 Control Register 1; 0x00000022 ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type */
    byte PE          :1;                                       /* Parity Enable */
    byte ILT         :1;                                       /* Idle Line Type Select */
    byte WAKE        :1;                                       /* Receiver Wakeup Method Select */
    byte M           :1;                                       /* 9-Bit or 8-Bit Mode Select */
    byte RSRC        :1;                                       /* Receiver Source Select */
    byte SCISWAI     :1;                                       /* SCI Stops in Wait Mode */
    byte LOOPS       :1;                                       /* Loop Mode Select */
  } Bits;
} SCI1C1STR;
extern volatile SCI1C1STR _SCI1C1 @0x00000022;
#define SCI1C1                          _SCI1C1.Byte
#define SCI1C1_PT                       _SCI1C1.Bits.PT
#define SCI1C1_PE                       _SCI1C1.Bits.PE
#define SCI1C1_ILT                      _SCI1C1.Bits.ILT
#define SCI1C1_WAKE                     _SCI1C1.Bits.WAKE
#define SCI1C1_M                        _SCI1C1.Bits.M
#define SCI1C1_RSRC                     _SCI1C1.Bits.RSRC
#define SCI1C1_SCISWAI                  _SCI1C1.Bits.SCISWAI
#define SCI1C1_LOOPS                    _SCI1C1.Bits.LOOPS

#define SCI1C1_PT_MASK                  1
#define SCI1C1_PE_MASK                  2
#define SCI1C1_ILT_MASK                 4
#define SCI1C1_WAKE_MASK                8
#define SCI1C1_M_MASK                   16
#define SCI1C1_RSRC_MASK                32
#define SCI1C1_SCISWAI_MASK             64
#define SCI1C1_LOOPS_MASK               128


/*** SCI1C2 - SCI1 Control Register 2; 0x00000023 ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break */
    byte RWU         :1;                                       /* Receiver Wakeup Control */
    byte RE          :1;                                       /* Receiver Enable */
    byte TE          :1;                                       /* Transmitter Enable */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable (for IDLE) */
    byte RIE         :1;                                       /* Receiver Interrupt Enable (for RDRF) */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable (for TC) */
    byte TIE         :1;                                       /* Transmit Interrupt Enable (for TDRE) */
  } Bits;
} SCI1C2STR;
extern volatile SCI1C2STR _SCI1C2 @0x00000023;
#define SCI1C2                          _SCI1C2.Byte
#define SCI1C2_SBK                      _SCI1C2.Bits.SBK
#define SCI1C2_RWU                      _SCI1C2.Bits.RWU
#define SCI1C2_RE                       _SCI1C2.Bits.RE
#define SCI1C2_TE                       _SCI1C2.Bits.TE
#define SCI1C2_ILIE                     _SCI1C2.Bits.ILIE
#define SCI1C2_RIE                      _SCI1C2.Bits.RIE
#define SCI1C2_TCIE                     _SCI1C2.Bits.TCIE
#define SCI1C2_TIE                      _SCI1C2.Bits.TIE

#define SCI1C2_SBK_MASK                 1
#define SCI1C2_RWU_MASK                 2
#define SCI1C2_RE_MASK                  4
#define SCI1C2_TE_MASK                  8
#define SCI1C2_ILIE_MASK                16
#define SCI1C2_RIE_MASK                 32
#define SCI1C2_TCIE_MASK                64
#define SCI1C2_TIE_MASK                 128


/*** SCI1S1 - SCI1 Status Register 1; 0x00000024 ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Receiver Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmission Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI1S1STR;
extern volatile SCI1S1STR _SCI1S1 @0x00000024;
#define SCI1S1                          _SCI1S1.Byte
#define SCI1S1_PF                       _SCI1S1.Bits.PF
#define SCI1S1_FE                       _SCI1S1.Bits.FE
#define SCI1S1_NF                       _SCI1S1.Bits.NF
#define SCI1S1_OR                       _SCI1S1.Bits.OR
#define SCI1S1_IDLE                     _SCI1S1.Bits.IDLE
#define SCI1S1_RDRF                     _SCI1S1.Bits.RDRF
#define SCI1S1_TC                       _SCI1S1.Bits.TC
#define SCI1S1_TDRE                     _SCI1S1.Bits.TDRE

#define SCI1S1_PF_MASK                  1
#define SCI1S1_FE_MASK                  2
#define SCI1S1_NF_MASK                  4
#define SCI1S1_OR_MASK                  8
#define SCI1S1_IDLE_MASK                16
#define SCI1S1_RDRF_MASK                32
#define SCI1S1_TC_MASK                  64
#define SCI1S1_TDRE_MASK                128


/*** SCI1S2 - SCI1 Status Register 2; 0x00000025 ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte LBKDE       :1;                                       /* LIN Break Detection Enable */
    byte BRK13       :1;                                       /* Break Character Generation Length */
    byte RWUID       :1;                                       /* Receive Wake Up Idle Detect */
    byte RXINV       :1;                                       /* Receive Data Inversion */
    byte             :1; 
    byte RXEDGIF     :1;                                       /* RxD Pin Active Edge Interrupt Flag */
    byte LBKDIF      :1;                                       /* LIN Break Detect Interrupt Flag */
  } Bits;
} SCI1S2STR;
extern volatile SCI1S2STR _SCI1S2 @0x00000025;
#define SCI1S2                          _SCI1S2.Byte
#define SCI1S2_RAF                      _SCI1S2.Bits.RAF
#define SCI1S2_LBKDE                    _SCI1S2.Bits.LBKDE
#define SCI1S2_BRK13                    _SCI1S2.Bits.BRK13
#define SCI1S2_RWUID                    _SCI1S2.Bits.RWUID
#define SCI1S2_RXINV                    _SCI1S2.Bits.RXINV
#define SCI1S2_RXEDGIF                  _SCI1S2.Bits.RXEDGIF
#define SCI1S2_LBKDIF                   _SCI1S2.Bits.LBKDIF

#define SCI1S2_RAF_MASK                 1
#define SCI1S2_LBKDE_MASK               2
#define SCI1S2_BRK13_MASK               4
#define SCI1S2_RWUID_MASK               8
#define SCI1S2_RXINV_MASK               16
#define SCI1S2_RXEDGIF_MASK             64
#define SCI1S2_LBKDIF_MASK              128


/*** SCI1C3 - SCI1 Control Register 3; 0x00000026 ***/
typedef union {
  byte Byte;
  struct {
    byte PEIE        :1;                                       /* Parity Error Interrupt Enable */
    byte FEIE        :1;                                       /* Framing Error Interrupt Enable */
    byte NEIE        :1;                                       /* Noise Error Interrupt Enable */
    byte ORIE        :1;                                       /* Overrun Interrupt Enable */
    byte TXINV       :1;                                       /* Transmit Data Inversion */
    byte TXDIR       :1;                                       /* TxD Pin Direction in Single-Wire Mode */
    byte T8          :1;                                       /* Ninth Data Bit for Transmitter */
    byte R8          :1;                                       /* Ninth Data Bit for Receiver */
  } Bits;
} SCI1C3STR;
extern volatile SCI1C3STR _SCI1C3 @0x00000026;
#define SCI1C3                          _SCI1C3.Byte
#define SCI1C3_PEIE                     _SCI1C3.Bits.PEIE
#define SCI1C3_FEIE                     _SCI1C3.Bits.FEIE
#define SCI1C3_NEIE                     _SCI1C3.Bits.NEIE
#define SCI1C3_ORIE                     _SCI1C3.Bits.ORIE
#define SCI1C3_TXINV                    _SCI1C3.Bits.TXINV
#define SCI1C3_TXDIR                    _SCI1C3.Bits.TXDIR
#define SCI1C3_T8                       _SCI1C3.Bits.T8
#define SCI1C3_R8                       _SCI1C3.Bits.R8

#define SCI1C3_PEIE_MASK                1
#define SCI1C3_FEIE_MASK                2
#define SCI1C3_NEIE_MASK                4
#define SCI1C3_ORIE_MASK                8
#define SCI1C3_TXINV_MASK               16
#define SCI1C3_TXDIR_MASK               32
#define SCI1C3_T8_MASK                  64
#define SCI1C3_R8_MASK                  128


/*** SCI1D - SCI1 Data Register; 0x00000027 ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Receive/Transmit Data Bit 0 */
    byte R1_T1       :1;                                       /* Receive/Transmit Data Bit 1 */
    byte R2_T2       :1;                                       /* Receive/Transmit Data Bit 2 */
    byte R3_T3       :1;                                       /* Receive/Transmit Data Bit 3 */
    byte R4_T4       :1;                                       /* Receive/Transmit Data Bit 4 */
    byte R5_T5       :1;                                       /* Receive/Transmit Data Bit 5 */
    byte R6_T6       :1;                                       /* Receive/Transmit Data Bit 6 */
    byte R7_T7       :1;                                       /* Receive/Transmit Data Bit 7 */
  } Bits;
} SCI1DSTR;
extern volatile SCI1DSTR _SCI1D @0x00000027;
#define SCI1D                           _SCI1D.Byte
#define SCI1D_R0_T0                     _SCI1D.Bits.R0_T0
#define SCI1D_R1_T1                     _SCI1D.Bits.R1_T1
#define SCI1D_R2_T2                     _SCI1D.Bits.R2_T2
#define SCI1D_R3_T3                     _SCI1D.Bits.R3_T3
#define SCI1D_R4_T4                     _SCI1D.Bits.R4_T4
#define SCI1D_R5_T5                     _SCI1D.Bits.R5_T5
#define SCI1D_R6_T6                     _SCI1D.Bits.R6_T6
#define SCI1D_R7_T7                     _SCI1D.Bits.R7_T7

#define SCI1D_R0_T0_MASK                1
#define SCI1D_R1_T1_MASK                2
#define SCI1D_R2_T2_MASK                4
#define SCI1D_R3_T3_MASK                8
#define SCI1D_R4_T4_MASK                16
#define SCI1D_R5_T5_MASK                32
#define SCI1D_R6_T6_MASK                64
#define SCI1D_R7_T7_MASK                128


/*** SPIC1 - SPI Control Register 1; 0x00000028 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* LSB First (Shifter Direction) */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* Clock Phase */
    byte CPOL        :1;                                       /* Clock Polarity */
    byte MSTR        :1;                                       /* Master/Slave Mode Select */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable */
    byte SPIE        :1;                                       /* SPI Interrupt Enable (for SPRF and MODF) */
  } Bits;
} SPIC1STR;
extern volatile SPIC1STR _SPIC1 @0x00000028;
#define SPIC1                           _SPIC1.Byte
#define SPIC1_LSBFE                     _SPIC1.Bits.LSBFE
#define SPIC1_SSOE                      _SPIC1.Bits.SSOE
#define SPIC1_CPHA                      _SPIC1.Bits.CPHA
#define SPIC1_CPOL                      _SPIC1.Bits.CPOL
#define SPIC1_MSTR                      _SPIC1.Bits.MSTR
#define SPIC1_SPTIE                     _SPIC1.Bits.SPTIE
#define SPIC1_SPE                       _SPIC1.Bits.SPE
#define SPIC1_SPIE                      _SPIC1.Bits.SPIE

#define SPIC1_LSBFE_MASK                1
#define SPIC1_SSOE_MASK                 2
#define SPIC1_CPHA_MASK                 4
#define SPIC1_CPOL_MASK                 8
#define SPIC1_MSTR_MASK                 16
#define SPIC1_SPTIE_MASK                32
#define SPIC1_SPE_MASK                  64
#define SPIC1_SPIE_MASK                 128


/*** SPIC2 - SPI Control Register 2; 0x00000029 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI Pin Control 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional Mode Output Enable */
    byte MODFEN      :1;                                       /* Master Mode-Fault Function Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SPIC2STR;
extern volatile SPIC2STR _SPIC2 @0x00000029;
#define SPIC2                           _SPIC2.Byte
#define SPIC2_SPC0                      _SPIC2.Bits.SPC0
#define SPIC2_SPISWAI                   _SPIC2.Bits.SPISWAI
#define SPIC2_BIDIROE                   _SPIC2.Bits.BIDIROE
#define SPIC2_MODFEN                    _SPIC2.Bits.MODFEN

#define SPIC2_SPC0_MASK                 1
#define SPIC2_SPISWAI_MASK              2
#define SPIC2_BIDIROE_MASK              8
#define SPIC2_MODFEN_MASK               16


/*** SPIBR - SPI Baud Rate Register; 0x0000002A ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Divisor Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Divisor Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Divisor Bit 2 */
    byte SPR3        :1;                                       /* SPI Baud Rate Divisor Bit 3 */
    byte SPPR0       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :4;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPIBRSTR;
extern volatile SPIBRSTR _SPIBR @0x0000002A;
#define SPIBR                           _SPIBR.Byte
#define SPIBR_SPR0                      _SPIBR.Bits.SPR0
#define SPIBR_SPR1                      _SPIBR.Bits.SPR1
#define SPIBR_SPR2                      _SPIBR.Bits.SPR2
#define SPIBR_SPR3                      _SPIBR.Bits.SPR3
#define SPIBR_SPPR0                     _SPIBR.Bits.SPPR0
#define SPIBR_SPPR1                     _SPIBR.Bits.SPPR1
#define SPIBR_SPPR2                     _SPIBR.Bits.SPPR2
#define SPIBR_SPR                       _SPIBR.MergedBits.grpSPR
#define SPIBR_SPPR                      _SPIBR.MergedBits.grpSPPR

#define SPIBR_SPR0_MASK                 1
#define SPIBR_SPR1_MASK                 2
#define SPIBR_SPR2_MASK                 4
#define SPIBR_SPR3_MASK                 8
#define SPIBR_SPPR0_MASK                16
#define SPIBR_SPPR1_MASK                32
#define SPIBR_SPPR2_MASK                64
#define SPIBR_SPR_MASK                  15
#define SPIBR_SPR_BITNUM                0
#define SPIBR_SPPR_MASK                 112
#define SPIBR_SPPR_BITNUM               4


/*** SPIS - SPI Status Register; 0x0000002B ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Master Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Buffer Empty Flag */
    byte             :1; 
    byte SPRF        :1;                                       /* SPI Read Buffer Full Flag */
  } Bits;
} SPISSTR;
extern volatile SPISSTR _SPIS @0x0000002B;
#define SPIS                            _SPIS.Byte
#define SPIS_MODF                       _SPIS.Bits.MODF
#define SPIS_SPTEF                      _SPIS.Bits.SPTEF
#define SPIS_SPRF                       _SPIS.Bits.SPRF

#define SPIS_MODF_MASK                  16
#define SPIS_SPTEF_MASK                 32
#define SPIS_SPRF_MASK                  128


/*** SPID - SPI Data Register; 0x0000002D ***/
typedef union {
  byte Byte;
} SPIDSTR;
extern volatile SPIDSTR _SPID @0x0000002D;
#define SPID                            _SPID.Byte


/*** PPAGE - Program Page Register; 0x00000030 ***/
typedef union {
  byte Byte;
  struct {
    byte XA14        :1;                                       /* Extended address, bit 14 */
    byte XA15        :1;                                       /* Extended address, bit 15 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpXA_14 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPAGESTR;
extern volatile PPAGESTR _PPAGE @0x00000030;
#define PPAGE                           _PPAGE.Byte
#define PPAGE_XA14                      _PPAGE.Bits.XA14
#define PPAGE_XA15                      _PPAGE.Bits.XA15
#define PPAGE_XA_14                     _PPAGE.MergedBits.grpXA_14
#define PPAGE_XA                        PPAGE_XA_14

#define PPAGE_XA14_MASK                 1
#define PPAGE_XA15_MASK                 2
#define PPAGE_XA_14_MASK                3
#define PPAGE_XA_14_BITNUM              0


/*** LAP2 - Linear Address Pointer Register 2; 0x00000031 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} LAP2STR;
extern volatile LAP2STR _LAP2 @0x00000031;
#define LAP2                            _LAP2.Byte


/*** LAP1 - Linear Address Pointer Register 1; 0x00000032 ***/
typedef union {
  byte Byte;
  struct {
    byte LA8         :1;                                       /* Linear address pointer, bit 8 */
    byte LA9         :1;                                       /* Linear address pointer, bit 9 */
    byte LA10        :1;                                       /* Linear address pointer, bit 10 */
    byte LA11        :1;                                       /* Linear address pointer, bit 11 */
    byte LA12        :1;                                       /* Linear address pointer, bit 12 */
    byte LA13        :1;                                       /* Linear address pointer, bit 13 */
    byte LA14        :1;                                       /* Linear address pointer, bit 14 */
    byte LA15        :1;                                       /* Linear address pointer, bit 15 */
  } Bits;
} LAP1STR;
extern volatile LAP1STR _LAP1 @0x00000032;
#define LAP1                            _LAP1.Byte
#define LAP1_LA8                        _LAP1.Bits.LA8
#define LAP1_LA9                        _LAP1.Bits.LA9
#define LAP1_LA10                       _LAP1.Bits.LA10
#define LAP1_LA11                       _LAP1.Bits.LA11
#define LAP1_LA12                       _LAP1.Bits.LA12
#define LAP1_LA13                       _LAP1.Bits.LA13
#define LAP1_LA14                       _LAP1.Bits.LA14
#define LAP1_LA15                       _LAP1.Bits.LA15

#define LAP1_LA8_MASK                   1
#define LAP1_LA9_MASK                   2
#define LAP1_LA10_MASK                  4
#define LAP1_LA11_MASK                  8
#define LAP1_LA12_MASK                  16
#define LAP1_LA13_MASK                  32
#define LAP1_LA14_MASK                  64
#define LAP1_LA15_MASK                  128


/*** LAP0 - Linear Address Pointer Register 0; 0x00000033 ***/
typedef union {
  byte Byte;
  struct {
    byte LA0         :1;                                       /* Linear address pointer, bit 0 */
    byte LA1         :1;                                       /* Linear address pointer, bit 1 */
    byte LA2         :1;                                       /* Linear address pointer, bit 2 */
    byte LA3         :1;                                       /* Linear address pointer, bit 3 */
    byte LA4         :1;                                       /* Linear address pointer, bit 4 */
    byte LA5         :1;                                       /* Linear address pointer, bit 5 */
    byte LA6         :1;                                       /* Linear address pointer, bit 6 */
    byte LA7         :1;                                       /* Linear address pointer, bit 7 */
  } Bits;
} LAP0STR;
extern volatile LAP0STR _LAP0 @0x00000033;
#define LAP0                            _LAP0.Byte
#define LAP0_LA0                        _LAP0.Bits.LA0
#define LAP0_LA1                        _LAP0.Bits.LA1
#define LAP0_LA2                        _LAP0.Bits.LA2
#define LAP0_LA3                        _LAP0.Bits.LA3
#define LAP0_LA4                        _LAP0.Bits.LA4
#define LAP0_LA5                        _LAP0.Bits.LA5
#define LAP0_LA6                        _LAP0.Bits.LA6
#define LAP0_LA7                        _LAP0.Bits.LA7

#define LAP0_LA0_MASK                   1
#define LAP0_LA1_MASK                   2
#define LAP0_LA2_MASK                   4
#define LAP0_LA3_MASK                   8
#define LAP0_LA4_MASK                   16
#define LAP0_LA5_MASK                   32
#define LAP0_LA6_MASK                   64
#define LAP0_LA7_MASK                   128


/*** LWP - Linear Word Post Increment Register; 0x00000034 ***/
typedef union {
  byte Byte;
  struct {
    byte D0          :1;                                       /* Data value bit 0 */
    byte D1          :1;                                       /* Data value bit 1 */
    byte D2          :1;                                       /* Data value bit 2 */
    byte D3          :1;                                       /* Data value bit 3 */
    byte D4          :1;                                       /* Data value bit 4 */
    byte D5          :1;                                       /* Data value bit 5 */
    byte D6          :1;                                       /* Data value bit 6 */
    byte D7          :1;                                       /* Data value bit 7 */
  } Bits;
} LWPSTR;
extern volatile LWPSTR _LWP @0x00000034;
#define LWP                             _LWP.Byte
#define LWP_D0                          _LWP.Bits.D0
#define LWP_D1                          _LWP.Bits.D1
#define LWP_D2                          _LWP.Bits.D2
#define LWP_D3                          _LWP.Bits.D3
#define LWP_D4                          _LWP.Bits.D4
#define LWP_D5                          _LWP.Bits.D5
#define LWP_D6                          _LWP.Bits.D6
#define LWP_D7                          _LWP.Bits.D7

#define LWP_D0_MASK                     1
#define LWP_D1_MASK                     2
#define LWP_D2_MASK                     4
#define LWP_D3_MASK                     8
#define LWP_D4_MASK                     16
#define LWP_D5_MASK                     32
#define LWP_D6_MASK                     64
#define LWP_D7_MASK                     128


/*** LBP - Linear Byte Post Increment Register; 0x00000035 ***/
typedef union {
  byte Byte;
  struct {
    byte D0          :1;                                       /* Data value bit 0 */
    byte D1          :1;                                       /* Data value bit 1 */
    byte D2          :1;                                       /* Data value bit 2 */
    byte D3          :1;                                       /* Data value bit 3 */
    byte D4          :1;                                       /* Data value bit 4 */
    byte D5          :1;                                       /* Data value bit 5 */
    byte D6          :1;                                       /* Data value bit 6 */
    byte D7          :1;                                       /* Data value bit 7 */
  } Bits;
} LBPSTR;
extern volatile LBPSTR _LBP @0x00000035;
#define LBP                             _LBP.Byte
#define LBP_D0                          _LBP.Bits.D0
#define LBP_D1                          _LBP.Bits.D1
#define LBP_D2                          _LBP.Bits.D2
#define LBP_D3                          _LBP.Bits.D3
#define LBP_D4                          _LBP.Bits.D4
#define LBP_D5                          _LBP.Bits.D5
#define LBP_D6                          _LBP.Bits.D6
#define LBP_D7                          _LBP.Bits.D7

#define LBP_D0_MASK                     1
#define LBP_D1_MASK                     2
#define LBP_D2_MASK                     4
#define LBP_D3_MASK                     8
#define LBP_D4_MASK                     16
#define LBP_D5_MASK                     32
#define LBP_D6_MASK                     64
#define LBP_D7_MASK                     128


/*** LB - Linear Byte Register; 0x00000036 ***/
typedef union {
  byte Byte;
  struct {
    byte D0          :1;                                       /* Data value bit 0 */
    byte D1          :1;                                       /* Data value bit 1 */
    byte D2          :1;                                       /* Data value bit 2 */
    byte D3          :1;                                       /* Data value bit 3 */
    byte D4          :1;                                       /* Data value bit 4 */
    byte D5          :1;                                       /* Data value bit 5 */
    byte D6          :1;                                       /* Data value bit 6 */
    byte D7          :1;                                       /* Data value bit 7 */
  } Bits;
} LBSTR;
extern volatile LBSTR _LB @0x00000036;
#define LB                              _LB.Byte
#define LB_D0                           _LB.Bits.D0
#define LB_D1                           _LB.Bits.D1
#define LB_D2                           _LB.Bits.D2
#define LB_D3                           _LB.Bits.D3
#define LB_D4                           _LB.Bits.D4
#define LB_D5                           _LB.Bits.D5
#define LB_D6                           _LB.Bits.D6
#define LB_D7                           _LB.Bits.D7

#define LB_D0_MASK                      1
#define LB_D1_MASK                      2
#define LB_D2_MASK                      4
#define LB_D3_MASK                      8
#define LB_D4_MASK                      16
#define LB_D5_MASK                      32
#define LB_D6_MASK                      64
#define LB_D7_MASK                      128


/*** LAPAB - Linear Address Pointer Add Byte Register; 0x00000037 ***/
typedef union {
  byte Byte;
  struct {
    byte D0          :1;                                       /* Data value bit 0 */
    byte D1          :1;                                       /* Data value bit 1 */
    byte D2          :1;                                       /* Data value bit 2 */
    byte D3          :1;                                       /* Data value bit 3 */
    byte D4          :1;                                       /* Data value bit 4 */
    byte D5          :1;                                       /* Data value bit 5 */
    byte D6          :1;                                       /* Data value bit 6 */
    byte D7          :1;                                       /* Data value bit 7 */
  } Bits;
} LAPABSTR;
extern volatile LAPABSTR _LAPAB @0x00000037;
#define LAPAB                           _LAPAB.Byte
#define LAPAB_D0                        _LAPAB.Bits.D0
#define LAPAB_D1                        _LAPAB.Bits.D1
#define LAPAB_D2                        _LAPAB.Bits.D2
#define LAPAB_D3                        _LAPAB.Bits.D3
#define LAPAB_D4                        _LAPAB.Bits.D4
#define LAPAB_D5                        _LAPAB.Bits.D5
#define LAPAB_D6                        _LAPAB.Bits.D6
#define LAPAB_D7                        _LAPAB.Bits.D7

#define LAPAB_D0_MASK                   1
#define LAPAB_D1_MASK                   2
#define LAPAB_D2_MASK                   4
#define LAPAB_D3_MASK                   8
#define LAPAB_D4_MASK                   16
#define LAPAB_D5_MASK                   32
#define LAPAB_D6_MASK                   64
#define LAPAB_D7_MASK                   128


/*** ICSC1 - ICS Control Register 1; 0x00000038 ***/
typedef union {
  byte Byte;
  struct {
    byte IREFSTEN    :1;                                       /* Internal Reference Stop Enable */
    byte IRCLKEN     :1;                                       /* Internal Reference Clock Enable */
    byte IREFS       :1;                                       /* Internal Reference Select */
    byte RDIV0       :1;                                       /* Reference Divider, bit 0 */
    byte RDIV1       :1;                                       /* Reference Divider, bit 1 */
    byte RDIV2       :1;                                       /* Reference Divider, bit 2 */
    byte CLKS0       :1;                                       /* Clock Source Select, bit 0 */
    byte CLKS1       :1;                                       /* Clock Source Select, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRDIV :3;
    byte grpCLKS :2;
  } MergedBits;
} ICSC1STR;
extern volatile ICSC1STR _ICSC1 @0x00000038;
#define ICSC1                           _ICSC1.Byte
#define ICSC1_IREFSTEN                  _ICSC1.Bits.IREFSTEN
#define ICSC1_IRCLKEN                   _ICSC1.Bits.IRCLKEN
#define ICSC1_IREFS                     _ICSC1.Bits.IREFS
#define ICSC1_RDIV0                     _ICSC1.Bits.RDIV0
#define ICSC1_RDIV1                     _ICSC1.Bits.RDIV1
#define ICSC1_RDIV2                     _ICSC1.Bits.RDIV2
#define ICSC1_CLKS0                     _ICSC1.Bits.CLKS0
#define ICSC1_CLKS1                     _ICSC1.Bits.CLKS1
#define ICSC1_RDIV                      _ICSC1.MergedBits.grpRDIV
#define ICSC1_CLKS                      _ICSC1.MergedBits.grpCLKS

#define ICSC1_IREFSTEN_MASK             1
#define ICSC1_IRCLKEN_MASK              2
#define ICSC1_IREFS_MASK                4
#define ICSC1_RDIV0_MASK                8
#define ICSC1_RDIV1_MASK                16
#define ICSC1_RDIV2_MASK                32
#define ICSC1_CLKS0_MASK                64
#define ICSC1_CLKS1_MASK                128
#define ICSC1_RDIV_MASK                 56
#define ICSC1_RDIV_BITNUM               3
#define ICSC1_CLKS_MASK                 192
#define ICSC1_CLKS_BITNUM               6


/*** ICSC2 - ICS Control Register 2; 0x00000039 ***/
typedef union {
  byte Byte;
  struct {
    byte EREFSTEN    :1;                                       /* External Reference Stop Enable */
    byte ERCLKEN     :1;                                       /* External Reference Enable */
    byte EREFS       :1;                                       /* External Reference Select */
    byte LP          :1;                                       /* Low Power Select */
    byte HGO         :1;                                       /* High Gain Oscillator Select */
    byte RANGE       :1;                                       /* Frequency Range Select */
    byte BDIV0       :1;                                       /* Bus Frequency Divider, bit 0 */
    byte BDIV1       :1;                                       /* Bus Frequency Divider, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpBDIV :2;
  } MergedBits;
} ICSC2STR;
extern volatile ICSC2STR _ICSC2 @0x00000039;
#define ICSC2                           _ICSC2.Byte
#define ICSC2_EREFSTEN                  _ICSC2.Bits.EREFSTEN
#define ICSC2_ERCLKEN                   _ICSC2.Bits.ERCLKEN
#define ICSC2_EREFS                     _ICSC2.Bits.EREFS
#define ICSC2_LP                        _ICSC2.Bits.LP
#define ICSC2_HGO                       _ICSC2.Bits.HGO
#define ICSC2_RANGE                     _ICSC2.Bits.RANGE
#define ICSC2_BDIV0                     _ICSC2.Bits.BDIV0
#define ICSC2_BDIV1                     _ICSC2.Bits.BDIV1
#define ICSC2_BDIV                      _ICSC2.MergedBits.grpBDIV

#define ICSC2_EREFSTEN_MASK             1
#define ICSC2_ERCLKEN_MASK              2
#define ICSC2_EREFS_MASK                4
#define ICSC2_LP_MASK                   8
#define ICSC2_HGO_MASK                  16
#define ICSC2_RANGE_MASK                32
#define ICSC2_BDIV0_MASK                64
#define ICSC2_BDIV1_MASK                128
#define ICSC2_BDIV_MASK                 192
#define ICSC2_BDIV_BITNUM               6


/*** ICSTRM - ICS Trim Register; 0x0000003A ***/
typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       /* ICS Trim Setting, bit 0 */
    byte TRIM1       :1;                                       /* ICS Trim Setting, bit 1 */
    byte TRIM2       :1;                                       /* ICS Trim Setting, bit 2 */
    byte TRIM3       :1;                                       /* ICS Trim Setting, bit 3 */
    byte TRIM4       :1;                                       /* ICS Trim Setting, bit 4 */
    byte TRIM5       :1;                                       /* ICS Trim Setting, bit 5 */
    byte TRIM6       :1;                                       /* ICS Trim Setting, bit 6 */
    byte TRIM7       :1;                                       /* ICS Trim Setting, bit 7 */
  } Bits;
} ICSTRMSTR;
extern volatile ICSTRMSTR _ICSTRM @0x0000003A;
#define ICSTRM                          _ICSTRM.Byte
#define ICSTRM_TRIM0                    _ICSTRM.Bits.TRIM0
#define ICSTRM_TRIM1                    _ICSTRM.Bits.TRIM1
#define ICSTRM_TRIM2                    _ICSTRM.Bits.TRIM2
#define ICSTRM_TRIM3                    _ICSTRM.Bits.TRIM3
#define ICSTRM_TRIM4                    _ICSTRM.Bits.TRIM4
#define ICSTRM_TRIM5                    _ICSTRM.Bits.TRIM5
#define ICSTRM_TRIM6                    _ICSTRM.Bits.TRIM6
#define ICSTRM_TRIM7                    _ICSTRM.Bits.TRIM7

#define ICSTRM_TRIM0_MASK               1
#define ICSTRM_TRIM1_MASK               2
#define ICSTRM_TRIM2_MASK               4
#define ICSTRM_TRIM3_MASK               8
#define ICSTRM_TRIM4_MASK               16
#define ICSTRM_TRIM5_MASK               32
#define ICSTRM_TRIM6_MASK               64
#define ICSTRM_TRIM7_MASK               128


/*** ICSSC - ICS Status and Control Register; 0x0000003B ***/
typedef union {
  byte Byte;
  struct {
    byte FTRIM       :1;                                       /* ICS Fine Trim */
    byte OSCINIT     :1;                                       /* OSC Initialization */
    byte CLKST0      :1;                                       /* Clock Mode Status, bit 0 */
    byte CLKST1      :1;                                       /* Clock Mode Status, bit 1 */
    byte IREFST      :1;                                       /* Internal Reference Status */
    byte DMX32       :1;                                       /* DCO Maximum frequency with 32.768 kHz reference */
    byte DRST_DRS0   :1;                                       /* DCO Range Status/Range Select, bit 0 */
    byte DRST_DRS1   :1;                                       /* DCO Range Status/Range Select, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpCLKST :2;
    byte         :1;
    byte grpDMX_32 :1;
    byte grpDRST_DRS :2;
  } MergedBits;
} ICSSCSTR;
extern volatile ICSSCSTR _ICSSC @0x0000003B;
#define ICSSC                           _ICSSC.Byte
#define ICSSC_FTRIM                     _ICSSC.Bits.FTRIM
#define ICSSC_OSCINIT                   _ICSSC.Bits.OSCINIT
#define ICSSC_CLKST0                    _ICSSC.Bits.CLKST0
#define ICSSC_CLKST1                    _ICSSC.Bits.CLKST1
#define ICSSC_IREFST                    _ICSSC.Bits.IREFST
#define ICSSC_DMX32                     _ICSSC.Bits.DMX32
#define ICSSC_DRST_DRS0                 _ICSSC.Bits.DRST_DRS0
#define ICSSC_DRST_DRS1                 _ICSSC.Bits.DRST_DRS1
#define ICSSC_CLKST                     _ICSSC.MergedBits.grpCLKST
#define ICSSC_DRST_DRS                  _ICSSC.MergedBits.grpDRST_DRS

#define ICSSC_FTRIM_MASK                1
#define ICSSC_OSCINIT_MASK              2
#define ICSSC_CLKST0_MASK               4
#define ICSSC_CLKST1_MASK               8
#define ICSSC_IREFST_MASK               16
#define ICSSC_DMX32_MASK                32
#define ICSSC_DRST_DRS0_MASK            64
#define ICSSC_DRST_DRS1_MASK            128
#define ICSSC_CLKST_MASK                12
#define ICSSC_CLKST_BITNUM              2
#define ICSSC_DRST_DRS_MASK             192
#define ICSSC_DRST_DRS_BITNUM           6


/*** TPM1SC - TPM1 Status and Control Register; 0x00000040 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1SCSTR;
extern volatile TPM1SCSTR _TPM1SC @0x00000040;
#define TPM1SC                          _TPM1SC.Byte
#define TPM1SC_PS0                      _TPM1SC.Bits.PS0
#define TPM1SC_PS1                      _TPM1SC.Bits.PS1
#define TPM1SC_PS2                      _TPM1SC.Bits.PS2
#define TPM1SC_CLKSA                    _TPM1SC.Bits.CLKSA
#define TPM1SC_CLKSB                    _TPM1SC.Bits.CLKSB
#define TPM1SC_CPWMS                    _TPM1SC.Bits.CPWMS
#define TPM1SC_TOIE                     _TPM1SC.Bits.TOIE
#define TPM1SC_TOF                      _TPM1SC.Bits.TOF
#define TPM1SC_PS                       _TPM1SC.MergedBits.grpPS
#define TPM1SC_CLKSx                    _TPM1SC.MergedBits.grpCLKSx

#define TPM1SC_PS0_MASK                 1
#define TPM1SC_PS1_MASK                 2
#define TPM1SC_PS2_MASK                 4
#define TPM1SC_CLKSA_MASK               8
#define TPM1SC_CLKSB_MASK               16
#define TPM1SC_CPWMS_MASK               32
#define TPM1SC_TOIE_MASK                64
#define TPM1SC_TOF_MASK                 128
#define TPM1SC_PS_MASK                  7
#define TPM1SC_PS_BITNUM                0
#define TPM1SC_CLKSx_MASK               24
#define TPM1SC_CLKSx_BITNUM             3


/*** TPM1CNT - TPM1 Timer Counter Register; 0x00000041 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1CNTH - TPM1 Timer Counter Register High; 0x00000041 ***/
    union {
      byte Byte;
    } TPM1CNTHSTR;
    #define TPM1CNTH                    _TPM1CNT.Overlap_STR.TPM1CNTHSTR.Byte
    

    /*** TPM1CNTL - TPM1 Timer Counter Register Low; 0x00000042 ***/
    union {
      byte Byte;
    } TPM1CNTLSTR;
    #define TPM1CNTL                    _TPM1CNT.Overlap_STR.TPM1CNTLSTR.Byte
    
  } Overlap_STR;

} TPM1CNTSTR;
extern volatile TPM1CNTSTR _TPM1CNT @0x00000041;
#define TPM1CNT                         _TPM1CNT.Word


/*** TPM1MOD - TPM1 Timer Counter Modulo Register; 0x00000043 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1MODH - TPM1 Timer Counter Modulo Register High; 0x00000043 ***/
    union {
      byte Byte;
    } TPM1MODHSTR;
    #define TPM1MODH                    _TPM1MOD.Overlap_STR.TPM1MODHSTR.Byte
    

    /*** TPM1MODL - TPM1 Timer Counter Modulo Register Low; 0x00000044 ***/
    union {
      byte Byte;
    } TPM1MODLSTR;
    #define TPM1MODL                    _TPM1MOD.Overlap_STR.TPM1MODLSTR.Byte
    
  } Overlap_STR;

} TPM1MODSTR;
extern volatile TPM1MODSTR _TPM1MOD @0x00000043;
#define TPM1MOD                         _TPM1MOD.Word


/*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register; 0x00000045 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C0SCSTR;
extern volatile TPM1C0SCSTR _TPM1C0SC @0x00000045;
#define TPM1C0SC                        _TPM1C0SC.Byte
#define TPM1C0SC_ELS0A                  _TPM1C0SC.Bits.ELS0A
#define TPM1C0SC_ELS0B                  _TPM1C0SC.Bits.ELS0B
#define TPM1C0SC_MS0A                   _TPM1C0SC.Bits.MS0A
#define TPM1C0SC_MS0B                   _TPM1C0SC.Bits.MS0B
#define TPM1C0SC_CH0IE                  _TPM1C0SC.Bits.CH0IE
#define TPM1C0SC_CH0F                   _TPM1C0SC.Bits.CH0F
#define TPM1C0SC_ELS0x                  _TPM1C0SC.MergedBits.grpELS0x
#define TPM1C0SC_MS0x                   _TPM1C0SC.MergedBits.grpMS0x

#define TPM1C0SC_ELS0A_MASK             4
#define TPM1C0SC_ELS0B_MASK             8
#define TPM1C0SC_MS0A_MASK              16
#define TPM1C0SC_MS0B_MASK              32
#define TPM1C0SC_CH0IE_MASK             64
#define TPM1C0SC_CH0F_MASK              128
#define TPM1C0SC_ELS0x_MASK             12
#define TPM1C0SC_ELS0x_BITNUM           2
#define TPM1C0SC_MS0x_MASK              48
#define TPM1C0SC_MS0x_BITNUM            4


/*** TPM1C0V - TPM1 Timer Channel 0 Value Register; 0x00000046 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High; 0x00000046 ***/
    union {
      byte Byte;
    } TPM1C0VHSTR;
    #define TPM1C0VH                    _TPM1C0V.Overlap_STR.TPM1C0VHSTR.Byte
    

    /*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low; 0x00000047 ***/
    union {
      byte Byte;
    } TPM1C0VLSTR;
    #define TPM1C0VL                    _TPM1C0V.Overlap_STR.TPM1C0VLSTR.Byte
    
  } Overlap_STR;

} TPM1C0VSTR;
extern volatile TPM1C0VSTR _TPM1C0V @0x00000046;
#define TPM1C0V                         _TPM1C0V.Word


/*** TPM1C1SC - TPM1 Timer Channel 1 Status and Control Register; 0x00000048 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for TPM Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for TPM Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C1SCSTR;
extern volatile TPM1C1SCSTR _TPM1C1SC @0x00000048;
#define TPM1C1SC                        _TPM1C1SC.Byte
#define TPM1C1SC_ELS1A                  _TPM1C1SC.Bits.ELS1A
#define TPM1C1SC_ELS1B                  _TPM1C1SC.Bits.ELS1B
#define TPM1C1SC_MS1A                   _TPM1C1SC.Bits.MS1A
#define TPM1C1SC_MS1B                   _TPM1C1SC.Bits.MS1B
#define TPM1C1SC_CH1IE                  _TPM1C1SC.Bits.CH1IE
#define TPM1C1SC_CH1F                   _TPM1C1SC.Bits.CH1F
#define TPM1C1SC_ELS1x                  _TPM1C1SC.MergedBits.grpELS1x
#define TPM1C1SC_MS1x                   _TPM1C1SC.MergedBits.grpMS1x

#define TPM1C1SC_ELS1A_MASK             4
#define TPM1C1SC_ELS1B_MASK             8
#define TPM1C1SC_MS1A_MASK              16
#define TPM1C1SC_MS1B_MASK              32
#define TPM1C1SC_CH1IE_MASK             64
#define TPM1C1SC_CH1F_MASK              128
#define TPM1C1SC_ELS1x_MASK             12
#define TPM1C1SC_ELS1x_BITNUM           2
#define TPM1C1SC_MS1x_MASK              48
#define TPM1C1SC_MS1x_BITNUM            4


/*** TPM1C1V - TPM1 Timer Channel 1 Value Register; 0x00000049 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C1VH - TPM1 Timer Channel 1 Value Register High; 0x00000049 ***/
    union {
      byte Byte;
    } TPM1C1VHSTR;
    #define TPM1C1VH                    _TPM1C1V.Overlap_STR.TPM1C1VHSTR.Byte
    

    /*** TPM1C1VL - TPM1 Timer Channel 1 Value Register Low; 0x0000004A ***/
    union {
      byte Byte;
    } TPM1C1VLSTR;
    #define TPM1C1VL                    _TPM1C1V.Overlap_STR.TPM1C1VLSTR.Byte
    
  } Overlap_STR;

} TPM1C1VSTR;
extern volatile TPM1C1VSTR _TPM1C1V @0x00000049;
#define TPM1C1V                         _TPM1C1V.Word


/*** TPM2SC - TPM2 Status and Control Register; 0x00000050 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2SCSTR;
extern volatile TPM2SCSTR _TPM2SC @0x00000050;
#define TPM2SC                          _TPM2SC.Byte
#define TPM2SC_PS0                      _TPM2SC.Bits.PS0
#define TPM2SC_PS1                      _TPM2SC.Bits.PS1
#define TPM2SC_PS2                      _TPM2SC.Bits.PS2
#define TPM2SC_CLKSA                    _TPM2SC.Bits.CLKSA
#define TPM2SC_CLKSB                    _TPM2SC.Bits.CLKSB
#define TPM2SC_CPWMS                    _TPM2SC.Bits.CPWMS
#define TPM2SC_TOIE                     _TPM2SC.Bits.TOIE
#define TPM2SC_TOF                      _TPM2SC.Bits.TOF
#define TPM2SC_PS                       _TPM2SC.MergedBits.grpPS
#define TPM2SC_CLKSx                    _TPM2SC.MergedBits.grpCLKSx

#define TPM2SC_PS0_MASK                 1
#define TPM2SC_PS1_MASK                 2
#define TPM2SC_PS2_MASK                 4
#define TPM2SC_CLKSA_MASK               8
#define TPM2SC_CLKSB_MASK               16
#define TPM2SC_CPWMS_MASK               32
#define TPM2SC_TOIE_MASK                64
#define TPM2SC_TOF_MASK                 128
#define TPM2SC_PS_MASK                  7
#define TPM2SC_PS_BITNUM                0
#define TPM2SC_CLKSx_MASK               24
#define TPM2SC_CLKSx_BITNUM             3


/*** TPM2CNT - TPM2 Timer Counter Register; 0x00000051 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2CNTH - TPM2 Timer Counter Register High; 0x00000051 ***/
    union {
      byte Byte;
    } TPM2CNTHSTR;
    #define TPM2CNTH                    _TPM2CNT.Overlap_STR.TPM2CNTHSTR.Byte
    

    /*** TPM2CNTL - TPM2 Timer Counter Register Low; 0x00000052 ***/
    union {
      byte Byte;
    } TPM2CNTLSTR;
    #define TPM2CNTL                    _TPM2CNT.Overlap_STR.TPM2CNTLSTR.Byte
    
  } Overlap_STR;

} TPM2CNTSTR;
extern volatile TPM2CNTSTR _TPM2CNT @0x00000051;
#define TPM2CNT                         _TPM2CNT.Word


/*** TPM2MOD - TPM2 Timer Counter Modulo Register; 0x00000053 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2MODH - TPM2 Timer Counter Modulo Register High; 0x00000053 ***/
    union {
      byte Byte;
    } TPM2MODHSTR;
    #define TPM2MODH                    _TPM2MOD.Overlap_STR.TPM2MODHSTR.Byte
    

    /*** TPM2MODL - TPM2 Timer Counter Modulo Register Low; 0x00000054 ***/
    union {
      byte Byte;
    } TPM2MODLSTR;
    #define TPM2MODL                    _TPM2MOD.Overlap_STR.TPM2MODLSTR.Byte
    
  } Overlap_STR;

} TPM2MODSTR;
extern volatile TPM2MODSTR _TPM2MOD @0x00000053;
#define TPM2MOD                         _TPM2MOD.Word


/*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register; 0x00000055 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2C0SCSTR;
extern volatile TPM2C0SCSTR _TPM2C0SC @0x00000055;
#define TPM2C0SC                        _TPM2C0SC.Byte
#define TPM2C0SC_ELS0A                  _TPM2C0SC.Bits.ELS0A
#define TPM2C0SC_ELS0B                  _TPM2C0SC.Bits.ELS0B
#define TPM2C0SC_MS0A                   _TPM2C0SC.Bits.MS0A
#define TPM2C0SC_MS0B                   _TPM2C0SC.Bits.MS0B
#define TPM2C0SC_CH0IE                  _TPM2C0SC.Bits.CH0IE
#define TPM2C0SC_CH0F                   _TPM2C0SC.Bits.CH0F
#define TPM2C0SC_ELS0x                  _TPM2C0SC.MergedBits.grpELS0x
#define TPM2C0SC_MS0x                   _TPM2C0SC.MergedBits.grpMS0x

#define TPM2C0SC_ELS0A_MASK             4
#define TPM2C0SC_ELS0B_MASK             8
#define TPM2C0SC_MS0A_MASK              16
#define TPM2C0SC_MS0B_MASK              32
#define TPM2C0SC_CH0IE_MASK             64
#define TPM2C0SC_CH0F_MASK              128
#define TPM2C0SC_ELS0x_MASK             12
#define TPM2C0SC_ELS0x_BITNUM           2
#define TPM2C0SC_MS0x_MASK              48
#define TPM2C0SC_MS0x_BITNUM            4


/*** TPM2C0V - TPM2 Timer Channel 0 Value Register; 0x00000056 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High; 0x00000056 ***/
    union {
      byte Byte;
    } TPM2C0VHSTR;
    #define TPM2C0VH                    _TPM2C0V.Overlap_STR.TPM2C0VHSTR.Byte
    

    /*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low; 0x00000057 ***/
    union {
      byte Byte;
    } TPM2C0VLSTR;
    #define TPM2C0VL                    _TPM2C0V.Overlap_STR.TPM2C0VLSTR.Byte
    
  } Overlap_STR;

} TPM2C0VSTR;
extern volatile TPM2C0VSTR _TPM2C0V @0x00000056;
#define TPM2C0V                         _TPM2C0V.Word


/*** TPM2C1SC - TPM2 Timer Channel 1 Status and Control Register; 0x00000058 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for TPM Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for TPM Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2C1SCSTR;
extern volatile TPM2C1SCSTR _TPM2C1SC @0x00000058;
#define TPM2C1SC                        _TPM2C1SC.Byte
#define TPM2C1SC_ELS1A                  _TPM2C1SC.Bits.ELS1A
#define TPM2C1SC_ELS1B                  _TPM2C1SC.Bits.ELS1B
#define TPM2C1SC_MS1A                   _TPM2C1SC.Bits.MS1A
#define TPM2C1SC_MS1B                   _TPM2C1SC.Bits.MS1B
#define TPM2C1SC_CH1IE                  _TPM2C1SC.Bits.CH1IE
#define TPM2C1SC_CH1F                   _TPM2C1SC.Bits.CH1F
#define TPM2C1SC_ELS1x                  _TPM2C1SC.MergedBits.grpELS1x
#define TPM2C1SC_MS1x                   _TPM2C1SC.MergedBits.grpMS1x

#define TPM2C1SC_ELS1A_MASK             4
#define TPM2C1SC_ELS1B_MASK             8
#define TPM2C1SC_MS1A_MASK              16
#define TPM2C1SC_MS1B_MASK              32
#define TPM2C1SC_CH1IE_MASK             64
#define TPM2C1SC_CH1F_MASK              128
#define TPM2C1SC_ELS1x_MASK             12
#define TPM2C1SC_ELS1x_BITNUM           2
#define TPM2C1SC_MS1x_MASK              48
#define TPM2C1SC_MS1x_BITNUM            4


/*** TPM2C1V - TPM2 Timer Channel 1 Value Register; 0x00000059 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2C1VH - TPM2 Timer Channel 1 Value Register High; 0x00000059 ***/
    union {
      byte Byte;
    } TPM2C1VHSTR;
    #define TPM2C1VH                    _TPM2C1V.Overlap_STR.TPM2C1VHSTR.Byte
    

    /*** TPM2C1VL - TPM2 Timer Channel 1 Value Register Low; 0x0000005A ***/
    union {
      byte Byte;
    } TPM2C1VLSTR;
    #define TPM2C1VL                    _TPM2C1V.Overlap_STR.TPM2C1VLSTR.Byte
    
  } Overlap_STR;

} TPM2C1VSTR;
extern volatile TPM2C1VSTR _TPM2C1V @0x00000059;
#define TPM2C1V                         _TPM2C1V.Word


/*** VREF1TRM - VREF Trim Register; 0x0000005C ***/
typedef union {
  byte Byte;
  struct {
    byte TRM0        :1;                                       /* Trim Bits, bit 0 */
    byte TRM1        :1;                                       /* Trim Bits, bit 1 */
    byte TRM2        :1;                                       /* Trim Bits, bit 2 */
    byte TRM3        :1;                                       /* Trim Bits, bit 3 */
    byte TRM4        :1;                                       /* Trim Bits, bit 4 */
    byte TRM5        :1;                                       /* Trim Bits, bit 5 */
    byte TRM6        :1;                                       /* Trim Bits, bit 6 */
    byte TRM7        :1;                                       /* Trim Bits, bit 7 */
  } Bits;
} VREF1TRMSTR;
extern volatile VREF1TRMSTR _VREF1TRM @0x0000005C;
#define VREF1TRM                        _VREF1TRM.Byte
#define VREF1TRM_TRM0                   _VREF1TRM.Bits.TRM0
#define VREF1TRM_TRM1                   _VREF1TRM.Bits.TRM1
#define VREF1TRM_TRM2                   _VREF1TRM.Bits.TRM2
#define VREF1TRM_TRM3                   _VREF1TRM.Bits.TRM3
#define VREF1TRM_TRM4                   _VREF1TRM.Bits.TRM4
#define VREF1TRM_TRM5                   _VREF1TRM.Bits.TRM5
#define VREF1TRM_TRM6                   _VREF1TRM.Bits.TRM6
#define VREF1TRM_TRM7                   _VREF1TRM.Bits.TRM7

#define VREF1TRM_TRM0_MASK              1
#define VREF1TRM_TRM1_MASK              2
#define VREF1TRM_TRM2_MASK              4
#define VREF1TRM_TRM3_MASK              8
#define VREF1TRM_TRM4_MASK              16
#define VREF1TRM_TRM5_MASK              32
#define VREF1TRM_TRM6_MASK              64
#define VREF1TRM_TRM7_MASK              128


/*** VREF1SC - VREF Control Register; 0x0000005D ***/
typedef union {
  byte Byte;
  struct {
    byte MODE0       :1;                                       /* Mode selection, bit 0 */
    byte MODE1       :1;                                       /* Mode selection, bit 1 */
    byte VREFST      :1;                                       /* Internal Voltage Reference Stable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte VREFEN      :1;                                       /* Internal Voltage Reference Enable */
  } Bits;
  struct {
    byte grpMODE :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} VREF1SCSTR;
extern volatile VREF1SCSTR _VREF1SC @0x0000005D;
#define VREF1SC                         _VREF1SC.Byte
#define VREF1SC_MODE0                   _VREF1SC.Bits.MODE0
#define VREF1SC_MODE1                   _VREF1SC.Bits.MODE1
#define VREF1SC_VREFST                  _VREF1SC.Bits.VREFST
#define VREF1SC_VREFEN                  _VREF1SC.Bits.VREFEN
#define VREF1SC_MODE                    _VREF1SC.MergedBits.grpMODE

#define VREF1SC_MODE0_MASK              1
#define VREF1SC_MODE1_MASK              2
#define VREF1SC_VREFST_MASK             4
#define VREF1SC_VREFEN_MASK             128
#define VREF1SC_MODE_MASK               3
#define VREF1SC_MODE_BITNUM             0


/*** VREF2TRM - VREF Trim Register; 0x0000005E ***/
typedef union {
  byte Byte;
  struct {
    byte TRM0        :1;                                       /* Trim Bits, bit 0 */
    byte TRM1        :1;                                       /* Trim Bits, bit 1 */
    byte TRM2        :1;                                       /* Trim Bits, bit 2 */
    byte TRM3        :1;                                       /* Trim Bits, bit 3 */
    byte TRM4        :1;                                       /* Trim Bits, bit 4 */
    byte TRM5        :1;                                       /* Trim Bits, bit 5 */
    byte TRM6        :1;                                       /* Trim Bits, bit 6 */
    byte TRM7        :1;                                       /* Trim Bits, bit 7 */
  } Bits;
} VREF2TRMSTR;
extern volatile VREF2TRMSTR _VREF2TRM @0x0000005E;
#define VREF2TRM                        _VREF2TRM.Byte
#define VREF2TRM_TRM0                   _VREF2TRM.Bits.TRM0
#define VREF2TRM_TRM1                   _VREF2TRM.Bits.TRM1
#define VREF2TRM_TRM2                   _VREF2TRM.Bits.TRM2
#define VREF2TRM_TRM3                   _VREF2TRM.Bits.TRM3
#define VREF2TRM_TRM4                   _VREF2TRM.Bits.TRM4
#define VREF2TRM_TRM5                   _VREF2TRM.Bits.TRM5
#define VREF2TRM_TRM6                   _VREF2TRM.Bits.TRM6
#define VREF2TRM_TRM7                   _VREF2TRM.Bits.TRM7

#define VREF2TRM_TRM0_MASK              1
#define VREF2TRM_TRM1_MASK              2
#define VREF2TRM_TRM2_MASK              4
#define VREF2TRM_TRM3_MASK              8
#define VREF2TRM_TRM4_MASK              16
#define VREF2TRM_TRM5_MASK              32
#define VREF2TRM_TRM6_MASK              64
#define VREF2TRM_TRM7_MASK              128


/*** VREF2SC - VREF Control Register; 0x0000005F ***/
typedef union {
  byte Byte;
  struct {
    byte MODE0       :1;                                       /* Mode selection, bit 0 */
    byte MODE1       :1;                                       /* Mode selection, bit 1 */
    byte VREFST      :1;                                       /* Internal Voltage Reference Stable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte VREFEN      :1;                                       /* Internal Voltage Reference Enable */
  } Bits;
  struct {
    byte grpMODE :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} VREF2SCSTR;
extern volatile VREF2SCSTR _VREF2SC @0x0000005F;
#define VREF2SC                         _VREF2SC.Byte
#define VREF2SC_MODE0                   _VREF2SC.Bits.MODE0
#define VREF2SC_MODE1                   _VREF2SC.Bits.MODE1
#define VREF2SC_VREFST                  _VREF2SC.Bits.VREFST
#define VREF2SC_VREFEN                  _VREF2SC.Bits.VREFEN
#define VREF2SC_MODE                    _VREF2SC.MergedBits.grpMODE

#define VREF2SC_MODE0_MASK              1
#define VREF2SC_MODE1_MASK              2
#define VREF2SC_VREFST_MASK             4
#define VREF2SC_VREFEN_MASK             128
#define VREF2SC_MODE_MASK               3
#define VREF2SC_MODE_BITNUM             0


/*** LCDPEN0 - LCD Pin Enable Register 0; 0x00001000 ***/
typedef union {
  byte Byte;
  struct {
    byte PEN0        :1;                                       /* Enable LCD pin 0 for LCD operation */
    byte PEN1        :1;                                       /* Enable LCD pin 1 for LCD operation */
    byte PEN2        :1;                                       /* Enable LCD pin 2 for LCD operation */
    byte PEN3        :1;                                       /* Enable LCD pin 3 for LCD operation */
    byte PEN4        :1;                                       /* Enable LCD pin 4 for LCD operation */
    byte PEN5        :1;                                       /* Enable LCD pin 5 for LCD operation */
    byte PEN6        :1;                                       /* Enable LCD pin 6 for LCD operation */
    byte PEN7        :1;                                       /* Enable LCD pin 7 for LCD operation */
  } Bits;
} LCDPEN0STR;
extern volatile LCDPEN0STR _LCDPEN0 @0x00001000;
#define LCDPEN0                         _LCDPEN0.Byte
#define LCDPEN0_PEN0                    _LCDPEN0.Bits.PEN0
#define LCDPEN0_PEN1                    _LCDPEN0.Bits.PEN1
#define LCDPEN0_PEN2                    _LCDPEN0.Bits.PEN2
#define LCDPEN0_PEN3                    _LCDPEN0.Bits.PEN3
#define LCDPEN0_PEN4                    _LCDPEN0.Bits.PEN4
#define LCDPEN0_PEN5                    _LCDPEN0.Bits.PEN5
#define LCDPEN0_PEN6                    _LCDPEN0.Bits.PEN6
#define LCDPEN0_PEN7                    _LCDPEN0.Bits.PEN7
/* LCDPEN_ARR: Access 6 LCDPENx registers in an array */
#define LCDPEN_ARR                      ((volatile byte * __far) &LCDPEN0)

#define LCDPEN0_PEN0_MASK               1
#define LCDPEN0_PEN1_MASK               2
#define LCDPEN0_PEN2_MASK               4
#define LCDPEN0_PEN3_MASK               8
#define LCDPEN0_PEN4_MASK               16
#define LCDPEN0_PEN5_MASK               32
#define LCDPEN0_PEN6_MASK               64
#define LCDPEN0_PEN7_MASK               128


/*** LCDPEN1 - LCD Pin Enable Register 1; 0x00001001 ***/
typedef union {
  byte Byte;
  struct {
    byte PEN8        :1;                                       /* Enable LCD pin 8 for LCD operation */
    byte PEN9        :1;                                       /* Enable LCD pin 9 for LCD operation */
    byte PEN10       :1;                                       /* Enable LCD pin 10 for LCD operation */
    byte PEN11       :1;                                       /* Enable LCD pin 11 for LCD operation */
    byte PEN12       :1;                                       /* Enable LCD pin 12 for LCD operation */
    byte PEN13       :1;                                       /* Enable LCD pin 13 for LCD operation */
    byte PEN14       :1;                                       /* Enable LCD pin 14 for LCD operation */
    byte PEN15       :1;                                       /* Enable LCD pin 15 for LCD operation */
  } Bits;
} LCDPEN1STR;
extern volatile LCDPEN1STR _LCDPEN1 @0x00001001;
#define LCDPEN1                         _LCDPEN1.Byte
#define LCDPEN1_PEN8                    _LCDPEN1.Bits.PEN8
#define LCDPEN1_PEN9                    _LCDPEN1.Bits.PEN9
#define LCDPEN1_PEN10                   _LCDPEN1.Bits.PEN10
#define LCDPEN1_PEN11                   _LCDPEN1.Bits.PEN11
#define LCDPEN1_PEN12                   _LCDPEN1.Bits.PEN12
#define LCDPEN1_PEN13                   _LCDPEN1.Bits.PEN13
#define LCDPEN1_PEN14                   _LCDPEN1.Bits.PEN14
#define LCDPEN1_PEN15                   _LCDPEN1.Bits.PEN15

#define LCDPEN1_PEN8_MASK               1
#define LCDPEN1_PEN9_MASK               2
#define LCDPEN1_PEN10_MASK              4
#define LCDPEN1_PEN11_MASK              8
#define LCDPEN1_PEN12_MASK              16
#define LCDPEN1_PEN13_MASK              32
#define LCDPEN1_PEN14_MASK              64
#define LCDPEN1_PEN15_MASK              128


/*** LCDPEN2 - LCD Pin Enable Register 2; 0x00001002 ***/
typedef union {
  byte Byte;
  struct {
    byte PEN16       :1;                                       /* Enable LCD pin 16 for LCD operation */
    byte PEN17       :1;                                       /* Enable LCD pin 17 for LCD operation */
    byte PEN18       :1;                                       /* Enable LCD pin 18 for LCD operation */
    byte PEN19       :1;                                       /* Enable LCD pin 19 for LCD operation */
    byte PEN20       :1;                                       /* Enable LCD pin 20 for LCD operation */
    byte PEN21       :1;                                       /* Enable LCD pin 21 for LCD operation */
    byte PEN22       :1;                                       /* Enable LCD pin 22 for LCD operation */
    byte PEN23       :1;                                       /* Enable LCD pin 23 for LCD operation */
  } Bits;
} LCDPEN2STR;
extern volatile LCDPEN2STR _LCDPEN2 @0x00001002;
#define LCDPEN2                         _LCDPEN2.Byte
#define LCDPEN2_PEN16                   _LCDPEN2.Bits.PEN16
#define LCDPEN2_PEN17                   _LCDPEN2.Bits.PEN17
#define LCDPEN2_PEN18                   _LCDPEN2.Bits.PEN18
#define LCDPEN2_PEN19                   _LCDPEN2.Bits.PEN19
#define LCDPEN2_PEN20                   _LCDPEN2.Bits.PEN20
#define LCDPEN2_PEN21                   _LCDPEN2.Bits.PEN21
#define LCDPEN2_PEN22                   _LCDPEN2.Bits.PEN22
#define LCDPEN2_PEN23                   _LCDPEN2.Bits.PEN23

#define LCDPEN2_PEN16_MASK              1
#define LCDPEN2_PEN17_MASK              2
#define LCDPEN2_PEN18_MASK              4
#define LCDPEN2_PEN19_MASK              8
#define LCDPEN2_PEN20_MASK              16
#define LCDPEN2_PEN21_MASK              32
#define LCDPEN2_PEN22_MASK              64
#define LCDPEN2_PEN23_MASK              128


/*** LCDPEN3 - LCD Pin Enable Register 3; 0x00001003 ***/
typedef union {
  byte Byte;
  struct {
    byte PEN24       :1;                                       /* Enable LCD pin 24 for LCD operation */
    byte PEN25       :1;                                       /* Enable LCD pin 25 for LCD operation */
    byte PEN26       :1;                                       /* Enable LCD pin 26 for LCD operation */
    byte PEN27       :1;                                       /* Enable LCD pin 27 for LCD operation */
    byte PEN28       :1;                                       /* Enable LCD pin 28 for LCD operation */
    byte PEN29       :1;                                       /* Enable LCD pin 29 for LCD operation */
    byte PEN30       :1;                                       /* Enable LCD pin 30 for LCD operation */
    byte PEN31       :1;                                       /* Enable LCD pin 31 for LCD operation */
  } Bits;
} LCDPEN3STR;
extern volatile LCDPEN3STR _LCDPEN3 @0x00001003;
#define LCDPEN3                         _LCDPEN3.Byte
#define LCDPEN3_PEN24                   _LCDPEN3.Bits.PEN24
#define LCDPEN3_PEN25                   _LCDPEN3.Bits.PEN25
#define LCDPEN3_PEN26                   _LCDPEN3.Bits.PEN26
#define LCDPEN3_PEN27                   _LCDPEN3.Bits.PEN27
#define LCDPEN3_PEN28                   _LCDPEN3.Bits.PEN28
#define LCDPEN3_PEN29                   _LCDPEN3.Bits.PEN29
#define LCDPEN3_PEN30                   _LCDPEN3.Bits.PEN30
#define LCDPEN3_PEN31                   _LCDPEN3.Bits.PEN31

#define LCDPEN3_PEN24_MASK              1
#define LCDPEN3_PEN25_MASK              2
#define LCDPEN3_PEN26_MASK              4
#define LCDPEN3_PEN27_MASK              8
#define LCDPEN3_PEN28_MASK              16
#define LCDPEN3_PEN29_MASK              32
#define LCDPEN3_PEN30_MASK              64
#define LCDPEN3_PEN31_MASK              128


/*** LCDPEN4 - LCD Pin Enable Register 4; 0x00001004 ***/
typedef union {
  byte Byte;
  struct {
    byte PEN32       :1;                                       /* Enable LCD pin 32 for LCD operation */
    byte PEN33       :1;                                       /* Enable LCD pin 33 for LCD operation */
    byte PEN34       :1;                                       /* Enable LCD pin 34 for LCD operation */
    byte PEN35       :1;                                       /* Enable LCD pin 35 for LCD operation */
    byte PEN36       :1;                                       /* Enable LCD pin 36 for LCD operation */
    byte PEN37       :1;                                       /* Enable LCD pin 37 for LCD operation */
    byte PEN38       :1;                                       /* Enable LCD pin 38 for LCD operation */
    byte PEN39       :1;                                       /* Enable LCD pin 39 for LCD operation */
  } Bits;
} LCDPEN4STR;
extern volatile LCDPEN4STR _LCDPEN4 @0x00001004;
#define LCDPEN4                         _LCDPEN4.Byte
#define LCDPEN4_PEN32                   _LCDPEN4.Bits.PEN32
#define LCDPEN4_PEN33                   _LCDPEN4.Bits.PEN33
#define LCDPEN4_PEN34                   _LCDPEN4.Bits.PEN34
#define LCDPEN4_PEN35                   _LCDPEN4.Bits.PEN35
#define LCDPEN4_PEN36                   _LCDPEN4.Bits.PEN36
#define LCDPEN4_PEN37                   _LCDPEN4.Bits.PEN37
#define LCDPEN4_PEN38                   _LCDPEN4.Bits.PEN38
#define LCDPEN4_PEN39                   _LCDPEN4.Bits.PEN39

#define LCDPEN4_PEN32_MASK              1
#define LCDPEN4_PEN33_MASK              2
#define LCDPEN4_PEN34_MASK              4
#define LCDPEN4_PEN35_MASK              8
#define LCDPEN4_PEN36_MASK              16
#define LCDPEN4_PEN37_MASK              32
#define LCDPEN4_PEN38_MASK              64
#define LCDPEN4_PEN39_MASK              128


/*** LCDPEN5 - LCD Pin Enable Register 5; 0x00001005 ***/
typedef union {
  byte Byte;
  struct {
    byte PEN40       :1;                                       /* Enable LCD pin 40 for LCD operation */
    byte PEN41       :1;                                       /* Enable LCD pin 41 for LCD operation */
    byte PEN42       :1;                                       /* Enable LCD pin 42 for LCD operation */
    byte PEN43       :1;                                       /* Enable LCD pin 43 for LCD operation */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPEN_40 :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} LCDPEN5STR;
extern volatile LCDPEN5STR _LCDPEN5 @0x00001005;
#define LCDPEN5                         _LCDPEN5.Byte
#define LCDPEN5_PEN40                   _LCDPEN5.Bits.PEN40
#define LCDPEN5_PEN41                   _LCDPEN5.Bits.PEN41
#define LCDPEN5_PEN42                   _LCDPEN5.Bits.PEN42
#define LCDPEN5_PEN43                   _LCDPEN5.Bits.PEN43
#define LCDPEN5_PEN_40                  _LCDPEN5.MergedBits.grpPEN_40
#define LCDPEN5_PEN                     LCDPEN5_PEN_40

#define LCDPEN5_PEN40_MASK              1
#define LCDPEN5_PEN41_MASK              2
#define LCDPEN5_PEN42_MASK              4
#define LCDPEN5_PEN43_MASK              8
#define LCDPEN5_PEN_40_MASK             15
#define LCDPEN5_PEN_40_BITNUM           0


/*** LCDBPEN0 - LCD Backplane Enable Register 0; 0x00001008 ***/
typedef union {
  byte Byte;
  struct {
    byte BPEN0       :1;                                       /* Enable LCD pin 0 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN1       :1;                                       /* Enable LCD pin 1 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN2       :1;                                       /* Enable LCD pin 2 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN3       :1;                                       /* Enable LCD pin 3 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN4       :1;                                       /* Enable LCD pin 4 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN5       :1;                                       /* Enable LCD pin 5 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN6       :1;                                       /* Enable LCD pin 6 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN7       :1;                                       /* Enable LCD pin 7 to operate as an LCD backplane or an LCD frontplane */
  } Bits;
} LCDBPEN0STR;
extern volatile LCDBPEN0STR _LCDBPEN0 @0x00001008;
#define LCDBPEN0                        _LCDBPEN0.Byte
#define LCDBPEN0_BPEN0                  _LCDBPEN0.Bits.BPEN0
#define LCDBPEN0_BPEN1                  _LCDBPEN0.Bits.BPEN1
#define LCDBPEN0_BPEN2                  _LCDBPEN0.Bits.BPEN2
#define LCDBPEN0_BPEN3                  _LCDBPEN0.Bits.BPEN3
#define LCDBPEN0_BPEN4                  _LCDBPEN0.Bits.BPEN4
#define LCDBPEN0_BPEN5                  _LCDBPEN0.Bits.BPEN5
#define LCDBPEN0_BPEN6                  _LCDBPEN0.Bits.BPEN6
#define LCDBPEN0_BPEN7                  _LCDBPEN0.Bits.BPEN7
/* LCDBPEN_ARR: Access 6 LCDBPENx registers in an array */
#define LCDBPEN_ARR                     ((volatile byte * __far) &LCDBPEN0)

#define LCDBPEN0_BPEN0_MASK             1
#define LCDBPEN0_BPEN1_MASK             2
#define LCDBPEN0_BPEN2_MASK             4
#define LCDBPEN0_BPEN3_MASK             8
#define LCDBPEN0_BPEN4_MASK             16
#define LCDBPEN0_BPEN5_MASK             32
#define LCDBPEN0_BPEN6_MASK             64
#define LCDBPEN0_BPEN7_MASK             128


/*** LCDBPEN1 - LCD Backplane Enable Register 1; 0x00001009 ***/
typedef union {
  byte Byte;
  struct {
    byte BPEN8       :1;                                       /* Enable LCD pin 8 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN9       :1;                                       /* Enable LCD pin 9 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN10      :1;                                       /* Enable LCD pin 10 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN11      :1;                                       /* Enable LCD pin 11 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN12      :1;                                       /* Enable LCD pin 12 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN13      :1;                                       /* Enable LCD pin 13 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN14      :1;                                       /* Enable LCD pin 14 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN15      :1;                                       /* Enable LCD pin 15 to operate as an LCD backplane or an LCD frontplane */
  } Bits;
} LCDBPEN1STR;
extern volatile LCDBPEN1STR _LCDBPEN1 @0x00001009;
#define LCDBPEN1                        _LCDBPEN1.Byte
#define LCDBPEN1_BPEN8                  _LCDBPEN1.Bits.BPEN8
#define LCDBPEN1_BPEN9                  _LCDBPEN1.Bits.BPEN9
#define LCDBPEN1_BPEN10                 _LCDBPEN1.Bits.BPEN10
#define LCDBPEN1_BPEN11                 _LCDBPEN1.Bits.BPEN11
#define LCDBPEN1_BPEN12                 _LCDBPEN1.Bits.BPEN12
#define LCDBPEN1_BPEN13                 _LCDBPEN1.Bits.BPEN13
#define LCDBPEN1_BPEN14                 _LCDBPEN1.Bits.BPEN14
#define LCDBPEN1_BPEN15                 _LCDBPEN1.Bits.BPEN15

#define LCDBPEN1_BPEN8_MASK             1
#define LCDBPEN1_BPEN9_MASK             2
#define LCDBPEN1_BPEN10_MASK            4
#define LCDBPEN1_BPEN11_MASK            8
#define LCDBPEN1_BPEN12_MASK            16
#define LCDBPEN1_BPEN13_MASK            32
#define LCDBPEN1_BPEN14_MASK            64
#define LCDBPEN1_BPEN15_MASK            128


/*** LCDBPEN2 - LCD Backplane Enable Register 2; 0x0000100A ***/
typedef union {
  byte Byte;
  struct {
    byte BPEN16      :1;                                       /* Enable LCD pin 16 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN17      :1;                                       /* Enable LCD pin 17 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN18      :1;                                       /* Enable LCD pin 18 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN19      :1;                                       /* Enable LCD pin 19 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN20      :1;                                       /* Enable LCD pin 20 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN21      :1;                                       /* Enable LCD pin 21 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN22      :1;                                       /* Enable LCD pin 22 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN23      :1;                                       /* Enable LCD pin 23 to operate as an LCD backplane or an LCD frontplane */
  } Bits;
} LCDBPEN2STR;
extern volatile LCDBPEN2STR _LCDBPEN2 @0x0000100A;
#define LCDBPEN2                        _LCDBPEN2.Byte
#define LCDBPEN2_BPEN16                 _LCDBPEN2.Bits.BPEN16
#define LCDBPEN2_BPEN17                 _LCDBPEN2.Bits.BPEN17
#define LCDBPEN2_BPEN18                 _LCDBPEN2.Bits.BPEN18
#define LCDBPEN2_BPEN19                 _LCDBPEN2.Bits.BPEN19
#define LCDBPEN2_BPEN20                 _LCDBPEN2.Bits.BPEN20
#define LCDBPEN2_BPEN21                 _LCDBPEN2.Bits.BPEN21
#define LCDBPEN2_BPEN22                 _LCDBPEN2.Bits.BPEN22
#define LCDBPEN2_BPEN23                 _LCDBPEN2.Bits.BPEN23

#define LCDBPEN2_BPEN16_MASK            1
#define LCDBPEN2_BPEN17_MASK            2
#define LCDBPEN2_BPEN18_MASK            4
#define LCDBPEN2_BPEN19_MASK            8
#define LCDBPEN2_BPEN20_MASK            16
#define LCDBPEN2_BPEN21_MASK            32
#define LCDBPEN2_BPEN22_MASK            64
#define LCDBPEN2_BPEN23_MASK            128


/*** LCDBPEN3 - LCD Backplane Enable Register 3; 0x0000100B ***/
typedef union {
  byte Byte;
  struct {
    byte BPEN24      :1;                                       /* Enable LCD pin 24 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN25      :1;                                       /* Enable LCD pin 25 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN26      :1;                                       /* Enable LCD pin 26 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN27      :1;                                       /* Enable LCD pin 27 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN28      :1;                                       /* Enable LCD pin 28 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN29      :1;                                       /* Enable LCD pin 29 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN30      :1;                                       /* Enable LCD pin 30 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN31      :1;                                       /* Enable LCD pin 31 to operate as an LCD backplane or an LCD frontplane */
  } Bits;
} LCDBPEN3STR;
extern volatile LCDBPEN3STR _LCDBPEN3 @0x0000100B;
#define LCDBPEN3                        _LCDBPEN3.Byte
#define LCDBPEN3_BPEN24                 _LCDBPEN3.Bits.BPEN24
#define LCDBPEN3_BPEN25                 _LCDBPEN3.Bits.BPEN25
#define LCDBPEN3_BPEN26                 _LCDBPEN3.Bits.BPEN26
#define LCDBPEN3_BPEN27                 _LCDBPEN3.Bits.BPEN27
#define LCDBPEN3_BPEN28                 _LCDBPEN3.Bits.BPEN28
#define LCDBPEN3_BPEN29                 _LCDBPEN3.Bits.BPEN29
#define LCDBPEN3_BPEN30                 _LCDBPEN3.Bits.BPEN30
#define LCDBPEN3_BPEN31                 _LCDBPEN3.Bits.BPEN31

#define LCDBPEN3_BPEN24_MASK            1
#define LCDBPEN3_BPEN25_MASK            2
#define LCDBPEN3_BPEN26_MASK            4
#define LCDBPEN3_BPEN27_MASK            8
#define LCDBPEN3_BPEN28_MASK            16
#define LCDBPEN3_BPEN29_MASK            32
#define LCDBPEN3_BPEN30_MASK            64
#define LCDBPEN3_BPEN31_MASK            128


/*** LCDBPEN4 - LCD Backplane Enable Register 4; 0x0000100C ***/
typedef union {
  byte Byte;
  struct {
    byte BPEN32      :1;                                       /* Enable LCD pin 32 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN33      :1;                                       /* Enable LCD pin 33 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN34      :1;                                       /* Enable LCD pin 34 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN35      :1;                                       /* Enable LCD pin 35 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN36      :1;                                       /* Enable LCD pin 36 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN37      :1;                                       /* Enable LCD pin 37 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN38      :1;                                       /* Enable LCD pin 38 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN39      :1;                                       /* Enable LCD pin 39 to operate as an LCD backplane or an LCD frontplane */
  } Bits;
} LCDBPEN4STR;
extern volatile LCDBPEN4STR _LCDBPEN4 @0x0000100C;
#define LCDBPEN4                        _LCDBPEN4.Byte
#define LCDBPEN4_BPEN32                 _LCDBPEN4.Bits.BPEN32
#define LCDBPEN4_BPEN33                 _LCDBPEN4.Bits.BPEN33
#define LCDBPEN4_BPEN34                 _LCDBPEN4.Bits.BPEN34
#define LCDBPEN4_BPEN35                 _LCDBPEN4.Bits.BPEN35
#define LCDBPEN4_BPEN36                 _LCDBPEN4.Bits.BPEN36
#define LCDBPEN4_BPEN37                 _LCDBPEN4.Bits.BPEN37
#define LCDBPEN4_BPEN38                 _LCDBPEN4.Bits.BPEN38
#define LCDBPEN4_BPEN39                 _LCDBPEN4.Bits.BPEN39

#define LCDBPEN4_BPEN32_MASK            1
#define LCDBPEN4_BPEN33_MASK            2
#define LCDBPEN4_BPEN34_MASK            4
#define LCDBPEN4_BPEN35_MASK            8
#define LCDBPEN4_BPEN36_MASK            16
#define LCDBPEN4_BPEN37_MASK            32
#define LCDBPEN4_BPEN38_MASK            64
#define LCDBPEN4_BPEN39_MASK            128


/*** LCDBPEN5 - LCD Backplane Enable Register 5; 0x0000100D ***/
typedef union {
  byte Byte;
  struct {
    byte BPEN40      :1;                                       /* Enable LCD pin 40 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN41      :1;                                       /* Enable LCD pin 41 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN42      :1;                                       /* Enable LCD pin 42 to operate as an LCD backplane or an LCD frontplane */
    byte BPEN43      :1;                                       /* Enable LCD pin 43 to operate as an LCD backplane or an LCD frontplane */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpBPEN_40 :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} LCDBPEN5STR;
extern volatile LCDBPEN5STR _LCDBPEN5 @0x0000100D;
#define LCDBPEN5                        _LCDBPEN5.Byte
#define LCDBPEN5_BPEN40                 _LCDBPEN5.Bits.BPEN40
#define LCDBPEN5_BPEN41                 _LCDBPEN5.Bits.BPEN41
#define LCDBPEN5_BPEN42                 _LCDBPEN5.Bits.BPEN42
#define LCDBPEN5_BPEN43                 _LCDBPEN5.Bits.BPEN43
#define LCDBPEN5_BPEN_40                _LCDBPEN5.MergedBits.grpBPEN_40
#define LCDBPEN5_BPEN                   LCDBPEN5_BPEN_40

#define LCDBPEN5_BPEN40_MASK            1
#define LCDBPEN5_BPEN41_MASK            2
#define LCDBPEN5_BPEN42_MASK            4
#define LCDBPEN5_BPEN43_MASK            8
#define LCDBPEN5_BPEN_40_MASK           15
#define LCDBPEN5_BPEN_40_BITNUM         0


/*** LCDWF0 - LCD Waveform Register 0; 0x00001010 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD0     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD0     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD0     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD0     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD0     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD0     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD0     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD0     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF0STR;
extern volatile LCDWF0STR _LCDWF0 @0x00001010;
#define LCDWF0                          _LCDWF0.Byte
#define LCDWF0_BPALCD0                  _LCDWF0.Bits.BPALCD0
#define LCDWF0_BPBLCD0                  _LCDWF0.Bits.BPBLCD0
#define LCDWF0_BPCLCD0                  _LCDWF0.Bits.BPCLCD0
#define LCDWF0_BPDLCD0                  _LCDWF0.Bits.BPDLCD0
#define LCDWF0_BPELCD0                  _LCDWF0.Bits.BPELCD0
#define LCDWF0_BPFLCD0                  _LCDWF0.Bits.BPFLCD0
#define LCDWF0_BPGLCD0                  _LCDWF0.Bits.BPGLCD0
#define LCDWF0_BPHLCD0                  _LCDWF0.Bits.BPHLCD0
/* LCDWF_ARR: Access 44 LCDWFx registers in an array */
#define LCDWF_ARR                       ((volatile byte * __far) &LCDWF0)

#define LCDWF0_BPALCD0_MASK             1
#define LCDWF0_BPBLCD0_MASK             2
#define LCDWF0_BPCLCD0_MASK             4
#define LCDWF0_BPDLCD0_MASK             8
#define LCDWF0_BPELCD0_MASK             16
#define LCDWF0_BPFLCD0_MASK             32
#define LCDWF0_BPGLCD0_MASK             64
#define LCDWF0_BPHLCD0_MASK             128


/*** LCDWF1 - LCD Waveform Register 1; 0x00001011 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD1     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD1     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD1     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD1     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD1     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD1     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD1     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD1     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF1STR;
extern volatile LCDWF1STR _LCDWF1 @0x00001011;
#define LCDWF1                          _LCDWF1.Byte
#define LCDWF1_BPALCD1                  _LCDWF1.Bits.BPALCD1
#define LCDWF1_BPBLCD1                  _LCDWF1.Bits.BPBLCD1
#define LCDWF1_BPCLCD1                  _LCDWF1.Bits.BPCLCD1
#define LCDWF1_BPDLCD1                  _LCDWF1.Bits.BPDLCD1
#define LCDWF1_BPELCD1                  _LCDWF1.Bits.BPELCD1
#define LCDWF1_BPFLCD1                  _LCDWF1.Bits.BPFLCD1
#define LCDWF1_BPGLCD1                  _LCDWF1.Bits.BPGLCD1
#define LCDWF1_BPHLCD1                  _LCDWF1.Bits.BPHLCD1

#define LCDWF1_BPALCD1_MASK             1
#define LCDWF1_BPBLCD1_MASK             2
#define LCDWF1_BPCLCD1_MASK             4
#define LCDWF1_BPDLCD1_MASK             8
#define LCDWF1_BPELCD1_MASK             16
#define LCDWF1_BPFLCD1_MASK             32
#define LCDWF1_BPGLCD1_MASK             64
#define LCDWF1_BPHLCD1_MASK             128


/*** LCDWF2 - LCD Waveform Register 2; 0x00001012 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD2     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD2     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD2     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD2     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD2     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD2     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD2     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD2     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF2STR;
extern volatile LCDWF2STR _LCDWF2 @0x00001012;
#define LCDWF2                          _LCDWF2.Byte
#define LCDWF2_BPALCD2                  _LCDWF2.Bits.BPALCD2
#define LCDWF2_BPBLCD2                  _LCDWF2.Bits.BPBLCD2
#define LCDWF2_BPCLCD2                  _LCDWF2.Bits.BPCLCD2
#define LCDWF2_BPDLCD2                  _LCDWF2.Bits.BPDLCD2
#define LCDWF2_BPELCD2                  _LCDWF2.Bits.BPELCD2
#define LCDWF2_BPFLCD2                  _LCDWF2.Bits.BPFLCD2
#define LCDWF2_BPGLCD2                  _LCDWF2.Bits.BPGLCD2
#define LCDWF2_BPHLCD2                  _LCDWF2.Bits.BPHLCD2

#define LCDWF2_BPALCD2_MASK             1
#define LCDWF2_BPBLCD2_MASK             2
#define LCDWF2_BPCLCD2_MASK             4
#define LCDWF2_BPDLCD2_MASK             8
#define LCDWF2_BPELCD2_MASK             16
#define LCDWF2_BPFLCD2_MASK             32
#define LCDWF2_BPGLCD2_MASK             64
#define LCDWF2_BPHLCD2_MASK             128


/*** LCDWF3 - LCD Waveform Register 3; 0x00001013 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD3     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD3     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD3     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD3     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD3     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD3     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD3     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD3     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF3STR;
extern volatile LCDWF3STR _LCDWF3 @0x00001013;
#define LCDWF3                          _LCDWF3.Byte
#define LCDWF3_BPALCD3                  _LCDWF3.Bits.BPALCD3
#define LCDWF3_BPBLCD3                  _LCDWF3.Bits.BPBLCD3
#define LCDWF3_BPCLCD3                  _LCDWF3.Bits.BPCLCD3
#define LCDWF3_BPDLCD3                  _LCDWF3.Bits.BPDLCD3
#define LCDWF3_BPELCD3                  _LCDWF3.Bits.BPELCD3
#define LCDWF3_BPFLCD3                  _LCDWF3.Bits.BPFLCD3
#define LCDWF3_BPGLCD3                  _LCDWF3.Bits.BPGLCD3
#define LCDWF3_BPHLCD3                  _LCDWF3.Bits.BPHLCD3

#define LCDWF3_BPALCD3_MASK             1
#define LCDWF3_BPBLCD3_MASK             2
#define LCDWF3_BPCLCD3_MASK             4
#define LCDWF3_BPDLCD3_MASK             8
#define LCDWF3_BPELCD3_MASK             16
#define LCDWF3_BPFLCD3_MASK             32
#define LCDWF3_BPGLCD3_MASK             64
#define LCDWF3_BPHLCD3_MASK             128


/*** LCDWF4 - LCD Waveform Register 4; 0x00001014 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD4     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD4     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD4     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD4     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD4     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD4     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD4     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD4     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF4STR;
extern volatile LCDWF4STR _LCDWF4 @0x00001014;
#define LCDWF4                          _LCDWF4.Byte
#define LCDWF4_BPALCD4                  _LCDWF4.Bits.BPALCD4
#define LCDWF4_BPBLCD4                  _LCDWF4.Bits.BPBLCD4
#define LCDWF4_BPCLCD4                  _LCDWF4.Bits.BPCLCD4
#define LCDWF4_BPDLCD4                  _LCDWF4.Bits.BPDLCD4
#define LCDWF4_BPELCD4                  _LCDWF4.Bits.BPELCD4
#define LCDWF4_BPFLCD4                  _LCDWF4.Bits.BPFLCD4
#define LCDWF4_BPGLCD4                  _LCDWF4.Bits.BPGLCD4
#define LCDWF4_BPHLCD4                  _LCDWF4.Bits.BPHLCD4

#define LCDWF4_BPALCD4_MASK             1
#define LCDWF4_BPBLCD4_MASK             2
#define LCDWF4_BPCLCD4_MASK             4
#define LCDWF4_BPDLCD4_MASK             8
#define LCDWF4_BPELCD4_MASK             16
#define LCDWF4_BPFLCD4_MASK             32
#define LCDWF4_BPGLCD4_MASK             64
#define LCDWF4_BPHLCD4_MASK             128


/*** LCDWF5 - LCD Waveform Register 5; 0x00001015 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD5     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD5     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD5     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD5     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD5     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD5     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD5     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD5     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF5STR;
extern volatile LCDWF5STR _LCDWF5 @0x00001015;
#define LCDWF5                          _LCDWF5.Byte
#define LCDWF5_BPALCD5                  _LCDWF5.Bits.BPALCD5
#define LCDWF5_BPBLCD5                  _LCDWF5.Bits.BPBLCD5
#define LCDWF5_BPCLCD5                  _LCDWF5.Bits.BPCLCD5
#define LCDWF5_BPDLCD5                  _LCDWF5.Bits.BPDLCD5
#define LCDWF5_BPELCD5                  _LCDWF5.Bits.BPELCD5
#define LCDWF5_BPFLCD5                  _LCDWF5.Bits.BPFLCD5
#define LCDWF5_BPGLCD5                  _LCDWF5.Bits.BPGLCD5
#define LCDWF5_BPHLCD5                  _LCDWF5.Bits.BPHLCD5

#define LCDWF5_BPALCD5_MASK             1
#define LCDWF5_BPBLCD5_MASK             2
#define LCDWF5_BPCLCD5_MASK             4
#define LCDWF5_BPDLCD5_MASK             8
#define LCDWF5_BPELCD5_MASK             16
#define LCDWF5_BPFLCD5_MASK             32
#define LCDWF5_BPGLCD5_MASK             64
#define LCDWF5_BPHLCD5_MASK             128


/*** LCDWF6 - LCD Waveform Register 6; 0x00001016 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD6     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD6     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD6     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD6     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD6     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD6     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD6     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD6     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF6STR;
extern volatile LCDWF6STR _LCDWF6 @0x00001016;
#define LCDWF6                          _LCDWF6.Byte
#define LCDWF6_BPALCD6                  _LCDWF6.Bits.BPALCD6
#define LCDWF6_BPBLCD6                  _LCDWF6.Bits.BPBLCD6
#define LCDWF6_BPCLCD6                  _LCDWF6.Bits.BPCLCD6
#define LCDWF6_BPDLCD6                  _LCDWF6.Bits.BPDLCD6
#define LCDWF6_BPELCD6                  _LCDWF6.Bits.BPELCD6
#define LCDWF6_BPFLCD6                  _LCDWF6.Bits.BPFLCD6
#define LCDWF6_BPGLCD6                  _LCDWF6.Bits.BPGLCD6
#define LCDWF6_BPHLCD6                  _LCDWF6.Bits.BPHLCD6

#define LCDWF6_BPALCD6_MASK             1
#define LCDWF6_BPBLCD6_MASK             2
#define LCDWF6_BPCLCD6_MASK             4
#define LCDWF6_BPDLCD6_MASK             8
#define LCDWF6_BPELCD6_MASK             16
#define LCDWF6_BPFLCD6_MASK             32
#define LCDWF6_BPGLCD6_MASK             64
#define LCDWF6_BPHLCD6_MASK             128


/*** LCDWF7 - LCD Waveform Register 7; 0x00001017 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD7     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD7     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD7     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD7     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD7     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD7     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD7     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD7     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF7STR;
extern volatile LCDWF7STR _LCDWF7 @0x00001017;
#define LCDWF7                          _LCDWF7.Byte
#define LCDWF7_BPALCD7                  _LCDWF7.Bits.BPALCD7
#define LCDWF7_BPBLCD7                  _LCDWF7.Bits.BPBLCD7
#define LCDWF7_BPCLCD7                  _LCDWF7.Bits.BPCLCD7
#define LCDWF7_BPDLCD7                  _LCDWF7.Bits.BPDLCD7
#define LCDWF7_BPELCD7                  _LCDWF7.Bits.BPELCD7
#define LCDWF7_BPFLCD7                  _LCDWF7.Bits.BPFLCD7
#define LCDWF7_BPGLCD7                  _LCDWF7.Bits.BPGLCD7
#define LCDWF7_BPHLCD7                  _LCDWF7.Bits.BPHLCD7

#define LCDWF7_BPALCD7_MASK             1
#define LCDWF7_BPBLCD7_MASK             2
#define LCDWF7_BPCLCD7_MASK             4
#define LCDWF7_BPDLCD7_MASK             8
#define LCDWF7_BPELCD7_MASK             16
#define LCDWF7_BPFLCD7_MASK             32
#define LCDWF7_BPGLCD7_MASK             64
#define LCDWF7_BPHLCD7_MASK             128


/*** LCDWF8 - LCD Waveform Register 8; 0x00001018 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD8     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD8     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD8     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD8     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD8     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD8     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD8     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD8     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF8STR;
extern volatile LCDWF8STR _LCDWF8 @0x00001018;
#define LCDWF8                          _LCDWF8.Byte
#define LCDWF8_BPALCD8                  _LCDWF8.Bits.BPALCD8
#define LCDWF8_BPBLCD8                  _LCDWF8.Bits.BPBLCD8
#define LCDWF8_BPCLCD8                  _LCDWF8.Bits.BPCLCD8
#define LCDWF8_BPDLCD8                  _LCDWF8.Bits.BPDLCD8
#define LCDWF8_BPELCD8                  _LCDWF8.Bits.BPELCD8
#define LCDWF8_BPFLCD8                  _LCDWF8.Bits.BPFLCD8
#define LCDWF8_BPGLCD8                  _LCDWF8.Bits.BPGLCD8
#define LCDWF8_BPHLCD8                  _LCDWF8.Bits.BPHLCD8

#define LCDWF8_BPALCD8_MASK             1
#define LCDWF8_BPBLCD8_MASK             2
#define LCDWF8_BPCLCD8_MASK             4
#define LCDWF8_BPDLCD8_MASK             8
#define LCDWF8_BPELCD8_MASK             16
#define LCDWF8_BPFLCD8_MASK             32
#define LCDWF8_BPGLCD8_MASK             64
#define LCDWF8_BPHLCD8_MASK             128


/*** LCDWF9 - LCD Waveform Register 9; 0x00001019 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD9     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD9     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD9     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD9     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD9     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD9     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD9     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD9     :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF9STR;
extern volatile LCDWF9STR _LCDWF9 @0x00001019;
#define LCDWF9                          _LCDWF9.Byte
#define LCDWF9_BPALCD9                  _LCDWF9.Bits.BPALCD9
#define LCDWF9_BPBLCD9                  _LCDWF9.Bits.BPBLCD9
#define LCDWF9_BPCLCD9                  _LCDWF9.Bits.BPCLCD9
#define LCDWF9_BPDLCD9                  _LCDWF9.Bits.BPDLCD9
#define LCDWF9_BPELCD9                  _LCDWF9.Bits.BPELCD9
#define LCDWF9_BPFLCD9                  _LCDWF9.Bits.BPFLCD9
#define LCDWF9_BPGLCD9                  _LCDWF9.Bits.BPGLCD9
#define LCDWF9_BPHLCD9                  _LCDWF9.Bits.BPHLCD9

#define LCDWF9_BPALCD9_MASK             1
#define LCDWF9_BPBLCD9_MASK             2
#define LCDWF9_BPCLCD9_MASK             4
#define LCDWF9_BPDLCD9_MASK             8
#define LCDWF9_BPELCD9_MASK             16
#define LCDWF9_BPFLCD9_MASK             32
#define LCDWF9_BPGLCD9_MASK             64
#define LCDWF9_BPHLCD9_MASK             128


/*** LCDWF10 - LCD Waveform Register 10; 0x0000101A ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD10    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD10    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD10    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD10    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD10    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD10    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD10    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD10    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF10STR;
extern volatile LCDWF10STR _LCDWF10 @0x0000101A;
#define LCDWF10                         _LCDWF10.Byte
#define LCDWF10_BPALCD10                _LCDWF10.Bits.BPALCD10
#define LCDWF10_BPBLCD10                _LCDWF10.Bits.BPBLCD10
#define LCDWF10_BPCLCD10                _LCDWF10.Bits.BPCLCD10
#define LCDWF10_BPDLCD10                _LCDWF10.Bits.BPDLCD10
#define LCDWF10_BPELCD10                _LCDWF10.Bits.BPELCD10
#define LCDWF10_BPFLCD10                _LCDWF10.Bits.BPFLCD10
#define LCDWF10_BPGLCD10                _LCDWF10.Bits.BPGLCD10
#define LCDWF10_BPHLCD10                _LCDWF10.Bits.BPHLCD10

#define LCDWF10_BPALCD10_MASK           1
#define LCDWF10_BPBLCD10_MASK           2
#define LCDWF10_BPCLCD10_MASK           4
#define LCDWF10_BPDLCD10_MASK           8
#define LCDWF10_BPELCD10_MASK           16
#define LCDWF10_BPFLCD10_MASK           32
#define LCDWF10_BPGLCD10_MASK           64
#define LCDWF10_BPHLCD10_MASK           128


/*** LCDWF11 - LCD Waveform Register 11; 0x0000101B ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD11    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD11    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD11    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD11    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD11    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD11    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD11    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD11    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF11STR;
extern volatile LCDWF11STR _LCDWF11 @0x0000101B;
#define LCDWF11                         _LCDWF11.Byte
#define LCDWF11_BPALCD11                _LCDWF11.Bits.BPALCD11
#define LCDWF11_BPBLCD11                _LCDWF11.Bits.BPBLCD11
#define LCDWF11_BPCLCD11                _LCDWF11.Bits.BPCLCD11
#define LCDWF11_BPDLCD11                _LCDWF11.Bits.BPDLCD11
#define LCDWF11_BPELCD11                _LCDWF11.Bits.BPELCD11
#define LCDWF11_BPFLCD11                _LCDWF11.Bits.BPFLCD11
#define LCDWF11_BPGLCD11                _LCDWF11.Bits.BPGLCD11
#define LCDWF11_BPHLCD11                _LCDWF11.Bits.BPHLCD11

#define LCDWF11_BPALCD11_MASK           1
#define LCDWF11_BPBLCD11_MASK           2
#define LCDWF11_BPCLCD11_MASK           4
#define LCDWF11_BPDLCD11_MASK           8
#define LCDWF11_BPELCD11_MASK           16
#define LCDWF11_BPFLCD11_MASK           32
#define LCDWF11_BPGLCD11_MASK           64
#define LCDWF11_BPHLCD11_MASK           128


/*** LCDWF12 - LCD Waveform Register 12; 0x0000101C ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD12    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD12    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD12    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD12    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD12    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD12    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD12    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD12    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF12STR;
extern volatile LCDWF12STR _LCDWF12 @0x0000101C;
#define LCDWF12                         _LCDWF12.Byte
#define LCDWF12_BPALCD12                _LCDWF12.Bits.BPALCD12
#define LCDWF12_BPBLCD12                _LCDWF12.Bits.BPBLCD12
#define LCDWF12_BPCLCD12                _LCDWF12.Bits.BPCLCD12
#define LCDWF12_BPDLCD12                _LCDWF12.Bits.BPDLCD12
#define LCDWF12_BPELCD12                _LCDWF12.Bits.BPELCD12
#define LCDWF12_BPFLCD12                _LCDWF12.Bits.BPFLCD12
#define LCDWF12_BPGLCD12                _LCDWF12.Bits.BPGLCD12
#define LCDWF12_BPHLCD12                _LCDWF12.Bits.BPHLCD12

#define LCDWF12_BPALCD12_MASK           1
#define LCDWF12_BPBLCD12_MASK           2
#define LCDWF12_BPCLCD12_MASK           4
#define LCDWF12_BPDLCD12_MASK           8
#define LCDWF12_BPELCD12_MASK           16
#define LCDWF12_BPFLCD12_MASK           32
#define LCDWF12_BPGLCD12_MASK           64
#define LCDWF12_BPHLCD12_MASK           128


/*** LCDWF13 - LCD Waveform Register 13; 0x0000101D ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD13    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD13    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD13    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD13    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD13    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD13    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD13    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD13    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF13STR;
extern volatile LCDWF13STR _LCDWF13 @0x0000101D;
#define LCDWF13                         _LCDWF13.Byte
#define LCDWF13_BPALCD13                _LCDWF13.Bits.BPALCD13
#define LCDWF13_BPBLCD13                _LCDWF13.Bits.BPBLCD13
#define LCDWF13_BPCLCD13                _LCDWF13.Bits.BPCLCD13
#define LCDWF13_BPDLCD13                _LCDWF13.Bits.BPDLCD13
#define LCDWF13_BPELCD13                _LCDWF13.Bits.BPELCD13
#define LCDWF13_BPFLCD13                _LCDWF13.Bits.BPFLCD13
#define LCDWF13_BPGLCD13                _LCDWF13.Bits.BPGLCD13
#define LCDWF13_BPHLCD13                _LCDWF13.Bits.BPHLCD13

#define LCDWF13_BPALCD13_MASK           1
#define LCDWF13_BPBLCD13_MASK           2
#define LCDWF13_BPCLCD13_MASK           4
#define LCDWF13_BPDLCD13_MASK           8
#define LCDWF13_BPELCD13_MASK           16
#define LCDWF13_BPFLCD13_MASK           32
#define LCDWF13_BPGLCD13_MASK           64
#define LCDWF13_BPHLCD13_MASK           128


/*** LCDWF14 - LCD Waveform Register 14; 0x0000101E ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD14    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD14    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD14    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD14    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD14    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD14    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD14    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD14    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF14STR;
extern volatile LCDWF14STR _LCDWF14 @0x0000101E;
#define LCDWF14                         _LCDWF14.Byte
#define LCDWF14_BPALCD14                _LCDWF14.Bits.BPALCD14
#define LCDWF14_BPBLCD14                _LCDWF14.Bits.BPBLCD14
#define LCDWF14_BPCLCD14                _LCDWF14.Bits.BPCLCD14
#define LCDWF14_BPDLCD14                _LCDWF14.Bits.BPDLCD14
#define LCDWF14_BPELCD14                _LCDWF14.Bits.BPELCD14
#define LCDWF14_BPFLCD14                _LCDWF14.Bits.BPFLCD14
#define LCDWF14_BPGLCD14                _LCDWF14.Bits.BPGLCD14
#define LCDWF14_BPHLCD14                _LCDWF14.Bits.BPHLCD14

#define LCDWF14_BPALCD14_MASK           1
#define LCDWF14_BPBLCD14_MASK           2
#define LCDWF14_BPCLCD14_MASK           4
#define LCDWF14_BPDLCD14_MASK           8
#define LCDWF14_BPELCD14_MASK           16
#define LCDWF14_BPFLCD14_MASK           32
#define LCDWF14_BPGLCD14_MASK           64
#define LCDWF14_BPHLCD14_MASK           128


/*** LCDWF15 - LCD Waveform Register 15; 0x0000101F ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD15    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD15    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD15    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD15    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD15    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD15    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD15    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD15    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF15STR;
extern volatile LCDWF15STR _LCDWF15 @0x0000101F;
#define LCDWF15                         _LCDWF15.Byte
#define LCDWF15_BPALCD15                _LCDWF15.Bits.BPALCD15
#define LCDWF15_BPBLCD15                _LCDWF15.Bits.BPBLCD15
#define LCDWF15_BPCLCD15                _LCDWF15.Bits.BPCLCD15
#define LCDWF15_BPDLCD15                _LCDWF15.Bits.BPDLCD15
#define LCDWF15_BPELCD15                _LCDWF15.Bits.BPELCD15
#define LCDWF15_BPFLCD15                _LCDWF15.Bits.BPFLCD15
#define LCDWF15_BPGLCD15                _LCDWF15.Bits.BPGLCD15
#define LCDWF15_BPHLCD15                _LCDWF15.Bits.BPHLCD15

#define LCDWF15_BPALCD15_MASK           1
#define LCDWF15_BPBLCD15_MASK           2
#define LCDWF15_BPCLCD15_MASK           4
#define LCDWF15_BPDLCD15_MASK           8
#define LCDWF15_BPELCD15_MASK           16
#define LCDWF15_BPFLCD15_MASK           32
#define LCDWF15_BPGLCD15_MASK           64
#define LCDWF15_BPHLCD15_MASK           128


/*** LCDWF16 - LCD Waveform Register 16; 0x00001020 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD16    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD16    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD16    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD16    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD16    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD16    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD16    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD16    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF16STR;
extern volatile LCDWF16STR _LCDWF16 @0x00001020;
#define LCDWF16                         _LCDWF16.Byte
#define LCDWF16_BPALCD16                _LCDWF16.Bits.BPALCD16
#define LCDWF16_BPBLCD16                _LCDWF16.Bits.BPBLCD16
#define LCDWF16_BPCLCD16                _LCDWF16.Bits.BPCLCD16
#define LCDWF16_BPDLCD16                _LCDWF16.Bits.BPDLCD16
#define LCDWF16_BPELCD16                _LCDWF16.Bits.BPELCD16
#define LCDWF16_BPFLCD16                _LCDWF16.Bits.BPFLCD16
#define LCDWF16_BPGLCD16                _LCDWF16.Bits.BPGLCD16
#define LCDWF16_BPHLCD16                _LCDWF16.Bits.BPHLCD16

#define LCDWF16_BPALCD16_MASK           1
#define LCDWF16_BPBLCD16_MASK           2
#define LCDWF16_BPCLCD16_MASK           4
#define LCDWF16_BPDLCD16_MASK           8
#define LCDWF16_BPELCD16_MASK           16
#define LCDWF16_BPFLCD16_MASK           32
#define LCDWF16_BPGLCD16_MASK           64
#define LCDWF16_BPHLCD16_MASK           128


/*** LCDWF17 - LCD Waveform Register 17; 0x00001021 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD17    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD17    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD17    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD17    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD17    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD17    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD17    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD17    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF17STR;
extern volatile LCDWF17STR _LCDWF17 @0x00001021;
#define LCDWF17                         _LCDWF17.Byte
#define LCDWF17_BPALCD17                _LCDWF17.Bits.BPALCD17
#define LCDWF17_BPBLCD17                _LCDWF17.Bits.BPBLCD17
#define LCDWF17_BPCLCD17                _LCDWF17.Bits.BPCLCD17
#define LCDWF17_BPDLCD17                _LCDWF17.Bits.BPDLCD17
#define LCDWF17_BPELCD17                _LCDWF17.Bits.BPELCD17
#define LCDWF17_BPFLCD17                _LCDWF17.Bits.BPFLCD17
#define LCDWF17_BPGLCD17                _LCDWF17.Bits.BPGLCD17
#define LCDWF17_BPHLCD17                _LCDWF17.Bits.BPHLCD17

#define LCDWF17_BPALCD17_MASK           1
#define LCDWF17_BPBLCD17_MASK           2
#define LCDWF17_BPCLCD17_MASK           4
#define LCDWF17_BPDLCD17_MASK           8
#define LCDWF17_BPELCD17_MASK           16
#define LCDWF17_BPFLCD17_MASK           32
#define LCDWF17_BPGLCD17_MASK           64
#define LCDWF17_BPHLCD17_MASK           128


/*** LCDWF18 - LCD Waveform Register 18; 0x00001022 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD18    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD18    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD18    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD18    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD18    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD18    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD18    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD18    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF18STR;
extern volatile LCDWF18STR _LCDWF18 @0x00001022;
#define LCDWF18                         _LCDWF18.Byte
#define LCDWF18_BPALCD18                _LCDWF18.Bits.BPALCD18
#define LCDWF18_BPBLCD18                _LCDWF18.Bits.BPBLCD18
#define LCDWF18_BPCLCD18                _LCDWF18.Bits.BPCLCD18
#define LCDWF18_BPDLCD18                _LCDWF18.Bits.BPDLCD18
#define LCDWF18_BPELCD18                _LCDWF18.Bits.BPELCD18
#define LCDWF18_BPFLCD18                _LCDWF18.Bits.BPFLCD18
#define LCDWF18_BPGLCD18                _LCDWF18.Bits.BPGLCD18
#define LCDWF18_BPHLCD18                _LCDWF18.Bits.BPHLCD18

#define LCDWF18_BPALCD18_MASK           1
#define LCDWF18_BPBLCD18_MASK           2
#define LCDWF18_BPCLCD18_MASK           4
#define LCDWF18_BPDLCD18_MASK           8
#define LCDWF18_BPELCD18_MASK           16
#define LCDWF18_BPFLCD18_MASK           32
#define LCDWF18_BPGLCD18_MASK           64
#define LCDWF18_BPHLCD18_MASK           128


/*** LCDWF19 - LCD Waveform Register 19; 0x00001023 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD19    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD19    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD19    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD19    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD19    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD19    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD19    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD19    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF19STR;
extern volatile LCDWF19STR _LCDWF19 @0x00001023;
#define LCDWF19                         _LCDWF19.Byte
#define LCDWF19_BPALCD19                _LCDWF19.Bits.BPALCD19
#define LCDWF19_BPBLCD19                _LCDWF19.Bits.BPBLCD19
#define LCDWF19_BPCLCD19                _LCDWF19.Bits.BPCLCD19
#define LCDWF19_BPDLCD19                _LCDWF19.Bits.BPDLCD19
#define LCDWF19_BPELCD19                _LCDWF19.Bits.BPELCD19
#define LCDWF19_BPFLCD19                _LCDWF19.Bits.BPFLCD19
#define LCDWF19_BPGLCD19                _LCDWF19.Bits.BPGLCD19
#define LCDWF19_BPHLCD19                _LCDWF19.Bits.BPHLCD19

#define LCDWF19_BPALCD19_MASK           1
#define LCDWF19_BPBLCD19_MASK           2
#define LCDWF19_BPCLCD19_MASK           4
#define LCDWF19_BPDLCD19_MASK           8
#define LCDWF19_BPELCD19_MASK           16
#define LCDWF19_BPFLCD19_MASK           32
#define LCDWF19_BPGLCD19_MASK           64
#define LCDWF19_BPHLCD19_MASK           128


/*** LCDWF20 - LCD Waveform Register 20; 0x00001024 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD20    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD20    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD20    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD20    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD20    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD20    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD20    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD20    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF20STR;
extern volatile LCDWF20STR _LCDWF20 @0x00001024;
#define LCDWF20                         _LCDWF20.Byte
#define LCDWF20_BPALCD20                _LCDWF20.Bits.BPALCD20
#define LCDWF20_BPBLCD20                _LCDWF20.Bits.BPBLCD20
#define LCDWF20_BPCLCD20                _LCDWF20.Bits.BPCLCD20
#define LCDWF20_BPDLCD20                _LCDWF20.Bits.BPDLCD20
#define LCDWF20_BPELCD20                _LCDWF20.Bits.BPELCD20
#define LCDWF20_BPFLCD20                _LCDWF20.Bits.BPFLCD20
#define LCDWF20_BPGLCD20                _LCDWF20.Bits.BPGLCD20
#define LCDWF20_BPHLCD20                _LCDWF20.Bits.BPHLCD20

#define LCDWF20_BPALCD20_MASK           1
#define LCDWF20_BPBLCD20_MASK           2
#define LCDWF20_BPCLCD20_MASK           4
#define LCDWF20_BPDLCD20_MASK           8
#define LCDWF20_BPELCD20_MASK           16
#define LCDWF20_BPFLCD20_MASK           32
#define LCDWF20_BPGLCD20_MASK           64
#define LCDWF20_BPHLCD20_MASK           128


/*** LCDWF21 - LCD Waveform Register 21; 0x00001025 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD21    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD21    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD21    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD21    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD21    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD21    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD21    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD21    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF21STR;
extern volatile LCDWF21STR _LCDWF21 @0x00001025;
#define LCDWF21                         _LCDWF21.Byte
#define LCDWF21_BPALCD21                _LCDWF21.Bits.BPALCD21
#define LCDWF21_BPBLCD21                _LCDWF21.Bits.BPBLCD21
#define LCDWF21_BPCLCD21                _LCDWF21.Bits.BPCLCD21
#define LCDWF21_BPDLCD21                _LCDWF21.Bits.BPDLCD21
#define LCDWF21_BPELCD21                _LCDWF21.Bits.BPELCD21
#define LCDWF21_BPFLCD21                _LCDWF21.Bits.BPFLCD21
#define LCDWF21_BPGLCD21                _LCDWF21.Bits.BPGLCD21
#define LCDWF21_BPHLCD21                _LCDWF21.Bits.BPHLCD21

#define LCDWF21_BPALCD21_MASK           1
#define LCDWF21_BPBLCD21_MASK           2
#define LCDWF21_BPCLCD21_MASK           4
#define LCDWF21_BPDLCD21_MASK           8
#define LCDWF21_BPELCD21_MASK           16
#define LCDWF21_BPFLCD21_MASK           32
#define LCDWF21_BPGLCD21_MASK           64
#define LCDWF21_BPHLCD21_MASK           128


/*** LCDWF22 - LCD Waveform Register 22; 0x00001026 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD22    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD22    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD22    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD22    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD22    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD22    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD22    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD22    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF22STR;
extern volatile LCDWF22STR _LCDWF22 @0x00001026;
#define LCDWF22                         _LCDWF22.Byte
#define LCDWF22_BPALCD22                _LCDWF22.Bits.BPALCD22
#define LCDWF22_BPBLCD22                _LCDWF22.Bits.BPBLCD22
#define LCDWF22_BPCLCD22                _LCDWF22.Bits.BPCLCD22
#define LCDWF22_BPDLCD22                _LCDWF22.Bits.BPDLCD22
#define LCDWF22_BPELCD22                _LCDWF22.Bits.BPELCD22
#define LCDWF22_BPFLCD22                _LCDWF22.Bits.BPFLCD22
#define LCDWF22_BPGLCD22                _LCDWF22.Bits.BPGLCD22
#define LCDWF22_BPHLCD22                _LCDWF22.Bits.BPHLCD22

#define LCDWF22_BPALCD22_MASK           1
#define LCDWF22_BPBLCD22_MASK           2
#define LCDWF22_BPCLCD22_MASK           4
#define LCDWF22_BPDLCD22_MASK           8
#define LCDWF22_BPELCD22_MASK           16
#define LCDWF22_BPFLCD22_MASK           32
#define LCDWF22_BPGLCD22_MASK           64
#define LCDWF22_BPHLCD22_MASK           128


/*** LCDWF23 - LCD Waveform Register 23; 0x00001027 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD23    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD23    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD23    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD23    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD23    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD23    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD23    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD23    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF23STR;
extern volatile LCDWF23STR _LCDWF23 @0x00001027;
#define LCDWF23                         _LCDWF23.Byte
#define LCDWF23_BPALCD23                _LCDWF23.Bits.BPALCD23
#define LCDWF23_BPBLCD23                _LCDWF23.Bits.BPBLCD23
#define LCDWF23_BPCLCD23                _LCDWF23.Bits.BPCLCD23
#define LCDWF23_BPDLCD23                _LCDWF23.Bits.BPDLCD23
#define LCDWF23_BPELCD23                _LCDWF23.Bits.BPELCD23
#define LCDWF23_BPFLCD23                _LCDWF23.Bits.BPFLCD23
#define LCDWF23_BPGLCD23                _LCDWF23.Bits.BPGLCD23
#define LCDWF23_BPHLCD23                _LCDWF23.Bits.BPHLCD23

#define LCDWF23_BPALCD23_MASK           1
#define LCDWF23_BPBLCD23_MASK           2
#define LCDWF23_BPCLCD23_MASK           4
#define LCDWF23_BPDLCD23_MASK           8
#define LCDWF23_BPELCD23_MASK           16
#define LCDWF23_BPFLCD23_MASK           32
#define LCDWF23_BPGLCD23_MASK           64
#define LCDWF23_BPHLCD23_MASK           128


/*** LCDWF24 - LCD Waveform Register 24; 0x00001028 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD24    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD24    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD24    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD24    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD24    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD24    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD24    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD24    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF24STR;
extern volatile LCDWF24STR _LCDWF24 @0x00001028;
#define LCDWF24                         _LCDWF24.Byte
#define LCDWF24_BPALCD24                _LCDWF24.Bits.BPALCD24
#define LCDWF24_BPBLCD24                _LCDWF24.Bits.BPBLCD24
#define LCDWF24_BPCLCD24                _LCDWF24.Bits.BPCLCD24
#define LCDWF24_BPDLCD24                _LCDWF24.Bits.BPDLCD24
#define LCDWF24_BPELCD24                _LCDWF24.Bits.BPELCD24
#define LCDWF24_BPFLCD24                _LCDWF24.Bits.BPFLCD24
#define LCDWF24_BPGLCD24                _LCDWF24.Bits.BPGLCD24
#define LCDWF24_BPHLCD24                _LCDWF24.Bits.BPHLCD24

#define LCDWF24_BPALCD24_MASK           1
#define LCDWF24_BPBLCD24_MASK           2
#define LCDWF24_BPCLCD24_MASK           4
#define LCDWF24_BPDLCD24_MASK           8
#define LCDWF24_BPELCD24_MASK           16
#define LCDWF24_BPFLCD24_MASK           32
#define LCDWF24_BPGLCD24_MASK           64
#define LCDWF24_BPHLCD24_MASK           128


/*** LCDWF25 - LCD Waveform Register 25; 0x00001029 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD25    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD25    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD25    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD25    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD25    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD25    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD25    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD25    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF25STR;
extern volatile LCDWF25STR _LCDWF25 @0x00001029;
#define LCDWF25                         _LCDWF25.Byte
#define LCDWF25_BPALCD25                _LCDWF25.Bits.BPALCD25
#define LCDWF25_BPBLCD25                _LCDWF25.Bits.BPBLCD25
#define LCDWF25_BPCLCD25                _LCDWF25.Bits.BPCLCD25
#define LCDWF25_BPDLCD25                _LCDWF25.Bits.BPDLCD25
#define LCDWF25_BPELCD25                _LCDWF25.Bits.BPELCD25
#define LCDWF25_BPFLCD25                _LCDWF25.Bits.BPFLCD25
#define LCDWF25_BPGLCD25                _LCDWF25.Bits.BPGLCD25
#define LCDWF25_BPHLCD25                _LCDWF25.Bits.BPHLCD25

#define LCDWF25_BPALCD25_MASK           1
#define LCDWF25_BPBLCD25_MASK           2
#define LCDWF25_BPCLCD25_MASK           4
#define LCDWF25_BPDLCD25_MASK           8
#define LCDWF25_BPELCD25_MASK           16
#define LCDWF25_BPFLCD25_MASK           32
#define LCDWF25_BPGLCD25_MASK           64
#define LCDWF25_BPHLCD25_MASK           128


/*** LCDWF26 - LCD Waveform Register 26; 0x0000102A ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD26    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD26    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD26    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD26    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD26    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD26    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD26    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD26    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF26STR;
extern volatile LCDWF26STR _LCDWF26 @0x0000102A;
#define LCDWF26                         _LCDWF26.Byte
#define LCDWF26_BPALCD26                _LCDWF26.Bits.BPALCD26
#define LCDWF26_BPBLCD26                _LCDWF26.Bits.BPBLCD26
#define LCDWF26_BPCLCD26                _LCDWF26.Bits.BPCLCD26
#define LCDWF26_BPDLCD26                _LCDWF26.Bits.BPDLCD26
#define LCDWF26_BPELCD26                _LCDWF26.Bits.BPELCD26
#define LCDWF26_BPFLCD26                _LCDWF26.Bits.BPFLCD26
#define LCDWF26_BPGLCD26                _LCDWF26.Bits.BPGLCD26
#define LCDWF26_BPHLCD26                _LCDWF26.Bits.BPHLCD26

#define LCDWF26_BPALCD26_MASK           1
#define LCDWF26_BPBLCD26_MASK           2
#define LCDWF26_BPCLCD26_MASK           4
#define LCDWF26_BPDLCD26_MASK           8
#define LCDWF26_BPELCD26_MASK           16
#define LCDWF26_BPFLCD26_MASK           32
#define LCDWF26_BPGLCD26_MASK           64
#define LCDWF26_BPHLCD26_MASK           128


/*** LCDWF27 - LCD Waveform Register 27; 0x0000102B ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD27    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD27    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD27    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD27    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD27    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD27    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD27    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD27    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF27STR;
extern volatile LCDWF27STR _LCDWF27 @0x0000102B;
#define LCDWF27                         _LCDWF27.Byte
#define LCDWF27_BPALCD27                _LCDWF27.Bits.BPALCD27
#define LCDWF27_BPBLCD27                _LCDWF27.Bits.BPBLCD27
#define LCDWF27_BPCLCD27                _LCDWF27.Bits.BPCLCD27
#define LCDWF27_BPDLCD27                _LCDWF27.Bits.BPDLCD27
#define LCDWF27_BPELCD27                _LCDWF27.Bits.BPELCD27
#define LCDWF27_BPFLCD27                _LCDWF27.Bits.BPFLCD27
#define LCDWF27_BPGLCD27                _LCDWF27.Bits.BPGLCD27
#define LCDWF27_BPHLCD27                _LCDWF27.Bits.BPHLCD27

#define LCDWF27_BPALCD27_MASK           1
#define LCDWF27_BPBLCD27_MASK           2
#define LCDWF27_BPCLCD27_MASK           4
#define LCDWF27_BPDLCD27_MASK           8
#define LCDWF27_BPELCD27_MASK           16
#define LCDWF27_BPFLCD27_MASK           32
#define LCDWF27_BPGLCD27_MASK           64
#define LCDWF27_BPHLCD27_MASK           128


/*** LCDWF28 - LCD Waveform Register 28; 0x0000102C ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD28    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD28    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD28    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD28    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD28    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD28    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD28    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD28    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF28STR;
extern volatile LCDWF28STR _LCDWF28 @0x0000102C;
#define LCDWF28                         _LCDWF28.Byte
#define LCDWF28_BPALCD28                _LCDWF28.Bits.BPALCD28
#define LCDWF28_BPBLCD28                _LCDWF28.Bits.BPBLCD28
#define LCDWF28_BPCLCD28                _LCDWF28.Bits.BPCLCD28
#define LCDWF28_BPDLCD28                _LCDWF28.Bits.BPDLCD28
#define LCDWF28_BPELCD28                _LCDWF28.Bits.BPELCD28
#define LCDWF28_BPFLCD28                _LCDWF28.Bits.BPFLCD28
#define LCDWF28_BPGLCD28                _LCDWF28.Bits.BPGLCD28
#define LCDWF28_BPHLCD28                _LCDWF28.Bits.BPHLCD28

#define LCDWF28_BPALCD28_MASK           1
#define LCDWF28_BPBLCD28_MASK           2
#define LCDWF28_BPCLCD28_MASK           4
#define LCDWF28_BPDLCD28_MASK           8
#define LCDWF28_BPELCD28_MASK           16
#define LCDWF28_BPFLCD28_MASK           32
#define LCDWF28_BPGLCD28_MASK           64
#define LCDWF28_BPHLCD28_MASK           128


/*** LCDWF29 - LCD Waveform Register 29; 0x0000102D ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD29    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD29    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD29    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD29    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD29    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD29    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD29    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD29    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF29STR;
extern volatile LCDWF29STR _LCDWF29 @0x0000102D;
#define LCDWF29                         _LCDWF29.Byte
#define LCDWF29_BPALCD29                _LCDWF29.Bits.BPALCD29
#define LCDWF29_BPBLCD29                _LCDWF29.Bits.BPBLCD29
#define LCDWF29_BPCLCD29                _LCDWF29.Bits.BPCLCD29
#define LCDWF29_BPDLCD29                _LCDWF29.Bits.BPDLCD29
#define LCDWF29_BPELCD29                _LCDWF29.Bits.BPELCD29
#define LCDWF29_BPFLCD29                _LCDWF29.Bits.BPFLCD29
#define LCDWF29_BPGLCD29                _LCDWF29.Bits.BPGLCD29
#define LCDWF29_BPHLCD29                _LCDWF29.Bits.BPHLCD29

#define LCDWF29_BPALCD29_MASK           1
#define LCDWF29_BPBLCD29_MASK           2
#define LCDWF29_BPCLCD29_MASK           4
#define LCDWF29_BPDLCD29_MASK           8
#define LCDWF29_BPELCD29_MASK           16
#define LCDWF29_BPFLCD29_MASK           32
#define LCDWF29_BPGLCD29_MASK           64
#define LCDWF29_BPHLCD29_MASK           128


/*** LCDWF30 - LCD Waveform Register 30; 0x0000102E ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD30    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD30    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD30    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD30    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD30    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD30    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD30    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD30    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF30STR;
extern volatile LCDWF30STR _LCDWF30 @0x0000102E;
#define LCDWF30                         _LCDWF30.Byte
#define LCDWF30_BPALCD30                _LCDWF30.Bits.BPALCD30
#define LCDWF30_BPBLCD30                _LCDWF30.Bits.BPBLCD30
#define LCDWF30_BPCLCD30                _LCDWF30.Bits.BPCLCD30
#define LCDWF30_BPDLCD30                _LCDWF30.Bits.BPDLCD30
#define LCDWF30_BPELCD30                _LCDWF30.Bits.BPELCD30
#define LCDWF30_BPFLCD30                _LCDWF30.Bits.BPFLCD30
#define LCDWF30_BPGLCD30                _LCDWF30.Bits.BPGLCD30
#define LCDWF30_BPHLCD30                _LCDWF30.Bits.BPHLCD30

#define LCDWF30_BPALCD30_MASK           1
#define LCDWF30_BPBLCD30_MASK           2
#define LCDWF30_BPCLCD30_MASK           4
#define LCDWF30_BPDLCD30_MASK           8
#define LCDWF30_BPELCD30_MASK           16
#define LCDWF30_BPFLCD30_MASK           32
#define LCDWF30_BPGLCD30_MASK           64
#define LCDWF30_BPHLCD30_MASK           128


/*** LCDWF31 - LCD Waveform Register 31; 0x0000102F ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD31    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD31    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD31    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD31    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD31    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD31    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD31    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD31    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF31STR;
extern volatile LCDWF31STR _LCDWF31 @0x0000102F;
#define LCDWF31                         _LCDWF31.Byte
#define LCDWF31_BPALCD31                _LCDWF31.Bits.BPALCD31
#define LCDWF31_BPBLCD31                _LCDWF31.Bits.BPBLCD31
#define LCDWF31_BPCLCD31                _LCDWF31.Bits.BPCLCD31
#define LCDWF31_BPDLCD31                _LCDWF31.Bits.BPDLCD31
#define LCDWF31_BPELCD31                _LCDWF31.Bits.BPELCD31
#define LCDWF31_BPFLCD31                _LCDWF31.Bits.BPFLCD31
#define LCDWF31_BPGLCD31                _LCDWF31.Bits.BPGLCD31
#define LCDWF31_BPHLCD31                _LCDWF31.Bits.BPHLCD31

#define LCDWF31_BPALCD31_MASK           1
#define LCDWF31_BPBLCD31_MASK           2
#define LCDWF31_BPCLCD31_MASK           4
#define LCDWF31_BPDLCD31_MASK           8
#define LCDWF31_BPELCD31_MASK           16
#define LCDWF31_BPFLCD31_MASK           32
#define LCDWF31_BPGLCD31_MASK           64
#define LCDWF31_BPHLCD31_MASK           128


/*** LCDWF32 - LCD Waveform Register 32; 0x00001030 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD32    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD32    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD32    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD32    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD32    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD32    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD32    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD32    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF32STR;
extern volatile LCDWF32STR _LCDWF32 @0x00001030;
#define LCDWF32                         _LCDWF32.Byte
#define LCDWF32_BPALCD32                _LCDWF32.Bits.BPALCD32
#define LCDWF32_BPBLCD32                _LCDWF32.Bits.BPBLCD32
#define LCDWF32_BPCLCD32                _LCDWF32.Bits.BPCLCD32
#define LCDWF32_BPDLCD32                _LCDWF32.Bits.BPDLCD32
#define LCDWF32_BPELCD32                _LCDWF32.Bits.BPELCD32
#define LCDWF32_BPFLCD32                _LCDWF32.Bits.BPFLCD32
#define LCDWF32_BPGLCD32                _LCDWF32.Bits.BPGLCD32
#define LCDWF32_BPHLCD32                _LCDWF32.Bits.BPHLCD32

#define LCDWF32_BPALCD32_MASK           1
#define LCDWF32_BPBLCD32_MASK           2
#define LCDWF32_BPCLCD32_MASK           4
#define LCDWF32_BPDLCD32_MASK           8
#define LCDWF32_BPELCD32_MASK           16
#define LCDWF32_BPFLCD32_MASK           32
#define LCDWF32_BPGLCD32_MASK           64
#define LCDWF32_BPHLCD32_MASK           128


/*** LCDWF33 - LCD Waveform Register 33; 0x00001031 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD33    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD33    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD33    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD33    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD33    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD33    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD33    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD33    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF33STR;
extern volatile LCDWF33STR _LCDWF33 @0x00001031;
#define LCDWF33                         _LCDWF33.Byte
#define LCDWF33_BPALCD33                _LCDWF33.Bits.BPALCD33
#define LCDWF33_BPBLCD33                _LCDWF33.Bits.BPBLCD33
#define LCDWF33_BPCLCD33                _LCDWF33.Bits.BPCLCD33
#define LCDWF33_BPDLCD33                _LCDWF33.Bits.BPDLCD33
#define LCDWF33_BPELCD33                _LCDWF33.Bits.BPELCD33
#define LCDWF33_BPFLCD33                _LCDWF33.Bits.BPFLCD33
#define LCDWF33_BPGLCD33                _LCDWF33.Bits.BPGLCD33
#define LCDWF33_BPHLCD33                _LCDWF33.Bits.BPHLCD33

#define LCDWF33_BPALCD33_MASK           1
#define LCDWF33_BPBLCD33_MASK           2
#define LCDWF33_BPCLCD33_MASK           4
#define LCDWF33_BPDLCD33_MASK           8
#define LCDWF33_BPELCD33_MASK           16
#define LCDWF33_BPFLCD33_MASK           32
#define LCDWF33_BPGLCD33_MASK           64
#define LCDWF33_BPHLCD33_MASK           128


/*** LCDWF34 - LCD Waveform Register 34; 0x00001032 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD34    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD34    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD34    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD34    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD34    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD34    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD34    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD34    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF34STR;
extern volatile LCDWF34STR _LCDWF34 @0x00001032;
#define LCDWF34                         _LCDWF34.Byte
#define LCDWF34_BPALCD34                _LCDWF34.Bits.BPALCD34
#define LCDWF34_BPBLCD34                _LCDWF34.Bits.BPBLCD34
#define LCDWF34_BPCLCD34                _LCDWF34.Bits.BPCLCD34
#define LCDWF34_BPDLCD34                _LCDWF34.Bits.BPDLCD34
#define LCDWF34_BPELCD34                _LCDWF34.Bits.BPELCD34
#define LCDWF34_BPFLCD34                _LCDWF34.Bits.BPFLCD34
#define LCDWF34_BPGLCD34                _LCDWF34.Bits.BPGLCD34
#define LCDWF34_BPHLCD34                _LCDWF34.Bits.BPHLCD34

#define LCDWF34_BPALCD34_MASK           1
#define LCDWF34_BPBLCD34_MASK           2
#define LCDWF34_BPCLCD34_MASK           4
#define LCDWF34_BPDLCD34_MASK           8
#define LCDWF34_BPELCD34_MASK           16
#define LCDWF34_BPFLCD34_MASK           32
#define LCDWF34_BPGLCD34_MASK           64
#define LCDWF34_BPHLCD34_MASK           128


/*** LCDWF35 - LCD Waveform Register 35; 0x00001033 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD35    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD35    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD35    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD35    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD35    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD35    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD35    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD35    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF35STR;
extern volatile LCDWF35STR _LCDWF35 @0x00001033;
#define LCDWF35                         _LCDWF35.Byte
#define LCDWF35_BPALCD35                _LCDWF35.Bits.BPALCD35
#define LCDWF35_BPBLCD35                _LCDWF35.Bits.BPBLCD35
#define LCDWF35_BPCLCD35                _LCDWF35.Bits.BPCLCD35
#define LCDWF35_BPDLCD35                _LCDWF35.Bits.BPDLCD35
#define LCDWF35_BPELCD35                _LCDWF35.Bits.BPELCD35
#define LCDWF35_BPFLCD35                _LCDWF35.Bits.BPFLCD35
#define LCDWF35_BPGLCD35                _LCDWF35.Bits.BPGLCD35
#define LCDWF35_BPHLCD35                _LCDWF35.Bits.BPHLCD35

#define LCDWF35_BPALCD35_MASK           1
#define LCDWF35_BPBLCD35_MASK           2
#define LCDWF35_BPCLCD35_MASK           4
#define LCDWF35_BPDLCD35_MASK           8
#define LCDWF35_BPELCD35_MASK           16
#define LCDWF35_BPFLCD35_MASK           32
#define LCDWF35_BPGLCD35_MASK           64
#define LCDWF35_BPHLCD35_MASK           128


/*** LCDWF36 - LCD Waveform Register 36; 0x00001034 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD36    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD36    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD36    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD36    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD36    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD36    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD36    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD36    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF36STR;
extern volatile LCDWF36STR _LCDWF36 @0x00001034;
#define LCDWF36                         _LCDWF36.Byte
#define LCDWF36_BPALCD36                _LCDWF36.Bits.BPALCD36
#define LCDWF36_BPBLCD36                _LCDWF36.Bits.BPBLCD36
#define LCDWF36_BPCLCD36                _LCDWF36.Bits.BPCLCD36
#define LCDWF36_BPDLCD36                _LCDWF36.Bits.BPDLCD36
#define LCDWF36_BPELCD36                _LCDWF36.Bits.BPELCD36
#define LCDWF36_BPFLCD36                _LCDWF36.Bits.BPFLCD36
#define LCDWF36_BPGLCD36                _LCDWF36.Bits.BPGLCD36
#define LCDWF36_BPHLCD36                _LCDWF36.Bits.BPHLCD36

#define LCDWF36_BPALCD36_MASK           1
#define LCDWF36_BPBLCD36_MASK           2
#define LCDWF36_BPCLCD36_MASK           4
#define LCDWF36_BPDLCD36_MASK           8
#define LCDWF36_BPELCD36_MASK           16
#define LCDWF36_BPFLCD36_MASK           32
#define LCDWF36_BPGLCD36_MASK           64
#define LCDWF36_BPHLCD36_MASK           128


/*** LCDWF37 - LCD Waveform Register 37; 0x00001035 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD37    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD37    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD37    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD37    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD37    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD37    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD37    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD37    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF37STR;
extern volatile LCDWF37STR _LCDWF37 @0x00001035;
#define LCDWF37                         _LCDWF37.Byte
#define LCDWF37_BPALCD37                _LCDWF37.Bits.BPALCD37
#define LCDWF37_BPBLCD37                _LCDWF37.Bits.BPBLCD37
#define LCDWF37_BPCLCD37                _LCDWF37.Bits.BPCLCD37
#define LCDWF37_BPDLCD37                _LCDWF37.Bits.BPDLCD37
#define LCDWF37_BPELCD37                _LCDWF37.Bits.BPELCD37
#define LCDWF37_BPFLCD37                _LCDWF37.Bits.BPFLCD37
#define LCDWF37_BPGLCD37                _LCDWF37.Bits.BPGLCD37
#define LCDWF37_BPHLCD37                _LCDWF37.Bits.BPHLCD37

#define LCDWF37_BPALCD37_MASK           1
#define LCDWF37_BPBLCD37_MASK           2
#define LCDWF37_BPCLCD37_MASK           4
#define LCDWF37_BPDLCD37_MASK           8
#define LCDWF37_BPELCD37_MASK           16
#define LCDWF37_BPFLCD37_MASK           32
#define LCDWF37_BPGLCD37_MASK           64
#define LCDWF37_BPHLCD37_MASK           128


/*** LCDWF38 - LCD Waveform Register 38; 0x00001036 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD38    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD38    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD38    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD38    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD38    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD38    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD38    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD38    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF38STR;
extern volatile LCDWF38STR _LCDWF38 @0x00001036;
#define LCDWF38                         _LCDWF38.Byte
#define LCDWF38_BPALCD38                _LCDWF38.Bits.BPALCD38
#define LCDWF38_BPBLCD38                _LCDWF38.Bits.BPBLCD38
#define LCDWF38_BPCLCD38                _LCDWF38.Bits.BPCLCD38
#define LCDWF38_BPDLCD38                _LCDWF38.Bits.BPDLCD38
#define LCDWF38_BPELCD38                _LCDWF38.Bits.BPELCD38
#define LCDWF38_BPFLCD38                _LCDWF38.Bits.BPFLCD38
#define LCDWF38_BPGLCD38                _LCDWF38.Bits.BPGLCD38
#define LCDWF38_BPHLCD38                _LCDWF38.Bits.BPHLCD38

#define LCDWF38_BPALCD38_MASK           1
#define LCDWF38_BPBLCD38_MASK           2
#define LCDWF38_BPCLCD38_MASK           4
#define LCDWF38_BPDLCD38_MASK           8
#define LCDWF38_BPELCD38_MASK           16
#define LCDWF38_BPFLCD38_MASK           32
#define LCDWF38_BPGLCD38_MASK           64
#define LCDWF38_BPHLCD38_MASK           128


/*** LCDWF39 - LCD Waveform Register 39; 0x00001037 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD39    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD39    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD39    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD39    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD39    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD39    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD39    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD39    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF39STR;
extern volatile LCDWF39STR _LCDWF39 @0x00001037;
#define LCDWF39                         _LCDWF39.Byte
#define LCDWF39_BPALCD39                _LCDWF39.Bits.BPALCD39
#define LCDWF39_BPBLCD39                _LCDWF39.Bits.BPBLCD39
#define LCDWF39_BPCLCD39                _LCDWF39.Bits.BPCLCD39
#define LCDWF39_BPDLCD39                _LCDWF39.Bits.BPDLCD39
#define LCDWF39_BPELCD39                _LCDWF39.Bits.BPELCD39
#define LCDWF39_BPFLCD39                _LCDWF39.Bits.BPFLCD39
#define LCDWF39_BPGLCD39                _LCDWF39.Bits.BPGLCD39
#define LCDWF39_BPHLCD39                _LCDWF39.Bits.BPHLCD39

#define LCDWF39_BPALCD39_MASK           1
#define LCDWF39_BPBLCD39_MASK           2
#define LCDWF39_BPCLCD39_MASK           4
#define LCDWF39_BPDLCD39_MASK           8
#define LCDWF39_BPELCD39_MASK           16
#define LCDWF39_BPFLCD39_MASK           32
#define LCDWF39_BPGLCD39_MASK           64
#define LCDWF39_BPHLCD39_MASK           128


/*** LCDWF40 - LCD Waveform Register 40; 0x00001038 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD40    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD40    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD40    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD40    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD40    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD40    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD40    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD40    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF40STR;
extern volatile LCDWF40STR _LCDWF40 @0x00001038;
#define LCDWF40                         _LCDWF40.Byte
#define LCDWF40_BPALCD40                _LCDWF40.Bits.BPALCD40
#define LCDWF40_BPBLCD40                _LCDWF40.Bits.BPBLCD40
#define LCDWF40_BPCLCD40                _LCDWF40.Bits.BPCLCD40
#define LCDWF40_BPDLCD40                _LCDWF40.Bits.BPDLCD40
#define LCDWF40_BPELCD40                _LCDWF40.Bits.BPELCD40
#define LCDWF40_BPFLCD40                _LCDWF40.Bits.BPFLCD40
#define LCDWF40_BPGLCD40                _LCDWF40.Bits.BPGLCD40
#define LCDWF40_BPHLCD40                _LCDWF40.Bits.BPHLCD40

#define LCDWF40_BPALCD40_MASK           1
#define LCDWF40_BPBLCD40_MASK           2
#define LCDWF40_BPCLCD40_MASK           4
#define LCDWF40_BPDLCD40_MASK           8
#define LCDWF40_BPELCD40_MASK           16
#define LCDWF40_BPFLCD40_MASK           32
#define LCDWF40_BPGLCD40_MASK           64
#define LCDWF40_BPHLCD40_MASK           128


/*** LCDWF41 - LCD Waveform Register 41; 0x00001039 ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD41    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD41    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD41    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD41    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD41    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD41    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD41    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD41    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF41STR;
extern volatile LCDWF41STR _LCDWF41 @0x00001039;
#define LCDWF41                         _LCDWF41.Byte
#define LCDWF41_BPALCD41                _LCDWF41.Bits.BPALCD41
#define LCDWF41_BPBLCD41                _LCDWF41.Bits.BPBLCD41
#define LCDWF41_BPCLCD41                _LCDWF41.Bits.BPCLCD41
#define LCDWF41_BPDLCD41                _LCDWF41.Bits.BPDLCD41
#define LCDWF41_BPELCD41                _LCDWF41.Bits.BPELCD41
#define LCDWF41_BPFLCD41                _LCDWF41.Bits.BPFLCD41
#define LCDWF41_BPGLCD41                _LCDWF41.Bits.BPGLCD41
#define LCDWF41_BPHLCD41                _LCDWF41.Bits.BPHLCD41

#define LCDWF41_BPALCD41_MASK           1
#define LCDWF41_BPBLCD41_MASK           2
#define LCDWF41_BPCLCD41_MASK           4
#define LCDWF41_BPDLCD41_MASK           8
#define LCDWF41_BPELCD41_MASK           16
#define LCDWF41_BPFLCD41_MASK           32
#define LCDWF41_BPGLCD41_MASK           64
#define LCDWF41_BPHLCD41_MASK           128


/*** LCDWF42 - LCD Waveform Register 42; 0x0000103A ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD42    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD42    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD42    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD42    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD42    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD42    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD42    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD42    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF42STR;
extern volatile LCDWF42STR _LCDWF42 @0x0000103A;
#define LCDWF42                         _LCDWF42.Byte
#define LCDWF42_BPALCD42                _LCDWF42.Bits.BPALCD42
#define LCDWF42_BPBLCD42                _LCDWF42.Bits.BPBLCD42
#define LCDWF42_BPCLCD42                _LCDWF42.Bits.BPCLCD42
#define LCDWF42_BPDLCD42                _LCDWF42.Bits.BPDLCD42
#define LCDWF42_BPELCD42                _LCDWF42.Bits.BPELCD42
#define LCDWF42_BPFLCD42                _LCDWF42.Bits.BPFLCD42
#define LCDWF42_BPGLCD42                _LCDWF42.Bits.BPGLCD42
#define LCDWF42_BPHLCD42                _LCDWF42.Bits.BPHLCD42

#define LCDWF42_BPALCD42_MASK           1
#define LCDWF42_BPBLCD42_MASK           2
#define LCDWF42_BPCLCD42_MASK           4
#define LCDWF42_BPDLCD42_MASK           8
#define LCDWF42_BPELCD42_MASK           16
#define LCDWF42_BPFLCD42_MASK           32
#define LCDWF42_BPGLCD42_MASK           64
#define LCDWF42_BPHLCD42_MASK           128


/*** LCDWF43 - LCD Waveform Register 43; 0x0000103B ***/
typedef union {
  byte Byte;
  struct {
    byte BPALCD43    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPBLCD43    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPCLCD43    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPDLCD43    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPELCD43    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPFLCD43    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPGLCD43    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
    byte BPHLCD43    :1;                                       /* Segment on/off Frontplane/Backplane Operation */
  } Bits;
} LCDWF43STR;
extern volatile LCDWF43STR _LCDWF43 @0x0000103B;
#define LCDWF43                         _LCDWF43.Byte
#define LCDWF43_BPALCD43                _LCDWF43.Bits.BPALCD43
#define LCDWF43_BPBLCD43                _LCDWF43.Bits.BPBLCD43
#define LCDWF43_BPCLCD43                _LCDWF43.Bits.BPCLCD43
#define LCDWF43_BPDLCD43                _LCDWF43.Bits.BPDLCD43
#define LCDWF43_BPELCD43                _LCDWF43.Bits.BPELCD43
#define LCDWF43_BPFLCD43                _LCDWF43.Bits.BPFLCD43
#define LCDWF43_BPGLCD43                _LCDWF43.Bits.BPGLCD43
#define LCDWF43_BPHLCD43                _LCDWF43.Bits.BPHLCD43

#define LCDWF43_BPALCD43_MASK           1
#define LCDWF43_BPBLCD43_MASK           2
#define LCDWF43_BPCLCD43_MASK           4
#define LCDWF43_BPDLCD43_MASK           8
#define LCDWF43_BPELCD43_MASK           16
#define LCDWF43_BPFLCD43_MASK           32
#define LCDWF43_BPGLCD43_MASK           64
#define LCDWF43_BPHLCD43_MASK           128


/*** SRS - System Reset Status Register; 0x00001800 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LVD         :1;                                       /* Low Voltage Detect */
    byte             :1; 
    byte ILAD        :1;                                       /* Illegal Address */
    byte ILOP        :1;                                       /* Illegal Opcode */
    byte COP         :1;                                       /* Computer Operating Properly (COP) Watchdog */
    byte PIN         :1;                                       /* External Reset Pin */
    byte POR         :1;                                       /* Power-On Reset */
  } Bits;
} SRSSTR;
extern volatile SRSSTR _SRS @0x00001800;
#define SRS                             _SRS.Byte
#define SRS_LVD                         _SRS.Bits.LVD
#define SRS_ILAD                        _SRS.Bits.ILAD
#define SRS_ILOP                        _SRS.Bits.ILOP
#define SRS_COP                         _SRS.Bits.COP
#define SRS_PIN                         _SRS.Bits.PIN
#define SRS_POR                         _SRS.Bits.POR

#define SRS_LVD_MASK                    2
#define SRS_ILAD_MASK                   8
#define SRS_ILOP_MASK                   16
#define SRS_COP_MASK                    32
#define SRS_PIN_MASK                    64
#define SRS_POR_MASK                    128


/*** SBDFR - System Background Debug Force Reset Register; 0x00001801 ***/
typedef union {
  byte Byte;
  struct {
    byte BDFR        :1;                                       /* Background Debug Force Reset */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SBDFRSTR;
extern volatile SBDFRSTR _SBDFR @0x00001801;
#define SBDFR                           _SBDFR.Byte
#define SBDFR_BDFR                      _SBDFR.Bits.BDFR

#define SBDFR_BDFR_MASK                 1


/*** SOPT1 - System Options Register 1; 0x00001802 ***/
typedef union {
  byte Byte;
  struct {
    byte RSTPE       :1;                                       /* RESET Pin Enable */
    byte BKGDPE      :1;                                       /* Background Debug Mode Pin Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte STOPE       :1;                                       /* Stop Mode Enable */
    byte COPT        :1;                                       /* COP Watchdog Timeout */
    byte COPE        :1;                                       /* COP Watchdog Enable */
  } Bits;
} SOPT1STR;
extern volatile SOPT1STR _SOPT1 @0x00001802;
#define SOPT1                           _SOPT1.Byte
#define SOPT1_RSTPE                     _SOPT1.Bits.RSTPE
#define SOPT1_BKGDPE                    _SOPT1.Bits.BKGDPE
#define SOPT1_STOPE                     _SOPT1.Bits.STOPE
#define SOPT1_COPT                      _SOPT1.Bits.COPT
#define SOPT1_COPE                      _SOPT1.Bits.COPE

#define SOPT1_RSTPE_MASK                1
#define SOPT1_BKGDPE_MASK               2
#define SOPT1_STOPE_MASK                32
#define SOPT1_COPT_MASK                 64
#define SOPT1_COPE_MASK                 128


/*** SOPT2 - System Options Register 2; 0x00001803 ***/
typedef union {
  byte Byte;
  struct {
    byte ACIC        :1;                                       /* Analog Comparator to Input Capture Enable */
    byte IICPS       :1;                                       /* IIC Pin Select */
    byte SPIPS       :1;                                       /* SPI Pin Select */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte COPCLKS     :1;                                       /* COP Watchdog Clock Select */
  } Bits;
} SOPT2STR;
extern volatile SOPT2STR _SOPT2 @0x00001803;
#define SOPT2                           _SOPT2.Byte
#define SOPT2_ACIC                      _SOPT2.Bits.ACIC
#define SOPT2_IICPS                     _SOPT2.Bits.IICPS
#define SOPT2_SPIPS                     _SOPT2.Bits.SPIPS
#define SOPT2_COPCLKS                   _SOPT2.Bits.COPCLKS

#define SOPT2_ACIC_MASK                 1
#define SOPT2_IICPS_MASK                2
#define SOPT2_SPIPS_MASK                4
#define SOPT2_COPCLKS_MASK              128


/*** SDID - System Device Identification Register; 0x00001806 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SDIDH - System Device Identification Register High; 0x00001806 ***/
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       /* Part Identification Number, bit 8 */
        byte ID9         :1;                                       /* Part Identification Number, bit 9 */
        byte ID10        :1;                                       /* Part Identification Number, bit 10 */
        byte ID11        :1;                                       /* Part Identification Number, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpID_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SDIDHSTR;
    #define SDIDH                       _SDID.Overlap_STR.SDIDHSTR.Byte
    #define SDIDH_ID8                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID8
    #define SDIDH_ID9                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID9
    #define SDIDH_ID10                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID10
    #define SDIDH_ID11                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID11
    #define SDIDH_ID_8                  _SDID.Overlap_STR.SDIDHSTR.MergedBits.grpID_8
    #define SDIDH_ID                    SDIDH_ID_8
    
    #define SDIDH_ID8_MASK              1
    #define SDIDH_ID9_MASK              2
    #define SDIDH_ID10_MASK             4
    #define SDIDH_ID11_MASK             8
    #define SDIDH_ID_8_MASK             15
    #define SDIDH_ID_8_BITNUM           0
    

    /*** SDIDL - System Device Identification Register Low; 0x00001807 ***/
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       /* Part Identification Number, bit 0 */
        byte ID1         :1;                                       /* Part Identification Number, bit 1 */
        byte ID2         :1;                                       /* Part Identification Number, bit 2 */
        byte ID3         :1;                                       /* Part Identification Number, bit 3 */
        byte ID4         :1;                                       /* Part Identification Number, bit 4 */
        byte ID5         :1;                                       /* Part Identification Number, bit 5 */
        byte ID6         :1;                                       /* Part Identification Number, bit 6 */
        byte ID7         :1;                                       /* Part Identification Number, bit 7 */
      } Bits;
    } SDIDLSTR;
    #define SDIDL                       _SDID.Overlap_STR.SDIDLSTR.Byte
    #define SDIDL_ID0                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID0
    #define SDIDL_ID1                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID1
    #define SDIDL_ID2                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID2
    #define SDIDL_ID3                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID3
    #define SDIDL_ID4                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID4
    #define SDIDL_ID5                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID5
    #define SDIDL_ID6                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID6
    #define SDIDL_ID7                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID7
    
    #define SDIDL_ID0_MASK              1
    #define SDIDL_ID1_MASK              2
    #define SDIDL_ID2_MASK              4
    #define SDIDL_ID3_MASK              8
    #define SDIDL_ID4_MASK              16
    #define SDIDL_ID5_MASK              32
    #define SDIDL_ID6_MASK              64
    #define SDIDL_ID7_MASK              128
    
  } Overlap_STR;

} SDIDSTR;
extern volatile SDIDSTR _SDID @0x00001806;
#define SDID                            _SDID.Word


/*** SPMSC1 - System Power Management Status and Control 1 Register; 0x00001808 ***/
typedef union {
  byte Byte;
  struct {
    byte BGBE        :1;                                       /* Bandgap Buffer Enable */
    byte BGBDS       :1;                                       /* Bandgap Buffer Drive Select */
    byte LVDE        :1;                                       /* Low-Voltage Detect Enable */
    byte LVDSE       :1;                                       /* Low-Voltage Detect Stop Enable */
    byte LVDRE       :1;                                       /* Low-Voltage Detect Reset Enable */
    byte LVDIE       :1;                                       /* Low-Voltage Detect Interrupt Enable */
    byte LVDACK      :1;                                       /* Low-Voltage Detect Acknowledge */
    byte LVDF        :1;                                       /* Low-Voltage Detect Flag */
  } Bits;
} SPMSC1STR;
extern volatile SPMSC1STR _SPMSC1 @0x00001808;
#define SPMSC1                          _SPMSC1.Byte
#define SPMSC1_BGBE                     _SPMSC1.Bits.BGBE
#define SPMSC1_BGBDS                    _SPMSC1.Bits.BGBDS
#define SPMSC1_LVDE                     _SPMSC1.Bits.LVDE
#define SPMSC1_LVDSE                    _SPMSC1.Bits.LVDSE
#define SPMSC1_LVDRE                    _SPMSC1.Bits.LVDRE
#define SPMSC1_LVDIE                    _SPMSC1.Bits.LVDIE
#define SPMSC1_LVDACK                   _SPMSC1.Bits.LVDACK
#define SPMSC1_LVDF                     _SPMSC1.Bits.LVDF

#define SPMSC1_BGBE_MASK                1
#define SPMSC1_BGBDS_MASK               2
#define SPMSC1_LVDE_MASK                4
#define SPMSC1_LVDSE_MASK               8
#define SPMSC1_LVDRE_MASK               16
#define SPMSC1_LVDIE_MASK               32
#define SPMSC1_LVDACK_MASK              64
#define SPMSC1_LVDF_MASK                128


/*** SPMSC2 - System Power Management Status and Control 2 Register; 0x00001809 ***/
typedef union {
  byte Byte;
  struct {
    byte PPDC        :1;                                       /* Partial Power Down Control */
    byte PPDE        :1;                                       /* Partial Power-Down Enable */
    byte PPDACK      :1;                                       /* Partial Power Down Acknowledge */
    byte PPDF        :1;                                       /* Partial Power Down Flag */
    byte             :1; 
    byte LPWUI       :1;                                       /* Low Power Wake Up on Interrupt */
    byte LPRS        :1;                                       /* Low Power Regulator Status */
    byte LPR         :1;                                       /* Low Power Regulator Control */
  } Bits;
} SPMSC2STR;
extern volatile SPMSC2STR _SPMSC2 @0x00001809;
#define SPMSC2                          _SPMSC2.Byte
#define SPMSC2_PPDC                     _SPMSC2.Bits.PPDC
#define SPMSC2_PPDE                     _SPMSC2.Bits.PPDE
#define SPMSC2_PPDACK                   _SPMSC2.Bits.PPDACK
#define SPMSC2_PPDF                     _SPMSC2.Bits.PPDF
#define SPMSC2_LPWUI                    _SPMSC2.Bits.LPWUI
#define SPMSC2_LPRS                     _SPMSC2.Bits.LPRS
#define SPMSC2_LPR                      _SPMSC2.Bits.LPR

#define SPMSC2_PPDC_MASK                1
#define SPMSC2_PPDE_MASK                2
#define SPMSC2_PPDACK_MASK              4
#define SPMSC2_PPDF_MASK                8
#define SPMSC2_LPWUI_MASK               32
#define SPMSC2_LPRS_MASK                64
#define SPMSC2_LPR_MASK                 128


/*** SPMSC3 - System Power Management Status and Control 3 Register; 0x0000180B ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LVWIE       :1;                                       /* Low-Voltage Warning Interrupt Enable */
    byte LVWV        :1;                                       /* Low-Voltage Warning Voltage Select */
    byte LVDV        :1;                                       /* Low-Voltage Detect Voltage Select */
    byte LVWACK      :1;                                       /* Low-Voltage Warning Acknowledge */
    byte LVWF        :1;                                       /* Low-Voltage Warning Flag */
  } Bits;
} SPMSC3STR;
extern volatile SPMSC3STR _SPMSC3 @0x0000180B;
#define SPMSC3                          _SPMSC3.Byte
#define SPMSC3_LVWIE                    _SPMSC3.Bits.LVWIE
#define SPMSC3_LVWV                     _SPMSC3.Bits.LVWV
#define SPMSC3_LVDV                     _SPMSC3.Bits.LVDV
#define SPMSC3_LVWACK                   _SPMSC3.Bits.LVWACK
#define SPMSC3_LVWF                     _SPMSC3.Bits.LVWF

#define SPMSC3_LVWIE_MASK               8
#define SPMSC3_LVWV_MASK                16
#define SPMSC3_LVDV_MASK                32
#define SPMSC3_LVWACK_MASK              64
#define SPMSC3_LVWF_MASK                128


/*** SCGC1 - System Clock Gating Control 1 Register; 0x0000180E ***/
typedef union {
  byte Byte;
  struct {
    byte SCI1        :1;                                       /* SCI1 Clock Gate Control */
    byte SCI2        :1;                                       /* SCI2 Clock Gate Control */
    byte IIC         :1;                                       /* IIC Clock Gate Control */
    byte VREF1       :1;                                       /* VREF1 Clock Gate Control */
    byte ADC         :1;                                       /* ADC Clock Gate Control */
    byte TPM1        :1;                                       /* TPM1 Clock Gate Control */
    byte TPM2        :1;                                       /* TPM2 Clock Gate Control */
    byte VREF2       :1;                                       /* VREF2 Clock Gate Control */
  } Bits;
  struct {
    byte grpSCI_1 :2;
    byte         :1;
    byte grpVREF_1 :1;
    byte         :1;
    byte grpTPM_1 :2;
    byte grpVREF_2 :1;
  } MergedBits;
} SCGC1STR;
extern volatile SCGC1STR _SCGC1 @0x0000180E;
#define SCGC1                           _SCGC1.Byte
#define SCGC1_SCI1                      _SCGC1.Bits.SCI1
#define SCGC1_SCI2                      _SCGC1.Bits.SCI2
#define SCGC1_IIC                       _SCGC1.Bits.IIC
#define SCGC1_VREF1                     _SCGC1.Bits.VREF1
#define SCGC1_ADC                       _SCGC1.Bits.ADC
#define SCGC1_TPM1                      _SCGC1.Bits.TPM1
#define SCGC1_TPM2                      _SCGC1.Bits.TPM2
#define SCGC1_VREF2                     _SCGC1.Bits.VREF2
#define SCGC1_SCI_1                     _SCGC1.MergedBits.grpSCI_1
#define SCGC1_TPM_1                     _SCGC1.MergedBits.grpTPM_1
#define SCGC1_SCI                       SCGC1_SCI_1
#define SCGC1_TPM                       SCGC1_TPM_1

#define SCGC1_SCI1_MASK                 1
#define SCGC1_SCI2_MASK                 2
#define SCGC1_IIC_MASK                  4
#define SCGC1_VREF1_MASK                8
#define SCGC1_ADC_MASK                  16
#define SCGC1_TPM1_MASK                 32
#define SCGC1_TPM2_MASK                 64
#define SCGC1_VREF2_MASK                128
#define SCGC1_SCI_1_MASK                3
#define SCGC1_SCI_1_BITNUM              0
#define SCGC1_TPM_1_MASK                96
#define SCGC1_TPM_1_BITNUM              5


/*** SCGC2 - System Clock Gating Control 2 Register; 0x0000180F ***/
typedef union {
  byte Byte;
  struct {
    byte SPI         :1;                                       /* SPI Clock Gate Control */
    byte LCD         :1;                                       /* LCD Clock Gate Control */
    byte TOD         :1;                                       /* TOD Clock Gate Control */
    byte ACMP        :1;                                       /* ACMP Clock Gate Control */
    byte KBI         :1;                                       /* KBI Clock Gate Control */
    byte IRQ         :1;                                       /* IRQ Clock Gate Control */
    byte FLS         :1;                                       /* FLASH Register Clock Gate Control */
    byte DBG         :1;                                       /* DBG Clock Gate Control */
  } Bits;
} SCGC2STR;
extern volatile SCGC2STR _SCGC2 @0x0000180F;
#define SCGC2                           _SCGC2.Byte
#define SCGC2_SPI                       _SCGC2.Bits.SPI
#define SCGC2_LCD                       _SCGC2.Bits.LCD
#define SCGC2_TOD                       _SCGC2.Bits.TOD
#define SCGC2_ACMP                      _SCGC2.Bits.ACMP
#define SCGC2_KBI                       _SCGC2.Bits.KBI
#define SCGC2_IRQ                       _SCGC2.Bits.IRQ
#define SCGC2_FLS                       _SCGC2.Bits.FLS
#define SCGC2_DBG                       _SCGC2.Bits.DBG

#define SCGC2_SPI_MASK                  1
#define SCGC2_LCD_MASK                  2
#define SCGC2_TOD_MASK                  4
#define SCGC2_ACMP_MASK                 8
#define SCGC2_KBI_MASK                  16
#define SCGC2_IRQ_MASK                  32
#define SCGC2_FLS_MASK                  64
#define SCGC2_DBG_MASK                  128


/*** DBGCA - Debug Comparator A Register; 0x00001810 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCAH - Debug Comparator A High Register; 0x00001810 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Comparator A High Compare Bit 8 */
        byte Bit9        :1;                                       /* Comparator A High Compare Bit 9 */
        byte Bit10       :1;                                       /* Comparator A High Compare Bit 10 */
        byte Bit11       :1;                                       /* Comparator A High Compare Bit 11 */
        byte Bit12       :1;                                       /* Comparator A High Compare Bit 12 */
        byte Bit13       :1;                                       /* Comparator A High Compare Bit 13 */
        byte Bit14       :1;                                       /* Comparator A High Compare Bit 14 */
        byte Bit15       :1;                                       /* Comparator A High Compare Bit 15 */
      } Bits;
    } DBGCAHSTR;
    #define DBGCAH                      _DBGCA.Overlap_STR.DBGCAHSTR.Byte
    #define DBGCAH_Bit8                 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit8
    #define DBGCAH_Bit9                 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit9
    #define DBGCAH_Bit10                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit10
    #define DBGCAH_Bit11                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit11
    #define DBGCAH_Bit12                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit12
    #define DBGCAH_Bit13                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit13
    #define DBGCAH_Bit14                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit14
    #define DBGCAH_Bit15                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit15
    
    #define DBGCAH_Bit8_MASK            1
    #define DBGCAH_Bit9_MASK            2
    #define DBGCAH_Bit10_MASK           4
    #define DBGCAH_Bit11_MASK           8
    #define DBGCAH_Bit12_MASK           16
    #define DBGCAH_Bit13_MASK           32
    #define DBGCAH_Bit14_MASK           64
    #define DBGCAH_Bit15_MASK           128
    

    /*** DBGCAL - Debug Comparator A Low Register; 0x00001811 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Comparator A Low Compare Bit 0 */
        byte Bit1        :1;                                       /* Comparator A Low Compare Bit 1 */
        byte Bit2        :1;                                       /* Comparator A Low Compare Bit 2 */
        byte Bit3        :1;                                       /* Comparator A Low Compare Bit 3 */
        byte Bit4        :1;                                       /* Comparator A Low Compare Bit 4 */
        byte Bit5        :1;                                       /* Comparator A Low Compare Bit 5 */
        byte Bit6        :1;                                       /* Comparator A Low Compare Bit 6 */
        byte Bit7        :1;                                       /* Comparator A Low Compare Bit 7 */
      } Bits;
    } DBGCALSTR;
    #define DBGCAL                      _DBGCA.Overlap_STR.DBGCALSTR.Byte
    #define DBGCAL_Bit0                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit0
    #define DBGCAL_Bit1                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit1
    #define DBGCAL_Bit2                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit2
    #define DBGCAL_Bit3                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit3
    #define DBGCAL_Bit4                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit4
    #define DBGCAL_Bit5                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit5
    #define DBGCAL_Bit6                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit6
    #define DBGCAL_Bit7                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit7
    
    #define DBGCAL_Bit0_MASK            1
    #define DBGCAL_Bit1_MASK            2
    #define DBGCAL_Bit2_MASK            4
    #define DBGCAL_Bit3_MASK            8
    #define DBGCAL_Bit4_MASK            16
    #define DBGCAL_Bit5_MASK            32
    #define DBGCAL_Bit6_MASK            64
    #define DBGCAL_Bit7_MASK            128
    
  } Overlap_STR;

} DBGCASTR;
extern volatile DBGCASTR _DBGCA @0x00001810;
#define DBGCA                           _DBGCA.Word


/*** DBGCB - Debug Comparator B Register; 0x00001812 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCBH - Debug Comparator B High Register; 0x00001812 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Comparator B High Compare Bit 8 */
        byte Bit9        :1;                                       /* Comparator B High Compare Bit 9 */
        byte Bit10       :1;                                       /* Comparator B High Compare Bit 10 */
        byte Bit11       :1;                                       /* Comparator B High Compare Bit 11 */
        byte Bit12       :1;                                       /* Comparator B High Compare Bit 12 */
        byte Bit13       :1;                                       /* Comparator B High Compare Bit 13 */
        byte Bit14       :1;                                       /* Comparator B High Compare Bit 14 */
        byte Bit15       :1;                                       /* Comparator B High Compare Bit 15 */
      } Bits;
    } DBGCBHSTR;
    #define DBGCBH                      _DBGCB.Overlap_STR.DBGCBHSTR.Byte
    #define DBGCBH_Bit8                 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit8
    #define DBGCBH_Bit9                 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit9
    #define DBGCBH_Bit10                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit10
    #define DBGCBH_Bit11                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit11
    #define DBGCBH_Bit12                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit12
    #define DBGCBH_Bit13                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit13
    #define DBGCBH_Bit14                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit14
    #define DBGCBH_Bit15                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit15
    
    #define DBGCBH_Bit8_MASK            1
    #define DBGCBH_Bit9_MASK            2
    #define DBGCBH_Bit10_MASK           4
    #define DBGCBH_Bit11_MASK           8
    #define DBGCBH_Bit12_MASK           16
    #define DBGCBH_Bit13_MASK           32
    #define DBGCBH_Bit14_MASK           64
    #define DBGCBH_Bit15_MASK           128
    

    /*** DBGCBL - Debug Comparator B Low Register; 0x00001813 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Comparator B Low Compare Bit 0 */
        byte Bit1        :1;                                       /* Comparator B Low Compare Bit 1 */
        byte Bit2        :1;                                       /* Comparator B Low Compare Bit 2 */
        byte Bit3        :1;                                       /* Comparator B Low Compare Bit 3 */
        byte Bit4        :1;                                       /* Comparator B Low Compare Bit 4 */
        byte Bit5        :1;                                       /* Comparator B Low Compare Bit 5 */
        byte Bit6        :1;                                       /* Comparator B Low Compare Bit 6 */
        byte Bit7        :1;                                       /* Comparator B Low Compare Bit 7 */
      } Bits;
    } DBGCBLSTR;
    #define DBGCBL                      _DBGCB.Overlap_STR.DBGCBLSTR.Byte
    #define DBGCBL_Bit0                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit0
    #define DBGCBL_Bit1                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit1
    #define DBGCBL_Bit2                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit2
    #define DBGCBL_Bit3                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit3
    #define DBGCBL_Bit4                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit4
    #define DBGCBL_Bit5                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit5
    #define DBGCBL_Bit6                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit6
    #define DBGCBL_Bit7                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit7
    
    #define DBGCBL_Bit0_MASK            1
    #define DBGCBL_Bit1_MASK            2
    #define DBGCBL_Bit2_MASK            4
    #define DBGCBL_Bit3_MASK            8
    #define DBGCBL_Bit4_MASK            16
    #define DBGCBL_Bit5_MASK            32
    #define DBGCBL_Bit6_MASK            64
    #define DBGCBL_Bit7_MASK            128
    
  } Overlap_STR;

} DBGCBSTR;
extern volatile DBGCBSTR _DBGCB @0x00001812;
#define DBGCB                           _DBGCB.Word


/*** DBGCC - Debug Comparator C Register; 0x00001814 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCCH - Debug Comparator C High Register; 0x00001814 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Comparator C High Compare Bit 8 */
        byte Bit9        :1;                                       /* Comparator C High Compare Bit 9 */
        byte Bit10       :1;                                       /* Comparator C High Compare Bit 10 */
        byte Bit11       :1;                                       /* Comparator C High Compare Bit 11 */
        byte Bit12       :1;                                       /* Comparator C High Compare Bit 12 */
        byte Bit13       :1;                                       /* Comparator C High Compare Bit 13 */
        byte Bit14       :1;                                       /* Comparator C High Compare Bit 14 */
        byte Bit15       :1;                                       /* Comparator C High Compare Bit 15 */
      } Bits;
    } DBGCCHSTR;
    #define DBGCCH                      _DBGCC.Overlap_STR.DBGCCHSTR.Byte
    #define DBGCCH_Bit8                 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit8
    #define DBGCCH_Bit9                 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit9
    #define DBGCCH_Bit10                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit10
    #define DBGCCH_Bit11                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit11
    #define DBGCCH_Bit12                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit12
    #define DBGCCH_Bit13                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit13
    #define DBGCCH_Bit14                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit14
    #define DBGCCH_Bit15                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit15
    
    #define DBGCCH_Bit8_MASK            1
    #define DBGCCH_Bit9_MASK            2
    #define DBGCCH_Bit10_MASK           4
    #define DBGCCH_Bit11_MASK           8
    #define DBGCCH_Bit12_MASK           16
    #define DBGCCH_Bit13_MASK           32
    #define DBGCCH_Bit14_MASK           64
    #define DBGCCH_Bit15_MASK           128
    

    /*** DBGCCL - Debug Comparator C Low Register; 0x00001815 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Comparator C Low Compare Bit 0 */
        byte Bit1        :1;                                       /* Comparator C Low Compare Bit 1 */
        byte Bit2        :1;                                       /* Comparator C Low Compare Bit 2 */
        byte Bit3        :1;                                       /* Comparator C Low Compare Bit 3 */
        byte Bit4        :1;                                       /* Comparator C Low Compare Bit 4 */
        byte Bit5        :1;                                       /* Comparator C Low Compare Bit 5 */
        byte Bit6        :1;                                       /* Comparator C Low Compare Bit 6 */
        byte Bit7        :1;                                       /* Comparator C Low Compare Bit 7 */
      } Bits;
    } DBGCCLSTR;
    #define DBGCCL                      _DBGCC.Overlap_STR.DBGCCLSTR.Byte
    #define DBGCCL_Bit0                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit0
    #define DBGCCL_Bit1                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit1
    #define DBGCCL_Bit2                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit2
    #define DBGCCL_Bit3                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit3
    #define DBGCCL_Bit4                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit4
    #define DBGCCL_Bit5                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit5
    #define DBGCCL_Bit6                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit6
    #define DBGCCL_Bit7                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit7
    
    #define DBGCCL_Bit0_MASK            1
    #define DBGCCL_Bit1_MASK            2
    #define DBGCCL_Bit2_MASK            4
    #define DBGCCL_Bit3_MASK            8
    #define DBGCCL_Bit4_MASK            16
    #define DBGCCL_Bit5_MASK            32
    #define DBGCCL_Bit6_MASK            64
    #define DBGCCL_Bit7_MASK            128
    
  } Overlap_STR;

} DBGCCSTR;
extern volatile DBGCCSTR _DBGCC @0x00001814;
#define DBGCC                           _DBGCC.Word


/*** DBGF - Debug FIFO Register; 0x00001816 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGFH - Debug FIFO High Register; 0x00001816 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* FIFO High Data Bit 8 */
        byte Bit9        :1;                                       /* FIFO High Data Bit 9 */
        byte Bit10       :1;                                       /* FIFO High Data Bit 10 */
        byte Bit11       :1;                                       /* FIFO High Data Bit 11 */
        byte Bit12       :1;                                       /* FIFO High Data Bit 12 */
        byte Bit13       :1;                                       /* FIFO High Data Bit 13 */
        byte Bit14       :1;                                       /* FIFO High Data Bit 14 */
        byte Bit15       :1;                                       /* FIFO High Data Bit 15 */
      } Bits;
    } DBGFHSTR;
    #define DBGFH                       _DBGF.Overlap_STR.DBGFHSTR.Byte
    #define DBGFH_Bit8                  _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit8
    #define DBGFH_Bit9                  _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit9
    #define DBGFH_Bit10                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit10
    #define DBGFH_Bit11                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit11
    #define DBGFH_Bit12                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit12
    #define DBGFH_Bit13                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit13
    #define DBGFH_Bit14                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit14
    #define DBGFH_Bit15                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit15
    
    #define DBGFH_Bit8_MASK             1
    #define DBGFH_Bit9_MASK             2
    #define DBGFH_Bit10_MASK            4
    #define DBGFH_Bit11_MASK            8
    #define DBGFH_Bit12_MASK            16
    #define DBGFH_Bit13_MASK            32
    #define DBGFH_Bit14_MASK            64
    #define DBGFH_Bit15_MASK            128
    

    /*** DBGFL - Debug FIFO Low Register; 0x00001817 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* FIFO Low Data Bit 0 */
        byte Bit1        :1;                                       /* FIFO Low Data Bit 1 */
        byte Bit2        :1;                                       /* FIFO Low Data Bit 2 */
        byte Bit3        :1;                                       /* FIFO Low Data Bit 3 */
        byte Bit4        :1;                                       /* FIFO Low Data Bit 4 */
        byte Bit5        :1;                                       /* FIFO Low Data Bit 5 */
        byte Bit6        :1;                                       /* FIFO Low Data Bit 6 */
        byte Bit7        :1;                                       /* FIFO Low Data Bit 7 */
      } Bits;
    } DBGFLSTR;
    #define DBGFL                       _DBGF.Overlap_STR.DBGFLSTR.Byte
    #define DBGFL_Bit0                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit0
    #define DBGFL_Bit1                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit1
    #define DBGFL_Bit2                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit2
    #define DBGFL_Bit3                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit3
    #define DBGFL_Bit4                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit4
    #define DBGFL_Bit5                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit5
    #define DBGFL_Bit6                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit6
    #define DBGFL_Bit7                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit7
    
    #define DBGFL_Bit0_MASK             1
    #define DBGFL_Bit1_MASK             2
    #define DBGFL_Bit2_MASK             4
    #define DBGFL_Bit3_MASK             8
    #define DBGFL_Bit4_MASK             16
    #define DBGFL_Bit5_MASK             32
    #define DBGFL_Bit6_MASK             64
    #define DBGFL_Bit7_MASK             128
    
  } Overlap_STR;

} DBGFSTR;
extern volatile DBGFSTR _DBGF @0x00001816;
#define DBGF                            _DBGF.Word


/*** DBGCAX - Debug Comparator A Extension Register; 0x00001818 ***/
typedef union {
  byte Byte;
  struct {
    byte Bit16       :1;                                       /* omparator A Extended Address Bit 16 Compare Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PAGSEL      :1;                                       /* Comparator A Page Select Bit */
    byte RWA         :1;                                       /* Read/Write Comparator A Value Bit */
    byte RWAEN       :1;                                       /* Read/Write Comparator A Enable Bit */
  } Bits;
} DBGCAXSTR;
extern volatile DBGCAXSTR _DBGCAX @0x00001818;
#define DBGCAX                          _DBGCAX.Byte
#define DBGCAX_Bit16                    _DBGCAX.Bits.Bit16
#define DBGCAX_PAGSEL                   _DBGCAX.Bits.PAGSEL
#define DBGCAX_RWA                      _DBGCAX.Bits.RWA
#define DBGCAX_RWAEN                    _DBGCAX.Bits.RWAEN

#define DBGCAX_Bit16_MASK               1
#define DBGCAX_PAGSEL_MASK              32
#define DBGCAX_RWA_MASK                 64
#define DBGCAX_RWAEN_MASK               128


/*** DBGCBX - Debug Comparator B Extension Register; 0x00001819 ***/
typedef union {
  byte Byte;
  struct {
    byte Bit16       :1;                                       /* omparator B Extended Address Bit 16 Compare Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PAGSEL      :1;                                       /* Comparator B Page Select Bit */
    byte RWB         :1;                                       /* Read/Write Comparator B Value Bit */
    byte RWBEN       :1;                                       /* Read/Write Comparator B Enable Bit */
  } Bits;
} DBGCBXSTR;
extern volatile DBGCBXSTR _DBGCBX @0x00001819;
#define DBGCBX                          _DBGCBX.Byte
#define DBGCBX_Bit16                    _DBGCBX.Bits.Bit16
#define DBGCBX_PAGSEL                   _DBGCBX.Bits.PAGSEL
#define DBGCBX_RWB                      _DBGCBX.Bits.RWB
#define DBGCBX_RWBEN                    _DBGCBX.Bits.RWBEN

#define DBGCBX_Bit16_MASK               1
#define DBGCBX_PAGSEL_MASK              32
#define DBGCBX_RWB_MASK                 64
#define DBGCBX_RWBEN_MASK               128


/*** DBGCCX - Debug Comparator C Extension Register; 0x0000181A ***/
typedef union {
  byte Byte;
  struct {
    byte Bit16       :1;                                       /* omparator C Extended Address Bit 16 Compare Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PAGSEL      :1;                                       /* Comparator C Page Select Bit */
    byte RWC         :1;                                       /* Read/Write Comparator C Value Bit */
    byte RWCEN       :1;                                       /* Read/Write Comparator C Enable Bit */
  } Bits;
} DBGCCXSTR;
extern volatile DBGCCXSTR _DBGCCX @0x0000181A;
#define DBGCCX                          _DBGCCX.Byte
#define DBGCCX_Bit16                    _DBGCCX.Bits.Bit16
#define DBGCCX_PAGSEL                   _DBGCCX.Bits.PAGSEL
#define DBGCCX_RWC                      _DBGCCX.Bits.RWC
#define DBGCCX_RWCEN                    _DBGCCX.Bits.RWCEN

#define DBGCCX_Bit16_MASK               1
#define DBGCCX_PAGSEL_MASK              32
#define DBGCCX_RWC_MASK                 64
#define DBGCCX_RWCEN_MASK               128


/*** DBGFX - Debug FIFO Extended Information Register; 0x0000181B ***/
typedef union {
  byte Byte;
  struct {
    byte Bit16       :1;                                       /* Extended Address Bit 16 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PPACC       :1;                                       /* PPAGE Access Indicator Bit */
  } Bits;
} DBGFXSTR;
extern volatile DBGFXSTR _DBGFX @0x0000181B;
#define DBGFX                           _DBGFX.Byte
#define DBGFX_Bit16                     _DBGFX.Bits.Bit16
#define DBGFX_PPACC                     _DBGFX.Bits.PPACC

#define DBGFX_Bit16_MASK                1
#define DBGFX_PPACC_MASK                128


/*** DBGC - Debug Control Register; 0x0000181C ***/
typedef union {
  byte Byte;
  struct {
    byte LOOP1       :1;                                       /* Select LOOP1 Capture Mode */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte BRKEN       :1;                                       /* Break Enable Bit */
    byte TAG         :1;                                       /* Tag or Force Bit */
    byte ARM         :1;                                       /* Arm Bit */
    byte DBGEN       :1;                                       /* DBG Module Enable Bit */
  } Bits;
} DBGCSTR;
extern volatile DBGCSTR _DBGC @0x0000181C;
#define DBGC                            _DBGC.Byte
#define DBGC_LOOP1                      _DBGC.Bits.LOOP1
#define DBGC_BRKEN                      _DBGC.Bits.BRKEN
#define DBGC_TAG                        _DBGC.Bits.TAG
#define DBGC_ARM                        _DBGC.Bits.ARM
#define DBGC_DBGEN                      _DBGC.Bits.DBGEN

#define DBGC_LOOP1_MASK                 1
#define DBGC_BRKEN_MASK                 16
#define DBGC_TAG_MASK                   32
#define DBGC_ARM_MASK                   64
#define DBGC_DBGEN_MASK                 128


/*** DBGT - Debug Trigger Register; 0x0000181D ***/
typedef union {
  byte Byte;
  struct {
    byte TRG0        :1;                                       /* Trigger Mode Bit 0 */
    byte TRG1        :1;                                       /* Trigger Mode Bit 1 */
    byte TRG2        :1;                                       /* Trigger Mode Bit 2 */
    byte TRG3        :1;                                       /* Trigger Mode Bit 3 */
    byte             :1; 
    byte             :1; 
    byte BEGIN       :1;                                       /* Begin/End Trigger Bit */
    byte TRGSEL      :1;                                       /* Trigger Selection Bit */
  } Bits;
  struct {
    byte grpTRG  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGTSTR;
extern volatile DBGTSTR _DBGT @0x0000181D;
#define DBGT                            _DBGT.Byte
#define DBGT_TRG0                       _DBGT.Bits.TRG0
#define DBGT_TRG1                       _DBGT.Bits.TRG1
#define DBGT_TRG2                       _DBGT.Bits.TRG2
#define DBGT_TRG3                       _DBGT.Bits.TRG3
#define DBGT_BEGIN                      _DBGT.Bits.BEGIN
#define DBGT_TRGSEL                     _DBGT.Bits.TRGSEL
#define DBGT_TRG                        _DBGT.MergedBits.grpTRG

#define DBGT_TRG0_MASK                  1
#define DBGT_TRG1_MASK                  2
#define DBGT_TRG2_MASK                  4
#define DBGT_TRG3_MASK                  8
#define DBGT_BEGIN_MASK                 64
#define DBGT_TRGSEL_MASK                128
#define DBGT_TRG_MASK                   15
#define DBGT_TRG_BITNUM                 0


/*** DBGS - Debug Status Register; 0x0000181E ***/
typedef union {
  byte Byte;
  struct {
    byte ARMF        :1;                                       /* Arm Flag Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte CF          :1;                                       /* Trigger C Match Bit */
    byte BF          :1;                                       /* Trigger B Match Bit */
    byte AF          :1;                                       /* Trigger A Match Bit */
  } Bits;
} DBGSSTR;
extern volatile DBGSSTR _DBGS @0x0000181E;
#define DBGS                            _DBGS.Byte
#define DBGS_ARMF                       _DBGS.Bits.ARMF
#define DBGS_CF                         _DBGS.Bits.CF
#define DBGS_BF                         _DBGS.Bits.BF
#define DBGS_AF                         _DBGS.Bits.AF

#define DBGS_ARMF_MASK                  1
#define DBGS_CF_MASK                    32
#define DBGS_BF_MASK                    64
#define DBGS_AF_MASK                    128


/*** DBGCNT - Debug Count Status Register; 0x0000181F ***/
typedef union {
  byte Byte;
  struct {
    byte CNT0        :1;                                       /* FIFO Valid Count Bits, bit 0 */
    byte CNT1        :1;                                       /* FIFO Valid Count Bits, bit 1 */
    byte CNT2        :1;                                       /* FIFO Valid Count Bits, bit 2 */
    byte CNT3        :1;                                       /* FIFO Valid Count Bits, bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCNT  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGCNTSTR;
extern volatile DBGCNTSTR _DBGCNT @0x0000181F;
#define DBGCNT                          _DBGCNT.Byte
#define DBGCNT_CNT0                     _DBGCNT.Bits.CNT0
#define DBGCNT_CNT1                     _DBGCNT.Bits.CNT1
#define DBGCNT_CNT2                     _DBGCNT.Bits.CNT2
#define DBGCNT_CNT3                     _DBGCNT.Bits.CNT3
#define DBGCNT_CNT                      _DBGCNT.MergedBits.grpCNT

#define DBGCNT_CNT0_MASK                1
#define DBGCNT_CNT1_MASK                2
#define DBGCNT_CNT2_MASK                4
#define DBGCNT_CNT3_MASK                8
#define DBGCNT_CNT_MASK                 15
#define DBGCNT_CNT_BITNUM               0


/*** FCDIV - FLASH Clock Divider Register; 0x00001820 ***/
typedef union {
  byte Byte;
  struct {
    byte DIV0        :1;                                       /* Divisor for FLASH Clock Divider, bit 0 */
    byte DIV1        :1;                                       /* Divisor for FLASH Clock Divider, bit 1 */
    byte DIV2        :1;                                       /* Divisor for FLASH Clock Divider, bit 2 */
    byte DIV3        :1;                                       /* Divisor for FLASH Clock Divider, bit 3 */
    byte DIV4        :1;                                       /* Divisor for FLASH Clock Divider, bit 4 */
    byte DIV5        :1;                                       /* Divisor for FLASH Clock Divider, bit 5 */
    byte PRDIV8      :1;                                       /* Prescale (Divide) FLASH Clock by 8 */
    byte DIVLD       :1;                                       /* Divisor Loaded Status Flag */
  } Bits;
  struct {
    byte grpDIV  :6;
    byte grpPRDIV_8 :1;
    byte         :1;
  } MergedBits;
} FCDIVSTR;
extern volatile FCDIVSTR _FCDIV @0x00001820;
#define FCDIV                           _FCDIV.Byte
#define FCDIV_DIV0                      _FCDIV.Bits.DIV0
#define FCDIV_DIV1                      _FCDIV.Bits.DIV1
#define FCDIV_DIV2                      _FCDIV.Bits.DIV2
#define FCDIV_DIV3                      _FCDIV.Bits.DIV3
#define FCDIV_DIV4                      _FCDIV.Bits.DIV4
#define FCDIV_DIV5                      _FCDIV.Bits.DIV5
#define FCDIV_PRDIV8                    _FCDIV.Bits.PRDIV8
#define FCDIV_DIVLD                     _FCDIV.Bits.DIVLD
#define FCDIV_DIV                       _FCDIV.MergedBits.grpDIV

#define FCDIV_DIV0_MASK                 1
#define FCDIV_DIV1_MASK                 2
#define FCDIV_DIV2_MASK                 4
#define FCDIV_DIV3_MASK                 8
#define FCDIV_DIV4_MASK                 16
#define FCDIV_DIV5_MASK                 32
#define FCDIV_PRDIV8_MASK               64
#define FCDIV_DIVLD_MASK                128
#define FCDIV_DIV_MASK                  63
#define FCDIV_DIV_BITNUM                0


/*** FOPT - Flash Options Register; 0x00001821 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FNORED      :1;                                       /* Vector Redirection Disable */
    byte KEYEN       :1;                                       /* Enable Security Key Writing */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FOPTSTR;
extern volatile FOPTSTR _FOPT @0x00001821;
#define FOPT                            _FOPT.Byte
#define FOPT_SEC0                       _FOPT.Bits.SEC0
#define FOPT_SEC1                       _FOPT.Bits.SEC1
#define FOPT_FNORED                     _FOPT.Bits.FNORED
#define FOPT_KEYEN                      _FOPT.Bits.KEYEN
#define FOPT_SEC                        _FOPT.MergedBits.grpSEC

#define FOPT_SEC0_MASK                  1
#define FOPT_SEC1_MASK                  2
#define FOPT_FNORED_MASK                64
#define FOPT_KEYEN_MASK                 128
#define FOPT_SEC_MASK                   3
#define FOPT_SEC_BITNUM                 0


/*** FCNFG - Flash Configuration Register; 0x00001823 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYACC      :1;                                       /* Enable Security Key Writing */
    byte             :1; 
    byte             :1; 
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @0x00001823;
#define FCNFG                           _FCNFG.Byte
#define FCNFG_KEYACC                    _FCNFG.Bits.KEYACC

#define FCNFG_KEYACC_MASK               32


/*** FPROT - Flash Protection Register; 0x00001824 ***/
typedef union {
  byte Byte;
  struct {
    byte FPDIS       :1;                                       /* Flash Protection Disable */
    byte FPS0        :1;                                       /* Flash Protection Size, bit 0 */
    byte FPS1        :1;                                       /* Flash Protection Size, bit 1 */
    byte FPS2        :1;                                       /* Flash Protection Size, bit 2 */
    byte FPS3        :1;                                       /* Flash Protection Size, bit 3 */
    byte FPS4        :1;                                       /* Flash Protection Size, bit 4 */
    byte FPS5        :1;                                       /* Flash Protection Size, bit 5 */
    byte FPS6        :1;                                       /* Flash Protection Size, bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS  :7;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @0x00001824;
#define FPROT                           _FPROT.Byte
#define FPROT_FPDIS                     _FPROT.Bits.FPDIS
#define FPROT_FPS0                      _FPROT.Bits.FPS0
#define FPROT_FPS1                      _FPROT.Bits.FPS1
#define FPROT_FPS2                      _FPROT.Bits.FPS2
#define FPROT_FPS3                      _FPROT.Bits.FPS3
#define FPROT_FPS4                      _FPROT.Bits.FPS4
#define FPROT_FPS5                      _FPROT.Bits.FPS5
#define FPROT_FPS6                      _FPROT.Bits.FPS6
#define FPROT_FPS                       _FPROT.MergedBits.grpFPS

#define FPROT_FPDIS_MASK                1
#define FPROT_FPS0_MASK                 2
#define FPROT_FPS1_MASK                 4
#define FPROT_FPS2_MASK                 8
#define FPROT_FPS3_MASK                 16
#define FPROT_FPS4_MASK                 32
#define FPROT_FPS5_MASK                 64
#define FPROT_FPS6_MASK                 128
#define FPROT_FPS_MASK                  254
#define FPROT_FPS_BITNUM                1


/*** FSTAT - Flash Status Register; 0x00001825 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte FBLANK      :1;                                       /* FLASH Flag Indicating the Erase Verify Operation Status */
    byte             :1; 
    byte FACCERR     :1;                                       /* FLASH Access Error Flag */
    byte FPVIOL      :1;                                       /* FLASH Protection Violation Flag */
    byte FCCF        :1;                                       /* FLASH Command Complete Interrupt Flag */
    byte FCBEF       :1;                                       /* FLASH Command Buffer Empty Flag */
  } Bits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @0x00001825;
#define FSTAT                           _FSTAT.Byte
#define FSTAT_FBLANK                    _FSTAT.Bits.FBLANK
#define FSTAT_FACCERR                   _FSTAT.Bits.FACCERR
#define FSTAT_FPVIOL                    _FSTAT.Bits.FPVIOL
#define FSTAT_FCCF                      _FSTAT.Bits.FCCF
#define FSTAT_FCBEF                     _FSTAT.Bits.FCBEF

#define FSTAT_FBLANK_MASK               4
#define FSTAT_FACCERR_MASK              16
#define FSTAT_FPVIOL_MASK               32
#define FSTAT_FCCF_MASK                 64
#define FSTAT_FCBEF_MASK                128


/*** FCMD - Flash Command Register; 0x00001826 ***/
typedef union {
  byte Byte;
  struct {
    byte FCMD0       :1;                                       /* Flash Command, bit 0 */
    byte FCMD1       :1;                                       /* Flash Command, bit 1 */
    byte FCMD2       :1;                                       /* Flash Command, bit 2 */
    byte FCMD3       :1;                                       /* Flash Command, bit 3 */
    byte FCMD4       :1;                                       /* Flash Command, bit 4 */
    byte FCMD5       :1;                                       /* Flash Command, bit 5 */
    byte FCMD6       :1;                                       /* Flash Command, bit 6 */
    byte FCMD7       :1;                                       /* Flash Command, bit 7 */
  } Bits;
} FCMDSTR;
extern volatile FCMDSTR _FCMD @0x00001826;
#define FCMD                            _FCMD.Byte
#define FCMD_FCMD0                      _FCMD.Bits.FCMD0
#define FCMD_FCMD1                      _FCMD.Bits.FCMD1
#define FCMD_FCMD2                      _FCMD.Bits.FCMD2
#define FCMD_FCMD3                      _FCMD.Bits.FCMD3
#define FCMD_FCMD4                      _FCMD.Bits.FCMD4
#define FCMD_FCMD5                      _FCMD.Bits.FCMD5
#define FCMD_FCMD6                      _FCMD.Bits.FCMD6
#define FCMD_FCMD7                      _FCMD.Bits.FCMD7

#define FCMD_FCMD0_MASK                 1
#define FCMD_FCMD1_MASK                 2
#define FCMD_FCMD2_MASK                 4
#define FCMD_FCMD3_MASK                 8
#define FCMD_FCMD4_MASK                 16
#define FCMD_FCMD5_MASK                 32
#define FCMD_FCMD6_MASK                 64
#define FCMD_FCMD7_MASK                 128


/*** TODC - TOD Control Register; 0x00001830 ***/
typedef union {
  byte Byte;
  struct {
    byte TODPS0      :1;                                       /* TOD Prescaler Bits, bit 0 */
    byte TODPS1      :1;                                       /* TOD Prescaler Bits, bit 1 */
    byte TODPS2      :1;                                       /* TOD Prescaler Bits, bit 2 */
    byte TODCLKEN    :1;                                       /* TOD Clock Enable */
    byte TODR        :1;                                       /* TOD Reset */
    byte TODCLKS0    :1;                                       /* TOD Clock Source, bit 0 */
    byte TODCLKS1    :1;                                       /* TOD Clock Source, bit 1 */
    byte TODEN       :1;                                       /* Time of Day Enable */
  } Bits;
  struct {
    byte grpTODPS :3;
    byte         :1;
    byte         :1;
    byte grpTODCLKS :2;
    byte         :1;
  } MergedBits;
} TODCSTR;
extern volatile TODCSTR _TODC @0x00001830;
#define TODC                            _TODC.Byte
#define TODC_TODPS0                     _TODC.Bits.TODPS0
#define TODC_TODPS1                     _TODC.Bits.TODPS1
#define TODC_TODPS2                     _TODC.Bits.TODPS2
#define TODC_TODCLKEN                   _TODC.Bits.TODCLKEN
#define TODC_TODR                       _TODC.Bits.TODR
#define TODC_TODCLKS0                   _TODC.Bits.TODCLKS0
#define TODC_TODCLKS1                   _TODC.Bits.TODCLKS1
#define TODC_TODEN                      _TODC.Bits.TODEN
#define TODC_TODPS                      _TODC.MergedBits.grpTODPS
#define TODC_TODCLKS                    _TODC.MergedBits.grpTODCLKS

#define TODC_TODPS0_MASK                1
#define TODC_TODPS1_MASK                2
#define TODC_TODPS2_MASK                4
#define TODC_TODCLKEN_MASK              8
#define TODC_TODR_MASK                  16
#define TODC_TODCLKS0_MASK              32
#define TODC_TODCLKS1_MASK              64
#define TODC_TODEN_MASK                 128
#define TODC_TODPS_MASK                 7
#define TODC_TODPS_BITNUM               0
#define TODC_TODCLKS_MASK               96
#define TODC_TODCLKS_BITNUM             5


/*** TODSC - TOD Status and Control Register; 0x00001831 ***/
typedef union {
  byte Byte;
  struct {
    byte MTCHWC      :1;                                       /* Match Write Complete */
    byte MTCHEN      :1;                                       /* Match Function Enable */
    byte MTCHIE      :1;                                       /* Match Interrupt Enable */
    byte SECIE       :1;                                       /* Second Interrupt Enable */
    byte QSECIE      :1;                                       /* Quarter-Second Interrupt Enable */
    byte MTCHF       :1;                                       /* Match Interrupt Flag */
    byte SECF        :1;                                       /* Second Interrupt Flag */
    byte QSECF       :1;                                       /* Quarter-Second Interrupt Flag */
  } Bits;
} TODSCSTR;
extern volatile TODSCSTR _TODSC @0x00001831;
#define TODSC                           _TODSC.Byte
#define TODSC_MTCHWC                    _TODSC.Bits.MTCHWC
#define TODSC_MTCHEN                    _TODSC.Bits.MTCHEN
#define TODSC_MTCHIE                    _TODSC.Bits.MTCHIE
#define TODSC_SECIE                     _TODSC.Bits.SECIE
#define TODSC_QSECIE                    _TODSC.Bits.QSECIE
#define TODSC_MTCHF                     _TODSC.Bits.MTCHF
#define TODSC_SECF                      _TODSC.Bits.SECF
#define TODSC_QSECF                     _TODSC.Bits.QSECF

#define TODSC_MTCHWC_MASK               1
#define TODSC_MTCHEN_MASK               2
#define TODSC_MTCHIE_MASK               4
#define TODSC_SECIE_MASK                8
#define TODSC_QSECIE_MASK               16
#define TODSC_MTCHF_MASK                32
#define TODSC_SECF_MASK                 64
#define TODSC_QSECF_MASK                128


/*** TODM - TOD Match Register; 0x00001832 ***/
typedef union {
  byte Byte;
  struct {
    byte MQSEC0      :1;                                       /* Match Quarter-Second Bits, bit 0 */
    byte MQSEC1      :1;                                       /* Match Quarter-Second Bits, bit 1 */
    byte TODM0       :1;                                       /* TOD Match Value, bit 0 */
    byte TODM1       :1;                                       /* TOD Match Value, bit 1 */
    byte TODM2       :1;                                       /* TOD Match Value, bit 2 */
    byte TODM3       :1;                                       /* TOD Match Value, bit 3 */
    byte TODM4       :1;                                       /* TOD Match Value, bit 4 */
    byte TODM5       :1;                                       /* TOD Match Value, bit 5 */
  } Bits;
  struct {
    byte grpMQSEC :2;
    byte grpTODM :6;
  } MergedBits;
} TODMSTR;
extern volatile TODMSTR _TODM @0x00001832;
#define TODM                            _TODM.Byte
#define TODM_MQSEC0                     _TODM.Bits.MQSEC0
#define TODM_MQSEC1                     _TODM.Bits.MQSEC1
#define TODM_TODM0                      _TODM.Bits.TODM0
#define TODM_TODM1                      _TODM.Bits.TODM1
#define TODM_TODM2                      _TODM.Bits.TODM2
#define TODM_TODM3                      _TODM.Bits.TODM3
#define TODM_TODM4                      _TODM.Bits.TODM4
#define TODM_TODM5                      _TODM.Bits.TODM5
#define TODM_MQSEC                      _TODM.MergedBits.grpMQSEC
#define TODM_TODM                       _TODM.MergedBits.grpTODM

#define TODM_MQSEC0_MASK                1
#define TODM_MQSEC1_MASK                2
#define TODM_TODM0_MASK                 4
#define TODM_TODM1_MASK                 8
#define TODM_TODM2_MASK                 16
#define TODM_TODM3_MASK                 32
#define TODM_TODM4_MASK                 64
#define TODM_TODM5_MASK                 128
#define TODM_MQSEC_MASK                 3
#define TODM_MQSEC_BITNUM               0
#define TODM_TODM_MASK                  252
#define TODM_TODM_BITNUM                2


/*** TODCNT - TOD Counter Register; 0x00001833 ***/
typedef union {
  byte Byte;
} TODCNTSTR;
extern volatile TODCNTSTR _TODCNT @0x00001833;
#define TODCNT                          _TODCNT.Byte


/*** PTAPE - Port A Pull Enable Register; 0x00001840 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAPE0      :1;                                       /* Internal Pull Enable for Port A Bit 0 */
    byte PTAPE1      :1;                                       /* Internal Pull Enable for Port A Bit 1 */
    byte PTAPE2      :1;                                       /* Internal Pull Enable for Port A Bit 2 */
    byte PTAPE3      :1;                                       /* Internal Pull Enable for Port A Bit 3 */
    byte PTAPE4      :1;                                       /* Internal Pull Enable for Port A Bit 4 */
    byte PTAPE5      :1;                                       /* Internal Pull Enable for Port A Bit 5 */
    byte PTAPE6      :1;                                       /* Internal Pull Enable for Port A Bit 6 */
    byte PTAPE7      :1;                                       /* Internal Pull Enable for Port A Bit 7 */
  } Bits;
} PTAPESTR;
extern volatile PTAPESTR _PTAPE @0x00001840;
#define PTAPE                           _PTAPE.Byte
#define PTAPE_PTAPE0                    _PTAPE.Bits.PTAPE0
#define PTAPE_PTAPE1                    _PTAPE.Bits.PTAPE1
#define PTAPE_PTAPE2                    _PTAPE.Bits.PTAPE2
#define PTAPE_PTAPE3                    _PTAPE.Bits.PTAPE3
#define PTAPE_PTAPE4                    _PTAPE.Bits.PTAPE4
#define PTAPE_PTAPE5                    _PTAPE.Bits.PTAPE5
#define PTAPE_PTAPE6                    _PTAPE.Bits.PTAPE6
#define PTAPE_PTAPE7                    _PTAPE.Bits.PTAPE7

#define PTAPE_PTAPE0_MASK               1
#define PTAPE_PTAPE1_MASK               2
#define PTAPE_PTAPE2_MASK               4
#define PTAPE_PTAPE3_MASK               8
#define PTAPE_PTAPE4_MASK               16
#define PTAPE_PTAPE5_MASK               32
#define PTAPE_PTAPE6_MASK               64
#define PTAPE_PTAPE7_MASK               128


/*** PTASE - Port A Slew Rate Enable Register; 0x00001841 ***/
typedef union {
  byte Byte;
  struct {
    byte PTASE0      :1;                                       /* Output Slew Rate Enable for Port A Bit 0 */
    byte PTASE1      :1;                                       /* Output Slew Rate Enable for Port A Bit 1 */
    byte PTASE2      :1;                                       /* Output Slew Rate Enable for Port A Bit 2 */
    byte PTASE3      :1;                                       /* Output Slew Rate Enable for Port A Bit 3 */
    byte PTASE4      :1;                                       /* Output Slew Rate Enable for Port A Bit 4 */
    byte PTASE5      :1;                                       /* Output Slew Rate Enable for Port A Bit 5 */
    byte PTASE6      :1;                                       /* Output Slew Rate Enable for Port A Bit 6 */
    byte PTASE7      :1;                                       /* Output Slew Rate Enable for Port A Bit 7 */
  } Bits;
} PTASESTR;
extern volatile PTASESTR _PTASE @0x00001841;
#define PTASE                           _PTASE.Byte
#define PTASE_PTASE0                    _PTASE.Bits.PTASE0
#define PTASE_PTASE1                    _PTASE.Bits.PTASE1
#define PTASE_PTASE2                    _PTASE.Bits.PTASE2
#define PTASE_PTASE3                    _PTASE.Bits.PTASE3
#define PTASE_PTASE4                    _PTASE.Bits.PTASE4
#define PTASE_PTASE5                    _PTASE.Bits.PTASE5
#define PTASE_PTASE6                    _PTASE.Bits.PTASE6
#define PTASE_PTASE7                    _PTASE.Bits.PTASE7

#define PTASE_PTASE0_MASK               1
#define PTASE_PTASE1_MASK               2
#define PTASE_PTASE2_MASK               4
#define PTASE_PTASE3_MASK               8
#define PTASE_PTASE4_MASK               16
#define PTASE_PTASE5_MASK               32
#define PTASE_PTASE6_MASK               64
#define PTASE_PTASE7_MASK               128


/*** PTADS - Port A Drive Strength Selection Register; 0x00001842 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADS0      :1;                                       /* Output Drive Strength Selection for Port A Bit 0 */
    byte PTADS1      :1;                                       /* Output Drive Strength Selection for Port A Bit 1 */
    byte PTADS2      :1;                                       /* Output Drive Strength Selection for Port A Bit 2 */
    byte PTADS3      :1;                                       /* Output Drive Strength Selection for Port A Bit 3 */
    byte PTADS4      :1;                                       /* Output Drive Strength Selection for Port A Bit 4 */
    byte PTADS5      :1;                                       /* Output Drive Strength Selection for Port A Bit 5 */
    byte PTADS6      :1;                                       /* Output Drive Strength Selection for Port A Bit 6 */
    byte PTADS7      :1;                                       /* Output Drive Strength Selection for Port A Bit 7 */
  } Bits;
} PTADSSTR;
extern volatile PTADSSTR _PTADS @0x00001842;
#define PTADS                           _PTADS.Byte
#define PTADS_PTADS0                    _PTADS.Bits.PTADS0
#define PTADS_PTADS1                    _PTADS.Bits.PTADS1
#define PTADS_PTADS2                    _PTADS.Bits.PTADS2
#define PTADS_PTADS3                    _PTADS.Bits.PTADS3
#define PTADS_PTADS4                    _PTADS.Bits.PTADS4
#define PTADS_PTADS5                    _PTADS.Bits.PTADS5
#define PTADS_PTADS6                    _PTADS.Bits.PTADS6
#define PTADS_PTADS7                    _PTADS.Bits.PTADS7

#define PTADS_PTADS0_MASK               1
#define PTADS_PTADS1_MASK               2
#define PTADS_PTADS2_MASK               4
#define PTADS_PTADS3_MASK               8
#define PTADS_PTADS4_MASK               16
#define PTADS_PTADS5_MASK               32
#define PTADS_PTADS6_MASK               64
#define PTADS_PTADS7_MASK               128


/*** PTBPE - Port B Pull Enable Register; 0x00001844 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBPE0      :1;                                       /* Internal Pull Enable for Port B Bit 0 */
    byte PTBPE1      :1;                                       /* Internal Pull Enable for Port B Bit 1 */
    byte PTBPE2      :1;                                       /* Internal Pull Enable for Port B Bit 2 */
    byte             :1; 
    byte PTBPE4      :1;                                       /* Internal Pull Enable for Port B Bit 4 */
    byte PTBPE5      :1;                                       /* Internal Pull Enable for Port B Bit 5 */
    byte PTBPE6      :1;                                       /* Internal Pull Enable for Port B Bit 6 */
    byte PTBPE7      :1;                                       /* Internal Pull Enable for Port B Bit 7 */
  } Bits;
  struct {
    byte grpPTBPE :3;
    byte         :1;
    byte grpPTBPE_4 :4;
  } MergedBits;
} PTBPESTR;
extern volatile PTBPESTR _PTBPE @0x00001844;
#define PTBPE                           _PTBPE.Byte
#define PTBPE_PTBPE0                    _PTBPE.Bits.PTBPE0
#define PTBPE_PTBPE1                    _PTBPE.Bits.PTBPE1
#define PTBPE_PTBPE2                    _PTBPE.Bits.PTBPE2
#define PTBPE_PTBPE4                    _PTBPE.Bits.PTBPE4
#define PTBPE_PTBPE5                    _PTBPE.Bits.PTBPE5
#define PTBPE_PTBPE6                    _PTBPE.Bits.PTBPE6
#define PTBPE_PTBPE7                    _PTBPE.Bits.PTBPE7
#define PTBPE_PTBPE                     _PTBPE.MergedBits.grpPTBPE
#define PTBPE_PTBPE_4                   _PTBPE.MergedBits.grpPTBPE_4

#define PTBPE_PTBPE0_MASK               1
#define PTBPE_PTBPE1_MASK               2
#define PTBPE_PTBPE2_MASK               4
#define PTBPE_PTBPE4_MASK               16
#define PTBPE_PTBPE5_MASK               32
#define PTBPE_PTBPE6_MASK               64
#define PTBPE_PTBPE7_MASK               128
#define PTBPE_PTBPE_MASK                7
#define PTBPE_PTBPE_BITNUM              0
#define PTBPE_PTBPE_4_MASK              240
#define PTBPE_PTBPE_4_BITNUM            4


/*** PTBSE - Port B Slew Rate Enable Register; 0x00001845 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBSE0      :1;                                       /* Output Slew Rate Enable for Port B Bit 0 */
    byte PTBSE1      :1;                                       /* Output Slew Rate Enable for Port B Bit 1 */
    byte PTBSE2      :1;                                       /* Output Slew Rate Enable for Port B Bit 2 */
    byte             :1; 
    byte PTBSE4      :1;                                       /* Output Slew Rate Enable for Port B Bit 4 */
    byte PTBSE5      :1;                                       /* Output Slew Rate Enable for Port B Bit 5 */
    byte PTBSE6      :1;                                       /* Output Slew Rate Enable for Port B Bit 6 */
    byte PTBSE7      :1;                                       /* Output Slew Rate Enable for Port B Bit 7 */
  } Bits;
  struct {
    byte grpPTBSE :3;
    byte         :1;
    byte grpPTBSE_4 :4;
  } MergedBits;
} PTBSESTR;
extern volatile PTBSESTR _PTBSE @0x00001845;
#define PTBSE                           _PTBSE.Byte
#define PTBSE_PTBSE0                    _PTBSE.Bits.PTBSE0
#define PTBSE_PTBSE1                    _PTBSE.Bits.PTBSE1
#define PTBSE_PTBSE2                    _PTBSE.Bits.PTBSE2
#define PTBSE_PTBSE4                    _PTBSE.Bits.PTBSE4
#define PTBSE_PTBSE5                    _PTBSE.Bits.PTBSE5
#define PTBSE_PTBSE6                    _PTBSE.Bits.PTBSE6
#define PTBSE_PTBSE7                    _PTBSE.Bits.PTBSE7
#define PTBSE_PTBSE                     _PTBSE.MergedBits.grpPTBSE
#define PTBSE_PTBSE_4                   _PTBSE.MergedBits.grpPTBSE_4

#define PTBSE_PTBSE0_MASK               1
#define PTBSE_PTBSE1_MASK               2
#define PTBSE_PTBSE2_MASK               4
#define PTBSE_PTBSE4_MASK               16
#define PTBSE_PTBSE5_MASK               32
#define PTBSE_PTBSE6_MASK               64
#define PTBSE_PTBSE7_MASK               128
#define PTBSE_PTBSE_MASK                7
#define PTBSE_PTBSE_BITNUM              0
#define PTBSE_PTBSE_4_MASK              240
#define PTBSE_PTBSE_4_BITNUM            4


/*** PTBDS - Port B Drive Strength Selection Register; 0x00001846 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDS0      :1;                                       /* Output Drive Strength Selection for Port B Bit 0 */
    byte PTBDS1      :1;                                       /* Output Drive Strength Selection for Port B Bit 1 */
    byte PTBDS2      :1;                                       /* Output Drive Strength Selection for Port B Bit 2 */
    byte             :1; 
    byte PTBDS4      :1;                                       /* Output Drive Strength Selection for Port B Bit 4 */
    byte PTBDS5      :1;                                       /* Output Drive Strength Selection for Port B Bit 5 */
    byte PTBDS6      :1;                                       /* Output Drive Strength Selection for Port B Bit 6 */
    byte PTBDS7      :1;                                       /* Output Drive Strength Selection for Port B Bit 7 */
  } Bits;
  struct {
    byte grpPTBDS :3;
    byte         :1;
    byte grpPTBDS_4 :4;
  } MergedBits;
} PTBDSSTR;
extern volatile PTBDSSTR _PTBDS @0x00001846;
#define PTBDS                           _PTBDS.Byte
#define PTBDS_PTBDS0                    _PTBDS.Bits.PTBDS0
#define PTBDS_PTBDS1                    _PTBDS.Bits.PTBDS1
#define PTBDS_PTBDS2                    _PTBDS.Bits.PTBDS2
#define PTBDS_PTBDS4                    _PTBDS.Bits.PTBDS4
#define PTBDS_PTBDS5                    _PTBDS.Bits.PTBDS5
#define PTBDS_PTBDS6                    _PTBDS.Bits.PTBDS6
#define PTBDS_PTBDS7                    _PTBDS.Bits.PTBDS7
#define PTBDS_PTBDS                     _PTBDS.MergedBits.grpPTBDS
#define PTBDS_PTBDS_4                   _PTBDS.MergedBits.grpPTBDS_4

#define PTBDS_PTBDS0_MASK               1
#define PTBDS_PTBDS1_MASK               2
#define PTBDS_PTBDS2_MASK               4
#define PTBDS_PTBDS4_MASK               16
#define PTBDS_PTBDS5_MASK               32
#define PTBDS_PTBDS6_MASK               64
#define PTBDS_PTBDS7_MASK               128
#define PTBDS_PTBDS_MASK                7
#define PTBDS_PTBDS_BITNUM              0
#define PTBDS_PTBDS_4_MASK              240
#define PTBDS_PTBDS_4_BITNUM            4


/*** PTCPE - Port C Pull Enable Register; 0x00001848 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCPE0      :1;                                       /* Internal Pull Enable for Port C Bit 0 */
    byte PTCPE1      :1;                                       /* Internal Pull Enable for Port C Bit 1 */
    byte PTCPE2      :1;                                       /* Internal Pull Enable for Port C Bit 2 */
    byte PTCPE3      :1;                                       /* Internal Pull Enable for Port C Bit 3 */
    byte PTCPE4      :1;                                       /* Internal Pull Enable for Port C Bit 4 */
    byte PTCPE5      :1;                                       /* Internal Pull Enable for Port C Bit 5 */
    byte PTCPE6      :1;                                       /* Internal Pull Enable for Port C Bit 6 */
    byte PTCPE7      :1;                                       /* Internal Pull Enable for Port C Bit 7 */
  } Bits;
} PTCPESTR;
extern volatile PTCPESTR _PTCPE @0x00001848;
#define PTCPE                           _PTCPE.Byte
#define PTCPE_PTCPE0                    _PTCPE.Bits.PTCPE0
#define PTCPE_PTCPE1                    _PTCPE.Bits.PTCPE1
#define PTCPE_PTCPE2                    _PTCPE.Bits.PTCPE2
#define PTCPE_PTCPE3                    _PTCPE.Bits.PTCPE3
#define PTCPE_PTCPE4                    _PTCPE.Bits.PTCPE4
#define PTCPE_PTCPE5                    _PTCPE.Bits.PTCPE5
#define PTCPE_PTCPE6                    _PTCPE.Bits.PTCPE6
#define PTCPE_PTCPE7                    _PTCPE.Bits.PTCPE7

#define PTCPE_PTCPE0_MASK               1
#define PTCPE_PTCPE1_MASK               2
#define PTCPE_PTCPE2_MASK               4
#define PTCPE_PTCPE3_MASK               8
#define PTCPE_PTCPE4_MASK               16
#define PTCPE_PTCPE5_MASK               32
#define PTCPE_PTCPE6_MASK               64
#define PTCPE_PTCPE7_MASK               128


/*** PTCSE - Port C Slew Rate Enable Register; 0x00001849 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCSE0      :1;                                       /* Output Slew Rate Enable for Port C Bit 0 */
    byte PTCSE1      :1;                                       /* Output Slew Rate Enable for Port C Bit 1 */
    byte PTCSE2      :1;                                       /* Output Slew Rate Enable for Port C Bit 2 */
    byte PTCSE3      :1;                                       /* Output Slew Rate Enable for Port C Bit 3 */
    byte PTCSE4      :1;                                       /* Output Slew Rate Enable for Port C Bit 4 */
    byte PTCSE5      :1;                                       /* Output Slew Rate Enable for Port C Bit 5 */
    byte PTCSE6      :1;                                       /* Output Slew Rate Enable for Port C Bit 6 */
    byte PTCSE7      :1;                                       /* Output Slew Rate Enable for Port C Bit 7 */
  } Bits;
} PTCSESTR;
extern volatile PTCSESTR _PTCSE @0x00001849;
#define PTCSE                           _PTCSE.Byte
#define PTCSE_PTCSE0                    _PTCSE.Bits.PTCSE0
#define PTCSE_PTCSE1                    _PTCSE.Bits.PTCSE1
#define PTCSE_PTCSE2                    _PTCSE.Bits.PTCSE2
#define PTCSE_PTCSE3                    _PTCSE.Bits.PTCSE3
#define PTCSE_PTCSE4                    _PTCSE.Bits.PTCSE4
#define PTCSE_PTCSE5                    _PTCSE.Bits.PTCSE5
#define PTCSE_PTCSE6                    _PTCSE.Bits.PTCSE6
#define PTCSE_PTCSE7                    _PTCSE.Bits.PTCSE7

#define PTCSE_PTCSE0_MASK               1
#define PTCSE_PTCSE1_MASK               2
#define PTCSE_PTCSE2_MASK               4
#define PTCSE_PTCSE3_MASK               8
#define PTCSE_PTCSE4_MASK               16
#define PTCSE_PTCSE5_MASK               32
#define PTCSE_PTCSE6_MASK               64
#define PTCSE_PTCSE7_MASK               128


/*** PTCDS - Port C Drive Strength Selection Register; 0x0000184A ***/
typedef union {
  byte Byte;
  struct {
    byte PTCDS0      :1;                                       /* Output Drive Strength Selection for Port C Bit 0 */
    byte PTCDS1      :1;                                       /* Output Drive Strength Selection for Port C Bit 1 */
    byte PTCDS2      :1;                                       /* Output Drive Strength Selection for Port C Bit 2 */
    byte PTCDS3      :1;                                       /* Output Drive Strength Selection for Port C Bit 3 */
    byte PTCDS4      :1;                                       /* Output Drive Strength Selection for Port C Bit 4 */
    byte PTCDS5      :1;                                       /* Output Drive Strength Selection for Port C Bit 5 */
    byte PTCDS6      :1;                                       /* Output Drive Strength Selection for Port C Bit 6 */
    byte PTCDS7      :1;                                       /* Output Drive Strength Selection for Port C Bit 7 */
  } Bits;
} PTCDSSTR;
extern volatile PTCDSSTR _PTCDS @0x0000184A;
#define PTCDS                           _PTCDS.Byte
#define PTCDS_PTCDS0                    _PTCDS.Bits.PTCDS0
#define PTCDS_PTCDS1                    _PTCDS.Bits.PTCDS1
#define PTCDS_PTCDS2                    _PTCDS.Bits.PTCDS2
#define PTCDS_PTCDS3                    _PTCDS.Bits.PTCDS3
#define PTCDS_PTCDS4                    _PTCDS.Bits.PTCDS4
#define PTCDS_PTCDS5                    _PTCDS.Bits.PTCDS5
#define PTCDS_PTCDS6                    _PTCDS.Bits.PTCDS6
#define PTCDS_PTCDS7                    _PTCDS.Bits.PTCDS7

#define PTCDS_PTCDS0_MASK               1
#define PTCDS_PTCDS1_MASK               2
#define PTCDS_PTCDS2_MASK               4
#define PTCDS_PTCDS3_MASK               8
#define PTCDS_PTCDS4_MASK               16
#define PTCDS_PTCDS5_MASK               32
#define PTCDS_PTCDS6_MASK               64
#define PTCDS_PTCDS7_MASK               128


/*** PTDPE - Port D Pull Enable Register; 0x0000184C ***/
typedef union {
  byte Byte;
  struct {
    byte PTDPE0      :1;                                       /* Internal Pull Enable for Port D Bit 0 */
    byte PTDPE1      :1;                                       /* Internal Pull Enable for Port D Bit 1 */
    byte PTDPE2      :1;                                       /* Internal Pull Enable for Port D Bit 2 */
    byte PTDPE3      :1;                                       /* Internal Pull Enable for Port D Bit 3 */
    byte PTDPE4      :1;                                       /* Internal Pull Enable for Port D Bit 4 */
    byte PTDPE5      :1;                                       /* Internal Pull Enable for Port D Bit 5 */
    byte PTDPE6      :1;                                       /* Internal Pull Enable for Port D Bit 6 */
    byte PTDPE7      :1;                                       /* Internal Pull Enable for Port D Bit 7 */
  } Bits;
} PTDPESTR;
extern volatile PTDPESTR _PTDPE @0x0000184C;
#define PTDPE                           _PTDPE.Byte
#define PTDPE_PTDPE0                    _PTDPE.Bits.PTDPE0
#define PTDPE_PTDPE1                    _PTDPE.Bits.PTDPE1
#define PTDPE_PTDPE2                    _PTDPE.Bits.PTDPE2
#define PTDPE_PTDPE3                    _PTDPE.Bits.PTDPE3
#define PTDPE_PTDPE4                    _PTDPE.Bits.PTDPE4
#define PTDPE_PTDPE5                    _PTDPE.Bits.PTDPE5
#define PTDPE_PTDPE6                    _PTDPE.Bits.PTDPE6
#define PTDPE_PTDPE7                    _PTDPE.Bits.PTDPE7

#define PTDPE_PTDPE0_MASK               1
#define PTDPE_PTDPE1_MASK               2
#define PTDPE_PTDPE2_MASK               4
#define PTDPE_PTDPE3_MASK               8
#define PTDPE_PTDPE4_MASK               16
#define PTDPE_PTDPE5_MASK               32
#define PTDPE_PTDPE6_MASK               64
#define PTDPE_PTDPE7_MASK               128


/*** PTDSE - Port D Slew Rate Enable Register; 0x0000184D ***/
typedef union {
  byte Byte;
  struct {
    byte PTDSE0      :1;                                       /* Output Slew Rate Enable for Port D Bit 0 */
    byte PTDSE1      :1;                                       /* Output Slew Rate Enable for Port D Bit 1 */
    byte PTDSE2      :1;                                       /* Output Slew Rate Enable for Port D Bit 2 */
    byte PTDSE3      :1;                                       /* Output Slew Rate Enable for Port D Bit 3 */
    byte PTDSE4      :1;                                       /* Output Slew Rate Enable for Port D Bit 4 */
    byte PTDSE5      :1;                                       /* Output Slew Rate Enable for Port D Bit 5 */
    byte PTDSE6      :1;                                       /* Output Slew Rate Enable for Port D Bit 6 */
    byte PTDSE7      :1;                                       /* Output Slew Rate Enable for Port D Bit 7 */
  } Bits;
} PTDSESTR;
extern volatile PTDSESTR _PTDSE @0x0000184D;
#define PTDSE                           _PTDSE.Byte
#define PTDSE_PTDSE0                    _PTDSE.Bits.PTDSE0
#define PTDSE_PTDSE1                    _PTDSE.Bits.PTDSE1
#define PTDSE_PTDSE2                    _PTDSE.Bits.PTDSE2
#define PTDSE_PTDSE3                    _PTDSE.Bits.PTDSE3
#define PTDSE_PTDSE4                    _PTDSE.Bits.PTDSE4
#define PTDSE_PTDSE5                    _PTDSE.Bits.PTDSE5
#define PTDSE_PTDSE6                    _PTDSE.Bits.PTDSE6
#define PTDSE_PTDSE7                    _PTDSE.Bits.PTDSE7

#define PTDSE_PTDSE0_MASK               1
#define PTDSE_PTDSE1_MASK               2
#define PTDSE_PTDSE2_MASK               4
#define PTDSE_PTDSE3_MASK               8
#define PTDSE_PTDSE4_MASK               16
#define PTDSE_PTDSE5_MASK               32
#define PTDSE_PTDSE6_MASK               64
#define PTDSE_PTDSE7_MASK               128


/*** PTDDS - Port D Drive Strength Selection Register; 0x0000184E ***/
typedef union {
  byte Byte;
  struct {
    byte PTDDS0      :1;                                       /* Output Drive Strength Selection for Port D Bit 0 */
    byte PTDDS1      :1;                                       /* Output Drive Strength Selection for Port D Bit 1 */
    byte PTDDS2      :1;                                       /* Output Drive Strength Selection for Port D Bit 2 */
    byte PTDDS3      :1;                                       /* Output Drive Strength Selection for Port D Bit 3 */
    byte PTDDS4      :1;                                       /* Output Drive Strength Selection for Port D Bit 4 */
    byte PTDDS5      :1;                                       /* Output Drive Strength Selection for Port D Bit 5 */
    byte PTDDS6      :1;                                       /* Output Drive Strength Selection for Port D Bit 6 */
    byte PTDDS7      :1;                                       /* Output Drive Strength Selection for Port D Bit 7 */
  } Bits;
} PTDDSSTR;
extern volatile PTDDSSTR _PTDDS @0x0000184E;
#define PTDDS                           _PTDDS.Byte
#define PTDDS_PTDDS0                    _PTDDS.Bits.PTDDS0
#define PTDDS_PTDDS1                    _PTDDS.Bits.PTDDS1
#define PTDDS_PTDDS2                    _PTDDS.Bits.PTDDS2
#define PTDDS_PTDDS3                    _PTDDS.Bits.PTDDS3
#define PTDDS_PTDDS4                    _PTDDS.Bits.PTDDS4
#define PTDDS_PTDDS5                    _PTDDS.Bits.PTDDS5
#define PTDDS_PTDDS6                    _PTDDS.Bits.PTDDS6
#define PTDDS_PTDDS7                    _PTDDS.Bits.PTDDS7

#define PTDDS_PTDDS0_MASK               1
#define PTDDS_PTDDS1_MASK               2
#define PTDDS_PTDDS2_MASK               4
#define PTDDS_PTDDS3_MASK               8
#define PTDDS_PTDDS4_MASK               16
#define PTDDS_PTDDS5_MASK               32
#define PTDDS_PTDDS6_MASK               64
#define PTDDS_PTDDS7_MASK               128


/*** PTEPE - Port E Pull Enable Register; 0x00001850 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEPE0      :1;                                       /* Internal Pull Enable for Port E Bit 0 */
    byte PTEPE1      :1;                                       /* Internal Pull Enable for Port E Bit 1 */
    byte PTEPE2      :1;                                       /* Internal Pull Enable for Port E Bit 2 */
    byte PTEPE3      :1;                                       /* Internal Pull Enable for Port E Bit 3 */
    byte PTEPE4      :1;                                       /* Internal Pull Enable for Port E Bit 4 */
    byte PTEPE5      :1;                                       /* Internal Pull Enable for Port E Bit 5 */
    byte PTEPE6      :1;                                       /* Internal Pull Enable for Port E Bit 6 */
    byte PTEPE7      :1;                                       /* Internal Pull Enable for Port E Bit 7 */
  } Bits;
} PTEPESTR;
extern volatile PTEPESTR _PTEPE @0x00001850;
#define PTEPE                           _PTEPE.Byte
#define PTEPE_PTEPE0                    _PTEPE.Bits.PTEPE0
#define PTEPE_PTEPE1                    _PTEPE.Bits.PTEPE1
#define PTEPE_PTEPE2                    _PTEPE.Bits.PTEPE2
#define PTEPE_PTEPE3                    _PTEPE.Bits.PTEPE3
#define PTEPE_PTEPE4                    _PTEPE.Bits.PTEPE4
#define PTEPE_PTEPE5                    _PTEPE.Bits.PTEPE5
#define PTEPE_PTEPE6                    _PTEPE.Bits.PTEPE6
#define PTEPE_PTEPE7                    _PTEPE.Bits.PTEPE7

#define PTEPE_PTEPE0_MASK               1
#define PTEPE_PTEPE1_MASK               2
#define PTEPE_PTEPE2_MASK               4
#define PTEPE_PTEPE3_MASK               8
#define PTEPE_PTEPE4_MASK               16
#define PTEPE_PTEPE5_MASK               32
#define PTEPE_PTEPE6_MASK               64
#define PTEPE_PTEPE7_MASK               128


/*** PTESE - Port E Slew Rate Enable Register; 0x00001851 ***/
typedef union {
  byte Byte;
  struct {
    byte PTESE0      :1;                                       /* Output Slew Rate Enable for Port E Bit 0 */
    byte PTESE1      :1;                                       /* Output Slew Rate Enable for Port E Bit 1 */
    byte PTESE2      :1;                                       /* Output Slew Rate Enable for Port E Bit 2 */
    byte PTESE3      :1;                                       /* Output Slew Rate Enable for Port E Bit 3 */
    byte PTESE4      :1;                                       /* Output Slew Rate Enable for Port E Bit 4 */
    byte PTESE5      :1;                                       /* Output Slew Rate Enable for Port E Bit 5 */
    byte PTESE6      :1;                                       /* Output Slew Rate Enable for Port E Bit 6 */
    byte PTESE7      :1;                                       /* Output Slew Rate Enable for Port E Bit 7 */
  } Bits;
} PTESESTR;
extern volatile PTESESTR _PTESE @0x00001851;
#define PTESE                           _PTESE.Byte
#define PTESE_PTESE0                    _PTESE.Bits.PTESE0
#define PTESE_PTESE1                    _PTESE.Bits.PTESE1
#define PTESE_PTESE2                    _PTESE.Bits.PTESE2
#define PTESE_PTESE3                    _PTESE.Bits.PTESE3
#define PTESE_PTESE4                    _PTESE.Bits.PTESE4
#define PTESE_PTESE5                    _PTESE.Bits.PTESE5
#define PTESE_PTESE6                    _PTESE.Bits.PTESE6
#define PTESE_PTESE7                    _PTESE.Bits.PTESE7

#define PTESE_PTESE0_MASK               1
#define PTESE_PTESE1_MASK               2
#define PTESE_PTESE2_MASK               4
#define PTESE_PTESE3_MASK               8
#define PTESE_PTESE4_MASK               16
#define PTESE_PTESE5_MASK               32
#define PTESE_PTESE6_MASK               64
#define PTESE_PTESE7_MASK               128


/*** PTEDS - Port E Drive Strength Selection Register; 0x00001852 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEDS0      :1;                                       /* Output Drive Strength Selection for Port E Bit 0 */
    byte PTEDS1      :1;                                       /* Output Drive Strength Selection for Port E Bit 1 */
    byte PTEDS2      :1;                                       /* Output Drive Strength Selection for Port E Bit 2 */
    byte PTEDS3      :1;                                       /* Output Drive Strength Selection for Port E Bit 3 */
    byte PTEDS4      :1;                                       /* Output Drive Strength Selection for Port E Bit 4 */
    byte PTEDS5      :1;                                       /* Output Drive Strength Selection for Port E Bit 5 */
    byte PTEDS6      :1;                                       /* Output Drive Strength Selection for Port E Bit 6 */
    byte PTEDS7      :1;                                       /* Output Drive Strength Selection for Port E Bit 7 */
  } Bits;
} PTEDSSTR;
extern volatile PTEDSSTR _PTEDS @0x00001852;
#define PTEDS                           _PTEDS.Byte
#define PTEDS_PTEDS0                    _PTEDS.Bits.PTEDS0
#define PTEDS_PTEDS1                    _PTEDS.Bits.PTEDS1
#define PTEDS_PTEDS2                    _PTEDS.Bits.PTEDS2
#define PTEDS_PTEDS3                    _PTEDS.Bits.PTEDS3
#define PTEDS_PTEDS4                    _PTEDS.Bits.PTEDS4
#define PTEDS_PTEDS5                    _PTEDS.Bits.PTEDS5
#define PTEDS_PTEDS6                    _PTEDS.Bits.PTEDS6
#define PTEDS_PTEDS7                    _PTEDS.Bits.PTEDS7

#define PTEDS_PTEDS0_MASK               1
#define PTEDS_PTEDS1_MASK               2
#define PTEDS_PTEDS2_MASK               4
#define PTEDS_PTEDS3_MASK               8
#define PTEDS_PTEDS4_MASK               16
#define PTEDS_PTEDS5_MASK               32
#define PTEDS_PTEDS6_MASK               64
#define PTEDS_PTEDS7_MASK               128


/*** SCI2BD - SCI2 Baud Rate Register; 0x00001858 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI2BDH - SCI2 Baud Rate Register High; 0x00001858 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
        byte SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
        byte SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
        byte SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
        byte SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
        byte             :1; 
        byte RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
        byte LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI2BDHSTR;
    #define SCI2BDH                     _SCI2BD.Overlap_STR.SCI2BDHSTR.Byte
    #define SCI2BDH_SBR8                _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR8
    #define SCI2BDH_SBR9                _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR9
    #define SCI2BDH_SBR10               _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR10
    #define SCI2BDH_SBR11               _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR11
    #define SCI2BDH_SBR12               _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR12
    #define SCI2BDH_RXEDGIE             _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.RXEDGIE
    #define SCI2BDH_LBKDIE              _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.LBKDIE
    #define SCI2BDH_SBR_8               _SCI2BD.Overlap_STR.SCI2BDHSTR.MergedBits.grpSBR_8
    #define SCI2BDH_SBR                 SCI2BDH_SBR_8
    
    #define SCI2BDH_SBR8_MASK           1
    #define SCI2BDH_SBR9_MASK           2
    #define SCI2BDH_SBR10_MASK          4
    #define SCI2BDH_SBR11_MASK          8
    #define SCI2BDH_SBR12_MASK          16
    #define SCI2BDH_RXEDGIE_MASK        64
    #define SCI2BDH_LBKDIE_MASK         128
    #define SCI2BDH_SBR_8_MASK          31
    #define SCI2BDH_SBR_8_BITNUM        0
    

    /*** SCI2BDL - SCI2 Baud Rate Register Low; 0x00001859 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
        byte SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
        byte SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
        byte SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
      } Bits;
    } SCI2BDLSTR;
    #define SCI2BDL                     _SCI2BD.Overlap_STR.SCI2BDLSTR.Byte
    #define SCI2BDL_SBR0                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR0
    #define SCI2BDL_SBR1                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR1
    #define SCI2BDL_SBR2                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR2
    #define SCI2BDL_SBR3                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR3
    #define SCI2BDL_SBR4                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR4
    #define SCI2BDL_SBR5                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR5
    #define SCI2BDL_SBR6                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR6
    #define SCI2BDL_SBR7                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR7
    
    #define SCI2BDL_SBR0_MASK           1
    #define SCI2BDL_SBR1_MASK           2
    #define SCI2BDL_SBR2_MASK           4
    #define SCI2BDL_SBR3_MASK           8
    #define SCI2BDL_SBR4_MASK           16
    #define SCI2BDL_SBR5_MASK           32
    #define SCI2BDL_SBR6_MASK           64
    #define SCI2BDL_SBR7_MASK           128
    
  } Overlap_STR;

} SCI2BDSTR;
extern volatile SCI2BDSTR _SCI2BD @0x00001858;
#define SCI2BD                          _SCI2BD.Word


/*** SCI2C1 - SCI2 Control Register 1; 0x0000185A ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type */
    byte PE          :1;                                       /* Parity Enable */
    byte ILT         :1;                                       /* Idle Line Type Select */
    byte WAKE        :1;                                       /* Receiver Wakeup Method Select */
    byte M           :1;                                       /* 9-Bit or 8-Bit Mode Select */
    byte RSRC        :1;                                       /* Receiver Source Select */
    byte SCISWAI     :1;                                       /* SCI Stops in Wait Mode */
    byte LOOPS       :1;                                       /* Loop Mode Select */
  } Bits;
} SCI2C1STR;
extern volatile SCI2C1STR _SCI2C1 @0x0000185A;
#define SCI2C1                          _SCI2C1.Byte
#define SCI2C1_PT                       _SCI2C1.Bits.PT
#define SCI2C1_PE                       _SCI2C1.Bits.PE
#define SCI2C1_ILT                      _SCI2C1.Bits.ILT
#define SCI2C1_WAKE                     _SCI2C1.Bits.WAKE
#define SCI2C1_M                        _SCI2C1.Bits.M
#define SCI2C1_RSRC                     _SCI2C1.Bits.RSRC
#define SCI2C1_SCISWAI                  _SCI2C1.Bits.SCISWAI
#define SCI2C1_LOOPS                    _SCI2C1.Bits.LOOPS

#define SCI2C1_PT_MASK                  1
#define SCI2C1_PE_MASK                  2
#define SCI2C1_ILT_MASK                 4
#define SCI2C1_WAKE_MASK                8
#define SCI2C1_M_MASK                   16
#define SCI2C1_RSRC_MASK                32
#define SCI2C1_SCISWAI_MASK             64
#define SCI2C1_LOOPS_MASK               128


/*** SCI2C2 - SCI2 Control Register 2; 0x0000185B ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break */
    byte RWU         :1;                                       /* Receiver Wakeup Control */
    byte RE          :1;                                       /* Receiver Enable */
    byte TE          :1;                                       /* Transmitter Enable */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable (for IDLE) */
    byte RIE         :1;                                       /* Receiver Interrupt Enable (for RDRF) */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable (for TC) */
    byte TIE         :1;                                       /* Transmit Interrupt Enable (for TDRE) */
  } Bits;
} SCI2C2STR;
extern volatile SCI2C2STR _SCI2C2 @0x0000185B;
#define SCI2C2                          _SCI2C2.Byte
#define SCI2C2_SBK                      _SCI2C2.Bits.SBK
#define SCI2C2_RWU                      _SCI2C2.Bits.RWU
#define SCI2C2_RE                       _SCI2C2.Bits.RE
#define SCI2C2_TE                       _SCI2C2.Bits.TE
#define SCI2C2_ILIE                     _SCI2C2.Bits.ILIE
#define SCI2C2_RIE                      _SCI2C2.Bits.RIE
#define SCI2C2_TCIE                     _SCI2C2.Bits.TCIE
#define SCI2C2_TIE                      _SCI2C2.Bits.TIE

#define SCI2C2_SBK_MASK                 1
#define SCI2C2_RWU_MASK                 2
#define SCI2C2_RE_MASK                  4
#define SCI2C2_TE_MASK                  8
#define SCI2C2_ILIE_MASK                16
#define SCI2C2_RIE_MASK                 32
#define SCI2C2_TCIE_MASK                64
#define SCI2C2_TIE_MASK                 128


/*** SCI2S1 - SCI2 Status Register 1; 0x0000185C ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Receiver Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmission Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI2S1STR;
extern volatile SCI2S1STR _SCI2S1 @0x0000185C;
#define SCI2S1                          _SCI2S1.Byte
#define SCI2S1_PF                       _SCI2S1.Bits.PF
#define SCI2S1_FE                       _SCI2S1.Bits.FE
#define SCI2S1_NF                       _SCI2S1.Bits.NF
#define SCI2S1_OR                       _SCI2S1.Bits.OR
#define SCI2S1_IDLE                     _SCI2S1.Bits.IDLE
#define SCI2S1_RDRF                     _SCI2S1.Bits.RDRF
#define SCI2S1_TC                       _SCI2S1.Bits.TC
#define SCI2S1_TDRE                     _SCI2S1.Bits.TDRE

#define SCI2S1_PF_MASK                  1
#define SCI2S1_FE_MASK                  2
#define SCI2S1_NF_MASK                  4
#define SCI2S1_OR_MASK                  8
#define SCI2S1_IDLE_MASK                16
#define SCI2S1_RDRF_MASK                32
#define SCI2S1_TC_MASK                  64
#define SCI2S1_TDRE_MASK                128


/*** SCI2S2 - SCI2 Status Register 2; 0x0000185D ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte LBKDE       :1;                                       /* LIN Break Detection Enable */
    byte BRK13       :1;                                       /* Break Character Generation Length */
    byte RWUID       :1;                                       /* Receive Wake Up Idle Detect */
    byte RXINV       :1;                                       /* Receive Data Inversion */
    byte             :1; 
    byte RXEDGIF     :1;                                       /* RxD Pin Active Edge Interrupt Flag */
    byte LBKDIF      :1;                                       /* LIN Break Detect Interrupt Flag */
  } Bits;
} SCI2S2STR;
extern volatile SCI2S2STR _SCI2S2 @0x0000185D;
#define SCI2S2                          _SCI2S2.Byte
#define SCI2S2_RAF                      _SCI2S2.Bits.RAF
#define SCI2S2_LBKDE                    _SCI2S2.Bits.LBKDE
#define SCI2S2_BRK13                    _SCI2S2.Bits.BRK13
#define SCI2S2_RWUID                    _SCI2S2.Bits.RWUID
#define SCI2S2_RXINV                    _SCI2S2.Bits.RXINV
#define SCI2S2_RXEDGIF                  _SCI2S2.Bits.RXEDGIF
#define SCI2S2_LBKDIF                   _SCI2S2.Bits.LBKDIF

#define SCI2S2_RAF_MASK                 1
#define SCI2S2_LBKDE_MASK               2
#define SCI2S2_BRK13_MASK               4
#define SCI2S2_RWUID_MASK               8
#define SCI2S2_RXINV_MASK               16
#define SCI2S2_RXEDGIF_MASK             64
#define SCI2S2_LBKDIF_MASK              128


/*** SCI2C3 - SCI2 Control Register 3; 0x0000185E ***/
typedef union {
  byte Byte;
  struct {
    byte PEIE        :1;                                       /* Parity Error Interrupt Enable */
    byte FEIE        :1;                                       /* Framing Error Interrupt Enable */
    byte NEIE        :1;                                       /* Noise Error Interrupt Enable */
    byte ORIE        :1;                                       /* Overrun Interrupt Enable */
    byte TXINV       :1;                                       /* Transmit Data Inversion */
    byte TXDIR       :1;                                       /* TxD Pin Direction in Single-Wire Mode */
    byte T8          :1;                                       /* Ninth Data Bit for Transmitter */
    byte R8          :1;                                       /* Ninth Data Bit for Receiver */
  } Bits;
} SCI2C3STR;
extern volatile SCI2C3STR _SCI2C3 @0x0000185E;
#define SCI2C3                          _SCI2C3.Byte
#define SCI2C3_PEIE                     _SCI2C3.Bits.PEIE
#define SCI2C3_FEIE                     _SCI2C3.Bits.FEIE
#define SCI2C3_NEIE                     _SCI2C3.Bits.NEIE
#define SCI2C3_ORIE                     _SCI2C3.Bits.ORIE
#define SCI2C3_TXINV                    _SCI2C3.Bits.TXINV
#define SCI2C3_TXDIR                    _SCI2C3.Bits.TXDIR
#define SCI2C3_T8                       _SCI2C3.Bits.T8
#define SCI2C3_R8                       _SCI2C3.Bits.R8

#define SCI2C3_PEIE_MASK                1
#define SCI2C3_FEIE_MASK                2
#define SCI2C3_NEIE_MASK                4
#define SCI2C3_ORIE_MASK                8
#define SCI2C3_TXINV_MASK               16
#define SCI2C3_TXDIR_MASK               32
#define SCI2C3_T8_MASK                  64
#define SCI2C3_R8_MASK                  128


/*** SCI2D - SCI2 Data Register; 0x0000185F ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Receive/Transmit Data Bit 0 */
    byte R1_T1       :1;                                       /* Receive/Transmit Data Bit 1 */
    byte R2_T2       :1;                                       /* Receive/Transmit Data Bit 2 */
    byte R3_T3       :1;                                       /* Receive/Transmit Data Bit 3 */
    byte R4_T4       :1;                                       /* Receive/Transmit Data Bit 4 */
    byte R5_T5       :1;                                       /* Receive/Transmit Data Bit 5 */
    byte R6_T6       :1;                                       /* Receive/Transmit Data Bit 6 */
    byte R7_T7       :1;                                       /* Receive/Transmit Data Bit 7 */
  } Bits;
} SCI2DSTR;
extern volatile SCI2DSTR _SCI2D @0x0000185F;
#define SCI2D                           _SCI2D.Byte
#define SCI2D_R0_T0                     _SCI2D.Bits.R0_T0
#define SCI2D_R1_T1                     _SCI2D.Bits.R1_T1
#define SCI2D_R2_T2                     _SCI2D.Bits.R2_T2
#define SCI2D_R3_T3                     _SCI2D.Bits.R3_T3
#define SCI2D_R4_T4                     _SCI2D.Bits.R4_T4
#define SCI2D_R5_T5                     _SCI2D.Bits.R5_T5
#define SCI2D_R6_T6                     _SCI2D.Bits.R6_T6
#define SCI2D_R7_T7                     _SCI2D.Bits.R7_T7

#define SCI2D_R0_T0_MASK                1
#define SCI2D_R1_T1_MASK                2
#define SCI2D_R2_T2_MASK                4
#define SCI2D_R3_T3_MASK                8
#define SCI2D_R4_T4_MASK                16
#define SCI2D_R5_T5_MASK                32
#define SCI2D_R6_T6_MASK                64
#define SCI2D_R7_T7_MASK                128


/*** IICA - IIC Address Register; 0x00001860 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte AD1         :1;                                       /* Slave Address Bit 1 */
    byte AD2         :1;                                       /* Slave Address Bit 2 */
    byte AD3         :1;                                       /* Slave Address Bit 3 */
    byte AD4         :1;                                       /* Slave Address Bit 4 */
    byte AD5         :1;                                       /* Slave Address Bit 5 */
    byte AD6         :1;                                       /* Slave Address Bit 6 */
    byte AD7         :1;                                       /* Slave Address Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpAD_1 :7;
  } MergedBits;
} IICASTR;
extern volatile IICASTR _IICA @0x00001860;
#define IICA                            _IICA.Byte
#define IICA_AD1                        _IICA.Bits.AD1
#define IICA_AD2                        _IICA.Bits.AD2
#define IICA_AD3                        _IICA.Bits.AD3
#define IICA_AD4                        _IICA.Bits.AD4
#define IICA_AD5                        _IICA.Bits.AD5
#define IICA_AD6                        _IICA.Bits.AD6
#define IICA_AD7                        _IICA.Bits.AD7
#define IICA_AD_1                       _IICA.MergedBits.grpAD_1
#define IICA_AD                         IICA_AD_1

#define IICA_AD1_MASK                   2
#define IICA_AD2_MASK                   4
#define IICA_AD3_MASK                   8
#define IICA_AD4_MASK                   16
#define IICA_AD5_MASK                   32
#define IICA_AD6_MASK                   64
#define IICA_AD7_MASK                   128
#define IICA_AD_1_MASK                  254
#define IICA_AD_1_BITNUM                1


/*** IICF - IIC Frequency Divider Register; 0x00001861 ***/
typedef union {
  byte Byte;
  struct {
    byte ICR0        :1;                                       /* IIC Clock Rate Bit 0 */
    byte ICR1        :1;                                       /* IIC Clock Rate Bit 1 */
    byte ICR2        :1;                                       /* IIC Clock Rate Bit 2 */
    byte ICR3        :1;                                       /* IIC Clock Rate Bit 3 */
    byte ICR4        :1;                                       /* IIC Clock Rate Bit 4 */
    byte ICR5        :1;                                       /* IIC Clock Rate Bit 5 */
    byte MULT0       :1;                                       /* Multiplier Factor Bit 0 */
    byte MULT1       :1;                                       /* Multiplier Factor Bit 1 */
  } Bits;
  struct {
    byte grpICR  :6;
    byte grpMULT :2;
  } MergedBits;
} IICFSTR;
extern volatile IICFSTR _IICF @0x00001861;
#define IICF                            _IICF.Byte
#define IICF_ICR0                       _IICF.Bits.ICR0
#define IICF_ICR1                       _IICF.Bits.ICR1
#define IICF_ICR2                       _IICF.Bits.ICR2
#define IICF_ICR3                       _IICF.Bits.ICR3
#define IICF_ICR4                       _IICF.Bits.ICR4
#define IICF_ICR5                       _IICF.Bits.ICR5
#define IICF_MULT0                      _IICF.Bits.MULT0
#define IICF_MULT1                      _IICF.Bits.MULT1
#define IICF_ICR                        _IICF.MergedBits.grpICR
#define IICF_MULT                       _IICF.MergedBits.grpMULT

#define IICF_ICR0_MASK                  1
#define IICF_ICR1_MASK                  2
#define IICF_ICR2_MASK                  4
#define IICF_ICR3_MASK                  8
#define IICF_ICR4_MASK                  16
#define IICF_ICR5_MASK                  32
#define IICF_MULT0_MASK                 64
#define IICF_MULT1_MASK                 128
#define IICF_ICR_MASK                   63
#define IICF_ICR_BITNUM                 0
#define IICF_MULT_MASK                  192
#define IICF_MULT_BITNUM                6


/*** IICC1 - IIC Control Register 1; 0x00001862 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** IICC1 - IIC Control Register 1; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte             :1; 
        byte RSTA        :1;                                       /* Repeat START */
        byte TXAK        :1;                                       /* Transmit Acknowledge Enable */
        byte TX          :1;                                       /* Transmit Mode Select */
        byte MST         :1;                                       /* Master Mode Select */
        byte IICIE       :1;                                       /* IIC Interrupt Enable */
        byte IICEN       :1;                                       /* IIC Enable */
      } Bits;
    } IICC1STR;
    #define IICC1                       _IICC1.Byte
    #define IICC1_RSTA                  _IICC1.SameAddr_STR.IICC1STR.Bits.RSTA
    #define IICC1_TXAK                  _IICC1.SameAddr_STR.IICC1STR.Bits.TXAK
    #define IICC1_TX                    _IICC1.SameAddr_STR.IICC1STR.Bits.TX
    #define IICC1_MST                   _IICC1.SameAddr_STR.IICC1STR.Bits.MST
    #define IICC1_IICIE                 _IICC1.SameAddr_STR.IICC1STR.Bits.IICIE
    #define IICC1_IICEN                 _IICC1.SameAddr_STR.IICC1STR.Bits.IICEN
    
    #define IICC1_RSTA_MASK             4
    #define IICC1_TXAK_MASK             8
    #define IICC1_TX_MASK               16
    #define IICC1_MST_MASK              32
    #define IICC1_IICIE_MASK            64
    #define IICC1_IICEN_MASK            128
    
    /*** IICC - IIC Control Register; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte             :1; 
        byte RSTA        :1;                                       /* Repeat START */
        byte TXAK        :1;                                       /* Transmit Acknowledge Enable */
        byte TX          :1;                                       /* Transmit Mode Select */
        byte MST         :1;                                       /* Master Mode Select */
        byte IICIE       :1;                                       /* IIC Interrupt Enable */
        byte IICEN       :1;                                       /* IIC Enable */
      } Bits;
    } IICCSTR;
    #define IICC                        _IICC1.Byte
    #define IICC_RSTA                   _IICC1.SameAddr_STR.IICCSTR.Bits.RSTA
    #define IICC_TXAK                   _IICC1.SameAddr_STR.IICCSTR.Bits.TXAK
    #define IICC_TX                     _IICC1.SameAddr_STR.IICCSTR.Bits.TX
    #define IICC_MST                    _IICC1.SameAddr_STR.IICCSTR.Bits.MST
    #define IICC_IICIE                  _IICC1.SameAddr_STR.IICCSTR.Bits.IICIE
    #define IICC_IICEN                  _IICC1.SameAddr_STR.IICCSTR.Bits.IICEN
    
    #define IICC_RSTA_MASK              4
    #define IICC_TXAK_MASK              8
    #define IICC_TX_MASK                16
    #define IICC_MST_MASK               32
    #define IICC_IICIE_MASK             64
    #define IICC_IICEN_MASK             128
    
  } SameAddr_STR; /*Several registers at the same address */

} IICC1STR;
extern volatile IICC1STR _IICC1 @0x00001862;


/*** IICS - IIC Status Register; 0x00001863 ***/
typedef union {
  byte Byte;
  struct {
    byte RXAK        :1;                                       /* Receive Acknowledge */
    byte IICIF       :1;                                       /* IIC Interrupt Flag */
    byte SRW         :1;                                       /* Slave Read/Write */
    byte             :1; 
    byte ARBL        :1;                                       /* Arbitration Lost */
    byte BUSY        :1;                                       /* Bus Busy */
    byte IAAS        :1;                                       /* Addressed as a Slave */
    byte TCF         :1;                                       /* Transfer Complete Flag */
  } Bits;
} IICSSTR;
extern volatile IICSSTR _IICS @0x00001863;
#define IICS                            _IICS.Byte
#define IICS_RXAK                       _IICS.Bits.RXAK
#define IICS_IICIF                      _IICS.Bits.IICIF
#define IICS_SRW                        _IICS.Bits.SRW
#define IICS_ARBL                       _IICS.Bits.ARBL
#define IICS_BUSY                       _IICS.Bits.BUSY
#define IICS_IAAS                       _IICS.Bits.IAAS
#define IICS_TCF                        _IICS.Bits.TCF

#define IICS_RXAK_MASK                  1
#define IICS_IICIF_MASK                 2
#define IICS_SRW_MASK                   4
#define IICS_ARBL_MASK                  16
#define IICS_BUSY_MASK                  32
#define IICS_IAAS_MASK                  64
#define IICS_TCF_MASK                   128


/*** IICD - IIC Data I/O Register; 0x00001864 ***/
typedef union {
  byte Byte;
  struct {
    byte DATA0       :1;                                       /* IIC Data Bit 0 */
    byte DATA1       :1;                                       /* IIC Data Bit 1 */
    byte DATA2       :1;                                       /* IIC Data Bit 2 */
    byte DATA3       :1;                                       /* IIC Data Bit 3 */
    byte DATA4       :1;                                       /* IIC Data Bit 4 */
    byte DATA5       :1;                                       /* IIC Data Bit 5 */
    byte DATA6       :1;                                       /* IIC Data Bit 6 */
    byte DATA7       :1;                                       /* IIC Data Bit 7 */
  } Bits;
} IICDSTR;
extern volatile IICDSTR _IICD @0x00001864;
#define IICD                            _IICD.Byte
#define IICD_DATA0                      _IICD.Bits.DATA0
#define IICD_DATA1                      _IICD.Bits.DATA1
#define IICD_DATA2                      _IICD.Bits.DATA2
#define IICD_DATA3                      _IICD.Bits.DATA3
#define IICD_DATA4                      _IICD.Bits.DATA4
#define IICD_DATA5                      _IICD.Bits.DATA5
#define IICD_DATA6                      _IICD.Bits.DATA6
#define IICD_DATA7                      _IICD.Bits.DATA7

#define IICD_DATA0_MASK                 1
#define IICD_DATA1_MASK                 2
#define IICD_DATA2_MASK                 4
#define IICD_DATA3_MASK                 8
#define IICD_DATA4_MASK                 16
#define IICD_DATA5_MASK                 32
#define IICD_DATA6_MASK                 64
#define IICD_DATA7_MASK                 128


/*** IICC2 - IIC Control Register 2; 0x00001865 ***/
typedef union {
  byte Byte;
  struct {
    byte AD8         :1;                                       /* Slave Address Bit 8 */
    byte AD9         :1;                                       /* Slave Address Bit 9 */
    byte AD10        :1;                                       /* Slave Address Bit 10 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ADEXT       :1;                                       /* Address Extension */
    byte GCAEN       :1;                                       /* General Call Address Enable */
  } Bits;
  struct {
    byte grpAD_8 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} IICC2STR;
extern volatile IICC2STR _IICC2 @0x00001865;
#define IICC2                           _IICC2.Byte
#define IICC2_AD8                       _IICC2.Bits.AD8
#define IICC2_AD9                       _IICC2.Bits.AD9
#define IICC2_AD10                      _IICC2.Bits.AD10
#define IICC2_ADEXT                     _IICC2.Bits.ADEXT
#define IICC2_GCAEN                     _IICC2.Bits.GCAEN
#define IICC2_AD_8                      _IICC2.MergedBits.grpAD_8
#define IICC2_AD                        IICC2_AD_8

#define IICC2_AD8_MASK                  1
#define IICC2_AD9_MASK                  2
#define IICC2_AD10_MASK                 4
#define IICC2_ADEXT_MASK                64
#define IICC2_GCAEN_MASK                128
#define IICC2_AD_8_MASK                 7
#define IICC2_AD_8_BITNUM               0


/*** ADCCV - Compare Value Register; 0x00001880 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCCVH - Compare Value High Register; 0x00001880 ***/
    union {
      byte Byte;
      struct {
        byte CV8         :1;                                       /* Compare Function Value Bit 8 */
        byte CV9         :1;                                       /* Compare Function Value Bit 9 */
        byte CV10        :1;                                       /* Compare Function Value Bit 10 */
        byte CV11        :1;                                       /* Compare Function Value Bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpCV_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ADCCVHSTR;
    #define ADCCVH                      _ADCCV.Overlap_STR.ADCCVHSTR.Byte
    #define ADCCVH_CV8                  _ADCCV.Overlap_STR.ADCCVHSTR.Bits.CV8
    #define ADCCVH_CV9                  _ADCCV.Overlap_STR.ADCCVHSTR.Bits.CV9
    #define ADCCVH_CV10                 _ADCCV.Overlap_STR.ADCCVHSTR.Bits.CV10
    #define ADCCVH_CV11                 _ADCCV.Overlap_STR.ADCCVHSTR.Bits.CV11
    #define ADCCVH_CV_8                 _ADCCV.Overlap_STR.ADCCVHSTR.MergedBits.grpCV_8
    #define ADCCVH_CV                   ADCCVH_CV_8
    
    #define ADCCVH_CV8_MASK             1
    #define ADCCVH_CV9_MASK             2
    #define ADCCVH_CV10_MASK            4
    #define ADCCVH_CV11_MASK            8
    #define ADCCVH_CV_8_MASK            15
    #define ADCCVH_CV_8_BITNUM          0
    

    /*** ADCCVL - Compare Value Low Register; 0x00001881 ***/
    union {
      byte Byte;
      struct {
        byte CV0         :1;                                       /* Compare Function Value 0 */
        byte CV1         :1;                                       /* Compare Function Value 1 */
        byte CV2         :1;                                       /* Compare Function Value 2 */
        byte CV3         :1;                                       /* Compare Function Value 3 */
        byte CV4         :1;                                       /* Compare Function Value 4 */
        byte CV5         :1;                                       /* Compare Function Value 5 */
        byte CV6         :1;                                       /* Compare Function Value 6 */
        byte CV7         :1;                                       /* Compare Function Value 7 */
      } Bits;
    } ADCCVLSTR;
    #define ADCCVL                      _ADCCV.Overlap_STR.ADCCVLSTR.Byte
    #define ADCCVL_CV0                  _ADCCV.Overlap_STR.ADCCVLSTR.Bits.CV0
    #define ADCCVL_CV1                  _ADCCV.Overlap_STR.ADCCVLSTR.Bits.CV1
    #define ADCCVL_CV2                  _ADCCV.Overlap_STR.ADCCVLSTR.Bits.CV2
    #define ADCCVL_CV3                  _ADCCV.Overlap_STR.ADCCVLSTR.Bits.CV3
    #define ADCCVL_CV4                  _ADCCV.Overlap_STR.ADCCVLSTR.Bits.CV4
    #define ADCCVL_CV5                  _ADCCV.Overlap_STR.ADCCVLSTR.Bits.CV5
    #define ADCCVL_CV6                  _ADCCV.Overlap_STR.ADCCVLSTR.Bits.CV6
    #define ADCCVL_CV7                  _ADCCV.Overlap_STR.ADCCVLSTR.Bits.CV7
    
    #define ADCCVL_CV0_MASK             1
    #define ADCCVL_CV1_MASK             2
    #define ADCCVL_CV2_MASK             4
    #define ADCCVL_CV3_MASK             8
    #define ADCCVL_CV4_MASK             16
    #define ADCCVL_CV5_MASK             32
    #define ADCCVL_CV6_MASK             64
    #define ADCCVL_CV7_MASK             128
    
  } Overlap_STR;

} ADCCVSTR;
extern volatile ADCCVSTR _ADCCV @0x00001880;
#define ADCCV                           _ADCCV.Word


/*** ADCSC2 - Status and Control Register 2; 0x00001884 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ACFGT       :1;                                       /* Compare Function Greater Than Enable */
    byte ACFE        :1;                                       /* Compare Function Enable - ACFE is used to enable the compare function */
    byte ADTRG       :1;                                       /* Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating a conversion */
    byte ADACT       :1;                                       /* Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a conversion is initiated and cleared when a conversion is completed or aborted */
  } Bits;
} ADCSC2STR;
extern volatile ADCSC2STR _ADCSC2 @0x00001884;
#define ADCSC2                          _ADCSC2.Byte
#define ADCSC2_ACFGT                    _ADCSC2.Bits.ACFGT
#define ADCSC2_ACFE                     _ADCSC2.Bits.ACFE
#define ADCSC2_ADTRG                    _ADCSC2.Bits.ADTRG
#define ADCSC2_ADACT                    _ADCSC2.Bits.ADACT

#define ADCSC2_ACFGT_MASK               16
#define ADCSC2_ACFE_MASK                32
#define ADCSC2_ADTRG_MASK               64
#define ADCSC2_ADACT_MASK               128


/*** ADCSC3 - Status and Control Register 3; 0x00001885 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ADCO        :1;                                       /* Continuous Conversion Enable - ADCO enables continuous conversions */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} ADCSC3STR;
extern volatile ADCSC3STR _ADCSC3 @0x00001885;
#define ADCSC3                          _ADCSC3.Byte
#define ADCSC3_ADCO                     _ADCSC3.Bits.ADCO

#define ADCSC3_ADCO_MASK                8


/*** APCTL1 - Pin Control 1 Register; 0x0000189F ***/
typedef union {
  byte Byte;
  struct {
    byte ADPC0       :1;                                       /* ADC Pin Control 0 - ADPC0 is used to control the pin associated with channel AD0 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ADPC4       :1;                                       /* ADC Pin Control 4 - ADPC4 is used to control the pin associated with channel AD4 */
    byte ADPC5       :1;                                       /* ADC Pin Control 5 - ADPC5 is used to control the pin associated with channel AD5 */
    byte ADPC6       :1;                                       /* ADC Pin Control 6 - ADPC6 is used to control the pin associated with channel AD6 */
    byte ADPC7       :1;                                       /* ADC Pin Control 7 - ADPC7 is used to control the pin associated with channel AD7 */
  } Bits;
  struct {
    byte grpADPC :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpADPC_4 :4;
  } MergedBits;
} APCTL1STR;
extern volatile APCTL1STR _APCTL1 @0x0000189F;
#define APCTL1                          _APCTL1.Byte
#define APCTL1_ADPC0                    _APCTL1.Bits.ADPC0
#define APCTL1_ADPC4                    _APCTL1.Bits.ADPC4
#define APCTL1_ADPC5                    _APCTL1.Bits.ADPC5
#define APCTL1_ADPC6                    _APCTL1.Bits.ADPC6
#define APCTL1_ADPC7                    _APCTL1.Bits.ADPC7
#define APCTL1_ADPC_4                   _APCTL1.MergedBits.grpADPC_4
#define APCTL1_ADPC                     APCTL1_ADPC_4

#define APCTL1_ADPC0_MASK               1
#define APCTL1_ADPC4_MASK               16
#define APCTL1_ADPC5_MASK               32
#define APCTL1_ADPC6_MASK               64
#define APCTL1_ADPC7_MASK               128
#define APCTL1_ADPC_4_MASK              240
#define APCTL1_ADPC_4_BITNUM            4


/*** APCTL2 - Pin Control 2 Register; 0x000018A0 ***/
typedef union {
  byte Byte;
  struct {
    byte ADPC8       :1;                                       /* ADC Pin Control 8 - ADPC8 is used to control the pin associated with channel AD8 */
    byte ADPC9       :1;                                       /* ADC Pin Control 9 - ADPC9 is used to control the pin associated with channel AD9 */
    byte ADPC10      :1;                                       /* ADC Pin Control 10 - ADPC10 is used to control the pin associated with channel AD10 */
    byte ADPC11      :1;                                       /* ADC Pin Control 11 - ADPC11 is used to control the pin associated with channel AD11 */
    byte ADPC12      :1;                                       /* ADC Pin Control 12 - ADPC12 is used to control the pin associated with channel AD12 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpADPC_8 :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} APCTL2STR;
extern volatile APCTL2STR _APCTL2 @0x000018A0;
#define APCTL2                          _APCTL2.Byte
#define APCTL2_ADPC8                    _APCTL2.Bits.ADPC8
#define APCTL2_ADPC9                    _APCTL2.Bits.ADPC9
#define APCTL2_ADPC10                   _APCTL2.Bits.ADPC10
#define APCTL2_ADPC11                   _APCTL2.Bits.ADPC11
#define APCTL2_ADPC12                   _APCTL2.Bits.ADPC12
#define APCTL2_ADPC_8                   _APCTL2.MergedBits.grpADPC_8
#define APCTL2_ADPC                     APCTL2_ADPC_8

#define APCTL2_ADPC8_MASK               1
#define APCTL2_ADPC9_MASK               2
#define APCTL2_ADPC10_MASK              4
#define APCTL2_ADPC11_MASK              8
#define APCTL2_ADPC12_MASK              16
#define APCTL2_ADPC_8_MASK              31
#define APCTL2_ADPC_8_BITNUM            0


/*** NVVREF1TRM - Non-volatile VREF Trim Register; 0x0000FFAC ***/
typedef union {
  byte Byte;
  struct {
    byte TRM0        :1;                                       /* Trim Bit 0, bit 0 */
    byte TRM1        :1;                                       /* Trim Bit 0, bit 1 */
    byte TRM2        :1;                                       /* Trim Bit 0, bit 2 */
    byte TRM3        :1;                                       /* Trim Bit 0, bit 3 */
    byte TRM4        :1;                                       /* Trim Bit 0, bit 4 */
    byte TRM5        :1;                                       /* Trim Bit 0, bit 5 */
    byte TRM6        :1;                                       /* Trim Bit 0, bit 6 */
    byte TRM7        :1;                                       /* Trim Bit 0, bit 7 */
  } Bits;
} NVVREF1TRMSTR;
/* Tip for register initialization in the user code:  const byte NVVREF1TRM_INIT @0x0000FFAC = <NVVREF1TRM_INITVAL>; */
#define _NVVREF1TRM (*(const NVVREF1TRMSTR * __far)0x0000FFAC)
#define NVVREF1TRM                      _NVVREF1TRM.Byte
#define NVVREF1TRM_TRM0                 _NVVREF1TRM.Bits.TRM0
#define NVVREF1TRM_TRM1                 _NVVREF1TRM.Bits.TRM1
#define NVVREF1TRM_TRM2                 _NVVREF1TRM.Bits.TRM2
#define NVVREF1TRM_TRM3                 _NVVREF1TRM.Bits.TRM3
#define NVVREF1TRM_TRM4                 _NVVREF1TRM.Bits.TRM4
#define NVVREF1TRM_TRM5                 _NVVREF1TRM.Bits.TRM5
#define NVVREF1TRM_TRM6                 _NVVREF1TRM.Bits.TRM6
#define NVVREF1TRM_TRM7                 _NVVREF1TRM.Bits.TRM7

#define NVVREF1TRM_TRM0_MASK            1
#define NVVREF1TRM_TRM1_MASK            2
#define NVVREF1TRM_TRM2_MASK            4
#define NVVREF1TRM_TRM3_MASK            8
#define NVVREF1TRM_TRM4_MASK            16
#define NVVREF1TRM_TRM5_MASK            32
#define NVVREF1TRM_TRM6_MASK            64
#define NVVREF1TRM_TRM7_MASK            128


/*** NVVREF2TRM - Non-volatile VREF Trim Register; 0x0000FFAD ***/
typedef union {
  byte Byte;
  struct {
    byte TRM0        :1;                                       /* Trim Bit 0, bit 0 */
    byte TRM1        :1;                                       /* Trim Bit 0, bit 1 */
    byte TRM2        :1;                                       /* Trim Bit 0, bit 2 */
    byte TRM3        :1;                                       /* Trim Bit 0, bit 3 */
    byte TRM4        :1;                                       /* Trim Bit 0, bit 4 */
    byte TRM5        :1;                                       /* Trim Bit 0, bit 5 */
    byte TRM6        :1;                                       /* Trim Bit 0, bit 6 */
    byte TRM7        :1;                                       /* Trim Bit 0, bit 7 */
  } Bits;
} NVVREF2TRMSTR;
/* Tip for register initialization in the user code:  const byte NVVREF2TRM_INIT @0x0000FFAD = <NVVREF2TRM_INITVAL>; */
#define _NVVREF2TRM (*(const NVVREF2TRMSTR * __far)0x0000FFAD)
#define NVVREF2TRM                      _NVVREF2TRM.Byte
#define NVVREF2TRM_TRM0                 _NVVREF2TRM.Bits.TRM0
#define NVVREF2TRM_TRM1                 _NVVREF2TRM.Bits.TRM1
#define NVVREF2TRM_TRM2                 _NVVREF2TRM.Bits.TRM2
#define NVVREF2TRM_TRM3                 _NVVREF2TRM.Bits.TRM3
#define NVVREF2TRM_TRM4                 _NVVREF2TRM.Bits.TRM4
#define NVVREF2TRM_TRM5                 _NVVREF2TRM.Bits.TRM5
#define NVVREF2TRM_TRM6                 _NVVREF2TRM.Bits.TRM6
#define NVVREF2TRM_TRM7                 _NVVREF2TRM.Bits.TRM7

#define NVVREF2TRM_TRM0_MASK            1
#define NVVREF2TRM_TRM1_MASK            2
#define NVVREF2TRM_TRM2_MASK            4
#define NVVREF2TRM_TRM3_MASK            8
#define NVVREF2TRM_TRM4_MASK            16
#define NVVREF2TRM_TRM5_MASK            32
#define NVVREF2TRM_TRM6_MASK            64
#define NVVREF2TRM_TRM7_MASK            128


/*** NVFTRIM - Nonvolatile ICS Fine Trim; 0x0000FFAE ***/
typedef union {
  byte Byte;
  struct {
    byte FTRIM       :1;                                       /* ICS Fine Trim */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NVFTRIMSTR;
/* Tip for register initialization in the user code:  const byte NVFTRIM_INIT @0x0000FFAE = <NVFTRIM_INITVAL>; */
#define _NVFTRIM (*(const NVFTRIMSTR * __far)0x0000FFAE)
#define NVFTRIM                         _NVFTRIM.Byte
#define NVFTRIM_FTRIM                   _NVFTRIM.Bits.FTRIM

#define NVFTRIM_FTRIM_MASK              1


/*** NVICSTRM - Nonvolatile ICS Trim Register; 0x0000FFAF ***/
typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       /* ICS Trim Setting, bit 0 */
    byte TRIM1       :1;                                       /* ICS Trim Setting, bit 1 */
    byte TRIM2       :1;                                       /* ICS Trim Setting, bit 2 */
    byte TRIM3       :1;                                       /* ICS Trim Setting, bit 3 */
    byte TRIM4       :1;                                       /* ICS Trim Setting, bit 4 */
    byte TRIM5       :1;                                       /* ICS Trim Setting, bit 5 */
    byte TRIM6       :1;                                       /* ICS Trim Setting, bit 6 */
    byte TRIM7       :1;                                       /* ICS Trim Setting, bit 7 */
  } Bits;
} NVICSTRMSTR;
/* Tip for register initialization in the user code:  const byte NVICSTRM_INIT @0x0000FFAF = <NVICSTRM_INITVAL>; */
#define _NVICSTRM (*(const NVICSTRMSTR * __far)0x0000FFAF)
#define NVICSTRM                        _NVICSTRM.Byte
#define NVICSTRM_TRIM0                  _NVICSTRM.Bits.TRIM0
#define NVICSTRM_TRIM1                  _NVICSTRM.Bits.TRIM1
#define NVICSTRM_TRIM2                  _NVICSTRM.Bits.TRIM2
#define NVICSTRM_TRIM3                  _NVICSTRM.Bits.TRIM3
#define NVICSTRM_TRIM4                  _NVICSTRM.Bits.TRIM4
#define NVICSTRM_TRIM5                  _NVICSTRM.Bits.TRIM5
#define NVICSTRM_TRIM6                  _NVICSTRM.Bits.TRIM6
#define NVICSTRM_TRIM7                  _NVICSTRM.Bits.TRIM7

#define NVICSTRM_TRIM0_MASK             1
#define NVICSTRM_TRIM1_MASK             2
#define NVICSTRM_TRIM2_MASK             4
#define NVICSTRM_TRIM3_MASK             8
#define NVICSTRM_TRIM4_MASK             16
#define NVICSTRM_TRIM5_MASK             32
#define NVICSTRM_TRIM6_MASK             64
#define NVICSTRM_TRIM7_MASK             128


/*** NVBACKKEY0 - Backdoor Comparison Key 0; 0x0000FFB0 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 7 */
  } Bits;
} NVBACKKEY0STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT @0x0000FFB0 = <NVBACKKEY0_INITVAL>; */
#define _NVBACKKEY0 (*(const NVBACKKEY0STR * __far)0x0000FFB0)
#define NVBACKKEY0                      _NVBACKKEY0.Byte
#define NVBACKKEY0_KEY0                 _NVBACKKEY0.Bits.KEY0
#define NVBACKKEY0_KEY1                 _NVBACKKEY0.Bits.KEY1
#define NVBACKKEY0_KEY2                 _NVBACKKEY0.Bits.KEY2
#define NVBACKKEY0_KEY3                 _NVBACKKEY0.Bits.KEY3
#define NVBACKKEY0_KEY4                 _NVBACKKEY0.Bits.KEY4
#define NVBACKKEY0_KEY5                 _NVBACKKEY0.Bits.KEY5
#define NVBACKKEY0_KEY6                 _NVBACKKEY0.Bits.KEY6
#define NVBACKKEY0_KEY7                 _NVBACKKEY0.Bits.KEY7
/* NVBACKKEY_ARR: Access 8 NVBACKKEYx registers in an array */
#define NVBACKKEY_ARR                   ((volatile byte * __far) &NVBACKKEY0)

#define NVBACKKEY0_KEY0_MASK            1
#define NVBACKKEY0_KEY1_MASK            2
#define NVBACKKEY0_KEY2_MASK            4
#define NVBACKKEY0_KEY3_MASK            8
#define NVBACKKEY0_KEY4_MASK            16
#define NVBACKKEY0_KEY5_MASK            32
#define NVBACKKEY0_KEY6_MASK            64
#define NVBACKKEY0_KEY7_MASK            128


/*** NVBACKKEY1 - Backdoor Comparison Key 1; 0x0000FFB1 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 7 */
  } Bits;
} NVBACKKEY1STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT @0x0000FFB1 = <NVBACKKEY1_INITVAL>; */
#define _NVBACKKEY1 (*(const NVBACKKEY1STR * __far)0x0000FFB1)
#define NVBACKKEY1                      _NVBACKKEY1.Byte
#define NVBACKKEY1_KEY0                 _NVBACKKEY1.Bits.KEY0
#define NVBACKKEY1_KEY1                 _NVBACKKEY1.Bits.KEY1
#define NVBACKKEY1_KEY2                 _NVBACKKEY1.Bits.KEY2
#define NVBACKKEY1_KEY3                 _NVBACKKEY1.Bits.KEY3
#define NVBACKKEY1_KEY4                 _NVBACKKEY1.Bits.KEY4
#define NVBACKKEY1_KEY5                 _NVBACKKEY1.Bits.KEY5
#define NVBACKKEY1_KEY6                 _NVBACKKEY1.Bits.KEY6
#define NVBACKKEY1_KEY7                 _NVBACKKEY1.Bits.KEY7

#define NVBACKKEY1_KEY0_MASK            1
#define NVBACKKEY1_KEY1_MASK            2
#define NVBACKKEY1_KEY2_MASK            4
#define NVBACKKEY1_KEY3_MASK            8
#define NVBACKKEY1_KEY4_MASK            16
#define NVBACKKEY1_KEY5_MASK            32
#define NVBACKKEY1_KEY6_MASK            64
#define NVBACKKEY1_KEY7_MASK            128


/*** NVBACKKEY2 - Backdoor Comparison Key 2; 0x0000FFB2 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 7 */
  } Bits;
} NVBACKKEY2STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT @0x0000FFB2 = <NVBACKKEY2_INITVAL>; */
#define _NVBACKKEY2 (*(const NVBACKKEY2STR * __far)0x0000FFB2)
#define NVBACKKEY2                      _NVBACKKEY2.Byte
#define NVBACKKEY2_KEY0                 _NVBACKKEY2.Bits.KEY0
#define NVBACKKEY2_KEY1                 _NVBACKKEY2.Bits.KEY1
#define NVBACKKEY2_KEY2                 _NVBACKKEY2.Bits.KEY2
#define NVBACKKEY2_KEY3                 _NVBACKKEY2.Bits.KEY3
#define NVBACKKEY2_KEY4                 _NVBACKKEY2.Bits.KEY4
#define NVBACKKEY2_KEY5                 _NVBACKKEY2.Bits.KEY5
#define NVBACKKEY2_KEY6                 _NVBACKKEY2.Bits.KEY6
#define NVBACKKEY2_KEY7                 _NVBACKKEY2.Bits.KEY7

#define NVBACKKEY2_KEY0_MASK            1
#define NVBACKKEY2_KEY1_MASK            2
#define NVBACKKEY2_KEY2_MASK            4
#define NVBACKKEY2_KEY3_MASK            8
#define NVBACKKEY2_KEY4_MASK            16
#define NVBACKKEY2_KEY5_MASK            32
#define NVBACKKEY2_KEY6_MASK            64
#define NVBACKKEY2_KEY7_MASK            128


/*** NVBACKKEY3 - Backdoor Comparison Key 3; 0x0000FFB3 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 7 */
  } Bits;
} NVBACKKEY3STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT @0x0000FFB3 = <NVBACKKEY3_INITVAL>; */
#define _NVBACKKEY3 (*(const NVBACKKEY3STR * __far)0x0000FFB3)
#define NVBACKKEY3                      _NVBACKKEY3.Byte
#define NVBACKKEY3_KEY0                 _NVBACKKEY3.Bits.KEY0
#define NVBACKKEY3_KEY1                 _NVBACKKEY3.Bits.KEY1
#define NVBACKKEY3_KEY2                 _NVBACKKEY3.Bits.KEY2
#define NVBACKKEY3_KEY3                 _NVBACKKEY3.Bits.KEY3
#define NVBACKKEY3_KEY4                 _NVBACKKEY3.Bits.KEY4
#define NVBACKKEY3_KEY5                 _NVBACKKEY3.Bits.KEY5
#define NVBACKKEY3_KEY6                 _NVBACKKEY3.Bits.KEY6
#define NVBACKKEY3_KEY7                 _NVBACKKEY3.Bits.KEY7

#define NVBACKKEY3_KEY0_MASK            1
#define NVBACKKEY3_KEY1_MASK            2
#define NVBACKKEY3_KEY2_MASK            4
#define NVBACKKEY3_KEY3_MASK            8
#define NVBACKKEY3_KEY4_MASK            16
#define NVBACKKEY3_KEY5_MASK            32
#define NVBACKKEY3_KEY6_MASK            64
#define NVBACKKEY3_KEY7_MASK            128


/*** NVBACKKEY4 - Backdoor Comparison Key 4; 0x0000FFB4 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 7 */
  } Bits;
} NVBACKKEY4STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT @0x0000FFB4 = <NVBACKKEY4_INITVAL>; */
#define _NVBACKKEY4 (*(const NVBACKKEY4STR * __far)0x0000FFB4)
#define NVBACKKEY4                      _NVBACKKEY4.Byte
#define NVBACKKEY4_KEY0                 _NVBACKKEY4.Bits.KEY0
#define NVBACKKEY4_KEY1                 _NVBACKKEY4.Bits.KEY1
#define NVBACKKEY4_KEY2                 _NVBACKKEY4.Bits.KEY2
#define NVBACKKEY4_KEY3                 _NVBACKKEY4.Bits.KEY3
#define NVBACKKEY4_KEY4                 _NVBACKKEY4.Bits.KEY4
#define NVBACKKEY4_KEY5                 _NVBACKKEY4.Bits.KEY5
#define NVBACKKEY4_KEY6                 _NVBACKKEY4.Bits.KEY6
#define NVBACKKEY4_KEY7                 _NVBACKKEY4.Bits.KEY7

#define NVBACKKEY4_KEY0_MASK            1
#define NVBACKKEY4_KEY1_MASK            2
#define NVBACKKEY4_KEY2_MASK            4
#define NVBACKKEY4_KEY3_MASK            8
#define NVBACKKEY4_KEY4_MASK            16
#define NVBACKKEY4_KEY5_MASK            32
#define NVBACKKEY4_KEY6_MASK            64
#define NVBACKKEY4_KEY7_MASK            128


/*** NVBACKKEY5 - Backdoor Comparison Key 5; 0x0000FFB5 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 7 */
  } Bits;
} NVBACKKEY5STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT @0x0000FFB5 = <NVBACKKEY5_INITVAL>; */
#define _NVBACKKEY5 (*(const NVBACKKEY5STR * __far)0x0000FFB5)
#define NVBACKKEY5                      _NVBACKKEY5.Byte
#define NVBACKKEY5_KEY0                 _NVBACKKEY5.Bits.KEY0
#define NVBACKKEY5_KEY1                 _NVBACKKEY5.Bits.KEY1
#define NVBACKKEY5_KEY2                 _NVBACKKEY5.Bits.KEY2
#define NVBACKKEY5_KEY3                 _NVBACKKEY5.Bits.KEY3
#define NVBACKKEY5_KEY4                 _NVBACKKEY5.Bits.KEY4
#define NVBACKKEY5_KEY5                 _NVBACKKEY5.Bits.KEY5
#define NVBACKKEY5_KEY6                 _NVBACKKEY5.Bits.KEY6
#define NVBACKKEY5_KEY7                 _NVBACKKEY5.Bits.KEY7

#define NVBACKKEY5_KEY0_MASK            1
#define NVBACKKEY5_KEY1_MASK            2
#define NVBACKKEY5_KEY2_MASK            4
#define NVBACKKEY5_KEY3_MASK            8
#define NVBACKKEY5_KEY4_MASK            16
#define NVBACKKEY5_KEY5_MASK            32
#define NVBACKKEY5_KEY6_MASK            64
#define NVBACKKEY5_KEY7_MASK            128


/*** NVBACKKEY6 - Backdoor Comparison Key 6; 0x0000FFB6 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 7 */
  } Bits;
} NVBACKKEY6STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT @0x0000FFB6 = <NVBACKKEY6_INITVAL>; */
#define _NVBACKKEY6 (*(const NVBACKKEY6STR * __far)0x0000FFB6)
#define NVBACKKEY6                      _NVBACKKEY6.Byte
#define NVBACKKEY6_KEY0                 _NVBACKKEY6.Bits.KEY0
#define NVBACKKEY6_KEY1                 _NVBACKKEY6.Bits.KEY1
#define NVBACKKEY6_KEY2                 _NVBACKKEY6.Bits.KEY2
#define NVBACKKEY6_KEY3                 _NVBACKKEY6.Bits.KEY3
#define NVBACKKEY6_KEY4                 _NVBACKKEY6.Bits.KEY4
#define NVBACKKEY6_KEY5                 _NVBACKKEY6.Bits.KEY5
#define NVBACKKEY6_KEY6                 _NVBACKKEY6.Bits.KEY6
#define NVBACKKEY6_KEY7                 _NVBACKKEY6.Bits.KEY7

#define NVBACKKEY6_KEY0_MASK            1
#define NVBACKKEY6_KEY1_MASK            2
#define NVBACKKEY6_KEY2_MASK            4
#define NVBACKKEY6_KEY3_MASK            8
#define NVBACKKEY6_KEY4_MASK            16
#define NVBACKKEY6_KEY5_MASK            32
#define NVBACKKEY6_KEY6_MASK            64
#define NVBACKKEY6_KEY7_MASK            128


/*** NVBACKKEY7 - Backdoor Comparison Key 7; 0x0000FFB7 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 7 */
  } Bits;
} NVBACKKEY7STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT @0x0000FFB7 = <NVBACKKEY7_INITVAL>; */
#define _NVBACKKEY7 (*(const NVBACKKEY7STR * __far)0x0000FFB7)
#define NVBACKKEY7                      _NVBACKKEY7.Byte
#define NVBACKKEY7_KEY0                 _NVBACKKEY7.Bits.KEY0
#define NVBACKKEY7_KEY1                 _NVBACKKEY7.Bits.KEY1
#define NVBACKKEY7_KEY2                 _NVBACKKEY7.Bits.KEY2
#define NVBACKKEY7_KEY3                 _NVBACKKEY7.Bits.KEY3
#define NVBACKKEY7_KEY4                 _NVBACKKEY7.Bits.KEY4
#define NVBACKKEY7_KEY5                 _NVBACKKEY7.Bits.KEY5
#define NVBACKKEY7_KEY6                 _NVBACKKEY7.Bits.KEY6
#define NVBACKKEY7_KEY7                 _NVBACKKEY7.Bits.KEY7

#define NVBACKKEY7_KEY0_MASK            1
#define NVBACKKEY7_KEY1_MASK            2
#define NVBACKKEY7_KEY2_MASK            4
#define NVBACKKEY7_KEY3_MASK            8
#define NVBACKKEY7_KEY4_MASK            16
#define NVBACKKEY7_KEY5_MASK            32
#define NVBACKKEY7_KEY6_MASK            64
#define NVBACKKEY7_KEY7_MASK            128


/*** NVPROT - Nonvolatile Flash Protection Register; 0x0000FFBD ***/
typedef union {
  byte Byte;
  struct {
    byte FPDIS       :1;                                       /* Flash Protection Disable */
    byte FPS0        :1;                                       /* Flash Protection Size, bit 0 */
    byte FPS1        :1;                                       /* Flash Protection Size, bit 1 */
    byte FPS2        :1;                                       /* Flash Protection Size, bit 2 */
    byte FPS3        :1;                                       /* Flash Protection Size, bit 3 */
    byte FPS4        :1;                                       /* Flash Protection Size, bit 4 */
    byte FPS5        :1;                                       /* Flash Protection Size, bit 5 */
    byte FPS6        :1;                                       /* Flash Protection Size, bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS  :7;
  } MergedBits;
} NVPROTSTR;
/* Tip for register initialization in the user code:  const byte NVPROT_INIT @0x0000FFBD = <NVPROT_INITVAL>; */
#define _NVPROT (*(const NVPROTSTR * __far)0x0000FFBD)
#define NVPROT                          _NVPROT.Byte
#define NVPROT_FPDIS                    _NVPROT.Bits.FPDIS
#define NVPROT_FPS0                     _NVPROT.Bits.FPS0
#define NVPROT_FPS1                     _NVPROT.Bits.FPS1
#define NVPROT_FPS2                     _NVPROT.Bits.FPS2
#define NVPROT_FPS3                     _NVPROT.Bits.FPS3
#define NVPROT_FPS4                     _NVPROT.Bits.FPS4
#define NVPROT_FPS5                     _NVPROT.Bits.FPS5
#define NVPROT_FPS6                     _NVPROT.Bits.FPS6
#define NVPROT_FPS                      _NVPROT.MergedBits.grpFPS

#define NVPROT_FPDIS_MASK               1
#define NVPROT_FPS0_MASK                2
#define NVPROT_FPS1_MASK                4
#define NVPROT_FPS2_MASK                8
#define NVPROT_FPS3_MASK                16
#define NVPROT_FPS4_MASK                32
#define NVPROT_FPS5_MASK                64
#define NVPROT_FPS6_MASK                128
#define NVPROT_FPS_MASK                 254
#define NVPROT_FPS_BITNUM               1


/*** NVOPT - Nonvolatile Flash Options Register; 0x0000FFBF ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FNORED      :1;                                       /* Vector Redirection Disable */
    byte KEYEN       :1;                                       /* Backdoor Key Security Enable */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NVOPTSTR;
/* Tip for register initialization in the user code:  const byte NVOPT_INIT @0x0000FFBF = <NVOPT_INITVAL>; */
#define _NVOPT (*(const NVOPTSTR * __far)0x0000FFBF)
#define NVOPT                           _NVOPT.Byte
#define NVOPT_SEC0                      _NVOPT.Bits.SEC0
#define NVOPT_SEC1                      _NVOPT.Bits.SEC1
#define NVOPT_FNORED                    _NVOPT.Bits.FNORED
#define NVOPT_KEYEN                     _NVOPT.Bits.KEYEN
#define NVOPT_SEC                       _NVOPT.MergedBits.grpSEC

#define NVOPT_SEC0_MASK                 1
#define NVOPT_SEC1_MASK                 2
#define NVOPT_FNORED_MASK               64
#define NVOPT_KEYEN_MASK                128
#define NVOPT_SEC_MASK                  3
#define NVOPT_SEC_BITNUM                0



/* Flash commands */
#define mBlank                          0x05
#define mBurstProg                      0x25
#define mByteProg                       0x20
#define mMassErase                      0x41
#define mPageErase                      0x40


/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/
/* --------------------------------------------------------------------------- */
/* The following symbols were removed, because they were invalid or irrelevant */
/* --------------------------------------------------------------------------- */



/* **** 19.2.2009 17:22:36 */

#define ADCRH_D12                        This_symb_has_been_depreciated
#define ADCRH_D13                        This_symb_has_been_depreciated
#define ADCRH_D14                        This_symb_has_been_depreciated
#define ADCRH_D15                        This_symb_has_been_depreciated
#define ADCRH_D12_MASK                   This_symb_has_been_depreciated
#define ADCRH_D13_MASK                   This_symb_has_been_depreciated
#define ADCRH_D14_MASK                   This_symb_has_been_depreciated
#define ADCRH_D15_MASK                   This_symb_has_been_depreciated
#define VREFTRM1                         VREF1TRM
#define VREFTRM1_TRM10                   VREF1TRM_TRM0
#define VREFTRM1_TRM11                   VREF1TRM_TRM1
#define VREFTRM1_TRM12                   VREF1TRM_TRM2
#define VREFTRM1_TRM13                   VREF1TRM_TRM3
#define VREFTRM1_TRM14                   VREF1TRM_TRM4
#define VREFTRM1_TRM15                   VREF1TRM_TRM5
#define VREFTRM1_TRM16                   VREF1TRM_TRM6
#define VREFTRM1_TRM17                   VREF1TRM_TRM7
#define VREFTRM1_TRM10_MASK              VREF1TRM_TRM0_MASK
#define VREFTRM1_TRM11_MASK              VREF1TRM_TRM1_MASK
#define VREFTRM1_TRM12_MASK              VREF1TRM_TRM2_MASK
#define VREFTRM1_TRM13_MASK              VREF1TRM_TRM3_MASK
#define VREFTRM1_TRM14_MASK              VREF1TRM_TRM4_MASK
#define VREFTRM1_TRM15_MASK              VREF1TRM_TRM5_MASK
#define VREFTRM1_TRM16_MASK              VREF1TRM_TRM6_MASK
#define VREFTRM1_TRM17_MASK              VREF1TRM_TRM7_MASK
#define VREFSC1                          VREF1SC
#define VREFSC1_MODE10                   VREF1SC_MODE0
#define VREFSC1_MODE11                   This_symb_has_been_depreciated
#define VREFSC1_VREFST1                  VREF1SC_VREFST
#define VREFSC1_VREFEN1                  VREF1SC_VREFEN
#define VREFSC1_MODE1                    VREF1SC_MODE1
#define VREFSC1_MODE10_MASK              VREF1SC_MODE0_MASK
#define VREFSC1_MODE11_MASK              This_symb_has_been_depreciated
#define VREFSC1_VREFST1_MASK             VREF1SC_VREFST_MASK
#define VREFSC1_VREFEN1_MASK             VREF1SC_VREFEN_MASK
#define VREFSC1_MODE1_MASK               VREF1SC_MODE1_MASK
#define VREFSC1_MODE1_BITNUM             VREF1SC_MODE_BITNUM
#define VREFTRM2                         VREF2TRM                      
#define VREFTRM2_TRM20                   VREF2TRM_TRM0                 
#define VREFTRM2_TRM21                   VREF2TRM_TRM1                 
#define VREFTRM2_TRM22                   VREF2TRM_TRM2                 
#define VREFTRM2_TRM23                   VREF2TRM_TRM3                 
#define VREFTRM2_TRM24                   VREF2TRM_TRM4                 
#define VREFTRM2_TRM25                   VREF2TRM_TRM5                 
#define VREFTRM2_TRM26                   VREF2TRM_TRM6                 
#define VREFTRM2_TRM27                   VREF2TRM_TRM7                 
#define VREFTRM2_TRM20_MASK              VREF2TRM_TRM0_MASK            
#define VREFTRM2_TRM21_MASK              VREF2TRM_TRM1_MASK            
#define VREFTRM2_TRM22_MASK              VREF2TRM_TRM2_MASK            
#define VREFTRM2_TRM23_MASK              VREF2TRM_TRM3_MASK            
#define VREFTRM2_TRM24_MASK              VREF2TRM_TRM4_MASK            
#define VREFTRM2_TRM25_MASK              VREF2TRM_TRM5_MASK            
#define VREFTRM2_TRM26_MASK              VREF2TRM_TRM6_MASK            
#define VREFTRM2_TRM27_MASK              VREF2TRM_TRM7_MASK            
#define VREFSC2                          VREF2SC                       
#define VREFSC2_MODE20                   VREF2SC_MODE0                 
#define VREFSC2_MODE21                   This_symb_has_been_depreciated
#define VREFSC2_VREFST2                  VREF2SC_VREFST                
#define VREFSC2_VREFEN2                  VREF2SC_VREFEN                
#define VREFSC2_MODE2                    VREF2SC_MODE1                 
#define VREFSC2_MODE20_MASK              VREF2SC_MODE0_MASK            
#define VREFSC2_MODE21_MASK              This_symb_has_been_depreciated
#define VREFSC2_VREFST2_MASK             VREF2SC_VREFST_MASK           
#define VREFSC2_VREFEN2_MASK             VREF2SC_VREFEN_MASK           
#define VREFSC2_MODE2_MASK               VREF2SC_MODE1_MASK            
#define VREFSC2_MODE2_BITNUM             VREF2SC_MODE_BITNUM           
#define ADCCV1H_CV112                    This_symb_has_been_depreciated
#define ADCCV1H_CV113                    This_symb_has_been_depreciated
#define ADCCV1H_CV114                    This_symb_has_been_depreciated
#define ADCCV1H_CV115                    This_symb_has_been_depreciated
#define ADCCV1H_CV112_MASK               This_symb_has_been_depreciated
#define ADCCV1H_CV113_MASK               This_symb_has_been_depreciated
#define ADCCV1H_CV114_MASK               This_symb_has_been_depreciated
#define ADCCV1H_CV115_MASK               This_symb_has_been_depreciated
#define _NVVREFTRM1                      _NVVREF1TRM
#define NVVREFTRM1                       NVVREF1TRM
#define NVVREFTRM1_TRM10                 NVVREF1TRM_TRM0
#define NVVREFTRM1_TRM11                 NVVREF1TRM_TRM1
#define NVVREFTRM1_TRM12                 NVVREF1TRM_TRM2
#define NVVREFTRM1_TRM13                 NVVREF1TRM_TRM3
#define NVVREFTRM1_TRM14                 NVVREF1TRM_TRM4
#define NVVREFTRM1_TRM15                 NVVREF1TRM_TRM5
#define NVVREFTRM1_TRM16                 NVVREF1TRM_TRM6
#define NVVREFTRM1_TRM17                 NVVREF1TRM_TRM7
#define NVVREFTRM1_TRM10_MASK            NVVREF1TRM_TRM0_MASK
#define NVVREFTRM1_TRM11_MASK            NVVREF1TRM_TRM1_MASK
#define NVVREFTRM1_TRM12_MASK            NVVREF1TRM_TRM2_MASK
#define NVVREFTRM1_TRM13_MASK            NVVREF1TRM_TRM3_MASK
#define NVVREFTRM1_TRM14_MASK            NVVREF1TRM_TRM4_MASK
#define NVVREFTRM1_TRM15_MASK            NVVREF1TRM_TRM5_MASK
#define NVVREFTRM1_TRM16_MASK            NVVREF1TRM_TRM6_MASK
#define NVVREFTRM1_TRM17_MASK            NVVREF1TRM_TRM7_MASK
#define _NVVREFTRM2                      _NVVREF2TRM         
#define NVVREFTRM2                       NVVREF2TRM          
#define NVVREFTRM2_TRM20                 NVVREF2TRM_TRM0     
#define NVVREFTRM2_TRM21                 NVVREF2TRM_TRM1     
#define NVVREFTRM2_TRM22                 NVVREF2TRM_TRM2     
#define NVVREFTRM2_TRM23                 NVVREF2TRM_TRM3     
#define NVVREFTRM2_TRM24                 NVVREF2TRM_TRM4     
#define NVVREFTRM2_TRM25                 NVVREF2TRM_TRM5     
#define NVVREFTRM2_TRM26                 NVVREF2TRM_TRM6     
#define NVVREFTRM2_TRM27                 NVVREF2TRM_TRM7     
#define NVVREFTRM2_TRM20_MASK            NVVREF2TRM_TRM0_MASK
#define NVVREFTRM2_TRM21_MASK            NVVREF2TRM_TRM1_MASK
#define NVVREFTRM2_TRM22_MASK            NVVREF2TRM_TRM2_MASK
#define NVVREFTRM2_TRM23_MASK            NVVREF2TRM_TRM3_MASK
#define NVVREFTRM2_TRM24_MASK            NVVREF2TRM_TRM4_MASK
#define NVVREFTRM2_TRM25_MASK            NVVREF2TRM_TRM5_MASK
#define NVVREFTRM2_TRM26_MASK            NVVREF2TRM_TRM6_MASK
#define NVVREFTRM2_TRM27_MASK            NVVREF2TRM_TRM7_MASK

/* **** 25.9.2009 10:57:34 */

#define ADCCV1H                          ADCCVH
#define ADCCV1H_CV18                     ADCCVH_CV8 
#define ADCCV1H_CV19                     ADCCVH_CV9 
#define ADCCV1H_CV110                    ADCCVH_CV10
#define ADCCV1H_CV111                    ADCCVH_CV11
#define ADCCV1H_CV_18                    ADCCVH_CV_8
#define ADCCV1H_CV1_10                   This_symb_has_been_depreciated
#define ADCCV1H_CV                       This_symb_has_been_depreciated
#define ADCCV1H_CV1                      ADCCVH_CV
#define ADCCV1H_CV18_MASK                ADCCVH_CV8_MASK
#define ADCCV1H_CV19_MASK                ADCCVH_CV9_MASK
#define ADCCV1H_CV110_MASK               ADCCVH_CV10_MASK
#define ADCCV1H_CV111_MASK               ADCCVH_CV11_MASK
#define ADCCV1H_CV_18_MASK               ADCCVH_CV_8_MASK
#define ADCCV1H_CV_18_BITNUM             ADCCVH_CV_8_BITNUM
#define ADCCV1H_CV1_10_MASK              This_symb_has_been_depreciated
#define ADCCV1H_CV1_10_BITNUM            This_symb_has_been_depreciated
#define ADCCV1L                          ADCCVL
#define ADCCV1L_CV10                     ADCCVL_CV0
#define ADCCV1L_CV11                     ADCCVL_CV1
#define ADCCV1L_CV12                     ADCCVL_CV2
#define ADCCV1L_CV13                     ADCCVL_CV3
#define ADCCV1L_CV14                     ADCCVL_CV4
#define ADCCV1L_CV15                     ADCCVL_CV5
#define ADCCV1L_CV16                     ADCCVL_CV6
#define ADCCV1L_CV17                     ADCCVL_CV7
#define ADCCV1L_CV10_MASK                ADCCVL_CV0_MASK
#define ADCCV1L_CV11_MASK                ADCCVL_CV1_MASK
#define ADCCV1L_CV12_MASK                ADCCVL_CV2_MASK
#define ADCCV1L_CV13_MASK                ADCCVL_CV3_MASK
#define ADCCV1L_CV14_MASK                ADCCVL_CV4_MASK
#define ADCCV1L_CV15_MASK                ADCCVL_CV5_MASK
#define ADCCV1L_CV16_MASK                ADCCVL_CV6_MASK
#define ADCCV1L_CV17_MASK                ADCCVL_CV7_MASK
#define ADCCV1                           ADCCV

/* **** 27.11.2009 11:30:38 */

#define PPAGE_XA16                       This_symb_has_been_depreciated
#define PPAGE_XA16_MASK                  This_symb_has_been_depreciated
#endif
