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
	uint16_t adc0_volt[40];
	uint16_t adc1_volt[40];
	uint8_t index = 0;	
    /* Replace with your application code */
	adc_read(2); // dummy conversion to settle values
    while (1) 
    {
		_delay_ms(1);
		adc0_volt[index] = adc_convert_mv(adc_read(0));
		adc1_volt[index] = adc_convert_mv(adc_read(1));
		index++;
		if (index == 40){
			break;
		}
		
    }
	transmit_text("Voltage, Current", 16);
	transmit_new_line();
	transmit_excel_two_columns(adc0_volt, adc1_volt);
}

