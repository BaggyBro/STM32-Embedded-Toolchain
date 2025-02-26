#include <stdlib.h>
#include "../include/stm32f446.h"
#include "./gpio.c"

void lcd_gpio_init(void){
  gpio_init();

  /* Pins used 
   * RS -> D2/PA10
   * E  -> D3/PB3
   * D4 -> D4/PB5
   * D5 -> D5/PB4
   * D6 -> D6/PB10
   * D7 -> D7/PB8
  */

  GPIOA_MODER &= ~(3U << (10*2)); // clear bits for PA10
  GPIOA_MODER |= (1U << (10*2));  // setting as output 01
                                  //
  GPIOB_MODER &= ~((3U << (3*2)) |(3U << (4*2))| (3U << (5*2))| (3U << (8*2))| (3U << (10*2)) );
  GPIOB_MODER |= ((1U << (3*2)) |(1U << (4*2))| (1U << (5*2))| (1U << (8*2))| (1U << (10*2)) );

}

void lcd_pulse_enable(void){
  gpio_init();

  GPIOB_ODR |= (1 << 3);  // E = 1
  for(volatile int i = 0; i < 2000; i++);
  GPIOB_ODR &= ~(1 << 3); //E = 0
}


void lcd_send_nibble(uint8_t data){
  GPIOB_ODR &= ~((1 << 4) |(1 << 5) |(1 << 8) |(1 << 10) );
  // clear data D4 - D7

    if (data & 0x01) GPIOB_ODR |= (1 << 5); // D4
    if (data & 0x02) GPIOB_ODR |= (1 << 4); // D5
    if (data & 0x04) GPIOB_ODR |= (1 << 10); // D6
    if (data & 0x08) GPIOB_ODR |= (1 << 8); // D7
}

void lcd_command(uint8_t cmd){
  GPIOA_ODR &= ~(1 << 10);  // RS = 0 (coomand mode)
  lcd_send_nibble(cmd >> 4);
  lcd_pulse_enable();
  lcd_send_nibble(cmd & 0x0F);
  lcd_pulse_enable();
}

void lcd_write_char(char c){
  GPIOA_ODR |= (1 << 10);  // RS = 1 (data mode)
  lcd_send_nibble(c >> 4);
  lcd_pulse_enable();
  lcd_send_nibble(c & 0x0F);
  lcd_pulse_enable();
}


void lcd_write_string(const char *str){
  while(*str){
    lcd_write_char(*str++);
  }
}

void lcd_init(void){
  lcd_gpio_init();

  GPIOA_ODR &= ~(1 << 10); // RS = 0 (coomand mode)
  for(volatile int i = 100000; i > 0; i--);

  lcd_send_nibble(0x3);    // function set (8-bit mode)
  lcd_pulse_enable();
  for(volatile int i = 100000; i > 0; i--); //delay

  lcd_send_nibble(0x3);
  lcd_pulse_enable();
  for(volatile int i = 10000; i > 0; i--);

  lcd_send_nibble(0x3);
  lcd_pulse_enable();

  lcd_send_nibble(0x2); // 4 bit mode
  lcd_pulse_enable(); 

  lcd_command(0x28); // function set 4bit, 2 lines, 5x8 dots
  lcd_command(0x0C); // display on, cursor off
  lcd_command(0x06); // entry mode: move right
  lcd_command(0x01); // clear display
  for(volatile int i = 100000; i > 0; i--);
}


