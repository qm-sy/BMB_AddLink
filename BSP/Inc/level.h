#ifndef __LEVEL_H_
#define __LEVEL_H_

#include "gpio.h"
#include "delay.h"
#include "communication.h"

#define MOTOR_ON    1
#define MOTOR_OFF   0

#define BUZZER_ON   0
#define BUZZER_OFF  1

#define BALL_H_UP    0
#define BALL_H_DOWN  1

#define BALL_L_UP    1
#define BALL_L_DOWN  0

extern uint8_t level1_l, level2_l, level3_l, level4_l;
extern uint8_t level1_h, level2_h, level3_h, level4_h;

typedef struct 
{
    uint16_t    level1_h_cnt;
    uint16_t    level2_h_cnt;
    uint16_t    level3_h_cnt;
    uint16_t    level4_h_cnt;

    uint16_t    motor_stop_time;
    uint16_t    motor_delay_time;

    uint8_t    ink_overflow_flag;
    uint8_t    ink_overflow_cnt;
    uint8_t    ink_overflow_allow;

    uint8_t     level1_allow_flag;
    uint8_t     motor1_start_flag;          
    uint16_t    motor1_stop_cnt;
    uint8_t     motor1_delay_flag;    
    uint16_t    motor1_delay_cnt;
    uint8_t     motor1_warning_flag;    


    uint8_t     level2_allow_flag;
    uint8_t     motor2_start_flag;          
    uint8_t     motor2_delay_flag;     
    uint16_t    motor2_delay_cnt;
    uint16_t    motor2_stop_cnt;
    uint8_t     motor2_warning_flag;  

    uint8_t     level3_allow_flag;
    uint8_t     motor3_start_flag;          
    uint8_t     motor3_delay_flag;     
    uint16_t    motor3_delay_cnt;
    uint16_t    motor3_stop_cnt;
    uint8_t     motor3_warning_flag;  
    
    uint8_t     level4_allow_flag;
    uint8_t     motor4_start_flag;          
    uint8_t     motor4_delay_flag;     
    uint16_t    motor4_delay_cnt;
    uint16_t    motor4_stop_cnt;
    uint8_t     motor4_warning_flag;  
    
    uint8_t     level5_allow_flag;
    uint8_t     motor5_start_flag;          
    uint8_t     motor5_delay_flag;     
    uint16_t    motor5_delay_cnt;
    uint16_t    motor5_stop_cnt;
    uint8_t     motor5_warning_flag;  

    uint8_t     level6_allow_flag;
    uint8_t     motor6_start_flag;          
    uint8_t     motor6_delay_flag;     
    uint16_t    motor6_delay_cnt;
    uint16_t    motor6_stop_cnt;
    uint8_t     motor6_warning_flag;  
}LEVEL;

typedef struct 
{
    uint8_t  buzzer_start_flag;
    uint16_t buzzer_runing_cnt;
    uint8_t  buzzer_statu;
    uint8_t  buzzer_start_allow;
}SPEAK;

extern LEVEL level;

void level_params_init( void );
void speak_param_init( void );
void motor_init( void );
void level_statu( void );
void key_reset( void );
void level1_scan( void );
void level2_scan( void );
void level3_scan( void );
void level4_scan( void );
void level5_scan( void );
void level6_scan( void );
void get_ball_level( void );

#endif