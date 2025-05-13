#include "main.h"

void main( void )
{
    P_SW2 |= 0x80;
    
    GPIO_Init();
    Timer0_Init();
    Timer1_Init();

    Uart1_Init();
    Uart1_Send_Statu_Init();

    motor_init();
    level_params_init();
    speak_param_init();
    get_ball_level();

    EA = 1;
    eeprom_statu_judge();
    printf("========== code start ========== \r\n");

    INK_OUT = 1;
    delay_ms(2000);
    INK_OUT = 0;
    while (1)
    {
        level_statu();
        key_reset();
        Modbus_Event();
        get_ball_level();
    }  
}