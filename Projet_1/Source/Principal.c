#define BROCHE_LED (5)
#define OUT_PP_2MHZ (2)
#define SEUIL_DIODE (0x00000020)

#include "stm32f10x.h"



int main(void)
{
		RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
	
	//RCC->APB2ENR = registre de l'unité périphérique RCC qui gère les horloges du microcontrôleur
	//ici: on y applique un masque avec un ou logique : 
	// RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
	// RCC->APB2ENR |= (0b0000 0100) | (0b0000 1000) | (0b0001 0000);
	// RCC->APB2ENR |= (0b0001 1100);
	// RCC->APB2ENR |= (0x1C);
	
	//(documentation Nucleo-64 figure 29 4/4)
	//Led verte : User LD2: PA 5 -> GPIOA_ODR : 0x00000020 seuil	 GP output push-pull
	//B1 USER: the user button is connected to the I/O PC13 (pin 2) of the STM32 microcontroller.
	
	
	GPIOA->CRL &= ~(0xF << (BROCHE_LED)*4); //si on est au-délà pin 7 -> CRH et et one repart à 0 donc -8
	GPIOA->CRL |= 0x3 << (BROCHE_LED*4);
	

		do {
			if (GPIOC->IDR < 0x0000F000) {
				GPIOA->ODR = SEUIL_DIODE;
			}
			else {
				GPIOA->ODR = 0;
			} 
		} while(1);
}

