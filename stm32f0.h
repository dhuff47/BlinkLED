#include <stdint.h>

/* Define GPIO Structure */
typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
    volatile uint32_t BRR;
} GPIO_t;


/* Define GPIO Port B Pointer */
#define GPIOB_BASE 0x48000400ul
#define GPIOB      ((GPIO_t *)(GPIOB_BASE))


/* Define TIM Structure */
typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMCR;
    volatile uint32_t DIER;
    volatile uint32_t SR;
    volatile uint32_t EGR;
    volatile uint32_t CCMR1;
    volatile uint32_t CCMR2;
    volatile uint32_t CCER;
    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;
    volatile uint32_t RCR;
    volatile uint32_t CCR1;
    volatile uint32_t CCR2;
    volatile uint32_t CCR3;
    volatile uint32_t CCR4;
    volatile uint32_t BTDR;
    volatile uint32_t DCR;
    volatile uint32_t DMAR;
} TIM_t;


/* Define TIM2 Pointer */
#define TIM2_BASE  0x40000000ul
#define TIM2       ((TIM_t *)(TIM2_BASE))
#define TIM2_IRQn  15ul


/* Define RCC Structure */
typedef struct {
    volatile uint32_t CR;
    volatile uint32_t CFGR;
    volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint32_t AHBTSTR;
    volatile uint32_t CFGR2;
    volatile uint32_t CFGR3;
    volatile uint32_t CR2;
} RCC_t;


/* Define RCC Pointer */
#define RCC_BASE  0x40021000ul
#define RCC       ((RCC_t *)(RCC_BASE))


/* Define Cortex M0 NVIC Structure */
typedef struct {
    volatile uint32_t ISER;
    volatile uint32_t RESERVED_0[31];
    volatile uint32_t ICER;
    volatile uint32_t RESERVED_1[31];
    volatile uint32_t ISPR;
    volatile uint32_t RESERVED_2[31];
    volatile uint32_t ICPR;
    volatile uint32_t RESERVED_3[31];
    volatile uint32_t IPR[7];
} NVIC_t;


/* Define NVIC Pointer */
#define NVIC_BASE 0xE000E100ul
#define NVIC      ((NVIC_t *)(NVIC_BASE))