/*
 * Lab6P2.c
 *
 * Created: 28/09/2026 12:29:36 pm
 * Author : Loelene
 */ 

#define F_CPU 2000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "UART.h"
#include "timer.h"
// Pin definitions
#define SH_CP (PINC3)
#define SH_DS (PINC4)
#define SH_ST (PINC5)

volatile uint8_t dig_pins[4] = {(1<<PIND4), (1<<PIND5), (1<<PIND6), (1<<PIND7)};
volatile uint8_t segment_0_to_9[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};
void send_next_char(uint8_t value){
	PORTC = 0;
	value = segment_0_to_9[value];
	for (uint8_t i = 7; i>=0; i--){
		PORTC |= (((value & (1 << i)) >> i) << SH_DS);
		PINC |= (1<<SH_CP);
		PORTC = 0;
	}
	PINC |= (1<<SH_ST);
	_delay_ms(1);
	PINC |= (1<<SH_ST);
}
void set_seg(uint8_t value, uint8_t dig){
	// Disable All digits
	PORTD = 0;
	send_next_char(value);
	PORTD |= dig_pins[dig - 1];	
}
int main(void)
{
	DDRD = 0b11110000;
	DDRC = 0b0001110;
	DDRB = 0xFF;
	volatile uint8_t testing = 0;
	volatile uint8_t button_down = 0;
    /* Replace with your application code */
    while (1) 
    {
		
		_delay_ms(100);
		if (button_down && (PINB & (1<<PINB7))){
			button_down = 0;
		} else if (!button_down && !(PINB & (1 << PINB7))){
			testing++;
			button_down = 1;
		}
		if (button_down){
			set_seg(0, 1);
			PORTB |= (1<<PINB0);
		} else{
			set_seg(7, 1);
			PORTB &= ~(1<<PINB0);
		}
		
    }
}

