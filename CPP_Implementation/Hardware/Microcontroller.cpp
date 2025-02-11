#include "Microcontroller.hpp"

std::atomic<bool> Microcontroller::timer_flag{false};
std::atomic<bool> Microcontroller::adc_flag{false};

Microcontroller::Microcontroller() {}

void Microcontroller::Clock_Init(ClockSource source, uint32_t frequency) {
    const char* source_str = (source == ClockSource::HSI) ? "HSI" :
        (source == ClockSource::HSE) ? "HSE" : "PLL";
    std::cout << "[Clock] Initialized with source: " << source_str
        << ", frequency: " << frequency << " Hz\n";
}

void Microcontroller::System_Init() {
    Clock_Init(ClockSource::HSI, 25000000);
    Interrupt_Init();
    SysTick_Init(1);
    std::cout << "[System] Initialized\n";
}

void Microcontroller::Interrupt_Init() {
    std::cout << "[Interrupt] Initializing...\n";
}

void Microcontroller::SysTick_Init(uint32_t interval_ms) {
    std::cout << "[SysTick] Initializing with interval: " << interval_ms << " ms\n";
}

void Microcontroller::Timer_Init(uint32_t interval_us) {
    std::cout << "[Timer] Initialized with interval: " << interval_us << " us\n";
}

void Microcontroller::Timer_Start() {
    std::cout << "[Timer] Started\n";
}

void Microcontroller::Timer_Stop() {
    std::cout << "[Timer] Stopped\n";
}

void Microcontroller::TIMER_IRQHandler() {
    adc_flag = true;
}

void Microcontroller::ADC_IRQHandler() {
    timer_flag = true;
}
