/*
 * Lab2Prelab.c
 *
 * Created: 30/07/2026 3:45:47 pm
 * Author : ferre
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

int main(void)
{
    /* Replace with your application code */
	static uint8_t primes[64];
	volatile uint8_t curNumber = 3;
	volatile uint8_t curIndex = 0;
	volatile bool curPrime = true;
	while (true){
		curPrime = true;
		for (uint8_t value = 2; value<curNumber; value++){
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
		if (curNumber>300){
			break;
		}
	}
		
		
    while (1) 
    {
    }
}

