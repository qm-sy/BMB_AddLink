/*
|P0^0|:LEVEL4_L |P1^0|:LEVEL5_H  |P2^0|:MOTOR4    |P3^0|:RX1       |P4^0|          |P5^0|     
|P0^1|:LEVEL6_H |P1^1|:LEVEL3_L  |P2^1|:MOTOR5    |P3^1|:TX1       |P4^1|          |P5^1|     
|P0^2|:LEVEL6_L |P1^2|:LEVEL3_H  |P2^2|:DC24V_1   |P3^2|:DC24V_2   |P4^2|          |P5^2|     
|P0^3|:LEVEL5_L |P1^3|:LEVEL1_L  |P2^3|:MOTOR6    |P3^3|:MOTOR1    |P4^3|          |P5^3|     
|P0^4|          |P1^4|:LEVEL1_H  |P2^4|:RESET     |P3^4|:MOTOR2    |P4^4|          |P5^4|:buzzer
|P0^5|          |P1^5|           |P2^5|:LEVEL2_L  |P3^5|:MOTOR3    |P4^5|          |P5^5|             
|P0^6|          |P1^6|           |P2^6|:LEVEL2_H  |P3^6|           |P4^6|          |P5^6|     
|P0^7|          |P1^7|           |P2^7|:LEVEL4_H  |P3^7|           |P4^7|          |P5^7|     
*/ 

#ifndef _GPIO_H_
#define _GPIO_H_

#include "sys.h"

void GPIO_Init( void );

sbit buzzer      = P5^4;

sbit LEVEL1_L    = P1^3;
sbit LEVEL1_H    = P1^4;

sbit LEVEL2_L    = P2^6;
sbit LEVEL2_H    = P2^5;

sbit LEVEL3_L    = P1^2;
sbit LEVEL3_H    = P1^1;

sbit LEVEL4_L    = P2^7;
sbit LEVEL4_H    = P0^0;

sbit LEVEL5_L    = P1^0;
sbit LEVEL5_H    = P0^3;

sbit LEVEL6_L    = P0^1;
sbit LEVEL6_H    = P0^2;

sbit MOTOR1      = P3^3;
sbit MOTOR2      = P3^4;
sbit MOTOR3      = P3^5;
sbit MOTOR4      = P2^0;
sbit MOTOR5      = P2^1;
sbit MOTOR6      = P2^3;

sbit RESET       = P2^4;

sbit INK_OUT       = P2^2;
sbit INK_OVERFLOW  = P3^2;

#endif