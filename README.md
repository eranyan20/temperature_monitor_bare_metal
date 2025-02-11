# Temperature Monitor - Bare Metal

## Overview
This project implements a **temperature monitoring system** on bare metal hardware. The system reads temperature data from a sensor and visualizes the temperature using LED indicators. The project is designed to be simple and efficient, targeting embedded systems with minimal dependencies.

## Features
- Reads temperature data from a temperature sensor (specific sensor model can be added in the future).
- Displays temperature using **LED indicators** (different LEDs correspond to different temperature thresholds).
- Fully implemented in C, suitable for bare metal systems with no OS.
- Easy to extend for additional sensors or functionalities.

## Directory Structure
temperature_monitor_bare_metal/ ├── Application/ # Application code │ └── App.c # Main application logic for the temperature monitor ├── HAL/ # Hardware Abstraction Layer (drivers and hardware setup) │ ├── ADC_Driver.c # ADC driver for reading analog data │ ├── GPIO_Driver.c # GPIO driver for controlling LEDs and other pins │ └── I2C_Driver.c # I2C driver for communication with sensors ├── Hardware/ # Hardware-specific configurations │ └── Microcontroller.c # Microcontroller initialization and configuration ├── Include/ # Header files for the project │ ├── ADC_Driver.h # Header for ADC driver │ ├── EEPROM_Service.h # Header for EEPROM service │ ├── GPIO_Driver.h # Header for GPIO driver │ ├── I2C_Driver.h # Header for I2C driver │ ├── LED_Service.h # Header for LED control service │ ├── Microcontroller.h # Header for microcontroller settings │ └── temperature_Service.h # Header for temperature service ├── Makefile # Makefile to build the project ├── obj/ # Compiled object files │ └── Application/ # Object files for application source files ├── Services/ # Service layer code │ ├── EEPROM_Service.c # Service for reading/writing EEPROM data │ ├── LED_service.c # Service for controlling LEDs │ └── temperature_Service.c # Service for temperature sensing logic └── bin/ # Compiled binaries (output directory) └── temp_mon.out # Final compiled executable



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
