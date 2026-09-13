



#include "adc.h"
#include "global.h"
void adc_init(void){
	// Enable ADC converter
	ADCSRA = (1<<ADEN);
	// Clock prescaler of 16
	ADCSRA |= (1 << ADPS2);
	ADCSRB = 0x00;
}

uint16_t adc_read(uint8_t chan){
	// Select channel from input
	ADMUX &= ~((1<<MUX3) | (1<<MUX2) | (1<<MUX1) | (1<<MUX0));
	ADMUX |= chan;
	// Start conversion
	ADCSRA |= (1<<ADSC);
	// Wait
	_delay_ms(500);
	return (((uint16_t)ADCH << 8) | ADCL);
	
}

uint16_t adc_convert_mv(uint16_t adc_count){
	uint32_t value = (uint32_t)adc_count;
	value *= ((V_REF*1000) / (1023))/0.82;
	return value;
}

