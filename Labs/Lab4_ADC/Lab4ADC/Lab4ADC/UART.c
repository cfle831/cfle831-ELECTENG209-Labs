 #include "global.h"
 #include "UART.h"
 #include <string.h>
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

char string_5_dig[6] = {};
char* decimal_to_char(uint16_t value){
	uint32_t divisor = 10000;
	memset(string_5_dig, 0, 6);
	string_5_dig[5] = '\0';
	
	for (uint8_t index = 0; index<5; index++){
		string_5_dig[index] = (char)(((value / divisor) % 10)+48);
		
		divisor /= 10;
		
	}
	
	// Trim Leading zeros
	
	uint8_t first_dig_index = 0;
	for (uint8_t index = 0; index<5; index++){
		if (string_5_dig[index] != '0'){
			
			first_dig_index = index;
			
			break;
		}
	}
	if (first_dig_index){
		for (uint8_t index = 0; index<6; index++){
			if ((index + first_dig_index) >=5){
				string_5_dig[index] = '\0';
				
				break;
			} else{
				
				string_5_dig[index] = string_5_dig[index + first_dig_index];	
					
			}
		
		}
	}
	
	return string_5_dig;
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
	 if (!(digits[0] <= 0)) {
		 usart_transmit(digits[0] + 48);
		 usart_transmit(digits[1] + 48);
		 usart_transmit(digits[2] + 48);
		 usart_transmit(',');
		 usart_transmit(' ');
		 } else if (!(digits[1] <= 0)){
		 usart_transmit(digits[1] + 48);
		 usart_transmit(digits[2] + 48);
		 usart_transmit(',');
		 usart_transmit(' ');
		 } else{
		 usart_transmit(digits[2] + 48);
		 usart_transmit(',');
		 usart_transmit(' ');
	 }
	 
 }
 
void transmit_string_with_val(char text[], char value[], uint8_t length){
	 for (uint8_t i = 0; i<length; i++){
		 usart_transmit(text[i]);
		 _delay_ms(5);
	 }
	 for (uint8_t n = 0; n<10; n++){
		if (value[n] == '\0'){
			break;
		}
		 usart_transmit(value[n]);
		 _delay_ms(5);
		  
	 }
 }
 
 
 void transmit_new_line(){
	 usart_transmit('\n');
	 usart_transmit('\r');
 }