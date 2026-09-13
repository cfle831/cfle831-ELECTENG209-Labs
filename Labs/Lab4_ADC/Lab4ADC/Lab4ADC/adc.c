



# include "adc.h"

void adc_init(void){
	ADCSRA = (1<<ADEN);
	ADCSRB = 0x00;
	ADCSRA |= (1 << ADPS2);
}

uint16_t adc_read(uint8_t chan){
	// Select channel from input
	ADMUX &= ~((1<<MUX3) | (1<<MUX2) | (1<<MUX1) | (1<<MUX0));
	ADMUX |= chan;
	// Start conversion
	ADCSRA |= (1<<ADSC);
	// Wait
	while (!((1<<ADIF) & (ADCSRA)));
	return (((uint16_t)ADCH << 8) | ADCL);
	
}

uint16_t adc_convert_mv(uint16_t adc_count){
	uint32_t value = adc_count;
	value *= ((V_REF*1000) / (1024));
	return value;
}

