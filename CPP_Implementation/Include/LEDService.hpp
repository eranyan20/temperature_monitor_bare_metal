#pragma once
#include "GPIODriver.hpp"

class LEDService {
private:
    GPIODriver& gpio;
    bool greenState, yellowState, redState;

public:
    explicit LEDService(GPIODriver& gpioDriver);
    bool init();
    void updateLEDs(float temperature);
    bool getGreenState() const;
    bool getYellowState() const;
    bool getRedState() const;
};