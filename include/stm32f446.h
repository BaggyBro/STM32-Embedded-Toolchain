#include <stdint.h>

#define RCC_AHB1ENR  (*(volatile uint32_t*) 0x40023830)  // RCC Enable Register
#define GPIOA_MODER  (*(volatile uint32_t*) 0x40020000)  // GPIO Mode Register
#define GPIOA_ODR    (*(volatile uint32_t*) 0x40020014)  // GPIO Output Register

#define USART2_BASE  0x40004400
#define USART2_SR    (*(volatile uint32_t*)(USART2_BASE + 0x00))
#define USART2_DR    (*(volatile uint32_t*)(USART2_BASE + 0x04))
#define USART2_BRR   (*(volatile uint32_t*)(USART2_BASE + 0x08))
#define USART2_CR1   (*(volatile uint32_t*)(USART2_BASE + 0x0C))
#define USART2_CR2   (*(volatile uint32_t*)(USART2_BASE + 0x10))


// for RTOS
#define SYST_CSR (*(volatile uint32_t*) 0xE000E010)    //Systick control
#define SYST_RVR (*(volatile uint32_t*) 0xE000E014)    //Reload value
#define SYST_CVR (*(volatile uint32_t*) 0xE000E018)    //Current value

