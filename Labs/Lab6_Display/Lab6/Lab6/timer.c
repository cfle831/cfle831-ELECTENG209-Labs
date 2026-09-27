#include "timer.h"
#include "UART.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

extern uint8_t update_flag;
volatile uint8_t cur_counting = 0;
ISR(TIMER1_COMPA_vect){
	update_flag = 1;
}

volatile uint16_t overflow_count = 0;
ISR(TIMER0_OVF_vect){
	if (cur_counting){
		
		overflow_count++;
	}
}



void timer1_init(){
	TCCR1A = 0;
	TCCR1B = 0b00001101;
	OCR1A = 0x100;
	TIMSK1 |= (1 << OCIE1A);
	sei();
}
