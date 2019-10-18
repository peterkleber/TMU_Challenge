/*
 * DET.h
 *
 *  Created on: Oct 18, 2019
 *      Author: PeterKleber
 */

#ifndef DET_H_
#define DET_H_

#include"std_types.h"
#include <avr/io.h>

void Det_Start(void);

Std_Func_t Det_ReportError(uint16 ModuleId, uint8 InstanceId, uint8 ApiId,uint8 ErrorId);


#endif /* DET_H_ */
