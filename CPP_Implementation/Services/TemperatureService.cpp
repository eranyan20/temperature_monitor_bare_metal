#include "TemperatureService.hpp"
#include <iostream>

TemperatureService::TemperatureService(ADCDriver& adcDriver, EEPROMService& eepromService, LEDService& ledServ)
    : adc(adcDriver), eeprom(eepromService), ledService(ledServ), lastTemperature(0.0f) {
}

bool TemperatureService::init() {
    return adc.init();
}

float TemperatureService::readTemperature() {

    int16_t rawValue = adc.readChannel();
    float temperature;

    if (eeprom.getHardwareRevision() == 0) {
        temperature = static_cast<float>(rawValue);
    }
    else {
        temperature = static_cast<float>(rawValue) / 10.0f;
        temperature = static_cast<float>(rawValue) / 10.0f;
    }

    lastTemperature = temperature;
    ledService.updateLEDs(temperature);
    return temperature;
}
