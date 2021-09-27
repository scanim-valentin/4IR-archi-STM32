#include "MyTimer.h"

//Initializes the timer with prescaling and autoreload 
//T = (1/TIMxCLK) * (PSC+1) * (ARR+1)
void MyTimer_Base_Init(MyTimer_Struct_TypeDef * TimerParam){
	TimerParam->Timer->PSC = TimerParam->PSC;
	TimerParam->Timer->ARR = TimerParam->ARR;	
}

//Enables the counter (CEN bit) in the TIMx->CR1 register
void MyTimer_Base_Start(TIM_TypeDef * Timer){
	Timer->CR1 ^= 0x01 ; 
}

//Disables the counter (CEN bit) in the TIMx->CR1 register
void MyTimer_Base_Stop(TIM_TypeDef * Timer){
	Timer->CR1 &= ~TIM_CR1_CEN ;
}

//Activates the overflow interuption of the timer and sets the priority to Prio
//0 highest to 15 lowest

//REDEFINING TIMER HANDLERS WITH GENERIC FUNCTIONS PASSED FROM MyTimer_ActiveIT

void (*generic_handler_function)(void);

void TIM2_IRQHandler(void){
	TIM2->SR &= ~(TIM_SR_UIF);
	generic_handler_function();

}

void TIM3_IRQHandler(void){
	generic_handler_function();
	TIM3->SR &= ~(TIM_SR_UIF);
}

void TIM4_IRQHandler(void){
	generic_handler_function();
	TIM4->SR &= ~(TIM_SR_UIF);
}

///////////////////
void MyTimer_ActiveIT(TIM_TypeDef * Timer, char prio,  void (*f)(void)){
	//UIE bit = update interuption. Overflow is an update 
	Timer->DIER ^=  TIM_DIER_UIE ;
	
	switch((int)Timer){
		case (int)TIM2:
			NVIC_EnableIRQ(TIM2_IRQn);		

			//Setting the priority: 0bXXXX0000 
			NVIC->IP[TIM2_IRQn] ^=  (prio << 4) ;
			break;
		
		case (int)TIM3:
			NVIC_EnableIRQ(TIM3_IRQn);		

			//Setting the priority: 0bXXXX0000 
			NVIC->IP[TIM3_IRQn] ^=  (prio << 4) ;
			break;
		
		case (int)TIM4:
			NVIC_EnableIRQ(TIM4_IRQn);		

			//Setting the priority: 0bXXXX0000 
			NVIC->IP[TIM4_IRQn] ^=  (prio << 4) ;
			break;
		}
	//Setting up the handler
	Init_periph(f);
}

void Init_periph ( void (*f)(void)){
	generic_handler_function = f;
}
/*
void MyTimer_PWM(TIM_TypeDef * Timer, char Channel){
	Timer->CCR4 = TIM_
}
*/



