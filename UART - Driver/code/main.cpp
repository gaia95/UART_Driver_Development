// K L A R

#include "led.h" // Inkluderar header bibloteket  

// Deklaration
LedState_Type led1_state;
LedState_Type led2_state;
LedState_Type led3_state;

Led led1(RED,ON);

int main(void){ //bygger upp huvudprogrammet som sköter LED-lampor
  USART2_Init();

  Led led2(BLUE,ON); 

  Led *led3 = new Led(YELLOW,ON); // 

// Hämtar state av led 1 och stänger sedan av den 
  led1_state = led1.getState(); 
  led1.setState(OFF);

  delete led3;

  while(1){} // loopar oändligt tills breakstatement dyker upp

}
