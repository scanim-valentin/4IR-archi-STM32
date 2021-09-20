#ifndef MYGPIO_H
#define MYGPIO_H
#include "stm32f10x.h"

typedef struct
{
GPIO_TypeDef * GPIO ;
char GPIO_Pin ; //numero de 0 à 15
char GPIO_Conf ; // voirci dessous
} MyGPIO_Struct_TypeDef;

#define In_Floating 0x0 // a completer
#define In_PullDown 0x0 // a completer
#define In _PullUp 0x0 // a completer
#define In_Analog 0x0 // a completer
#define Out _Ppull 0x2 // a completer ?
#define Out_OD 0x0 // a completer
#define AltOut_Ppull 0x0 // a completer
#define AltOut_OD 0x0 // a completer

void MyGPIO_Init (MyGPIO_Struct_TypeDef * GPIOStructPtr);
int MyGPIO_Read (GPIO_TypeDef * GPIO, char GPIO_Pin ); // renvoie 0 ou autre chose different de 0
void MyGPIO_Set (GPIO_TypeDef * GPIO, char GPIO_Pin );
void MyGPIO_Reset (GPIO_TypeDef * GPIO, char GPIO_Pin );
void MyGPIO_Toggle (GPIO_TypeDef * GPIO, char GPIO_Pin );
#endif