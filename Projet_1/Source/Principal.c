#include "stm32f10x.h"
#include "MyTimer.h"

int n = 0;
void handler_timer(void){
	n += 1;
	
}

int main(void)
{
	/**INITIALISATION DES VARIABLES**/
	MyTimer_Struct_TypeDef timer_param = {TIM2, 4499, 7999}; //Structure paramètre de la fonction timer init
	/********************************/
	
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN | RCC_APB1ENR_TIM3EN | RCC_APB1ENR_TIM4EN;
	
	MyTimer_Base_Init(&timer_param);
	MyTimer_Base_Start(TIM2);
	MyTimer_ActiveIT(TIM2,1,&handler_timer);
	
	
	do {
		
		} while(1);
}

