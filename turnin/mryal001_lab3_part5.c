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
	DDRB = 0xFF; PORTB = 0x00; //output for only bit 0
	DDRD = 0xFF; PORTD = 0x00; //output

	unsigned char tempB = 0x00; //temp val for B
	unsigned char tempD = 0x00; //temp val for D
    	unsigned char tempAirbag = 0x00; //temp val for airbag
	
	while (1) {
		tempB = PINB & 0x01; //only need PB0
		tempD = PIND; //need all of PD
		tempAirbag = 0x00; 

		if ((tempD >= 70 && tempB == 0) || (tempD >= 69 && tempB == 1)) { //check if weight is greater than 70
			tempAirbag = 0x02; //set PB1 to 1		
		}
		else if ((tempD > 5 && tempB == 0) || (tempD > 4 && tempB == 1)) { //check if weight is between 5 and 70
			tempAirbag = 0x04; //set PB2 to 1
		}
		else {
			tempAirbag = 0x00; //no passengers
		}

		PORTD = tempB | tempAirbag; //set output
   	}
	return 1;
}
