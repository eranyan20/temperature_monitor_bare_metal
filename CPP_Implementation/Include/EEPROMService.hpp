#pragma once
#include "I2CDriver.hpp"
#include <string>

class EEPROMService {
private:
    I2CDriver& i2c;
    uint8_t hwRevision;
    std::string serialNumber;

public:
    explicit EEPROMService(I2CDriver& i2cDriver);
    bool init();
    uint8_t getHardwareRevision();
    std::string getSerialNumber();
};