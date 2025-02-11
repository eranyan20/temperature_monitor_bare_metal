#include "../LEDService.hpp"

LEDService::LEDService(GPIODriver& gpioDriver)
    : gpio(gpioDriver), greenState(false), yellowState(false), redState(false) {
}

bool LEDService::init() {
    return gpio.init();
}

void LEDService::updateLEDs(float temperature) {
    greenState = yellowState = redState = false;

    if (temperature < 5.0f || temperature >= 105.0f) {
        redState = true;
    }
    else if (temperature >= 85.0f) {
        yellowState = true;
    }
    else {
        greenState = true;
    }

    gpio.digitalWrite(GPIODriver::GREEN_LED, greenState);
    gpio.digitalWrite(GPIODriver::YELLOW_LED, yellowState);
    gpio.digitalWrite(GPIODriver::RED_LED, redState);
}

bool LEDService::getGreenState() const { return greenState; }
bool LEDService::getYellowState() const { return yellowState; }
bool LEDService::getRedState() const { return redState; }
