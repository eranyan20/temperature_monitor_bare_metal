#pragma once
#include "LEDService.hpp"
#include <iostream>
#include <iomanip>

class ConsoleVisualizer {
public:
    static void clearScreen();
    static void drawTemperatureGauge(float temperature);
    static void drawLEDStatus(const LEDService& ledService);
};