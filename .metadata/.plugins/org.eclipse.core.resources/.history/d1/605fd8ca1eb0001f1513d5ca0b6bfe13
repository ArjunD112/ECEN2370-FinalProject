/*
 * RNG_Driver.c
 *
 *  Created on: Nov 29, 2024
 *      Author: Arjun
 */


#include "RNG_Driver.h"

RNG_HandleTypeDef hrng;


uint32_t randNum = 0;



void RNG_Init(){

	__HAL_RCC_RNG_CLK_ENABLE();

	hrng.Instance = RNG;

	while(HAL_RNG_Init(&hrng) != HAL_OK){
		;
	}

}


void RNG_DeInit(){

	while(HAL_RNG_DeInit(&hrng) != HAL_OK){
		;
	}

}


uint32_t RNG_GenRandNum(){

	RNG_Init();


	while(HAL_RNG_GenerateRandomNumber(&hrng, &randNum) != HAL_OK){
		;
	}


	uint32_t rn = (randNum >> SHIFT) + MIN;


	if(rn > MAX){

		uint32_t s = (randNum >> SHIFT) + 1;

		rn -= s;

		if(rn < MIN){
			rn = MIN;
		}

	}


	RNG_DeInit();


	return rn;

}


