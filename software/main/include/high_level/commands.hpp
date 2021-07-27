// *************************************************************************
//
// Copyright (c) 2021 Andrei Gramakov. All rights reserved.
//
// This file is licensed under the terms of the MIT license.  
// For a copy, see: https://opensource.org/licenses/MIT
//
// site:    https://agramakov.me
// e-mail:  mail@agramakov.me
//
// *************************************************************************

#pragma once

#define CMD_NONE (-1U)
#define CMD_DONE (0)

#define CMD_FORWARD 119     // char 'w'
#define CMD_BACKWARD 115    // char 's'
#define CMD_LEFT 97         // char 'a'
#define CMD_RIGHT 100       // char 'd'
#define CMD_SHIVER 0x71     // char 'q'
#define CMD_STOP_KB 0x20    // char 'Space'
#define CMD_STOP 0xA0

#define CMD_SPEED0 0x30 // char '0'
#define CMD_SPEED1 0x31 // char '1'
#define CMD_SPEED2 0x32 // char '2'
#define CMD_SPEED3 0x33 // char '3'

#define CMD_MPU_CALIBRATE 99 // char 'c'
#define CMD_SET_ARG_TO_30 35 // char '#'
#define CMD_TEST 0x74        // char 't'

void S1(void);
void S2(void);
void SMAX(void);
void W(void);
void A(void);
void S(void);
void D(void);
void Stop(void);
void Shiver(void);
void set_arg_to_30(void);
