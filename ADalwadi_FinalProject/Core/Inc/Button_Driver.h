/*
 * Button_Driver.h
 *
 *  Created on: Sep 24, 2024
 *      Author: Arjun
 */

#ifndef BUTTON_DRIVER_H_
#define BUTTON_DRIVER_H_


#include "stm32f4xx_hal.h"


#define BUTTON_PORT_VALUE   GPIOA
#define BUTTON_PIN_NUMBER   GPIO_PIN_0
#define BUTTON_PRESSED        1
#define BUTTON_NOT_PRESSED    0


void Button_Init();
void Button_Init_InterruptMode();
uint8_t Button_Check_State();



#endif /* BUTTON_DRIVER_H_ */
