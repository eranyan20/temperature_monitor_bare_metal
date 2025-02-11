#include "EEPROMService.hpp"

EEPROMService::EEPROMService(I2CDriver& i2cDriver)
    : i2c(i2cDriver), hwRevision(1), serialNumber("ZEISS123") {
}

bool EEPROMService::init() {
    return i2c.init();
}

uint8_t EEPROMService::getHardwareRevision() {
    return hwRevision;
}

std::string EEPROMService::getSerialNumber() {
    return serialNumber;
}
