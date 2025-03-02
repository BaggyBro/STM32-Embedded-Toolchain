#include "./uart.h"
#include "../include/stm32f446.h"
void uart_init(void) {
    RCC_AHB1ENR |= (1 << 0); // Enable GPIOA clock

    RCC_APB1ENR |= (1 << 17); // Enable USART2 clock

    GPIOA_MODER &= ~(3U << 4); // Clear PA2 mode
    GPIOA_MODER |= (2U << 4);  // Set PA2 to AF mode
    GPIOA_AFRL |= (7U << 8);   // Set PA2 AF7 (USART2_TX)

    USART2_BRR = 0x0683; // Baud Rate 9600 (for 16 MHz clock)
    USART2_CR1 |= (1 << 13); // Enable USART2
    USART2_CR1 |= (1 << 3);  // Enable TX
}

void uart_send_char(char c) {
    while (!(USART2_SR & (1 << 7)));  // Wait until TXE (Transmit buffer empty)
    USART2_DR = c;
    while (!(USART2_SR & (1 << 6)));  // Wait for TC (Transmission Complete)
}

void uart_send_string(const char *str) {
    while (*str) {
        uart_send_char(*str++);
    }
}

