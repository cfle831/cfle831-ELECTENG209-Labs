/*
 * Lab2Prelab.c
 *
 * Created: 30/07/2026 3:45:47 pm
 * Author : ferre
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>
#define UPPERLIM 300
int main(void)
{
    /* Replace with your application code */
	static uint16_t primes[63];
	volatile uint16_t curNumber = 2;
	volatile uint8_t curIndex = 0;
	volatile bool curPrime = true;
	while (true){
		curPrime = true;
		for (uint16_t value = 2; value<curNumber; value++){
			if (curNumber % value == 0){
				curPrime = false;
				break;
			}
		}
		if (curPrime){
			
			primes[curIndex] = curNumber;
			curIndex++;
		}
		curNumber++;
		if (curNumber>UPPERLIM){
			break;
		}
	}
	
		
    while (1) 
    {
    }
}

