#include <stdint.h>


/* Symbols defined by the linker script */
extern uint32_t _etext;   // End of code
extern uint32_t _sdata;   // Start of .data in RAM
extern uint32_t _edata;   // End of .data in RAM
extern uint32_t _sbss;    // Start of .bss in RAM
extern uint32_t _ebss;    // End of .bss in RAM
extern uint32_t _estack;  // Top of stack


/* Define Default Handler */
void Default_Handler(void) {
    for (;;);
}


/* Define Prototypes for System Handlers and ISRs */
void Reset_Handler(void);
void ISR_TIM2(void);


/* Define Vector Table */
__attribute__((section(".isr_vector"))) 
void (* const vector_table[])(void) = {
    (void (*)(void))(&_estack),
    Reset_Handler,
    Default_Handler,
    Default_Handler,
    (void (*)(void))0,
    (void (*)(void))0,
    (void (*)(void))0,
    (void (*)(void))0,
    (void (*)(void))0,
    (void (*)(void))0,
    (void (*)(void))0,
    Default_Handler,
    (void (*)(void))0,
    (void (*)(void))0,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    ISR_TIM2,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler,
    Default_Handler
};


/* Define Prototype of main */
int main(void);


/* Define Reset Handler */
void Reset_Handler(void) {

    uint32_t *src, *dst;

    // Copy .data from FLASH to RAM
    src = &_etext;
    dst = &_sdata;
    while (dst < &_edata) {
        *dst++ = *src++;
    }

    // Zero out .bss section
    dst = &_sbss;
    while (dst < &_ebss) {
        *dst++ = 0;
    }

    // Enter main
    main();

    // Fallback loop
    for(;;);

}
