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

//
int MyGPIO_Read(GPIO_TypeDef * GPIO, char GPIO_Pin) {

	return (0x1 << GPIO_Pin) == ( GPIO->IDR & (0x1 << GPIO_Pin) );
	
}


void MyGPIO_Set(GPIO_TypeDef * GPIO, char GPIO_Pin) {
	
	GPIO->ODR |= (0x1 << GPIO_Pin);
	//PAS UN VRAI REGISTRE
}

void MyGPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_Pin) {
	

	GPIO->ODR &= ~(0x1 << GPIO_Pin);
	
}

void MyGPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_Pin) {
	

	
	// On inverse le bit à la position voulue.
	GPIO->ODR ^= (0x1 << GPIO_Pin);
}


void MyGPIO_Init (MyGPIO_Struct_TypeDef * GPIOStructPtr){
	
	//Mise à 0 des 4 bits correspondant dans CRL
	GPIOStructPtr->GPIO->CRL &= ~(0xF << (GPIOStructPtr->GPIO_Pin)*4); //si on est au-délà pin 7 -> CRH et et one repart à 0 donc -8
	//Sélection du mode et de la config de la pin (Sur 4 bits : 0b(2 bits CNF)(2 bits MODE) )
	GPIOStructPtr->GPIO->CRL |= GPIOStructPtr->GPIO_Conf << (GPIOStructPtr->GPIO_Pin*4);
	

}
