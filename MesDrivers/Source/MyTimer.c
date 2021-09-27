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
	
	//Releasing update interruption flag
	TIM2->SR &= ~(TIM_SR_UIF);
	
	//Calling the user defined handler 
	generic_handler_function();

}

void TIM3_IRQHandler(void){
	TIM3->SR &= ~(TIM_SR_UIF);
	generic_handler_function();

}

void TIM4_IRQHandler(void){
	TIM4->SR &= ~(TIM_SR_UIF);
	generic_handler_function();
}

//Particular cases : TIM1 & TIM8 interrupt handlers

void TIM1_UP_IRQHandler(void){
	TIM1->SR &= ~(TIM_SR_UIF);
	generic_handler_function();
}

void TIM8_UP_IRQHandler(void){
	TIM8->SR &= ~(TIM_SR_UIF);
	generic_handler_function();
}

///////////////////
void MyTimer_ActiveIT(TIM_TypeDef * Timer, char prio,  void (*f)(void)){
	//UIE bit = update interuption. Overflow is an update 
	Timer->DIER ^=  TIM_DIER_UIE ;
	
	switch((int)Timer){
		
		case (int)TIM2:
			
			//Enabling the interruption in the NVIC
			NVIC_EnableIRQ(TIM2_IRQn);		

			//Setting the priority: IPRx_Ny <- 0bXXXX0000 
			NVIC->IP[TIM2_IRQn] ^=  (prio << 4) ;
			break;
		
		case (int)TIM3:
			NVIC_EnableIRQ(TIM3_IRQn);		
			NVIC->IP[TIM3_IRQn] ^=  (prio << 4) ;
			break;
		
		case (int)TIM4:
			NVIC_EnableIRQ(TIM4_IRQn);		
			NVIC->IP[TIM4_IRQn] ^=  (prio << 4) ;
			break;
		
		//Dealing with TIM1 & TIM2
		case (int)TIM1 : 
			//from stm32f10x.h : 25, !< TIM1 Update Interrupt
			NVIC_EnableIRQ(TIM1_UP_IRQn); 
			NVIC->IP[TIM1_UP_IRQn] ^=  (prio << 4) ;
			break;
		
		/*case (int)TIM8 : 
			//from stm32f10x.h : 25, !< TIM1 Update Interrupt
			NVIC_EnableIRQ(TIM8_UP_IRQn); 
			NVIC->IP[TIM8_UP_IRQn] ^=  (prio << 4) ;
			break;*/
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



