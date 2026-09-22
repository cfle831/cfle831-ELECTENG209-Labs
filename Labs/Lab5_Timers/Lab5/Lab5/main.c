/*
 * Lab5.c
 *
 * Created: 20/09/2026 1:42:04 pm
 * Author : ferre
 */ 
#define F_CPU 2000000UL
#define F_LED 2
#include <avr/io.h>
#include <util/delay.h>
#include "timer.h"
#include "led.h"
#include "UART.h"

volatile uint8_t cur_timer_value = 0;
volatile uint8_t finished_cycle = 0;
extern uint8_t overflow_count;

int main(void)
{
	timer0_init();
	usart_init(12);
	volatile float period = 0;
	volatile float frequency = 0;
	DDRB |= 0xFF;
	DDRC &= ~(0xFF);
	DDRD &= ~(0xFF);
	volatile uint8_t things = 0;
    while (1) 
    {
		if (finished_cycle){
			/*things++;
			transmit_text("OF count  ", 10);
			transmit_string(decimal_to_char(overflow_count));
			transmit_new_line();
			transmit_text("TC count  ", 10);
			transmit_string(decimal_to_char(cur_timer_value));
			transmit_new_line();*/
			period = 2*0.000128f*(cur_timer_value + overflow_count*256);
			frequency = 1/period;
			transmit_string(decimal_to_char(frequency));
			transmit_new_line();
			overflow_count = 0;
			finished_cycle = 0;
		}
	
    }
}

