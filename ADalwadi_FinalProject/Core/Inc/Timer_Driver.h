/*
 * Timer_Driver.h
 *
 *  Created on: Oct 8, 2024
 *      Author: Arjun
 */

#include "stm32f4xx_hal.h"

#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_



#define PSC_VAL 2999
#define ARR_VAL 6249



void Timer6Init();
void StartTimer();
void StopTimer();
void TIM_ClearInterruptFlag();




#endif /* TIMER_DRIVER_H_ */
