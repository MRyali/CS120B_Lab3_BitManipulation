/*	Author: Mayur Ryali
 *  Partner(s) Name: 
 *	Lab Section: 21
 *	Assignment: Lab #3  Exercise #4
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
	DDRB = 0xFF; PORTB = 0x00; //output
	DDRC = 0xFF; PORTC = 0x00; //output

	unsigned char tempA = 0x00; //temp val for A
	unsigned char tempB = 0x00; //temp val for B
    	unsigned char tempC = 0x00; //temp val for C
	
	while (1) {
		tempA = PINA;
		tempB = 0x00;
		tempC = 0x00;

		tempB = (tempA & 0xF0) >> 4; //assign upper nibble of A to lower nibble of B
		tempC = (tempA & 0x0F) << 4; //assign lower nibble of A to upper nibble of B

		PORTB = tempB; //set PORTB to tempB
		PORTC = tempC; //set PORTC to tempC
   	}
	return 1;
}
