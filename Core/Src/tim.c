#include "tim.h"

void Timer0_Init()         //11.0592Mhz  10ms
{
	AUXR &= 0x7F;			//定时器时钟12T模式
	TMOD &= 0xF0;			//设置定时器模式
	TL0 = 0x00;				//设置定时初始值
	TH0 = 0xDC;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时

	ET0 = 1;                //打开IE-ET0，TIM0中断
}

void Tim0Isr(void) interrupt 1 
{
    /*  补墨并计时    */
    if( level.motor1_flag == 1 )
    {
        if( LEVEL1_L == 0 )     //下浮球处于低位，开始补墨并计时t1
        {
            level.motor1_delay_t1++;

            /*  1.如果t1时间后下浮球仍处于低位  */
            if( level.motor1_delay_t1 == level.motor_warning_delay )
            {
                /*  2.判断为墨桶缺墨，发出报警  */
                DC24V_OUT1 = 1;

                MOTOR1 = 0;

                level.motor1_flag  = 0;
                level.motor1_delay_t1 = 0;
                level.motor1_warning_flag = 1;
            }
        }else                   //下浮球处于低位，开始补墨并计时t2
        {
            level.motor1_delay_t2++;

            /*  1.t2补墨时间到  */
            if( level.motor1_delay_t2 == level.motor_stop_delay )
            {
                /*  2.电机停止  */
                MOTOR1 = 0;

                level.motor1_flag  = 0;
                level.motor1_delay_t1 = 0;
                level.motor1_delay_t2 = 0;
            }
        }
        if( LEVEL1_H == 1 ) //上浮球处于高位
        {
            /*  1.未知原因导致墨水溢出 电机停止并报警  */
            DC24V_OUT2 = 1;

            MOTOR1 = 0;

            level.motor1_flag  = 0;
            level.motor1_delay_t1 = 0;
            level.motor1_delay_t2 = 0;
        }
    }

    if( level.motor1_warning_flag & level.motor2_warning_flag & level.motor3_warning_flag    \
       &level.motor4_warning_flag & level.motor5_warning_flag & level.motor6_warning_flag == 0 )   
       {
            buzzer = 0;
       }else
       {
            buzzer = 1;
       }
    
}
