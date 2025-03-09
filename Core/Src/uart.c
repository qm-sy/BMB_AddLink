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
    P_SW1 |= 0X40;           //串口1功能脚选择P3.6 P3.7

	SCON   = 0x50;           //8位数据,可变波特率

    AUXR  |= 0x01;		     //串口1选择定时器2为波特率发生器
	AUXR  |= 0x04;           //定时器时钟1T模式

	T2L    = 0xE8;           //设置定时初始值
	T2H    = 0xFF;           //设置定时初始值

	AUXR  |= 0x10;           //定时器2开始计时

	ES    = 1;			    //串口1 中断允许位
}

