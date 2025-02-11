#include "Microcontroller.h"
#include "temperature_Service.h"
#include "LED_Service.h"
#include "EEPROM_Service.h"
#include <stdio.h>
#include <math.h>

// ANSI color codes
#define COLOR_RED     "\x1B[31m"
#define COLOR_YELLOW  "\x1B[33m"
#define COLOR_GREEN   "\x1B[32m"
#define COLOR_RESET   "\x1B[0m"

#define LED_ON  "(*)"
#define LED_OFF "( )"

void draw_gauge(float temperature) {
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

// Function to draw the LED status (remains on a separate line)
void draw_led_status(float temperature) {
    const char* red = (temperature >= 105.0f || temperature < 5.0f) ? LED_ON : LED_OFF;
    const char* yellow = (temperature >= 85.0f && temperature < 105.0f) ? LED_ON : LED_OFF;
    const char* green = (temperature < 85.0f && temperature >= 5.0f) ? LED_ON : LED_OFF;

    printf("\n\rLED Status: %s%s%s Critical  %s%s%s Warning  %s%s%s Normal      ",
        (temperature >= 105.0f || temperature < 5.0f) ? COLOR_RED : "", red, COLOR_RESET,
        (temperature >= 85.0f && temperature < 105.0f) ? COLOR_YELLOW : "", yellow, COLOR_RESET,
        (temperature < 85.0f && temperature >= 5.0f) ? COLOR_GREEN : "", green, COLOR_RESET);

    fflush(stdout);
}

int main(void) {
    // Initialize system
    System_Init();
    Timer_Init(100); // 100µs interval
    GPIO_Init();
    ADC_Init();
    I2C_Init();
    EEPROM_Init();
    TemperatureSensor_Init();
    LED_Controller_Init();

    // Read hardware revision from EEPROM
    EEPROM_Config config = EEPROM_ReadConfig();
    uint8_t revision = config.revision; // 0 for Rev-A, 1 for Rev-B

    // Start the timer
    Timer_Start();

    float prev_temperature = -100.0f; // Initialize to random value

    // Main loop
    while (1) {
        delay_us(100000000); // Simulated more than 100µs delay for demonstration of the solution in console
        timer_flag = true; // Set the timer flag
        TIMER_IRQHandler(); // Trigger timer ISR

        if (adc_flag) {
            adc_flag = false; // Clear the ADC flag
            float temperature = TemperatureSensor_Read(revision);

            // Draw the temperature gauge
            draw_gauge(temperature);

            // Update LEDs and draw LED status if the temperature changes significantly
            if (fabs(temperature - prev_temperature) >= 1.0f) {
                LED_Controller_Update(temperature);
                draw_led_status(temperature);
                prev_temperature = temperature;
            }
        }
    }

    return 0;
}
