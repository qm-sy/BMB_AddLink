#include "level.h"

LEVEL level;
SPEAK speak;
BALL ball;
uint8_t level1_l, level2_l, level3_l, level4_l = BALL_L_ON;
uint8_t level1_h, level2_h, level3_h, level4_h = BALL_H_OFF;
uint8_t* level[8] = {&level1_l, &level1_h, &level2_l, &level2_h, &level3_l, &level3_h, &level4_l, &level4_h}; // arr[0] 存储a的地址

void level_params_init( void )
{
    level.motor_stop_time     = 18000;
    level.motor_delay_time    = 3000;
    level.level1_allow_flag   = 1;
    level.motor1_start_flag   = 0;          
    level.motor1_delay_flag   = 0;     
    level.motor1_stop_cnt     = 0;
    level.motor1_delay_cnt    = 0;
    level.motor1_warning_flag = 0;

    level.level2_allow_flag   = 1;
    level.motor2_start_flag   = 0;          
    level.motor2_delay_flag   = 0;     
    level.motor2_delay_cnt    = 0;
    level.motor2_stop_cnt     = 0;
    level.motor2_warning_flag = 0;

    level.level3_allow_flag   = 1;
    level.motor3_start_flag   = 0;          
    level.motor3_delay_flag   = 0;     
    level.motor3_delay_cnt    = 0;
    level.motor3_stop_cnt     = 0;
    level.motor3_warning_flag = 0;

    level.level4_allow_flag   = 1;
    level.motor4_start_flag   = 0;          
    level.motor4_delay_flag   = 0;     
    level.motor4_delay_cnt    = 0;
    level.motor4_stop_cnt     = 0;
    level.motor4_warning_flag = 0;

    level.level5_allow_flag   = 1;
    level.motor5_start_flag   = 0;          
    level.motor5_delay_flag   = 0;     
    level.motor5_delay_cnt    = 0;
    level.motor5_stop_cnt     = 0;
    level.motor5_warning_flag = 0;

    level.level6_allow_flag   = 1;
    level.motor6_start_flag   = 0;          
    level.motor6_delay_flag   = 0;     
    level.motor6_delay_cnt    = 0;
    level.motor6_stop_cnt     = 0;
    level.motor6_warning_flag = 0;
}


void speak_param_init( void )
{
    speak.buzzer_start_flag = 0;
    speak.buzzer_runing_cnt = 0;
    speak.buzzer_statu      = 0;
}

void motor_init( void )
{
    MOTOR1 = MOTOR_OFF;
    MOTOR2 = MOTOR_OFF;
    MOTOR3 = MOTOR_OFF;
    MOTOR4 = MOTOR_OFF;
    MOTOR5 = MOTOR_OFF;
    MOTOR6 = MOTOR_OFF;

    level.ink_out_flag   = 0;
    level.ink_out_alarm = 0;
    level.ink_overflow_flag  = 0;
    level.ink_overflow_alarm = 0;
    INK_OUT = 0;
    INK_OVERFLOW = 0;
}


void key_reset( void )
{
    while ( RESET == 0 )
    {
        delay_ms(100);
        if( RESET == 0 )
        {
            MOTOR1 = MOTOR_OFF;
            MOTOR2 = MOTOR_OFF;
            MOTOR3 = MOTOR_OFF;
            MOTOR4 = MOTOR_OFF;
            buzzer = 1;
            // MOTOR5 = MOTOR_OFF;
            // MOTOR6 = MOTOR_OFF;
            INK_OUT = 0;
            
           
            level.ink_out_flag   = 0;
            level.ink_out_alarm = 0;
            level.ink_out_cnt = 0;
            level.ink_overflow_flag  = 0;
            level.ink_overflow_alarm = 0;
            level.ink_overflow_cnt = 0;
    
            level.level1_allow_flag    = 1;
            level.motor1_warning_flag  = 0;

            level.level2_allow_flag    = 1;
            level.motor2_warning_flag  = 0;

            level.level3_allow_flag    = 1;
            level.motor3_warning_flag  = 0;

            level.level4_allow_flag    = 1;
            level.motor4_warning_flag  = 0;

            level.level5_allow_flag    = 1;
            level.motor5_warning_flag  = 0;

            level.level6_allow_flag    = 1;
            level.motor6_warning_flag  = 0;
        }
    }
}


void level_statu( void )
{
    level1_scan();
    level2_scan();
    level3_scan();
    level4_scan();
    level5_scan();
    level6_scan();
    
    if( level.motor1_warning_flag | level.motor2_warning_flag | level.motor3_warning_flag    \
        |level.motor4_warning_flag == 1 )   
    {
        INK_OUT = 1;
        speak.buzzer_start_flag = 1;
        level.ink_out_flag = 1;

    }else
    {
        if((LEVEL1_H != 0)&&(LEVEL2_H != 0)&&(LEVEL3_H != 0)&&(LEVEL4_H != 0))
        {
            //buzzer = 1;
        }else
        {
            speak.buzzer_start_flag = 1;
        }
        
    }     
}


