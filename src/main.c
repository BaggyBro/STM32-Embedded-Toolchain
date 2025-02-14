#include "uart.h"
#include "rtos.h"

int main(){
  uart_init();
  systick_init(16000000);

  while(1){
    uart_send_string("Hello there!");
    for(volatile int i = 1; i < 1000000; i++); //simple delay
    __asm("WFI");   //sleep until next interrupt
  }
}
