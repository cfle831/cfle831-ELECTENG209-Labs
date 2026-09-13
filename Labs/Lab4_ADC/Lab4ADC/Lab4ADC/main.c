/*
 * Lab4ADC.c
 *
 * Created: 12/09/2026 1:44:14 pm
 * Author : Loelene
 */ 

#include "global.h"
#include "adc.h"
#include "UART.h"

#include <avr/io.h>
#include <util/delay.h>




int main(void)
{
	volatile uint16_t volt_value = 0;
	adc_init();
	usart_init(((F_CPU/((uint32_t)16*BAUD)) - 1));
    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(1);
		volt_value = adc_convert_mv(adc_read(2));
		transmit_string_with_val("Read voltage is ", decimal_to_char(12345), 16);
		// fix decimal to char
		
    }
}

