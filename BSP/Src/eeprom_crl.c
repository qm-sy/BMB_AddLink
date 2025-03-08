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
        eeprom.warning_time  = 5;          //011 011 11 pwm7、8默认开，3档风速
        eeprom.stop_time     = 10;
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

    ISP_Write(WARNING_DELAY,eeprom.warning_time);
    ISP_Write(STOP_DELAY,eeprom.stop_time);

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
    eeprom.warning_time = ISP_Read(WARNING_DELAY);
    level.motor_warning_delay = eeprom.warning_time * 100;

    eeprom.stop_time = ISP_Read(STOP_DELAY); 
    level.motor_stop_delay = eeprom.stop_time * 100;
}
