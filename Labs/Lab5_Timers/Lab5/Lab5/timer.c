#include "timer.h"
#include "led.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

ISR(TIMER0_OVF_vect){
	//led_toggle();
}

volatile uint8_t overflow_count = 0;
ISR(TIMER0_COMPA_vect){
	if (overflow_count == 10){
		led_toggle();
		overflow_count = 0;
	}
	overflow_count++;
}

void timer0_init(){
	TCCR0A = 0;
	TCCR0B = 0b00000100;
	OCR0A = 0b01001110;
	TIMSK0 |= (1 << TOIE0) | (1 << OCIE0A);
	sei();
}
uint8_t timer0_check_clear_compare(){
	if( TIFR0 & (1 << OCF0A )){ 
		TIFR0 |= (1 << OCF0A);
		return 1;
	}
	return 0;
}