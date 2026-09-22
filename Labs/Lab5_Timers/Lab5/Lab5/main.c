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

int main(void)
{
	timer0_init();
	
	DDRB |= 0xFF;
	DDRC &= ~(0xFF);
	DDRD &= ~(0xFF);
    while (1) 
    {
		
	
    }
}

