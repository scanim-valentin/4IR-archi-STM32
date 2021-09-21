#include "MyGPIO.h"
#define PIN_NUMBER (5)

//Renvoie la valeur trouvée dans le Control Register correspondant au pin
//Je sais pas si c'est ce qui est attendu
/*int MyGPIO_Read(GPIO_TypeDef * GPIO, char GPIO_Pin) {

	int value;
	int pin = (int)GPIO_Pin;
	
	// Selon le numéro de pin on regarde le CRL (0 à 7) ou le CRH (8 à 15)
	// https://gist.github.com/iwalpola/6c36c9573fd322a268ce890a118571ca
	if (pin > 7) {
		value = GPIO->CRH;
	}
	else {
		value = GPIO->CRL;
	}
	return value;
}*/

int MyGPIO_Read(GPIO_TypeDef * GPIO, char GPIO_Pin) {

	return GPIO->IDR & (0x1 << GPIO_Pin);
	
}


void MyGPIO_Set(GPIO_TypeDef * GPIO, char GPIO_Pin) {
	
	//int pin = (int)GPIO_Pin;
	
	// On met à un le bon bit et on le déplace dans les 16 premiers bits pour affecter la valeur
	// https://gist.github.com/iwalpola/6c36c9573fd322a268ce890a118571ca
	GPIO->BSRR |= (1 << GPIO_Pin) << 16 ;
	
}

void MyGPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_Pin) {
	
	int pin = (int)GPIO_Pin;
	
	// On met à un le bon bit et on le déplace dans les 16 bits de poids fort pour affecter la valeur
	// https://gist.github.com/iwalpola/6c36c9573fd322a268ce890a118571ca
	GPIO->BRR |= (1 << pin) << 16;
	
}

void MyGPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_Pin) {
	
	int pin = (int)GPIO_Pin;
	
	// On inverse le bit à la position voulue.
	GPIO->ODR ^= (1 << pin);
}


void MyGPIO_Init (MyGPIO_Struct_TypeDef * GPIOStructPtr){
	
	//Mise à 0 des 4 bits correspondant dans CRL
	GPIOStructPtr->GPIO->CRL &= ~(0xF << (GPIOStructPtr->GPIO_Pin)*4); //si on est au-délà pin 7 -> CRH et et one repart à 0 donc -8
	//Sélection du mode et de la config de la pin (Sur 4 bits : 0b(2 bits CNF)(2 bits MODE) )
	GPIOStructPtr->GPIO->CRL |= GPIOStructPtr->GPIO_Conf << (GPIOStructPtr->GPIO_Pin*4);
	

}

/*typedef struct
{
  __IO uint32_t CRL;
  __IO uint32_t CRH;
  __IO uint32_t IDR;
  __IO uint32_t ODR;
  __IO uint32_t BSRR;
  __IO uint32_t BRR;
  __IO uint32_t LCKR;
} GPIO_TypeDef;*/


MyGPIO_Struct_TypeDef LD2 = {GPIOA , PIN_NUMBER , Out_Ppull};
	//Led 2 activation structure


//int main(void) {
//    
//    RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
//	
//	/*Test:
//	Reproduire l'expérience du blink avec les fonction définie plus haut
//	*/


//	
//	
//	//Initiating LED 2 
//	
//	MyGPIO_Init(&LD2);
//	
//}
