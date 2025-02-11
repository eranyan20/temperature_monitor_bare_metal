# Temperature Monitor - Bare Metal

## Overview
This project implements a **temperature monitoring system** on bare metal hardware with mocked interfaces. The system reads temperature data from a sensor and visualizes the temperature using LED indicators. The project is designed to be with minimal dependencies.

## Features
- Reads temperature data from a temperature sensor and shows this in a temperature guage (specific sensor model can be added in the future).
- Displays temperature using **LED indicators** (different LEDs correspond to different temperature thresholds).
- Fully implemented in C, suitable for bare metal systems with no OS.
- Easy to extend for additional sensors or functionalities.

## Directory Structure
```bash
└── temperature_monitor_bare_metal
    ├── C_Implementation
    │   ├── Application
    │   │   └── App.c
    │   ├── HAL
    │   │   ├── ADC_Driver.c
    │   │   ├── GPIO_Driver.c
    │   │   └── I2C_Driver.c
    │   ├── Hardware
    │   │   └── Microcontroller.c
    │   ├── Include
    │   │   ├── ADC_Driver.h
    │   │   ├── EEPROM_Service.h
    │   │   ├── GPIO_Driver.h
    │   │   ├── I2C_Driver.h
    │   │   ├── LED_Service.h
    │   │   ├── Microcontroller.h
    │   │   └── temperature_Service.h
    │   ├── Makefile
    │   └── Services
    │       ├── EEPROM_Service.c
    │       ├── LED_service.c
    │       └── temperature_Service.c
    ├── Documentation
    │   ├── System Architecture Final.png
    │   └── System Architecture Temp Monitor Final.pdf
    ├── LICENSE
    └── README.md

```

## Prerequisites
- C compiler (GCC).
- GNU Make

## Getting Started

Follow these steps to clone the repository and get the project up and running:

### 1. Clone the Repository
```bash

git clone https://github.com/eranyan20/temperature_monitor_bare_metal.git

cd temperature_monitor_bare_metal
```
### 2. Build the Project
To compile and build the project, simply run the make command:
```bash
make clean

make
```

### 3. Run the Application
Within the bin folder temp_mon.out file would be generated, execute it on the console.
```bash

./bin/temp_mon.out
```
## Expected Output
The Temperature guage shows the sweeping of temperature from -5 to 120 Degree celcius and returns back to -5 on a loop.
The LED Indicator should have the right LED glowing for the respective temperature reported. The expected output somehow looks like this.

```bash

eranyan20@ProgressivKI:~/Desktop/cpp_repo/temperature_monitor_bare_metal/C_Implementation/bin$ ./temp_mon.out 
[Clock] Initialized with source: HSI, frequency: 25000000 Hz
[Interrupt] Initializing...
[SysTick] Initializing with interval: 1 ms
[System] Initialized
[Timer] Initialized with interval: 100 �s
[GPIO] Initialized
[ADC] Initialized
[I2C] Initialized
[EEPROM] Initialized
[Temperature Sensor] Initialized
[LED Controller] Initialized
[I2C] Read from device 0x50, register 0x00
[EEPROM] Read Config: Revision = 1, Serial = ABCDEFGHIJKLMNOP
[Timer] Started
Temperature:   -4.0 C [#                                       ]       
Temperature:   -3.0 C [##                                      ]       
Temperature:   -2.0 C [##                                      ]       
Temperature:   -1.0 C [##                                      ]       
Temperature:    0.0 C [###                                     ]       
Temperature:    1.0 C [###                                     ]       
Temperature:    2.0 C [###                                     ]       
Temperature:    3.0 C [####                                    ]       
Temperature:    4.0 C [####                                    ]       
Temperature:    5.0 C [####                                    ]       
Temperature:    6.0 C [####                                    ]       
Temperature:    7.0 C [#####                                   ]       
Temperature:    8.0 C [#####                                   ]       
LED Status: ( ) Critical  ( ) Warning  (*) Normal

```
