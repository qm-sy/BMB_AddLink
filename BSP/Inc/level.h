#ifndef __LEVEL_H_
#define __LEVEL_H_

#include "gpio.h"

typedef struct 
{
    #define MOTOR_WARNING_DELAY     2000
    uint8_t     motor1_flag;          //motor1
    uint8_t     motor2_flag;          //motor1
    uint8_t     motor3_flag;          //motor1
    uint8_t     motor4_flag;          //motor1
    uint8_t     motor5_flag;          //motor1
    uint8_t     motor6_flag;          //motor1

    uint8_t     motor1_warning_flag;          //motor1
    uint8_t     motor2_warning_flag;          //motor1
    uint8_t     motor3_warning_flag;          //motor1
    uint8_t     motor4_warning_flag;          //motor1
    uint8_t     motor5_warning_flag;          //motor1
    uint8_t     motor6_warning_flag;          //motor1

    uint16_t    motor1_delay_t1;
    uint16_t    motor2_delay_t1;
    uint16_t    motor3_delay_t1;
    uint16_t    motor4_delay_t1;
    uint16_t    motor5_delay_t1;
    uint16_t    motor6_delay_t1;

    uint16_t    motor1_delay_t2;
    uint16_t    motor2_delay_t2;
    uint16_t    motor3_delay_t2;
    uint16_t    motor4_delay_t2;
    uint16_t    motor5_delay_t2;
    uint16_t    motor6_delay_t2;

    uint16_t    motor_warning_delay;
    uint16_t    motor_stop_delay;
}LEVEL;

extern LEVEL level;

void level_scan( void );

#endif