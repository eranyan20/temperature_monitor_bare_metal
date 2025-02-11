#include <iostream>

#include <chrono>
#include <thread>
#include "ConsoleVisualizer.hpp"
#include "ADCDriver.hpp"
#include "GPIODriver.hpp"
#include "I2CDriver.hpp"
#include "EEPROMService.hpp"
#include "LEDService.hpp"
#include "TemperatureService.hpp"
#include "Microcontroller.hpp"

int main() {

    // Initialize system
    Microcontroller mcu;

    mcu.System_Init();
    mcu.Timer_Init(100); // 100µs interval
    mcu.Timer_Start();

    I2CDriver i2c;
    ADCDriver adc;
    GPIODriver gpio;

    EEPROMService eeprom(i2c);
    LEDService ledService(gpio);
    TemperatureService tempService(adc, eeprom, ledService);

    i2c.init();
    adc.init();
    gpio.init();
    eeprom.init();
    ledService.init();
    tempService.init();

    std::cout << "Temperature Monitoring and Visualizer System\n";
    std::cout << "Hardware Revision: " << (eeprom.getHardwareRevision() == 0 ? "Rev-A" : "Rev-B") << "\n";
    std::cout << "Serial Number: " << eeprom.getSerialNumber() << "\n\n";

    while (true) {
        float temperature = tempService.readTemperature();
        //mcu.TIMER_IRQHandler();  // Simulating timer interrupt

        //ConsoleVisualizer::clearScreen();
        ConsoleVisualizer::drawTemperatureGauge(temperature);
        ConsoleVisualizer::drawLEDStatus(ledService);

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return 0;
}
