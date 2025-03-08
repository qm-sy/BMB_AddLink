#include "uart.h"

/**
 * @brief	串口2初始化函数--tim2
 *
 * @param   
 *
 * @return  void
**/
void Uart1_Init( void )       //115200bps@11.0592MHz  16位自动装载
{
    P_SW2 |= 0X00;           //串口1功能脚选择P3.0 P3.1

	SCON   = 0x50;           //8位数据,可变波特率

    AUXR  |= 0x01;		     //串口1选择定时器2为波特率发生器
	AUXR  |= 0x04;           //定时器时钟1T模式

	T2L    = 0xE8;           //设置定时初始值
	T2H    = 0xFF;           //设置定时初始值

	AUXR  |= 0x10;           //定时器2开始计时

	IE2   |= 0X01;			//串口2 中断允许位
}

void Uart1_ISR() interrupt 4 
{   
    if(TI == 1)
    {
        TI = 0;
    }
    
    if(RI == 1)
    {
        RI = 0;
    }
}

void Uart1_Sendbyte(uint8_t dat)
{
    while(TI);
    TI = 1;
    SBUF = dat;
}

void Uart1_SendStr(uint8_t *sendstr)
{   
    while(*sendstr)
    {
        Uart1_Sendbyte(*sendstr++);
    }
}

char putchar(char c)  // 串口重定向需要添加头文件stdio.h
{
    SBUF = c;
    while(!TI);
    TI = 0;
    return c;
}