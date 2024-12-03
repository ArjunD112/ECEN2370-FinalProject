/*
 * Timer_Driver.c
 *
 *  Created on: Oct 8, 2024
 *      Author: Arjun
 */


#include "Timer_Driver.h"



TIM_HandleTypeDef htim7;



void Timer7Init(){

	__HAL_RCC_TIM7_CLK_ENABLE();

	//HAL code below
	TIM_MasterConfigTypeDef sMasterConfig = {0};

	htim7.Instance = TIM7;
	htim7.Init.Prescaler = PSC_VAL;
	htim7.Init.CounterMode = TIM_COUNTERMODE_UP;
	htim7.Init.Period = ARR_VAL;
	htim7.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;

	HAL_TIM_Base_Init(&htim7);

	sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;

	HAL_TIMEx_MasterConfigSynchronization(&htim7, &sMasterConfig);

	NVIC_EnableIRQ(TIM7_IRQn);

}


void Timer7DeInit(){

	HAL_TIM_Base_DeInit(&htim7);

}


void StartTimer(){

	Timer7Init();

	TIM_ClearInterruptFlag();



	HAL_TIM_Base_Start_IT(&htim7);

}


uint16_t StopTimer(){

	HAL_TIM_Base_Stop_IT(&htim7);

	uint16_t c = __HAL_TIM_GET_COUNTER(&htim7);

	Timer7DeInit();

	return c;

}


void TIM_ClearInterruptFlag(){

	__HAL_TIM_CLEAR_FLAG(&htim7, TIM_FLAG_UPDATE);

}
