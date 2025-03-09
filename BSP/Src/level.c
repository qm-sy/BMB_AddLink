#include "level.h"

LEVEL level;
SPEAK speak;

void level_params_init( void )
{
    level.level1_allow_flag   = 1;
    level.motor1_start_flag   = 0;          
    level.motor1_warning_flag = 0;     
    level.motor1_warning_cnt  = 0;
    level.motor1_stop_cnt     = 0;

    level.level2_allow_flag   = 1;
    level.motor2_start_flag   = 0;          
    level.motor2_warning_flag = 0;     
    level.motor2_warning_cnt  = 0;
    level.motor2_stop_cnt     = 0;


    level.level3_allow_flag   = 1;
    level.motor3_start_flag   = 0;          
    level.motor3_warning_flag = 0;     
    level.motor3_warning_cnt  = 0;
    level.motor3_stop_cnt     = 0;


    level.level4_allow_flag   = 1;
    level.motor4_start_flag   = 0;          
    level.motor4_warning_flag = 0;     
    level.motor4_warning_cnt  = 0;
    level.motor4_stop_cnt     = 0;


    level.level5_allow_flag   = 1;
    level.motor5_start_flag   = 0;          
    level.motor5_warning_flag = 0;     
    level.motor5_warning_cnt  = 0;
    level.motor5_stop_cnt     = 0;

    level.level6_allow_flag   = 1;
    level.motor6_start_flag   = 0;          
    level.motor6_warning_flag = 0;     
    level.motor6_warning_cnt  = 0;
    level.motor6_stop_cnt     = 0;
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

    INK_OUT       = 0;
    INK_OVERFLOW  = 0;
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
        |level.motor4_warning_flag | level.motor5_warning_flag | level.motor6_warning_flag == 1 )   
        {
             speak.buzzer_start_flag = 1;
        }
}


void level1_scan( void )
{
    if( LEVEL1_H == 1 ) //上浮球处于高位
    {
        /*  未知原因导致墨水溢出 电机停止并报警  */
        INK_OVERFLOW = 1;

        MOTOR1 = MOTOR_OFF;

        speak.buzzer_start_flag = 1;

        level.level1_allow_flag = 0;
        level.motor1_start_flag = 0;
    }else 
    {
        if( level.level1_allow_flag == 1 )
        {
            if( LEVEL1_L == 0 )
            {
                /*  下浮球下落，电机启动,定时器开始计时    */
                MOTOR1 = MOTOR_ON;
                level.level1_allow_flag = 0;
    
                level.motor1_warning_cnt = 0;
                level.motor1_stop_cnt    = 0;
                level.motor1_start_flag  = 1;
            }
        }
    }
}

void level2_scan( void )
{
    if( LEVEL2_H == 1 ) //上浮球处于高位
    {
        /*  未知原因导致墨水溢出 电机停止并报警  */
        INK_OVERFLOW = 1;

        MOTOR2 = MOTOR_OFF;

        speak.buzzer_start_flag = 1;

        level.level2_allow_flag = 0;
        level.motor2_start_flag = 0;
    }else 
    {
        if( level.level2_allow_flag == 1 )
        {
            if( LEVEL2_L == 0 )
            {
                /*  下浮球下落，电机启动,定时器开始计时    */
                MOTOR2 = MOTOR_ON;
                level.level2_allow_flag = 0;
    
                level.motor2_warning_cnt = 0;
                level.motor2_stop_cnt    = 0;
                level.motor2_start_flag  = 1;
            }
        }
    }
}

void level3_scan( void )
{
    if( LEVEL3_H == 1 ) //上浮球处于高位
    {
        /*  未知原因导致墨水溢出 电机停止并报警  */
        INK_OVERFLOW = 1;

        MOTOR3 = MOTOR_OFF;

        speak.buzzer_start_flag = 1;

        level.level3_allow_flag = 0;
        level.motor3_start_flag = 0;
    }else 
    {
        if( level.level3_allow_flag == 1 )
        {
            if( LEVEL3_L == 0 )
            {
                /*  下浮球下落，电机启动,定时器开始计时    */
                MOTOR3 = MOTOR_ON;
                level.level3_allow_flag = 0;
    
                level.motor3_warning_cnt = 0;
                level.motor3_stop_cnt    = 0;
                level.motor3_start_flag  = 1;
            }
        }
    }
}

