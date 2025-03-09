/*
|P0^0|:LEVEL4_L |P1^0|:LEVEL5_H  |P2^0|:MOTOR4    |P3^0|           |P4^0|          |P5^0|     
|P0^1|:LEVEL6_H |P1^1|:LEVEL3_L  |P2^1|           |P3^1|           |P4^1|          |P5^1|     
|P0^2|:LEVEL6_L |P1^2|:LEVEL3_H  |P2^2|:MOTOR6    |P3^2|           |P4^2|          |P5^2|     
|P0^3|:LEVEL5_L |P1^3|:LEVEL1_L  |P2^3|:MOTOR5    |P3^3|:MOTOR1    |P4^3|          |P5^3|     
|P0^4|          |P1^4|:LEVEL1_H  |P2^4|:RESET     |P3^4|:MOTOR2    |P4^4|          |P5^4|:buzzer
|P0^5|          |P1^5|           |P2^5|:LEVEL2_L  |P3^5|:MOTOR3    |P4^5|          |P5^5|             
|P0^6|          |P1^6|           |P2^6|:LEVEL2_H  |P3^6|:RX1       |P4^6|          |P5^6|     
|P0^7|          |P1^7|           |P2^7|:LEVEL4_H  |P3^7|:TX1       |P4^7|          |P5^7|     
*/ 

#include "gpio.h"

/**
 * @brief	GPIO初始化
 *
 * @param   void
 *
 * @return  void
 */
void GPIO_Init( void )
{
    P0M0 = 0x00;    P0M1 = 0x00;        //P0.1为推挽输出，P0.2、P0.3、P0.4为高阻输入
    P1M0 = 0x00;    P1M1 = 0x00;        //1.1为推挽输出,P1.4、P1.5、P1.6、P1.7为高阻输入
    P2M0 = 0x1f;    P2M1 = 0x00;        //P2.0、P2.1、P2.2、P2.3、P2.4为高阻输入
    P3M0 = 0xbc;    P3M1 = 0x00;        //P3.2、P3.3、P3.4、P3.5、P3.7为推挽输出
    P4M0 = 0x00;    P4M1 = 0x00;        //P4.7为推挽输出       
    P5M0 = 0x10;    P5M1 = 0x00;    
}