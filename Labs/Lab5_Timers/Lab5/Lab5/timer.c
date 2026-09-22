#include "timer.h"
#include "led.h"
#include "UART.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

extern uint8_t cur_timer_value;
extern uint8_t finished_cycle;

volatile uint8_t cur_counting = 0;


volatile uint16_t overflow_count = 0;
ISR(TIMER0_OVF_vect){
	led_toggle();
	if (cur_counting){
		
		overflow_count++;
	}
}
ISR(PCINT2_vect){
	if (PIND & (1<< PIND2)){
		// Rising edge
		cur_counting = 1;
		overflow_count = 0;
		finished_cycle = 0;
		TCNT0 = 0;
		EICRA &= ~(1 << ISC00);
	} else{
		// Falling Edge
		cur_timer_value = TCNT0;
		EICRA |= (1 << ISC00);
		cur_counting = 0;
		finished_cycle = 1;
		
		
	}
}


void timer0_init(){
	TCCR0A = 0;
	TCCR0B = 0b00000100;
	TIMSK0 |= (1 << TOIE0);
	EICRA |= (1<< ISC01) | (1<< ISC00);
	PCICR|= (1<< PCIE2);
	PCMSK2 |= (1 << PCINT18);
	sei();
}
uint8_t timer0_check_clear_compare(){
	if( TIFR0 & (1 << OCF0A )){ 
		TIFR0 |= (1 << OCF0A);
		return 1;
	}
	return 0;
}