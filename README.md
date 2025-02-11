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
    ├── 21
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
git clone https://github.com/eranyan20/temperature_monitor_bare_metal.git
cd temperature_monitor_bare_metal

### 2. Build the Project
To compile and build the project, simply run the make command:

make

### 3. Run the Application
Within the bin folder temp_mon.out file would be generated, execute it on the console.
./bin/temp_mon.out
