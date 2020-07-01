#include "stm32f10x.h"
#include "timer.h"
#include "gpio.h"
/* See Reference Manual for the register names!*/
 
/*Add global variables at this area*/

uint16_t TIM2_counter;
uint16_t TIM2_UIF;

int main(void)
{
	gpio_ports_enable();
	timer2_enable();
	uint8_t state=0;
	while(1){
		/*Get actual Countervalue*/
		TIM2_counter = TIM2->CNT;
		
		if((TIM2->SR & TIM_SR_UIF) == TIM_SR_UIF && state){
			GPIOC->BSRR = GPIO_BSRR_BS13; 
			TIM2->SR &= ~TIM_SR_UIF;
			state=0;
		}
		else if((TIM2->SR & TIM_SR_UIF) == TIM_SR_UIF && !state){
			GPIOC->BSRR = GPIO_BSRR_BR13; 
			/*Necessary to reset the corresponding bit in status Register*/
			TIM2->SR &= ~TIM_SR_UIF;
			state=1;
		}
	}
}
