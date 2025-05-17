#include <stdint.h>
#include "stm32f0.h"


/* Define Blinker Delay Time */
#define DELAY_SECONDS 1ul
#define DELAY_MS      (DELAY_SECONDS * 1000ul)


/* Define GPIO Settings */
#define LED_GPIO_PORT  GPIOB  // Use GPIO B for built-in Nucleo LED
#define LED_GPIO_PIN   3ul    // Use Pin 3 for built-in Nucleo LED


/* Define Timer Settings */
#define PCLK_FREQ               8000000ul                                          // PCLK runs on HSI by default (8 MHz) 
#define DELAY_TIMER             TIM2                                               // Use TIM2 for delay
#define DELAY_TIMER_FREQ        1000ul                                             // Set timer frequency to 1 kHz
#define DELAY_TIMER_PRESCALER   (uint16_t)((PCLK_FREQ / DELAY_TIMER_FREQ) - 1ul)   // Set 16 bit prescaler to 7999 to get 1 ms tick
#define DELAY_TIMER_AUTORELOAD  (uint16_t)(DELAY_MS)                               // Update timer at every delay interval (1000 ms)


/* Set up GPIO Output for LED */
void gpioSetup(void) {

    // Enable I/O Port B clock in RCC
    RCC->AHBENR |= (1ul << 18ul);

    // Set GPIO Mode to Output
    GPIOB->MODER |= (1ul << (LED_GPIO_PIN * 2ul));
    GPIOB->MODER &= ~(1ul << (LED_GPIO_PIN * 2ul + 1));

    // Set output type to push-pull
    GPIOB->OTYPER &= ~(1u << LED_GPIO_PIN);

    // Set output speed to low
    GPIOB->OSPEEDR &= ~(1ul << (LED_GPIO_PIN * 2ul));

}


void timerSetup(void) {

    // Enable TIM2 clock in RCC
    RCC->APB1ENR |= (1ul << 0ul);

    // Set the prescaler value
    TIM2->PSC = DELAY_TIMER_PRESCALER;

    // Set the auto reload value
    TIM2->ARR = DELAY_TIMER_AUTORELOAD;

    // Enable Timer updates
    TIM2->CR1 &= ~(1ul << 1ul);

    // Enable update interrupts
    TIM2->DIER |= (1ul << 0ul);

    // Enable TIM2 in the Cortex NVIC
    NVIC->ISER |= (1ul << TIM2_IRQn);

    // Enable TIM2 counter
    TIM2->CR1 |= (1ul << 0ul);

}


/* Define global LED toggle variable */
uint32_t fLED;


int main(void) {

    // Setup gpio pin
    gpioSetup();

    // Setup timer/interrupt
    timerSetup();

    fLED = 0;

    // Main loop
    for (;;) {
        // Enter sleep mode in Cortex
        __asm volatile ("wfi");    // WFI inline instruction for ARM
    }

    return 0;
}


/* Define TIM2 ISR */
void ISR_TIM2(void) {

    // Toggle the LED
    if (fLED) {
        GPIOB->BSRR |= (1ul << (LED_GPIO_PIN + 16ul));
    } else {
        GPIOB->BSRR |= (1ul << LED_GPIO_PIN);
    }
    fLED = !fLED;

    // Clear update interrupt
    TIM2->SR &= ~(1ul << 0ul);

}
