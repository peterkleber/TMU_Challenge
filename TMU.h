/*
 * TMU.h
 *
 *  Created on: Oct 12, 2019
 *      Author: PeterKleber
 */

#ifndef TMU_H_
#define TMU_H_

#include"std_types.h"
#include"TMU_cnfg.h"
#include "Timer.h"
#include "DET.h"

#define TMU_ModuleId (0x02)
#define TMU_InstanceId (0x00)

#define TMU_Init_ApiId (0x00)
#define TMU_Start_Timer_ApiId (0x01)
#define TMU_Stop_Timer_ApiId (0x02)
#define TMU_Dispatch_ApiId (0x03)
#define TMU_DeInit_ApiId (0x04)

#define TMU_Nullptr_ErrorId (0x00)
#define TMU_Not_Initialized_ErrorId (0x01)
#define TMU_Reinitialize_ErrorId (0x02)
#define TMU_Buffer_Overflow_ErrorId (0x03)



#define BUFFER_SIZE ((uint8)4)

typedef enum {NOT_Active,Active}Status_t;

typedef enum {
 PERIODIC, ONE_SHOT
 } Rotation_t;


typedef enum {
	TMU_NOK, TMU_OK
} EnmTMUError_t;


typedef struct{
	void (*ptr) ();
	uint16 Start_time ;
	uint16 Delay_time ;
	Rotation_t Mode ;
	Status_t Status ;
}TMU_Buffer_t;

EnmTMUError_t TMU_Init(const TMU_ConfigType *ConfigPtr);
EnmTMUError_t TMU_Start_Timer(uint16 Time_Delay, void (*Ptr)(void), Rotation_t mode);
EnmTMUError_t TMU_Stop_Timer(void (*Ptr)(void));
EnmTMUError_t TMU_Dispatch();
EnmTMUError_t TMU_DeInit(void);
void ISR_Generated_Flag_Setter();

//extern uint8 Buffer_ptr ;

#endif /* TMU_H_ */
