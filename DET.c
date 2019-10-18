/*
 * DET.c
 *
 *  Created on: Oct 18, 2019
 *      Author: PeterKleber
 */

#include"DET.h"

static uint8 Det_Start_Flag = 0;

void Det_Start(void) {
	DDRB |= (1 << PB0);
	PORTB &= ~(1 << PB0);

	Det_Start_Flag = 1;
}

Std_Func_t Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId,
		uint8 ErrorId) {

	if (Det_Start_Flag == 1) {
		PORTB |= (1 << PB0);
	}

	return OK;
}
