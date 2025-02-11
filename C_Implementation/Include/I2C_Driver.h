#ifndef I2C_H
#define I2C_H

#include <stdint.h>

typedef enum {
    I2C_SUCCESS,
    I2C_ERROR,
    I2C_TIMEOUT
} I2C_Status;

void I2C_Init(void);
I2C_Status I2C_Read(uint8_t dev_addr, uint8_t reg_addr, uint8_t* data, uint16_t len);
I2C_Status I2C_Write(uint8_t dev_addr, uint8_t reg_addr, uint8_t* data, uint16_t len);

#endif // I2C_H
