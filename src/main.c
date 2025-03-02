#include "../include/stm32f446.h"
#include "./led_blink.c"
#include "./lcd.c"
#include "./uart.h"

int main(void) {
    uart_init();
    
    while (1) {
        uart_send_string("Hello UART!\r\n");
        for (volatile int i = 0; i < 1000000; i++); // Delay
    }
}

