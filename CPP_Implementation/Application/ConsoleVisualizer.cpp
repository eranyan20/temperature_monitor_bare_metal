#include "ConsoleVisualizer.hpp"
#include <algorithm>

void ConsoleVisualizer::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void ConsoleVisualizer::drawTemperatureGauge(float temperature) {
    const int width = 50;
    int position = static_cast<int>((temperature + 5.0f) * width / 125.0f);
    position = std::max(0, std::min(position, width - 1));

    std::cout << "Temperature: " << std::fixed << std::setprecision(1) << temperature << "°C\n";
    std::cout << "[-5°C ";
    for (int i = 0; i < width; ++i) {
        std::cout << (i == position ? "|" : "-");
    }
    std::cout << " 120C]\n";
}

void ConsoleVisualizer::drawLEDStatus(const LEDService& ledService) {
    std::cout << "\nLED Status:\n";
    std::cout << "Green  (< 85 C):     " << (ledService.getGreenState() ? "(X)" : "( )") << "\n";
    std::cout << "Yellow (>= 85 C):    " << (ledService.getYellowState() ? "(X)" : "( )") << "\n";
    std::cout << "Red    (>= 105 C):   " << (ledService.getRedState() ? "(X)" : "( )") << "\n";
}
