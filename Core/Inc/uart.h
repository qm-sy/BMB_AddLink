#ifndef _UART_H_
#define _UART_H_

#include "sys.h"

void Uart1_Init( void );
void Uart1_Sendbyte(uint8_t dat);
void Uart1_SendStr(uint8_t *sendstr);
char putchar(char c);

#endif