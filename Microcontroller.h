#ifndef MICROCONTROLLER_H
#define MICROCONTROLLER_H

#include <stdint.h>
#include <stdbool.h>

// Clock Configuration
typedef enum {
    CLOCK_SOURCE_HSI, // High-Speed Internal Oscillator
    CLOCK_SOURCE_HSE, // High-Speed External Oscillator
    CLOCK_SOURCE_PLL  // Phase-Locked Loop
} ClockSource;

void Clock_Init(ClockSource source, uint32_t frequency);
void System_Init(void);

// Timer Configuration
void Timer_Init(uint32_t interval_us);
void Timer_Start(void);
void Timer_Stop(void);

// Interrupt Configuration
void Interrupt_Init(void);

// System Tick Configuration
void SysTick_Init(uint32_t interval_ms);

// Interrupt Handlers
void TIMER_IRQHandler(void); // Timer ISR
void ADC_IRQHandler(void);   // ADC ISR

// Simulated Interrupt Flags
extern volatile bool timer_flag;
extern volatile bool adc_flag;

#endif // MICROCONTROLLER_H

