/*
 * Timer_Driver.h
 *
 *  Created on: Oct 8, 2024
 *      Author: Arjun
 */

#include "stm32f4xx_hal.h"

#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_



#define PSC_VAL 7199
#define ARR_VAL 9999



void Timer7Init();
void Timer7DeInit();
void StartTimer();
uint16_t StopTimer();
void TIM_ClearInterruptFlag();




#endif /* TIMER_DRIVER_H_ */
