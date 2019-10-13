/*
 * main.c
 *
 *  Created on: Oct 11, 2019
 *      Author: PeterKleber
 */

#include "TMU.h"
#include <avr/io.h>


volatile uint8 fun2_counter = 0;


void func1() {

	PORTB ^= (1<<PB4);

}
void func2() {
	fun2_counter++;

	PORTB ^= (1<<PB5);
}

int main() {

	DDRB |= (1<<PB4);
	DDRB |= (1<<PB5);
	DDRB |= (1<<PB6);

	PORTB &= ~(1<<PB4);
	PORTB &= ~(1<<PB5);
	PORTB &= ~(1<<PB6);


	TMU_Init(&TMU_cnfg);
	TMU_Start_Timer(20, func1, ONE_SHOT);
	TMU_Start_Timer(10, func2, PERIODIC);
	//TMU_Start_Timer(15, func1, PERIODIC);


	while (1) {

		TMU_Dispatch();

		if (fun2_counter == 3) {
			TMU_Stop_Timer(func2);
		}

	}

}
