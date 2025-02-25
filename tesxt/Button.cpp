#include "Button.h"
#include "Arduino.h"

Button::Button(int pin){
  this->pin = pin;
}

void Button::initalize(){
  pinMode(pin, INPUT);
}

bool Button::getButtonState(){
  
  return digitalRead(pin) == HIGH;
  
}