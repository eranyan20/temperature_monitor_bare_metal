#include "GPIO_Driver.h"
#include <stdio.h>

void GPIO_Init(void) {
    printf("[GPIO] Initialized\n");
}

void GPIO_SetPin(GPIO_Pin pin, bool state) {
    const char* colors[] = { "RED", "YELLOW", "GREEN" };
    //printf("[GPIO] %s LED: %s\n", colors[pin], state ? "ON" : "OFF");
}