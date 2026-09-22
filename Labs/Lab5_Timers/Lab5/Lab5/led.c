#include "led.h"

void led_toggle(){
	PINB |= (1<<PINB5);
}