/*
 * Timer_Driver.h
 *
 *  Created on: Oct 8, 2024
 *      Author: Arjun
 */

#include "stm32f4xx_hal.h"
#include <stdbool.h>

#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_



#define MMS_RESET         0x0
#define MMS_ENABLE        0x1
#define MMS_UPDATE        0x2
#define MMS_COMPAREPULSE  0x3
#define MMS_COMPARE1      0x4
#define MMS_COMPARE2      0x5
#define MMS_COMPARE3      0x6
#define MMS_COMPARE4      0x7

#define CKD_1  0x0
#define CKD_2  0x1
#define CKD_4  0x2

#define CMS_EALIGNED   0x0
#define CMS_CALIGNED1  0x1
#define CMS_CALIGNED2  0x2
#define CMS_CALIGNED3  0x3


#define CKD_BITSHIFT        8
#define CMS_BITSHIFT        5
#define MMS_BITSHIFT        4
#define COUNTDOWN_BITSHIFT  4
#define ARPE_BITSHIFT       7
#define OPM_BITSHIFT        3
#define UDIS_BITSHIFT       1
#define UIE_BITSHIFT        0
#define CEN_BITSHIFT        0
#define UG_BITSHIFT         0



typedef struct {

	volatile uint32_t ARV;
	volatile uint8_t MMS;
	volatile uint8_t CKD;
	volatile uint16_t PSC;
	volatile uint8_t CMS;
	volatile bool ARPE;
	volatile bool CountDown;
	volatile bool UIE;
	volatile bool UDIS;
	volatile bool OPM;

} GPTimer_Config_t ;




void TimerInit(GPTIMR_RegDef_t *timer, GPTimer_Config_t config);
void Timer_ClockControl(GPTIMR_RegDef_t *timer, bool state);
void StartTimer(GPTIMR_RegDef_t *timer);
void StopTimer(GPTIMR_RegDef_t *timer);
void ResetTimer(GPTIMR_RegDef_t *timer);
uint32_t GetTimerValue(GPTIMR_RegDef_t *timer);
void Timer_InterruptControl(GPTIMR_RegDef_t *timer, bool state);
uint32_t GetTimerARV(GPTIMR_RegDef_t *timer);
void Timer_ClearInterruptFlag(GPTIMR_RegDef_t *timer);
void Timer_EnableInterruptBit(GPTIMR_RegDef_t *timer);
bool TimerStopped(GPTIMR_RegDef_t *timer);
void ForceTimerUpdate(GPTIMR_RegDef_t *timer);




#endif /* TIMER_DRIVER_H_ */
