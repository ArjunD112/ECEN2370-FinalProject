/*
 * Button_Driver.c
 *
 *  Created on: Sep 24, 2024
 *      Author: Arjun
 */


#include "Button_Driver.h"


void Button_Init(){

	GPIO_InitTypeDef config = {0};

	config.Pin = BUTTON_PIN_NUMBER;
	config.Mode = GPIO_MODE_INPUT;
	config.Speed = GPIO_SPEED_FREQ_HIGH;


	__HAL_RCC_GPIOA_CLK_ENABLE();

	HAL_GPIO_Init(BUTTON_PORT_VALUE, &config);

}


void Button_Init_InterruptMode(){

	GPIO_InitTypeDef config = {0};

	config.Pin = BUTTON_PIN_NUMBER;
	config.Mode = GPIO_MODE_IT_RISING;
	config.Speed = GPIO_SPEED_FREQ_HIGH;


	__HAL_RCC_GPIOA_CLK_ENABLE();

	HAL_GPIO_Init(BUTTON_PORT_VALUE, &config);

	HAL_NVIC_EnableIRQ(EXTI0_IRQn);

}


GPIO_PinState Button_Check_State(){

	uint8_t data = HAL_GPIO_ReadPin(BUTTON_PORT_VALUE, BUTTON_PIN_NUMBER);

	return data;

}
