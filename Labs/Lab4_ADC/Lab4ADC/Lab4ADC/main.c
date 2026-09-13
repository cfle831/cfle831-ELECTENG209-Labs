/*
 * Lab4ADC.c
 *
 * Created: 12/09/2026 1:44:14 pm
 * Author : Loelene
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"


int main(void)
{
	volatile uint16_t value = 0;
	adc_init();
    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(1);
		value = adc_convert_mv(adc_read(2));
		
    }
}

