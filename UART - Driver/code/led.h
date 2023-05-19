// K L A R
#ifndef LED_H // Kollar så att LED_H finns deklarerat/definierat någonstans i filen 
#define LED_H

#include <stdint.h> // Standard biblotek 
#include "UART.h"
#include "stm32f4xx.h" //Device Header för enhetsspecifika angivelser om hårdvaran

//Definerar GPIOB som ska ansvara för LED-funktion 
#define LED_PORT GPIOB

//Definerar klocksignalen för porten
#define LED_PORT_CLOCK (1U<<1)

//Fastställer färger för pinsen
#define LED_RED_PIN (1U<<14)
#define LED_GREEN_PIN (1U<<12)
#define LED_BLUE_PIN (1U<<15)
#define LED_YELLOW_PIN (1U<<13)

// Mode bits blir tilldelade LED-färger
#define LED_RED_MODE_BIT (1U<<28)
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MODE_BIT (1U<<30)

//Skapar LED-färgerna som ska finnas
typedef enum {
  RED = 0,
  GREEN,
  YELLOW,
  BLUE
}LedColor_Type; // kan anta någon av värden som står ovan

// Definierar status för LED färgerna (av/på)
typedef enum {
  OFF = 0,
  ON = 1
}LedState_Type;


class Led{

// LedColor_Type består av color och state (attribut)
  private:
      LedColor_Type color; 
      LedState_Type state; 

// Hämtar och sätter status för färg och state
  public:

      Led(LedColor_Type _color,LedState_Type _state);
      void setState(LedState_Type _state);
      LedState_Type getState() const;

};

#endif