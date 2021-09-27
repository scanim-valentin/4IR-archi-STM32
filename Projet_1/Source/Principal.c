#include "stm32f10x.h"
#include "MyTimer.h"
#include "MyGPIO.h"

int n = 0;
void handler_timer(void){
	n += 1;
	
}

int main(void)
{
	MyGPIO_Struct_TypeDef GPIOx = {GPIOA, 7, AltOut_Ppull};
	/**INITIALISATION DES VARIABLES**/
	MyTimer_Struct_TypeDef timer_param = {TIM2, 0, 0xE0F}; //Structure paramètre de la fonction timer init
	/********************************/
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN | RCC_APB1ENR_TIM3EN | RCC_APB1ENR_TIM4EN;
	
	MyGPIO_Init(&GPIOx);
	//MyTimer_PWM(TIM2, 1);
	
	MyTimer_Base_Init(&timer_param);
	MyTimer_Base_Start(TIM2);
	MyTimer_ActiveIT(TIM2,1,&handler_timer);
	
	do {
		
		} while(1);
}

