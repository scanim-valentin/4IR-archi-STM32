#define BROCHE_LED (5)
#define OUT_PP_2MHZ (2)
#define SEUIL_DIODE (0x00000020)

void configure_led(int pin) {
	// pin 5 -> d�cale 4 fois
	GPIOA->CRL &= ~(0xF << (BROCHE_LED)*(pin-1)); //si on est au-d�l� pin 7 -> CRH et et one repart � 0 donc -8
	GPIOA->CRL |= OUT_PP_2MHZ << (BROCHE_LED*(pin-1));
}

