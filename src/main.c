#include "../include/stm32f446.h"
#include "./led_blink.c"

#define RCC_AHB1ENR  (*(volatile uint32_t*) 0x40023830)
#define GPIOA_MODER  (*(volatile uint32_t*) 0x40020000)
#define GPIOA_ODR    (*(volatile uint32_t*) 0x40020014)


int main(void) {

    RCC_AHB1ENR |= (1U << 0);  

    GPIOA_MODER &= ~(3U << 10); 
    GPIOA_MODER |= (1U << 10);

    led_blink();

    return 0;
}

