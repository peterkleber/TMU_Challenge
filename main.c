/*
 * main.c
 *
 *  Created on: Oct 11, 2019
 *      Author: PeterKleber
 */

#include <avr/io.h>
#include "TMU.h"
#include "DET.h"

volatile uint8 fun2_counter = 0;


void func1() {

	PORTB ^= (1<<PB4);

}
void func2() {
//	fun2_counter++;

	PORTB ^= (1<<PB5);
	fun2_counter++;
}

void func3() {
	PORTB ^= (1<<PB7);
}

void func4() {
	PORTB ^= (1<<PB7);
}
int main() {

	Det_Start();

	DDRA |= 0xFF ;
	PORTA = ~(1);

	DDRB |= (1<<PB4);
	DDRB |= (1<<PB5);
	DDRB |= (1<<PB6);
	DDRB |= (1<<PB7);

	PORTB &= ~(1<<PB4);
	PORTB &= ~(1<<PB5);
	PORTB &= ~(1<<PB6);
	PORTB &= ~(1<<PB7);


	TMU_Init(&TMU_cnfg);

	TMU_Start_Timer(20, func1, PERIODIC);
	TMU_Start_Timer(10, func2, PERIODIC);
	TMU_Start_Timer(4, func3, PERIODIC);
	//TMU_Start_Timer(400, func3, ONE_SHOT);
	TMU_Start_Timer(800, func2, ONE_SHOT);

	//TMU_Start_Timer(15, func1, PERIODIC);


	while (1) {

		TMU_Dispatch();

		//PORTA = Buffer_ptr;

		if (fun2_counter == 30) {
			TMU_Stop_Timer(func2);
			fun2_counter++ ;
		}

	}

}
