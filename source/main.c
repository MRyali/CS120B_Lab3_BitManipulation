/*	Author: Mayur Ryali
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #3  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

/*
unsigned char getBit(unsigned char val, unsigned char k) {
	return ((val & (0x01 << k)) != 0); //bit logic AND each bit and see if the bit is a 1 or 0 and return
}
*/


int main(void) {
	DDRA = 0x00; PORTA = 0xFF; //input
	DDRC = 0xFF; PORTC = 0x00; //output

	unsigned char tempA = 0x00; //temp val for A
	unsigned char tempC = 0x00; //temp val for C
    	unsigned char tempPA = 0x00; //temp val for PINA
	
	while (1) {
		tempA = PINA & 0x0F; //get first 4 bits
		tempC = 0x00;
		tempPA = PINA & 0x70; //make sure we only have bits 6-4

		if (tempA == 1 || tempA == 2) {
			tempC = 0x20; //PC5
			tempC = tempC | 0x40; //low fuel
		}
		else if (tempA == 3 || tempA == 4) {
			tempC = 0x30; // PC5-PC4
			tempC = tempC | 0x40; //low fuel
		}
		else if (tempA == 5 || tempA == 6) {
			tempC = 0x38; // PC5-PC3
		}
		else if (tempA >= 7 && tempA <= 9) {
			tempC = 0x3C; // PC5 - PC2
		}
		else if (tempA >= 10 && tempA <= 12) {
			tempC = 0x3E; // PC5 - PC1
		}
		else if (tempA >= 13 && tempA <= 15) {
			tempC = 0x3F; // PC5 - PC0
		}
		else {
			tempC = 0x00;
			tempC = tempC | 0x40; //low fuel
		}

		tempPA = tempPA >> 4; //shift bits left 4 to put bits 5 and 4 at the start

		if (tempPA == 3) { //check if bit 5 and 4 are 1 and bit 6 is zero
			tempC = tempC | 0x80; //fasten seat belt
		}

		PORTC = tempC; //set PORTC to tempC
   	}
	return 1;
}
