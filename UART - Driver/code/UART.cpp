// K L A R 

#include "UART.h" // Inkluderar header filen (STM) som innehåller definitioner


// Funktionen som deklarerades i UART.h initialiserades här med viktiga egenskaper för UART protokollet
void USART2_Init(void) {

// Ger uart2 klocktillgång.
RCC->APB1ENR |= 0x20000; // APB = buss transport för data. Sätter bit 17 till 1 enligt registret för att aktivera klockan. 
RCC->AHB1ENR |= 0x01; // Sätter bit 0 till 1 för att aktivera GPIOA, som är port A och förser den med klock tillgång 


// Aktiverar 2 pins för att UART kommunikationen ska fungera 

GPIOA->MODER &= ~0x00F0; //Rensar bitarna 4-7 för att förbereda pins PA2 och PA3
  //& samt ~forcerar en invertering som leder till att bitarna som via hex betecknas med 1, i realvärde ersätts med 0

GPIOA->MODER |= 0x00A0; //Bitarna 5 och 7 sätts till 1 för att aktivera alternativ funktion på pins PA2 och PA3


// Val av vilken typ alternativa funktion som ska antas för pins 
GPIOA->AFR[0] &= ~0xFF00; //Rensar och nollställer bitarna 8-15 för att förbereda pins PA2 och PA3
GPIOA->AFR[0] |= 0x7700; //Bitarna 8-11 samt 12-15 sätts till formatet 0111

/* Konstruktion av enhetens kommunikation avslutas */

// UART uppbyggnad 
USART2->BRR = 0x0683; // Sätter baud rate till 9600 (hexadecimalt)
USART2->CR1 = 0x000C; // Sätter igång transmitter och reciever för kommunikationen och jobbar med 8 bitars data

// kontroll register 2 & 3 nollställs
USART2->CR2 = 0x000; 
USART2->CR3 = 0x000; 

USART2->CR1 |= 0x2000; // Aktiverar UART genom att ändra bit 13 till 1 (enligt STM)

}

// Deklarerar UART skrivfunktion som ska överföras till USART 2 port
int USART2_write(int ch){ 

  while(!(USART2->SR & 0x0080)){} // Så länge data finns kvar i sändnings register kan nästa karaktär inte tas emot
  
  USART2->DR = (ch & 0xFF); //Sätter överföringen av byten till dataregistret

  return ch;

}



// Deklarerar UART läsfunktion som ska motta information 
int USART2_read(void){ //Deklarerar läsfunktionen (mottagning av information)

  while(!(USART2->SR & 0x0020)){} // Kontrollerar om mer data finns som ska läggas till i data registret 
  return USART2->DR; //skriver ut datan

}