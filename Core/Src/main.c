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
    //eeprom_statu_judge();
    printf("========== code start ========== \r\n");

    while (1)
    {
        level_statu();
        key_reset();
        Modbus_Event();
        get_ball_level();
        printf("motor1_stop_cnt is %d \r\n",(int)level.motor1_stop_cnt);
        printf("motor1_delay_cnt is %d \r\n",(int)level.motor1_delay_cnt);
        printf("level1_l is %d \r\n",(int)level1_l);
        printf("level1_h is %d \r\n",(int)level1_h);
        printf("level2_h is %d \r\n",(int)level2_h);
        printf("level3_h is %d \r\n",(int)level3_h);
        printf("level4_h is %d \r\n",(int)level4_h);
        printf("level1_h_cnt is %d \r\n",(int)level.level1_h_cnt);
        printf("level2_h_cnt is %d \r\n",(int)level.level2_h_cnt);
        printf("level3_h_cnt is %d \r\n",(int)level.level3_h_cnt);
        printf("level4_h_cnt is %d \r\n",(int)level.level4_h_cnt);
    }  
}