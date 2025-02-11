#pragma once
#include "ADCDriver.hpp"
#include "EEPROMService.hpp"
#include "LEDService.hpp"

class TemperatureService {
private:
    ADCDriver& adc;
    EEPROMService& eeprom;
    LEDService& ledService;
    float lastTemperature;

public:
    TemperatureService(ADCDriver& adcDriver, EEPROMService& eepromService, LEDService& ledServ);
    bool init();
    float readTemperature();
};