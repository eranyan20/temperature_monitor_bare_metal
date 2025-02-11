#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include <stdint.h>

void TemperatureSensor_Init(void);
float TemperatureSensor_Read(uint8_t revision);

#endif // TEMPERATURE_SENSOR_H
