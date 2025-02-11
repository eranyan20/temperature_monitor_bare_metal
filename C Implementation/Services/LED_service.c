#include "LED_Service.h"
#include "GPIO_Driver.h"

void LED_Controller_Init(void) {
    printf("[LED Controller] Initialized\n");
}

void LED_Controller_Update(float temperature) {
    if (temperature >= 105.0f || temperature < 5.0f) {
        GPIO_SetPin(GPIO_PIN_0, true);  // Red LED
    }
    else if (temperature >= 85.0f) {
        GPIO_SetPin(GPIO_PIN_1, true);  // Yellow LED
    }
    else {
        GPIO_SetPin(GPIO_PIN_2, true);  // Green LED
    }
}