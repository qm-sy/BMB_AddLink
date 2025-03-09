#include "main.h"

void main( void )
{
    P_SW2 |= 0x80;
    
    GPIO_Init();
    Timer0_Init();
    Timer1_Init();

    Uart1_Init();
    Uart1_Send_Statu_Init();


    level_params_init();
    speak_param_init();
    motor_init();

    EA = 1;
    eeprom_statu_judge();
    printf("========== code start ========== \r\n");

    while (1)
    {
        level_statu();
        key_reset();
        Modbus_Event();
    }  
}