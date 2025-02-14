#ifndef __RTOS_H
#define __RTOS_H

#include "../include/stm32f446.h"

void SysTick_Handler(void);
void systick_init(uint32_t ticks);

#endif
