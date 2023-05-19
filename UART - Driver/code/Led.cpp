// K L A R

#include "LED.h" //Inkluderar header filen så alal funktioner ska fungera som de ska 

//LED-lampornas Konstruktor 
Led::Led(LedColor_Type _color, LedState_Type _state)
{

  // Deklarerar 2 variabler som kommunicerar och lagra LED lampans status
  this->color = _color;  // nyckelord 'this' refererar till variabel i detta kodblock 
  this->state = _state;

  //Aktiverar klockan för LED-porten (GPIOB)
  RCC->AHB1ENR |= LED_PORT_CLOCK;

  //Organiserar LED-pinsens status och färg. Beroende på vilket case pinsen har blir outputs olika..
  switch(_color){

    case RED: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      if(this->state == ON){
        //Sätter på LED
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        //Stänger av LED
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      case YELLOW: //Sätta portläget för LED-konfigurationen till output
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      if(this->state == ON){
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE: 
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      if(this->state == ON){
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN:
      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      if(this->state == ON){
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;
  }
}


void Led::setState(LedState_Type _state){

  //Sätter statusen av LED:n
  this->state = _state;

  //Kontrollerar genom färger så att man hanterar och ändrar på rätt LED.
  switch(this->color){

      //if LED är röd
    case RED:
      //ändras pin till outputläge
      LED_PORT->MODER |= LED_RED_MODE_BIT;
      
      //if status är ON blir pinoutput aktiv 
      if(this->state == ON){
        LED_PORT->ODR |= LED_RED_PIN;
      }
      else{
        //Pin output sätt till inaktiv
        LED_PORT->ODR &= ~LED_RED_PIN;
      }
      break;

      case YELLOW:
     
      LED_PORT->MODER |= LED_YELLOW_MODE_BIT;
      if(this->state == ON){
        LED_PORT->ODR |= LED_YELLOW_PIN;
      }
      else{
        LED_PORT->ODR &= ~LED_YELLOW_PIN;
      }
      break;

      case BLUE:
      
      LED_PORT->MODER |= LED_BLUE_MODE_BIT;
      if(this->state == ON){
        LED_PORT->ODR |= LED_BLUE_PIN;
      }
      else{
        LED_PORT->ODR &= ~LED_BLUE_PIN;
      }
      break;

      case GREEN:

      LED_PORT->MODER |= LED_GREEN_MODE_BIT;
      if(this->state == ON){
        LED_PORT->ODR |= LED_GREEN_PIN;
      }
      else{
        LED_PORT->ODR &= ~LED_GREEN_PIN;
      }
      break;
  }

}

LedState_Type Led::getState(void)const{

  //Styr över den efterfrågande LED
  switch(this->color){

    case RED:
      break;

    case YELLOW:
      break;

    case BLUE:
      break;

    case GREEN:
      break;
  }
             return this->state; // printar ut statusen av den valda LED:n
}
