/*
 * Timer_Driver.c
 *
 *  Created on: Oct 8, 2024
 *      Author: Arjun
 */


#include "Timer_Driver.h"



TIM_HandleTypeDef htim6;


void Timer6Init(){

	__HAL_RCC_TIM6_CLK_ENABLE();

	htim6.Instance = TIM6;
	htim6.Init.Prescaler = PSC_VAL;
	htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim6.Init.Period = ARR_VAL;
	htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;

	HAL_TIM_Base_Init(&htim6);

}


void StartTimer(){

	HAL_TIM_Base_Start_IT(&htim6);

}


void StopTimer(){

	HAL_TIM_Base_Stop_IT(&htim6);

}
