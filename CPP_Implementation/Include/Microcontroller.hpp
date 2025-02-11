#pragma once


#include <iostream>
#include <cstdint>
#include <atomic>

class Microcontroller {
public:
    enum class ClockSource {
        HSI,
        HSE,
        PLL
    };

    Microcontroller();
    void Clock_Init(ClockSource source, uint32_t frequency);
    void System_Init();
    void Timer_Init(uint32_t interval_us);
    void Timer_Start();
    void Timer_Stop();
    void Interrupt_Init();
    void SysTick_Init(uint32_t interval_ms);
    void TIMER_IRQHandler();
    void ADC_IRQHandler();

    static std::atomic<bool> timer_flag;
    static std::atomic<bool> adc_flag;
};
