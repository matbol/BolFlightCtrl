#include "stm32f10x.h"
#include "timer.h"

void timer2_enable(void){
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->PSC = 48000;
	TIM2->ARR = 1000;
	
	TIM2->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN;
}