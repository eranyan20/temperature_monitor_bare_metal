#include "Microcontroller.h"
#include <stdio.h>

volatile bool timer_flag = false;
volatile bool adc_flag = false;

// Clock Initialization
void Clock_Init(ClockSource source, uint32_t frequency) {
    const char* source_str;
    switch (source) {
    case CLOCK_SOURCE_HSI: source_str = "HSI"; break;
    case CLOCK_SOURCE_HSE: source_str = "HSE"; break;
    case CLOCK_SOURCE_PLL: source_str = "PLL"; break;
    default: source_str = "Unknown"; break;
    }
    printf("[Clock] Initialized with source: %s, frequency: %lu Hz\n", source_str, frequency);
}

// System Initialization
void System_Init(void) {
    Clock_Init(CLOCK_SOURCE_HSI, 25000000); // 25 MHz HSI
    Interrupt_Init();

    SysTick_Init(1); // 1ms interval

    printf("[System] Initialized\n");
}

// Interrupt Initialization
void Interrupt_Init(void) {
    printf("[Interrupt] Initializing...\n");
    // Configure NVIC (Nested Vectored Interrupt Controller)
    // Enable global interrupts
}

// System Tick Initialization
void SysTick_Init(uint32_t interval_ms) {
    printf("[SysTick] Initializing with interval: %lu ms\n", interval_ms);
    // Configure the SysTick timer for the given interval
}

// Timer Initialization
void Timer_Init(uint32_t interval_us) {
    printf("[Timer] Initialized with interval: %lu µs\n", interval_us);
}

// Busy-wait loop to simulate 100µs delay
void delay_us(uint32_t us) {
    for (volatile uint32_t i = 0; i < us * 10; i++); // Adjust loop count for your system
}

void Timer_Start(void) {
    printf("[Timer] Started\n");
}

void Timer_Stop(void) {
    printf("[Timer] Stopped\n");
}

// Timer ISR
void TIMER_IRQHandler(void) {
    //printf("[Timer] ISR Triggered\n");
    adc_flag = true; // Trigger ADC read
}