#include "rtos.h"
#include "./uart.h"

void SysTick_Handler(void) {
  uart_send_string("Tick! \r\n"); 
}

void systick_init(uint32_t ticks){
  SYST_RVR = ticks - 1;
  SYST_CVR = 0;
  SYST_CSR = 0x7;         // enable Systick with interrupts
}

