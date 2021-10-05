#include "stm32f10x.h"
#include "MyTimer.h"
#include "MyGPIO.h"

float cycle = 0.2;
int mode = 0; //0 -> rising, 1 -> falling

void changer_rapport_cyclique(void) {
	
	if (cycle > 1) {
		mode = 1;
	}
	else if (cycle < 0) {
		mode = 0;
	}
	
	if (mode == 0) {
		cycle += 0.00002;
		MyTimer_PWM_Change_Duty_Cycle(TIM2, 2, cycle);
	}
	
	else {
		cycle -= 0.00002;
		MyTimer_PWM_Change_Duty_Cycle(TIM2, 2, cycle);
	}
}


int main(void)
{
	
	
	MyGPIO_Struct_TypeDef GPIOx = {GPIOA, 1, AltOut_Ppull};
	/**INITIALISATION DES VARIABLES**/
	MyTimer_Struct_TypeDef timer_param = {TIM2, 719, 0}; //Structure paramètre de la fonction timer init
	/********************************/
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN | RCC_APB1ENR_TIM3EN | RCC_APB1ENR_TIM4EN;
	
	MyGPIO_Init(&GPIOx);
	
	MyTimer_Base_Init(&timer_param);
	
	MyTimer_ActiveIT(TIM2, 4,  &changer_rapport_cyclique);
	
	//TODO: Test avec PWM = 100kHz avec Rapport cyclique = 20%
	MyTimer_PWM_Init(TIM2, 2);
	MyTimer_PWM_Change_Duty_Cycle(TIM2, 2, cycle);
	
	
	
	MyTimer_Base_Start(TIM2);
	
	do {
		
		} while(1);
}

