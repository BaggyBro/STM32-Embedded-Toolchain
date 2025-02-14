#include "uart.h"
#include "../include/stm32f446.h"

void uart_init(void){
  RCC_AHB1ENR |= (1 << 0);    // enable GPIOA
  GPIOA_MODER |= (2 << 4);    // set PA2 (USART TX) as alternate function
  USART2_BRR = 0x683;         // 9600 baud for 16Mhz clock
  USART2_CR1 = (1 << 13) | (1 << 3); // enable usart2 and tx
}

void uart_send_char(char c){
  while (!(USART2_SR & (1 << 7)));    // wait until TX buffer is empty
  USART2_DR = c;
}

void uart_send_string(const char *str){
  while(*str) uart_send_char(*str++);
}


