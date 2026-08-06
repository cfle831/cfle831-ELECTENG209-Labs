/*
 * ATmega testing.c
 *
 * Created: 6/08/2026 3:13:50 pm
 * Author : ferre
 */ 



#define F_CPU  2000000UL

#include <avr/io.h>
#include <util/delay.h>

volatile uint16_t checkVal;
void usart_init(uint16_t ubrr){
	// Operating Mode - Async
	UCSR0C &= ~((1<<6) | (1<<7));
	// Character Size - 8 bit
	UCSR0B &= ~(1 << UCSZ02);
	UCSR0C |= (1 << UCSZ01);
	UCSR0C |= (1 << UCSZ00);
	// Clock Polarity - Drive low for Async
	UCSR0C &= ~(1 << UCPOL0);
	// Baude Rate of 9600
	
	UBRR0L = (uint8_t)ubrr;
	// Transmitter Enable
	UCSR0B |= (1 << TXEN0);
	// Parity Mode - disabled
	UCSR0C &= ~((1<<UPM00) | (1<<UPM01));
	// Stop Bits - 1
	UCSR0C &= ~(1<<USBS0);
}

void usart_transmit(uint8_t data){
	// Check if able to transmit / Safe to Load
	if (UCSR0A && 1 << UDRE0){
		UDR0 = data;
	} 
}
int main(void)
{
	usart_init(12);
	
	
    while (1) 
    {
		if (!(UCSR0A && 1 << UDRE0)){
			_delay_ms(1);
			continue;
		} else{
			usart_transmit('3');
			_delay_ms(500);
		}
	}
}

