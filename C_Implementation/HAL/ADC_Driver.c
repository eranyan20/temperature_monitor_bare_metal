#include "ADC_Driver.h"
#include <stdio.h>

static int16_t raw_value = -50; // Start at -5°C (scaled by 10)
static int8_t direction = 1;     // 1 for increasing, -1 for decreasing

void ADC_Init(void) {
    printf("[ADC] Initialized\n");
}

int16_t ADC_Read(void) {
    // Simulate temperature sweep from -5°C to 120°C 
    if (raw_value >= 1200) {
	// Start decreasing
	direction = -1;
    }
    else if (raw_value <= -50) { 
        // Start increasing
	direction = 1;
    }

    raw_value += direction * 10; // Increment or decrement by 1°C 

    // Enable Debug if needed - commented as it floods the console
    //printf("[ADC] Raw Value: %d\n", raw_value);
    return (uint16_t)raw_value;
}
