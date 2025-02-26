#include "../include/stm32f446.h"
#include "./led_blink.c"
#include "./lcd.c"


int main(void) {
    lcd_init();
    lcd_write_string("Hello there!");
    
    while(1);
}

