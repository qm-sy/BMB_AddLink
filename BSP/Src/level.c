#include "level.h"

LEVEL level;

void level_scan( void )
{
    if( LEVEL1_L == 0 )
    {
        /*  下浮球下落，电机启动并计时    */
        MOTOR1 = 1;
        level.motor1_flag = 1;
    }
    
    
    if( LEVEL2_L == 0 )
    {
        MOTOR2 = 1;
        level.motor2_flag = 1;
    }

    if( LEVEL3_L == 0 )
    {
        MOTOR3 = 1;
        level.motor3_flag = 1;
    }

    if( LEVEL4_L == 0 )
    {
        MOTOR4 = 1;
        level.motor4_flag = 1;
    }

    if( LEVEL5_L == 0 )
    {
        MOTOR5 = 1;
        level.motor5_flag = 1;
    }

    if( LEVEL6_L == 0 )
    {
        MOTOR6 = 6;
        level.motor6_flag = 1;
    }
}