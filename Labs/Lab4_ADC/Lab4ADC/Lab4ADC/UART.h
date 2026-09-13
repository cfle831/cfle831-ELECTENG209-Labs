 
 
#ifndef _UART_H
#define _UART_H

#include <stdint.h>
#include <avr/io.h>

#define BAUD 9600
 
void usart_init(uint16_t ubrr);
char* decimal_to_char(uint16_t value);
void usart_transmit(uint8_t data);
void transmit_decimal(uint16_t dec_val);
void transmit_string_with_val(char text[], char value[], uint8_t length);


#endif