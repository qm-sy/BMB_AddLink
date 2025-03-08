#include "main.h"

void main( void )
{
    P_SW2 |= 0x80;
    
    GPIO_Init();
    Timer0_Init();
    
    printf("========== code start ========== \r\n");

    while (1)
    {
        level_scan();
    }  
}