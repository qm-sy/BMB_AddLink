#include "eeprom_crl.h"

EEPROM_INFO eeprom;

/**
 * @brief	eeprom状态判定，是否写入过
 *
 * @param   
 *
 * @return  void
**/
void eeprom_statu_judge( void )
{
    uint8_t eeprom_statu_flag;

    eeprom_statu_flag = ISP_Read(EEPROM_STATU_JUDGE);
   
    if( eeprom_statu_flag == 0xFF)
    {
        eeprom.stop_time   = 180;
        eeprom.delay_time  = 30;          //011 011 11 pwm7、8默认开，3档风速
        eeprom_data_record(); 
    }
    eeprom_data_init();    
}

/**
 * @brief	eeprom 数据写入
 *
 * @param   
 *
 * @return  void
**/
void eeprom_data_record( void )
{
    ISP_Earse(0x0000);

    ISP_Write(STOP_DELAY,eeprom.stop_time);
    ISP_Write(WARNING_DELAY,eeprom.delay_time);
    
    ISP_Write(EEPROM_STATU_JUDGE,0x58);
}


/**
 * @brief	eeprom 数据初始化
 *
 * @param   
 *
 * @return  void
**/
void eeprom_data_init( void )
{
    eeprom.stop_time = ISP_Read(STOP_DELAY); 
    level.motor_stop_time = eeprom.stop_time * 100;

    eeprom.delay_time = ISP_Read(WARNING_DELAY);
    level.motor_delay_time = eeprom.delay_time * 100;
}
