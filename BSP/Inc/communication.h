#ifndef __COMMUNICATION_H_
#define __COMMUNICATION_H_

#include "uart.h"
#include "sys.h"
#include "delay.h"
#include "gpio.h"

typedef struct 
{
    uint8_t     TX_busy_Flag;          //等待发送标志位
    uint8_t     RX_rev_end_Flag;       //数据包接收完毕标志
    uint8_t     TX_buf[24];           //SBUF TI缓冲区
    uint8_t     RX_buf[24];           //SBUF RI缓冲区
    uint8_t     TX_send_bytelength;    //发送字节数
    uint8_t     TX_send_cnt;           //发送计数
    uint16_t    RX_rev_timeout;        //接收超时
    uint8_t     RX_rev_cnt;            //接收计数
    uint8_t     send_scan_flag;
}RS485;

extern RS485 rs485;

void Uart1_Send_Statu_Init( void );
void Uart1_Sendbyte( uint8_t dat );
void Uart1_SendStr( uint8_t *sendstr );

char putchar(char c);

#endif