#include "I2C_Driver.h"
#include <stdio.h>

void I2C_Init(void) {
    printf("[I2C] Initialized\n");
}

I2C_Status I2C_Read(uint8_t dev_addr, uint8_t reg_addr, uint8_t* data, uint16_t len) {
    printf("[I2C] Read from device 0x%02X, register 0x%02X\n", dev_addr, reg_addr);

    // Simulate reading data from EEPROM
    if (dev_addr == 0x50) { // EEPROM address
        data[0] = 1; // Simulate Rev-B
        for (int i = 1; i < len; i++) {
            data[i] = 'A' + (i - 1); // Simulate serial number "ABCDEF"
        }
        return I2C_SUCCESS;
    }

    else {
        return I2C_ERROR; // Simulate I2C error for invalid device address
    }
}

I2C_Status I2C_Write(uint8_t dev_addr, uint8_t reg_addr, uint8_t* data, uint16_t len) {
    printf("[I2C] Write to device 0x%02X, register 0x%02X\n", dev_addr, reg_addr);
    return I2C_SUCCESS;
}
