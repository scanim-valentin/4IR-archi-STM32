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
	
	//(documentation Nucleo-64)
	//Led verte : User LD2: the green LED is a user LED connected to Arduino signal D13 corresponding to 
  //MCU I/O PA5 (pin 21) or PB13 (pin 34) depending on the STM32 target. 
	
	//B1 USER: the user button is connected to the I/O PC13 (pin 2) of the STM32 microcontroller.
	
		do {} 
		while(1);
}