void level1_scan( void )
{
    if( LEVEL1_H != 1 ) //上浮球处于高位
    {
        /*  未知原因导致墨水溢出 电机停止并报警  */
        level.ink_overflow_flag  = 1;

        MOTOR1 = MOTOR_OFF;
        speak.buzzer_start_flag = 1;

        level.level1_allow_flag = 0;
        level.motor1_start_flag = 0;
    }else 
    {
        if( level.level1_allow_flag == 1 )
        {
            if( LEVEL1_L != 1 )
            {
                /*  下浮球下落，电机启动,定时器开始计时    */
                MOTOR1 = MOTOR_ON;
                level.level1_allow_flag = 0;
    
                level.motor1_stop_cnt = 0;
                level.motor1_delay_cnt    = 0;
                level.motor1_start_flag  = 1;
            }
        }
    }
}


void Tim0Isr(void) interrupt 1 
{
   /*  levle1 补墨并计时    */
   if( level.motor1_start_flag == 1 )
   {
        if( level.motor1_delay_flag == 0 )
        {
            level.motor1_stop_cnt++;
            if( LEVEL1_L != 0 )
            {
                level.motor1_stop_cnt = 0;
                level.motor1_delay_flag = 1;
                
            }
            if( level.motor1_stop_cnt >= level.motor_stop_time ) 
            {
                MOTOR1 = MOTOR_OFF;
                level.motor1_start_flag = 0;
                level.motor1_stop_cnt = 0;
                level.motor1_warning_flag  = 1;
                

            }
        }else
        {
            level.motor1_delay_cnt++;
            if( level.motor1_delay_cnt >= level.motor_delay_time )
            {
                MOTOR1 = MOTOR_OFF;
                level.motor1_start_flag = 0;
                level.motor1_delay_flag = 0;
                level.motor1_delay_cnt  = 0;
                level.level1_allow_flag = 1;
                
            }
        }
   }

   /*  levle2 补墨并计时    */
   

   /*  levle3 补墨并计时    */
  

   /*  levle4 补墨并计时    */
   


}

void Tim1Isr(void) interrupt 3 
{
    /* 1, 如果接收未超时                                             */
    if ( rs485.RX_rev_timeout != 0 )  
    {
        rs485.RX_rev_timeout--;
        /* 2, 如果接收超时                                          */
        if( rs485.RX_rev_timeout == 0 )  
        {
            if( rs485.RX_rev_cnt > 0 )  
            {   
                    /* 3, 接收完毕标志位亮起并初始化接收缓冲区         */
                rs485.RX_rev_end_Flag = 1;    
            }
        }
    } 

    if( speak.buzzer_start_flag == 1 ) 
    {
        speak.buzzer_runing_cnt++;
        if( speak.buzzer_runing_cnt == 50 )
        {
            speak.buzzer_runing_cnt = 0;
            speak.buzzer_statu = 1 - speak.buzzer_statu;
            if(speak.buzzer_statu ==0)
            {
                buzzer = 1;
            }else
            {
                buzzer = 0;
            }
        
        }
    }else
    {
        speak.buzzer_runing_cnt = 0;
    }


   

    if(( level.ink_overflow_flag == 1 ) && (level.ink_overflow_alarm == 0))
    {
        level.ink_overflow_cnt ++;
        INK_OVERFLOW = 1;
        if( level.ink_overflow_cnt == 100 )
        {
            INK_OVERFLOW = 0;
            level.ink_overflow_flag = 0;
            level.ink_overflow_alarm = 1;  
            level.ink_overflow_cnt = 0;
        }
    }
}

void get_ball_level( void )
{
    uint8_t i = 0;
    uint8_t j = 0;
    uint8_t k = 0;
    uint8_t level_statu = 0;
    for( i = 0; i < 10; i++ )
    {
        switch (i)
        {
            case 0:
                level_statu = LEVEL1_L;
                break;

            case 1:
                level_statu = LEVEL1_H;
                break;

            case 2:
                level_statu = LEVEL1_H;
                break;

            case 3:
                level_statu = LEVEL1_H;
                break;

            case 4:
                level_statu = LEVEL1_H;
                break;

            case 5:
                level_statu = LEVEL1_H;
                break;

            case 6:
                level_statu = LEVEL1_H;
                break;

            case 7:
                level_statu = LEVEL1_H;
                break;

            default:
                break;
        }
        if( LEVEL1_H == 0 )
        {
            j++;
        }else
        {
            k++;
        }
    }
    if( j >= k )
    {
        level[i] = 0;
    }else
    {
        level[i] = 1;
    }
}