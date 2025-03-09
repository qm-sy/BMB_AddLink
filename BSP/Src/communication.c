#include "communication.h"

RS485 rs485;

/**
 * @brief	串口1调用结构体 rs485 初始化
 *
 * @param   
 *
 * @return  void
**/
void Uart1_Send_Statu_Init( void )
{
    rs485.TX_busy_Flag = 0;
    rs485.RX_rev_end_Flag = 0;
    rs485.TX_buf[24] = 0;
    rs485.RX_buf[24] = 0;
    rs485.TX_send_bytelength = 0;
    rs485.TX_send_cnt = 0;
    rs485.RX_rev_timeout = 0;
    rs485.RX_rev_cnt = 0;
    rs485.send_scan_flag = 0;
}

void Uart1_ISR() interrupt 4 
{   
    
    /* 1, 检测到硬件将S2TI置1，即发送完毕                       */
    if( TI )          //
    {
        /* 2, 软件将S2TI清零，等待发送标志位重置，可继续发送    */
        TI = 0;         
        rs485.TX_busy_Flag = 0;
        
        /* 3, 依次将TX_buf中数据送出（写S2BUF操作即为发送）    */
        if( rs485.TX_send_bytelength != 0 )
        {
            SBUF = rs485.TX_buf[rs485.TX_send_cnt++];
            rs485.TX_send_bytelength--;
        }else
        {
            rs485.TX_send_cnt = 0;
        }
    }
    
    /* 1, 检测到硬件将S2RI置1，即接收完毕                       */
    if( RI )
    {
        /* 2, 软件将S2RI清零，等待接收标志位重置，可继续发送    */
        RI = 0;

        /* 3, 判断数据包是否接收完毕                           */
        if( !rs485.RX_rev_end_Flag )
        {
            /* 4, 数据包大于RX_buf 则从头计数                  */
            if( rs485.RX_rev_cnt > 24 )
            {
                rs485.RX_rev_cnt = 0;
            }

            /* 5, 依次将RX_buf中数据接收（读S2BUF操作即为接收）*/
            rs485.RX_buf[rs485.RX_rev_cnt] = SBUF;
            rs485.RX_rev_cnt++;
        }
        /* 6, 重置接收完毕判断时间                              */
        rs485.RX_rev_timeout = 50;
    }
}

// void Uart1_Sendbyte(uint8_t dat)
// {
//     while(TI);
//     TI = 1;
//     SBUF = dat;
// }

// void Uart1_SendStr(uint8_t *sendstr)
// {   
//     while(*sendstr)
//     {
//         Uart1_Sendbyte(*sendstr++);
//     }
// }

char putchar(char c)  // 串口重定向需要添加头文件stdio.h
{
    SBUF = c;
    while(!TI);
    TI = 0;
    return c;
}