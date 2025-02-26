#include <stdint.h>
#include "../include/stm32f446.h"
void delay() {
  for(volatile int i = 0; i < 1000000; i++ );
}


void led_blink(void){
  
    RCC_AHB1ENR |= (1U << 0);  

    GPIOA_MODER &= ~(3U << 10); 
    GPIOA_MODER |= (1U << 10);
    while (1) {
        GPIOA_ODR ^= (1U << 5);  // Toggle LED
        delay();           // Delay
    }


}
