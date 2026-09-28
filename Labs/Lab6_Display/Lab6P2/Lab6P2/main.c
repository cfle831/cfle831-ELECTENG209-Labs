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
	for (int8_t i = 7; i>=0; i--){
		PORTC |= (((value & (1 << i)) >> i) << SH_DS);
		PINC |= (1<<SH_CP);
		PINC |= (1<<SH_CP);
		PORTC = 0;
	}
	PINC |= (1<<SH_ST);
	PINC |= (1<<SH_ST);
}
void set_seg(uint8_t value, uint8_t dig){
	// Disable All digits
	PORTD = 0xFF;
	send_next_char(value);
	PORTD &= ~(dig_pins[dig - 1]);	
}
void set_seg_all_digits(uint8_t value){
	// Enable All Digits
	PORTD = 0;
	send_next_char(value);
}
int main(void)
{
	DDRD = 0xFE;
	DDRC = 0xFF;
	DDRB = 0xFF;
	volatile uint8_t testing = 0;
	volatile uint8_t button_down = 0;
	volatile uint8_t counter = 0;
    while (1) 
    {
		
		set_seg_all_digits(counter);
		_delay_ms(1000);
		counter++;
		if (counter > 9){
			counter = 0;
		}
		
		
		
    }
}

