/*	Author: Mayur Ryali
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char getBit(unsigned char val, unsigned char k) {
	return ((val & (0x01 << k)) != 0); //bit logic AND each bit and see if the bit is a 1 or 0 and return
}


int main(void) {
	DDRA = 0x00; PORTA = 0xFF; //input
	DDRB = 0x00; PORTB = 0xFF; //input
	DDRC = 0xFF; PORTC = 0x00; //output

	unsigned char tempA = 0x00; //temp val for A
	unsigned char tempB = 0x00; //temp val for B
	unsigned char button = 0x00; //temp val for bit manipulation
    	
	while (1) {
		tempA = PINA;
		tempB = PINB;
		button = 0x00;

		for(int i = 0; i < 8; i++) {
			if (getBit(tempA,i)) { //checks which bits in A are 1
				button++;
			}
			if (getBit(tempB,i)) { //checks which bits in B are 1
				button++;
			}
		}

		PORTC = button; //set PORTC to number of 1 bits in A and B
   	}
	return 1;
}
