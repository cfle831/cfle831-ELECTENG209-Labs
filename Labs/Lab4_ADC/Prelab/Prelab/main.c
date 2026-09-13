/*
 * Prelab.c
 *
 * Created: 27/08/2026 1:20:16 pm
 * Author : ferre
 */ 
#define F_CPU 2000000
#define LED_FREQUENCY 1
#define BUTTON_OPEN (PINB & (1<<PINB7))


#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

void pin_Setup(){
	DDRB = (1<<DDB5);
	DDRC = 0xff;
	DDRD = 0xff;
	PORTB = 0x00;
	
}

int main(void)
{
	pin_Setup();
    /* Replace with your application code */
	volatile bool button_held = false;
    while (1) 
    {
		if (BUTTON_OPEN){
			PORTB |= (1<<PINB5);
			_delay_ms(50);
		} else{
			PORTB &= ~(1<<PINB5);
			_delay_ms(50);
		}
		
		
    }
}

