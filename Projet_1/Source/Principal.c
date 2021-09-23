#include "stm32f10x.h"
#include "MyTimer.h"

int main(void)
{
	/**INITIALISATION DES VARIABLES**/
	MyTimer_Struct_TypeDef timer_param = {TIM1, 217, 32}; //Structure paramètre de la fonction timer init
	/********************************/
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
		
	//RCC->APB2ENR = registre de l'unité périphérique RCC qui gère les horloges du microcontrôleur
	//ici: on y applique un masque avec un ou logique : 
	// RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
	// RCC->APB2ENR |= (0b0000 0100) | (0b0000 1000) | (0b0001 0000);
	// RCC->APB2ENR |= (0b0001 1100);
	// RCC->APB2ENR |= (0x1C);
	MyTimer_Base_Init(&timer_param);
	MyTimer_Base_Start(TIM1);
	do {
		
		} while(1);
}

