# Projet de Simon et Guerbette

Pour tester les drivers, utiliser le projet Keil du dossier Projet_1 

#Changelog :

## Valentin 27/09/2021
- Fonction MyGPIO_Init corrigée (prise en compte de numéro de pin > 8)
- MyTimer_Init peut initialiser TIM1 maintenant (à tester)
   -> pb TIM8 (TIM8_UP_IRQn) Activation TIM8 : #ifdef STM32F10X_HD??? dans stm32f10x.h


## 0xACCO 24/09/2021
- Ajout du .gitignore
