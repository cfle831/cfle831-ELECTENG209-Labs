/*
 * Lab6.c
 *
 * Created: 24/09/2026 10:41:16 am
 * Author : ferre
 */ 
#define F_CPU 2000000UL
#define left_dig (1<<PINB1)
#define right_dig (1<<PINB0)
#include <util/delay.h>
#include <avr/io.h>
#include "UART.h"
#include "timer.h"
volatile uint8_t segment_0_to_9[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};
volatile uint8_t thing = 0;
volatile uint8_t disp_to_update = 1;
volatile uint8_t update_flag = 0;
void set_seg(uint8_t value){
	value = segment_0_to_9[value];
	PORTC = (value);
	if (value & (1<<6)){
		PORTB |= (1<<PINB4);
	} else{
		PORTB &= ~(1<<PINB4);
	}
}

void two_dig_update_display(uint8_t value){
	PORTB &= ~(left_dig | right_dig);
	if (disp_to_update == 1){
		set_seg((value / 10) % 10);
		PORTB |= (left_dig);
		disp_to_update = 2;
	}else{
		set_seg(value % 10);
		PORTB |= (right_dig);
		disp_to_update = 1;
	}
	
	
}
int main(void)
{
	// Everything but the button pin as output
	//usart_init(12);
	timer1_init();
	DDRB = 0xFF;
	DDRB &= ~(1 << PINB7);
	DDRC = 0xFF;
	PORTB |= (1<< PINB0);
	volatile uint8_t counter = 10;
	volatile uint8_t delay_count = 0;
	volatile uint8_t button_down = 0;
	volatile uint8_t testing = 0;
    while (1) 
    {
		if (update_flag){
			two_dig_update_display(counter);
			update_flag = 0;
		}
		if (button_down && (PINB & (1<<PINB7))){
			button_down = 0;
		} else if (!button_down && !(PINB & (1 << PINB7))){
			counter = 0;
			testing++;
			button_down = 1;
		}
		// 50 appears to be the smallest delay that allows correct display
		_delay_ms(50);
		delay_count++;
		if (delay_count >= 20){
			delay_count = 0;
			counter++; 
		}
		
		if (counter >= 100){
			counter = 0;
		}
	}
}

