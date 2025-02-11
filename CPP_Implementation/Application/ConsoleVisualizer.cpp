#include "ConsoleVisualizer.hpp"
#include <algorithm>
#include <stdio.h>

#define COLOR_RED     "\x1B[31m"
#define COLOR_YELLOW  "\x1B[33m"
#define COLOR_GREEN   "\x1B[32m"
#define COLOR_RESET   "\x1B[0m"

#define LED_ON  "(*)"
#define LED_OFF "( )"

void ConsoleVisualizer::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void ConsoleVisualizer::drawTemperatureGauge(float temperature) {
    const int gauge_width = 40;
    int filled = (int)((temperature + 10) / 130.0 * gauge_width); // Scale temperature to gauge width
    filled = filled < 0 ? 0 : (filled > gauge_width ? gauge_width : filled);

    printf("\rTemperature: %6.1f C [", temperature);
    for (int i = 0; i < gauge_width; i++) {
        printf(i < filled ? "#" : " ");
    }
    printf("]       ");
    fflush(stdout);

}

void ConsoleVisualizer::drawLEDStatus(const LEDService& ledService) {

    const char* red = (ledService.getRedState() ? LED_ON : LED_OFF);
    const char* yellow = (ledService.getYellowState() ? LED_ON : LED_OFF);
    const char* green = (ledService.getGreenState() ? LED_ON : LED_OFF);

    printf("\n\rLED Status: %s%s%s Critical  %s%s%s Warning  %s%s%s Normal      ",
        (ledService.getRedState()) ? COLOR_RED : "", red, COLOR_RESET,
        (ledService.getYellowState()) ? COLOR_YELLOW : "", yellow, COLOR_RESET,
        (ledService.getGreenState()) ? COLOR_GREEN : "", green, COLOR_RESET);

    fflush(stdout);

}
