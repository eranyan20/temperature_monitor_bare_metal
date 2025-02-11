#include "temperature_Service.h"
#include "ADC_Driver.h"
#include <stdio.h>

void TemperatureSensor_Init(void) {
    printf("[Temperature Sensor] Initialized\n");
}

float TemperatureSensor_Read(uint8_t revision) {
    int16_t raw_value = ADC_Read();
    float temperature;

    // Convert raw ADC value to temperature based on hardware revision
    if (revision == 0) { // Rev-A: 1°C per digit
        temperature = (float)raw_value;
    }
    else { // Rev-B: 0.1°C per digit
        temperature = raw_value * 0.1f;
    }

    //printf("[Temperature Sensor] Raw Value: %d, Temperature: %.1f C\n", raw_value, temperature);
    return temperature;
}