#ifndef __EEPROM_CRL_H_
#define __EEPROM_CRL_H_

#include "eeprom.h"
#include "sys.h"
#include "level.h"

#define STOP_DELAY       0x0000
#define WARNING_DELAY    0x0001

#define EEPROM_STATU_JUDGE    0X0010         

typedef struct 
{
    uint16_t  delay_time;
    uint16_t  stop_time;            
}EEPROM_INFO;

extern EEPROM_INFO eeprom;

void eeprom_statu_judge( void );
void eeprom_data_record( void );
void eeprom_data_init( void );

#endif