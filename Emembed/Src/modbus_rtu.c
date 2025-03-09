#include "modbus_rtu.h"

/**
 * @brief	modbus_rtu  无奇偶校验
 *
 * @param   void
 *
 * @return  void 
**/
void Modbus_Event( void )
{
    /*1.接收完毕                                           */
    if( rs485.RX_rev_end_Flag == 1 )
    {
        //printf("here \r\n");
        /*2.清空接收完毕标志位                              */    
        rs485.RX_rev_end_Flag = 0;

        /*3.清空接收计数                                    */
        rs485.RX_rev_cnt = 0; 

        /*4.地址域校验通过，进入相应功能函数进行处理      */
        if( rs485.RX_buf[0] == MY_ADDR )
        {
            eeprom.warning_time = rs485.RX_buf[1];
            eeprom.stop_time    = rs485.RX_buf[2];
            eeprom_data_record();

            level.motor_warning_delay = eeprom.warning_time * 100;
            level.motor_stop_delay    = eeprom.stop_time    * 100;
            
            rs485.TX_buf[0] = 0xAA;
            rs485.TX_buf[1] = 0xCC;
            rs485.TX_send_bytelength = 2;
            TI = 1;
            //printf("here2 \r\n");
        }
    }
}