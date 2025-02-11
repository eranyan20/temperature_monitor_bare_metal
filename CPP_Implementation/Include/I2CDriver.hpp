#pragma once
#include <cstdint>
#include <cstddef>

class I2CDriver {
public:
    virtual bool init();
    virtual bool write(uint8_t address, uint8_t* data, size_t length);
    virtual bool read(uint8_t address, uint8_t* data, size_t length);
};