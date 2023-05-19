// K L A R

#ifndef __UART_H
#define __UART_H

#include "stm32f4xx.h" //Headerfil som hämtar och innehåller riktlinjer för att kunna arbeta med en STM-Hårdvara.
#include <stdio.h> //Inkluderar standard biblotek för C språket. Headerfilen innehåller variabler, funktioner och definitioner som är viktiga för att operationerna ska fungera som dem ska.

void USART2_Init(void); // Här initialiseras UART funktionen. Tar void som argument då inget ska returneras än.
void test_setup(void); // Test funktionen i UART.c fil initialiseras.
#endif // Avslutar headerfil