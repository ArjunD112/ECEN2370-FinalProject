/*
 * Timer_Driver.c
 *
 *  Created on: Oct 8, 2024
 *      Author: Arjun
 */


#include "Timer_Driver.h"


void StartTimer(GPTIMR_RegDef_t *timer){ timer -> CR1 |= (ENABLE << CEN_BITSHIFT); }

void StopTimer(GPTIMR_RegDef_t *timer){ timer -> CR1 &= ~(ENABLE << CEN_BITSHIFT); }

void ResetTimer(GPTIMR_RegDef_t *timer){ timer -> CNT = RESET; }

void ForceTimerUpdate(GPTIMR_RegDef_t *timer){ timer -> EGR |= (SET << UG_BITSHIFT); }

uint32_t GetTimerARV(GPTIMR_RegDef_t *timer){ return (timer -> ARR); }

volatile uint32_t GetTimerValue(GPTIMR_RegDef_t *timer){ return (timer -> CNT); }


void Timer_ClearInterruptFlag(GPTIMR_RegDef_t *timer){ timer -> SR &= ~(SET); }


void Timer_InterruptControl(GPTIMR_RegDef_t *timer, bool state){

	if(state){

		if(timer == TIM2){ IRQ_EnableInterrupt(TIM2_IRQ_NUM); }
		else if(timer == TIM5){ IRQ_EnableInterrupt(TIM5_IRQ_NUM); }

	}
	else{

		if(timer == TIM2){ IRQ_DisableInterrupt(TIM2_IRQ_NUM); }
		else if(timer == TIM5){ IRQ_DisableInterrupt(TIM5_IRQ_NUM); }

	}

}


void Timer_EnableInterruptBit(GPTIMR_RegDef_t *timer){


	timer -> DIER |= (SET << UIE_BITSHIFT);

	Timer_InterruptControl(timer, true);

}



void Timer_ClockControl(GPTIMR_RegDef_t *timer, bool state){

	if(state){

		if(timer == TIM2) { APB1_CLK_ENABLE(TIM2_CLK_BIT); }
		else if(timer == TIM5) { APB1_CLK_ENABLE(TIM5_CLK_BIT); }

	}
	else{

		if(timer == TIM2) { APB1_CLK_DISABLE(TIM2_CLK_BIT); }
		else if(timer == TIM5) { APB1_CLK_DISABLE(TIM5_CLK_BIT); }

	}

}


bool TimerStopped(GPTIMR_RegDef_t *timer){

	if((timer -> CR1) & 1){ return false; }
	else { return true; }

}


void TimerInit(GPTIMR_RegDef_t *timer, GPTimer_Config_t config){

	Timer_ClockControl(timer, ENABLE);

	uint32_t temp;


	temp = (config.CKD << CKD_BITSHIFT);
	timer -> CR1 &= ~(0x3 << CKD_BITSHIFT);
	timer -> CR1 |= temp;

	temp = (config.CMS << CMS_BITSHIFT);
	timer -> CR1 &= ~(0x3 << CMS_BITSHIFT);
	timer -> CR1 |= temp;

	temp = (config.MMS << MMS_BITSHIFT);
	timer -> CR2 &= ~(0x7 << MMS_BITSHIFT);
	timer -> CR2 |= temp;

	temp = (config.CountDown << COUNTDOWN_BITSHIFT);
	timer -> CR1 &= ~(SET << COUNTDOWN_BITSHIFT);
	timer -> CR1 |= temp;

	temp = (config.ARPE << ARPE_BITSHIFT);
	timer -> CR1 &= ~(SET << ARPE_BITSHIFT);
	timer -> CR1 |= temp;

	temp = (config.OPM << OPM_BITSHIFT);
	timer -> CR1 &= ~(SET << OPM_BITSHIFT);
	timer -> CR1 |= temp;

	temp = (config.UDIS << UDIS_BITSHIFT);
	timer -> CR1 &= ~(SET << UDIS_BITSHIFT);
	timer -> CR1 |= temp;

	temp = (config.UIE << UIE_BITSHIFT);
	timer -> DIER &= ~(SET << UIE_BITSHIFT);
	timer -> DIER |= temp;


	timer -> PSC = config.PSC;

	timer -> ARR = config.ARV;


	if(config.UIE){ Timer_InterruptControl(timer, true); }
	else { Timer_InterruptControl(timer, false); }


}
