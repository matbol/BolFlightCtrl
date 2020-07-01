#include "stm32f10x.h"
#include "gpio.h"
void gpio_ports_enable(void)
{
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN |     RCC_APB2ENR_IOPBEN|RCC_APB2ENR_IOPCEN; //ports A & B & C clock enabled
  GPIOC->CRH = 0x44344444; //Pin C13 enable. If you don't like number 13, use pin C_1_P.M. LOL
	/*TODO: Avoid Magic Numbers!*/
}