void level4_scan( void )
{
    if( LEVEL4_H == 1 ) //上浮球处于高位
    {
        /*  未知原因导致墨水溢出 电机停止并报警  */
        INK_OVERFLOW = 1;

        MOTOR4 = MOTOR_OFF;

        speak.buzzer_start_flag = 1;

        level.level4_allow_flag = 0;
        level.motor4_start_flag = 0;
    }else 
    {
        if( level.level4_allow_flag == 1 )
        {
            if( LEVEL4_L == 0 )
            {
                /*  下浮球下落，电机启动,定时器开始计时    */
                MOTOR4 = MOTOR_ON;
                level.level4_allow_flag = 0;
    
                level.motor4_warning_cnt = 0;
                level.motor4_stop_cnt    = 0;
                level.motor4_start_flag  = 1;
            }
        }
    }
}

void level5_scan( void )
{
    if( LEVEL5_H == 1 ) //上浮球处于高位
    {
        /*  未知原因导致墨水溢出 电机停止并报警  */
        INK_OVERFLOW = 1;

        MOTOR5 = MOTOR_OFF;

        speak.buzzer_start_flag = 1;

        level.level5_allow_flag = 0;
        level.motor5_start_flag = 0;
    }else 
    {
        if( level.level5_allow_flag == 1 )
        {
            if( LEVEL5_L == 0 )
            {
                /*  下浮球下落，电机启动,定时器开始计时    */
                MOTOR5 = MOTOR_ON;
                level.level5_allow_flag = 0;
    
                level.motor5_warning_cnt = 0;
                level.motor5_stop_cnt    = 0;
                level.motor5_start_flag  = 1;
            }
        }
    }
}

