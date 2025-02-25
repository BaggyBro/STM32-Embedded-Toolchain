#include <stdint.h>
#include "../include/stm32f446.h"
void delay() {
  for(volatile int i = 0; i < 1000000; i++ );
}


void led_blink(void){
    while (1) {
        GPIOA_ODR ^= (1U << 5);  // Toggle LED
        delay();           // Delay
    }


}
