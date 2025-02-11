#ifndef GPIO_H
#define GPIO_H

#include <stdbool.h>

typedef enum {
    GPIO_PIN_0, // Red LED
    GPIO_PIN_1, // Yellow LED
    GPIO_PIN_2  // Green LED
} GPIO_Pin;

void GPIO_Init(void);
void GPIO_SetPin(GPIO_Pin pin, bool state);

#endif // GPIO_H