void level6_scan( void )
{
    if( LEVEL6_H == 1 ) //上浮球处于高位
    {
        /*  未知原因导致墨水溢出 电机停止并报警  */
        INK_OVERFLOW = 1;

        MOTOR6 = MOTOR_OFF;

        speak.buzzer_start_flag = 1;

        level.level6_allow_flag = 0;
        level.motor6_start_flag = 0;
    }else 
    {
        if( level.level6_allow_flag == 1 )
        {
            if( LEVEL6_L == 0 )
            {
                /*  下浮球下落，电机启动,定时器开始计时    */
                MOTOR6 = MOTOR_ON;
                level.level6_allow_flag = 0;
    
                level.motor6_warning_cnt = 0;
                level.motor6_stop_cnt    = 0;
                level.motor6_start_flag  = 1;
            }
        }
    }
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
            MOTOR5 = MOTOR_OFF;
            MOTOR6 = MOTOR_OFF;

            buzzer = BUZZER_OFF;
            speak.buzzer_start_flag = 0;
            INK_OVERFLOW = 0;
            INK_OUT      = 0;
    
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


void Tim0Isr(void) interrupt 1 
{
   /*  levle1 补墨并计时    */
   if( level.motor1_start_flag == 1 )
   {
       if( LEVEL1_L == 0 )     //下浮球处于低位，开始补墨并计时t1
       {
           level.motor1_warning_cnt++;

           /*  1.如果t1时间后下浮球仍处于低位  */
           if( level.motor1_warning_cnt >= level.motor_warning_delay )
           {
               /*  2.判断为墨桶缺墨，发出报警  */
               INK_OUT = 1;

               MOTOR1 = MOTOR_OFF;

               level.motor1_warning_flag = 1;
               level.motor1_start_flag   = 0;
           }
       }else                   //下浮球处于低位，开始补墨并计时t2
       {
           level.motor1_stop_cnt++;

           /*  1.t2补墨时间到  */
           if( level.motor1_stop_cnt >= level.motor_stop_delay )
           {
               /*  2.电机停止  */
               MOTOR1 = MOTOR_OFF;

               level.motor1_start_flag  = 0;
               level.level1_allow_flag  = 1;
           }
       }
   }

   /*  levle2 补墨并计时    */
   if( level.motor2_start_flag == 1 )
   {
       if( LEVEL2_L == 0 )     //下浮球处于低位，开始补墨并计时t1
       {
           level.motor2_warning_cnt++;

           /*  1.如果t1时间后下浮球仍处于低位  */
           if( level.motor2_warning_cnt >= level.motor_warning_delay )
           {
               /*  2.判断为墨桶缺墨，发出报警  */
               INK_OUT = 1;

               MOTOR2 = MOTOR_OFF;

               level.motor2_warning_flag = 1;
               level.motor2_start_flag   = 0;
           }
       }else                   //下浮球处于低位，开始补墨并计时t2
       {
           level.motor2_stop_cnt++;

           /*  1.t2补墨时间到  */
           if( level.motor2_stop_cnt >= level.motor_stop_delay )
           {
               /*  2.电机停止  */
               MOTOR2 = MOTOR_OFF;

               level.motor2_start_flag  = 0;
               level.level2_allow_flag  = 1;
           }
       }
   }

   /*  levle3 补墨并计时    */
   if( level.motor3_start_flag == 1 )
   {
       if( LEVEL3_L == 0 )     //下浮球处于低位，开始补墨并计时t1
       {
           level.motor3_warning_cnt++;

           /*  1.如果t1时间后下浮球仍处于低位  */
           if( level.motor3_warning_cnt >= level.motor_warning_delay )
           {
               /*  2.判断为墨桶缺墨，发出报警  */
               INK_OUT = 1;

               MOTOR3 = MOTOR_OFF;

               level.motor3_warning_flag = 1;
               level.motor3_start_flag   = 0;
           }
       }else                   //下浮球处于低位，开始补墨并计时t2
       {
           level.motor3_stop_cnt++;

           /*  1.t2补墨时间到  */
           if( level.motor3_stop_cnt >= level.motor_stop_delay )
           {
               /*  2.电机停止  */
               MOTOR3 = MOTOR_OFF;

               level.motor3_start_flag  = 0;
               level.level3_allow_flag  = 1;
           }
       }
   }

   /*  levle4 补墨并计时    */
   if( level.motor4_start_flag == 1 )
   {
       if( LEVEL4_L == 0 )     //下浮球处于低位，开始补墨并计时t1
       {
           level.motor4_warning_cnt++;

           /*  1.如果t1时间后下浮球仍处于低位  */
           if( level.motor4_warning_cnt >= level.motor_warning_delay )
           {
               /*  2.判断为墨桶缺墨，发出报警  */
               INK_OUT = 1;

               MOTOR4 = MOTOR_OFF;

               level.motor4_warning_flag = 1;
               level.motor4_start_flag   = 0;
           }
       }else                   //下浮球处于低位，开始补墨并计时t2
       {
           level.motor4_stop_cnt++;

           /*  1.t2补墨时间到  */
           if( level.motor4_stop_cnt >= level.motor_stop_delay )
           {
               /*  2.电机停止  */
               MOTOR4 = MOTOR_OFF;

               level.motor4_start_flag  = 0;
               level.level4_allow_flag  = 1;
           }
       }
   }
   
   /*  levle5 补墨并计时    */
   if( level.motor5_start_flag == 1 )
   {
       if( LEVEL5_L == 0 )     //下浮球处于低位，开始补墨并计时t1
       {
           level.motor5_warning_cnt++;

           /*  1.如果t1时间后下浮球仍处于低位  */
           if( level.motor5_warning_cnt >= level.motor_warning_delay )
           {
               /*  2.判断为墨桶缺墨，发出报警  */
               INK_OUT = 1;

               MOTOR5 = MOTOR_OFF;

               level.motor5_warning_flag = 1;
               level.motor5_start_flag   = 0;
           }
       }else                   //下浮球处于低位，开始补墨并计时t2
       {
           level.motor5_stop_cnt++;

           /*  1.t2补墨时间到  */
           if( level.motor5_stop_cnt >= level.motor_stop_delay )
           {
               /*  2.电机停止  */
               MOTOR5 = MOTOR_OFF;

               level.motor5_start_flag  = 0;
               level.level5_allow_flag  = 1;
           }
       }
   }

   /*  levle6 补墨并计时    */
   if( level.motor6_start_flag == 1 )
   {
       if( LEVEL6_L == 0 )     //下浮球处于低位，开始补墨并计时t1
       {
           level.motor6_warning_cnt++;

           /*  1.如果t1时间后下浮球仍处于低位  */
           if( level.motor6_warning_cnt >= level.motor_warning_delay )
           {
               /*  2.判断为墨桶缺墨，发出报警  */
               INK_OUT = 1;

               MOTOR6 = MOTOR_OFF;

               level.motor6_warning_flag = 1;
               level.motor6_start_flag   = 0;
           }
       }else                   //下浮球处于低位，开始补墨并计时t2
       {
           level.motor6_stop_cnt++;

           /*  1.t2补墨时间到  */
           if( level.motor6_stop_cnt >= level.motor_stop_delay )
           {
               /*  2.电机停止  */
               MOTOR6 = MOTOR_OFF;

               level.motor6_start_flag  = 0;
               level.level6_allow_flag  = 1;
           }
       }
   }
}

void Tim1Isr(void) interrupt 3 
{
    if( speak.buzzer_start_flag == 1 )
    {
        speak.buzzer_runing_cnt++;
        if( speak.buzzer_runing_cnt == 500 )
        {
            speak.buzzer_runing_cnt = 0;
            speak.buzzer_statu = 1 - speak.buzzer_statu;
            buzzer = speak.buzzer_statu;
        }
    }else
    {
        speak.buzzer_runing_cnt = 0;
    }

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
    
}