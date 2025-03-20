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
    

    EA = 1;
    //eeprom_statu_judge();
    printf("========== code start ========== \r\n");

    while (1)
    {
        level_statu();
        key_reset();
        Modbus_Event();
        
        printf("The value of level.motor_stop_time is %d \r\n",(int)level.motor_stop_time);
        printf("The value of level.motor_delay_time is %d \r\n",(int)level.motor_delay_time);
        printf("The value of motor1_stop_cnt is %d \r\n",(int)level.motor1_stop_cnt);
        printf("The value of motor1_delay_cnt is %d \r\n",(int)level.motor1_delay_cnt);
        delay_ms(50);
    }  
}