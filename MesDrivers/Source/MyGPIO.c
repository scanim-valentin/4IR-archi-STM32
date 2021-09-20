#include MyGPIO.h

//Renvoie la valeur trouvée dans le Control Register correspondant au pin
//Je sais pas si c'est ce qui est attendu
int MyGPIO_Read(GPIO_TypeDef * GPIO, char GPIO_Pin) {

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
}

void MyGPIO_Set(GPIO_TypeDef * GPIO, char GPIO_Pin) {
	
	int pin = (int)GPIO_Pin;
	
	// On met à un le bon bit et on le déplace dans les 16 premiers bits pour affecter la valeur
	// https://gist.github.com/iwalpola/6c36c9573fd322a268ce890a118571ca
	GPIO->BSRR |= (0b01 << pin) << 16;
	
}

void MyGPIO_Reset(GPIO_TypeDef * GPIO, char GPIO_Pin) {
	
	int pin = (int)GPIO_Pin;
	
	// On met à un le bon bit et on le déplace dans les 16 bits de poids fort pour affecter la valeur
	// https://gist.github.com/iwalpola/6c36c9573fd322a268ce890a118571ca
	GPIO->BRR |= (0b01 << pin) << 16;
	
}

void MyGPIO_Toggle(GPIO_TypeDef * GPIO, char GPIO_Pin) {
	
	int pin = (int)GPIO_Pin;
	
	// On inverse le bit à la position voulue.
	GPIO->ODR ^= (1 << pin);
}


void MyGPIO_Init (MyGPIO_Struct_TypeDef * GPIOStructPtr){
        	

}

int main(void) {
    
    RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);

}
