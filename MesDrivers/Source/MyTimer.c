#include "MyTimer.h"

void MyTimer_Base_Init(MyTimer_Struct_TypeDef * TimerParam){
	TimerParam->Timer->PSC = TimerParam->PSC;
	TimerParam->Timer->ARR = TimerParam->ARR;	
}

void MyTimer_Base_Start(TIM_TypeDef * Timer) {
	uwu
}