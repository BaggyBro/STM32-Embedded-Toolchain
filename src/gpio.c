#include "../include/stm32f446.h"

void gpio_init(void){
  RCC_AHB1ENR |= (1U << 0);   // enables GPIOA clk
  RCC_AHB1ENR |= (1U << 1);   // enables GPIOB clk
}
