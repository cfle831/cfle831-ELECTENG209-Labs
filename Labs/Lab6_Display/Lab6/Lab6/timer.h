#ifndef TIMER1_H_
#define TIMER1_H_

#include <stdbool.h>
#include <stdint.h>
//Initialize timer1
void timer1_init();
//Using polling check if timer0 has reached comparison value
//if so, it will clear the compare flag and return 1
//otherwise, it returns 0
uint8_t timer0_check_clear_compare();
#endif