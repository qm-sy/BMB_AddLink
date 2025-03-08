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

void Timer1_Init(void)		//10毫秒@11.0592MHz
{
	AUXR &= 0xBF;			//定时器时钟12T模式
	TMOD &= 0x0F;			//设置定时器模式
	TL1   = 0x00;				//设置定时初始值
	TH1   = 0xDC;				//设置定时初始值
	TF1   = 0;				//清除TF1标志
	TR1   = 1;				//定时器1开始计时

    ET1   = 1;                //打开IE-ET1，TIM1中断
}

