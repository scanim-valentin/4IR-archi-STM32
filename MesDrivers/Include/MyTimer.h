#ifndef MYTIMER_H
#define MYTIMER_H
#include "stm32f10x.h"

#define TIM1CLK 72000000

typedef struct {
	TIM_TypeDef * Timer; // TIM1 à TIM4
	unsigned short ARR;
	unsigned short PSC;
} MyTimer_Struct_TypeDef;


/*
*************************************************************************************************
* @brief
* @param -> Paramètre sous forme d’ une structure (son adresse) contenant les
informations de base
* @Note -> Fonction à lancer systématiquement avant d’ aller plus en détail dans les
conf plus fines (PWM, codeur inc...)
*************************************************************************************************
*/

/*
Je veux T -> T = (1/TIMxCLK) * (PSC+1) * (ARR+1)

Exemple 500ms -> 500e-3*13888.88 = (PSC+1) * (ARR+1)
<=> Ftimer = Fclock * (PSC+1) * (ARR+1) = 32 * 217 (https://www.desmos.com/calculator?lang=fr)
Soit PSC = 216 et ARR = 31 pour cet exemple (PSC max = 512 voir RM 92, ARR = 65535 résolution du timer)

Lancer Timer -> CEN=1
*/



void MyTimer_Base_Init(MyTimer_Struct_TypeDef * TimerParam);
void MyTimer_Base_Start(TIM_TypeDef * Timer);
void MyTimer_Base_Stop(TIM_TypeDef * Timer);

//GESTION DES INTERRUPTIONS
void MyTimer_ActiveIT(TIM_TypeDef * Timer, char prio,  void (*f)(void) );

#endif



