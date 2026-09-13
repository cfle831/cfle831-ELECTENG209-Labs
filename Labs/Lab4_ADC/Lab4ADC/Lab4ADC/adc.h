

#ifndef _ADC_H
#define _ADC_H

#include <stdint.h>
#include <avr/io.h>
#define  V_REF 5

void adc_init(void);
uint16_t adc_read(uint8_t chan);
uint16_t adc_convert_mv(uint16_t adc_count);

#endif