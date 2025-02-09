#include "ADC.h"
#include <stdio.h>

// Global variables for temperature simulation
static int16_t raw_value = -50; // Start at -5°C (scaled by 10)
static int8_t direction = 1;     // 1 for increasing, -1 for decreasing

void ADC_Init(void) {
    printf("[ADC] Initialized\n");
}

int16_t ADC_Read(void) {
    // Simulate temperature sweep from -5°C to 120°C and back
    if (raw_value >= 1200) { // 120°C (scaled by 10)
        direction = -1; // Start decreasing
    }
    else if (raw_value <= -50) { // -10°C (scaled by 10)
        direction = 1; // Start increasing
    }

    raw_value += direction * 10; // Increment or decrement by 1°C (scaled by 10)

    //printf("[ADC] Raw Value: %d\n", raw_value);
    return (uint16_t)raw_value;
}