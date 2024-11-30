/*
 * RNG_Driver.c
 *
 *  Created on: Nov 29, 2024
 *      Author: Arjun
 */


#include "RNG_Driver.h"

RNG_HandleTypeDef hrng;


uint32_t randNum;



void RNG_Init(){

	__HAL_RCC_RNG_CLK_ENABLE();

	hrng.Instance = RNG;
	HAL_RNG_Init(&hrng);

}


uint32_t RNG_GenRandNum(){

	HAL_RNG_GenerateRandomNumber(&hrng, &randNum);

	uint32_t rn = (randNum >> SHIFT) + MIN;


	if(rn > MAX){

		uint32_t s = (randNum >> SHIFT) + 1;

		rn -= s;

		if(rn < MIN){
			rn = MIN;
		}

	}


	return rn;

}

