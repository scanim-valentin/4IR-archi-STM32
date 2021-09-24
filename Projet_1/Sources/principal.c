#define OUT_PP_2MHZ (2)
#define SEUIL_DIODE (0x00000020)


#include "stm32f10x.h"
#include "MyTimer.h"
#include "MyGPIO.h"

int n = 0;
void TIM4_IRQHandler(){
		TIM4->SR &= ~(TIM_SR_UIF);	
		MyGPIO_Toggle (GPIOA, 5 );
		n++;
}

int main(void){
	
	MyGPIO_Struct_TypeDef gpioA = {GPIOA,5,Out_Ppull};
	MyTimer_Struct_TypeDef timer4 = {TIM4, 4499, 7999};
	RCC->APB1ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
		
	MyGPIO_Init(&gpioA);
	
	MyTimer_Base_Init(&timer4);
	MyTimer_Base_Start(TIM4);
	MyTimer_ActiveIT(TIM4,1);

	do{
		
	}while(1);
	
}
