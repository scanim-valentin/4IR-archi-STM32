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
	Timer->CR1 &= ~(0x01) ;
}

//Activates the overflow interuption of the timer and sets the priority to Prio
//0 highest to 15 lowest
void MyTimer_ActiveIT(TIM_TypeDef * Timer, char Prio){
	//UIE bit = update interuption. Overflow is an update 
	Timer->DIER ^=  0x01 ; 
	
	//Setting the priority: 0bXXXX0000 
	NVIC->IPR0
}

