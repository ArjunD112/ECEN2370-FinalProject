/*
 * RNG_Driver.h
 *
 *  Created on: Nov 29, 2024
 *      Author: Arjun
 */

#ifndef INC_RNG_DRIVER_H_
#define INC_RNG_DRIVER_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>


#define MIN    2
#define MAX    8
#define SHIFT 29


void RNG_Init();
uint32_t RNG_GenRandNum();

#endif /* INC_RNG_DRIVER_H_ */
