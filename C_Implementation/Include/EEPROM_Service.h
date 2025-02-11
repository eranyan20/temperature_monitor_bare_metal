#ifndef EEPROM_H
#define EEPROM_H

#include <stdint.h>

typedef struct {
    uint8_t revision; // 0 for Rev-A, 1 for Rev-B
    char serial[16];  // Hardware serial number
} EEPROM_Config;

void EEPROM_Init(void);
EEPROM_Config EEPROM_ReadConfig(void);

#endif // EEPROM_H