#include "../ADCDriver.hpp"

ADCDriver::ADCDriver() : currentTemp(-5.0f), step(1.0f), increasing(true) {}

bool ADCDriver::init() {
    return true;
}

uint16_t ADCDriver::readChannel() {
    if (increasing) {
        currentTemp += step;
        if (currentTemp >= 120.0f) {
            increasing = false;
        }
    }
    else {
        currentTemp -= step;
        if (currentTemp <= -5.0f) {
            increasing = true;
        }
    }
    return static_cast<uint16_t>(currentTemp * 10);
}

