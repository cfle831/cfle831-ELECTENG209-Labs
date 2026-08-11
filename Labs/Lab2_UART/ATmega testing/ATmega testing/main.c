/*
 * ATmega testing.c
 *
 * Created: 6/08/2026 3:13:50 pm
 * Author : ferre
 */ 



#define F_CPU  2000000UL
#define UPPERLIM 300

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

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
		while (!(UCSR0A & (1 << UDRE0)));
		UDR0 = data;
	
}
void transmit_decimal(uint16_t dec_val){
	uint8_t digits[3] = {};
	digits[0] = ((dec_val / 100) % 10);
	digits[1] = ((dec_val / 10) % 10);
	digits[2] = ((dec_val) % 10);
	if (!(digits[0] <=0)) {
		usart_transmit(digits[0] + 48);
		usart_transmit(digits[1] + 48);
		usart_transmit(digits[2] + 48);
	} else if (!(digits[1] <=0)){
			usart_transmit(digits[1] + 48);
			usart_transmit(digits[2] + 48);
	} else{
		usart_transmit(digits[2] + 48);
	}
	
}
int main(void)
{
	usart_init(12);
	// Find Prime numbers
	static uint16_t primes[63];
	volatile uint16_t curNumber = 2;
	volatile uint8_t curIndex = 0;
	volatile bool curPrime = true;
	while (true){
		curPrime = true;
		for (uint16_t value = 2; value<curNumber; value++){
			if (curNumber % value == 0){
				curPrime = false;
				break;
			}
		}
		if (curPrime){
			
			primes[curIndex] = curNumber;
			curIndex++;
		}
		curNumber++;
		if (curNumber>UPPERLIM){
			break;
		}
	}
	curIndex = 0;
	
    while (1) 
    {
		if (!(UCSR0A & 1 << UDRE0)){
			_delay_ms(1);
			continue;
		} else{
			transmit_decimal(primes[curIndex]);
			curIndex++;
			
			_delay_ms(500);
		}
	}
}

