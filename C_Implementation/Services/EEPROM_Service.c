#include "EEPROM_Service.h"
#include "I2C_Driver.h"
#include <stdio.h>

void EEPROM_Init(void) {
    printf("[EEPROM] Initialized\n");
}

EEPROM_Config EEPROM_ReadConfig(void) {
    EEPROM_Config config;
    uint8_t data[17]; // 1 byte for revision + 16 bytes for serial number

    // Simulate I2C read from EEPROM
    I2C_Status status = I2C_Read(0x50, 0x00, data, 17); // EEPROM Slave address = 0x50
    if (status == I2C_SUCCESS) {
        config.revision = data[0];
        for (int i = 0; i < 16; i++) {
            config.serial[i] = data[i + 1]; 
        }
        config.serial[16] = '\0';
    }
    else {
        config.revision = 1; // Rev-B
        //sprintf_s(config.serial, sizeof(config.serial), "ZEISS-1234"); // Default serial number
	sprintf(config.serial, "ZEISS-1234"); // Default serial number

    }

    printf("[EEPROM] Read Config: Revision = %d, Serial = %s\n", config.revision, config.serial);
    return config;
}
