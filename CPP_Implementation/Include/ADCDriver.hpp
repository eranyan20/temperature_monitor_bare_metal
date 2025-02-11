#pragma once
#include <cstdint>

class ADCDriver {
private:
    float currentTemp;
    float step;
    bool increasing;

public:
    ADCDriver();
    bool init();
    uint16_t readChannel();
};
