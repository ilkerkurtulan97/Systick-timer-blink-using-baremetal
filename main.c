#include "stm32f4xx.h"                  // Device header


int main(void)
{
	RCC->APB1ENR |= 1;
	GPIOG->MODER |= 0x4000000; 								//Activating led on PG13...
	
	//Configuring Systick
	SysTick->LOAD = 3200000 -1;
	SysTick->VAL = 0;
	SysTick->CTRL = 13;
	
	while(1)
	{
		//Check if count flag is set
		if(SysTick->CTRL & 0x10000000000000){
			GPIOG->ODR ^=0x2000;
	}
	
	}
	
}