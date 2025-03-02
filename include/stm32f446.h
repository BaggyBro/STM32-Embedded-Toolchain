
#include <stdint.h>

// pg no. 127 on docs
#define RCC_AHB1ENR  (*(volatile uint32_t*) 0x40023830) 

#define GPIOA_MODER  (*(volatile uint32_t*) 0x40020000)  // GPIO Mode Register
#define GPIOA_OTYPER (*(volatile uint32_t*) 0x40020004)  // Output Type Register
#define GPIOA_OSPEEDR (*(volatile uint32_t*) 0x40020008) // Output Speed Register
#define GPIOA_PUPDR  (*(volatile uint32_t*) 0x4002000C)  // Pull-up/Pull-down Register
#define GPIOA_IDR    (*(volatile uint32_t*) 0x40020010)  // Input Data Register
#define GPIOA_ODR    (*(volatile uint32_t*) 0x40020014)  // Output Data Register
#define GPIOA_AFRL   (*(volatile uint32_t*) 0x40020020)  // Alternate Function Low Register

#define RCC_AHB1ENR  (*(volatile uint32_t*) 0x40023830)  // RCC AHB1 Enable Register
#define RCC_APB1ENR  (*(volatile uint32_t*) 0x40023800)// RCC AHP1 Enable Register

#define GPIOB_BASE   0x40020400  // Base address of GPIOB
#define GPIOB_MODER  (*(volatile uint32_t*) (GPIOB_BASE + 0x00))  // GPIOB Mode Register
#define GPIOB_OTYPER (*(volatile uint32_t*) (GPIOB_BASE + 0x04))  // GPIOB Output Type Register
#define GPIOB_OSPEEDR (*(volatile uint32_t*) (GPIOB_BASE + 0x08)) // GPIOB Speed Register
#define GPIOB_PUPDR  (*(volatile uint32_t*) (GPIOB_BASE + 0x0C))  // GPIOB Pull-up/Pull-down Register
#define GPIOB_IDR    (*(volatile uint32_t*) (GPIOB_BASE + 0x10))  // GPIOB Input Data Register
#define GPIOB_ODR    (*(volatile uint32_t*) (GPIOB_BASE + 0x14))  // GPIOB Output Data Register
#define GPIOB_AFRL   (*(volatile uint32_t*) (GPIOB_BASE + 0x20))  // GPIOB Alternate Function Low Register

#define USART2_BASE  0x40004400
#define USART2_SR    (*(volatile uint32_t*)(USART2_BASE + 0x00))
#define USART2_DR    (*(volatile uint32_t*)(USART2_BASE + 0x04))
#define USART2_BRR   (*(volatile uint32_t*)(USART2_BASE + 0x08))
#define USART2_CR1   (*(volatile uint32_t*)(USART2_BASE + 0x0C))
#define USART2_CR2   (*(volatile uint32_t*)(USART2_BASE + 0x10))

// Systick Registers 
#define SYST_CSR  (*(volatile uint32_t*) 0xE000E010)  // Systick control
#define SYST_RVR  (*(volatile uint32_t*) 0xE000E014)  // Reload value
#define SYST_CVR  (*(volatile uint32_t*) 0xE000E018)  // Current value



