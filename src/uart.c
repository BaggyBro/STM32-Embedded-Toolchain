
#include "uart.h"
#include "../include/stm32f446.h"

void uart_init(void) {
  // enables GPIOA clock
  #define RCC_AHB1ENR  (*(volatile uint32_t*) 0x40023830)
  RCC_AHB1ENR |= (1U << 0); 

  // enables USART2 clock (APB1 bus)
  #define RCC_APB1ENR  (*(volatile uint32_t*) 0x40023840)
  RCC_APB1ENR |= (1U << 17);

  /* sets PA2 as alternate function
   * clear PA2 mode 
   * set PA2 as alternate function
  */
  #define GPIOA_MODER  (*(volatile uint32_t*) 0x40020000)
  GPIOA_MODER &= ~(3U << 4);
  GPIOA_MODER |= (2U << 4);  

  /* set PA2 AF7
  */
  GPIOA_AFRL |= (7U << 8);  

  /* set baud rate for 42MHz APB1 and 9600 baud */
  USART2_BRR = 0x1117;  

  /* Enable USART2 and TX */
  USART2_CR1 = (1U << 13) | (1U << 3);
}

void uart_send_char(char c) {

  while (!(USART2_SR & (1 << 7))); // waits until TX buffer is enpty
  USART2_DR = c;
  while (!(USART2_SR & (1 << 6))); // wait for transmission complete TC
}

void uart_send_string(const char *str) {
  while (*str) uart_send_char(*str++);
}

