#include "Button.h"
#include "Arduino.h"

Button::Button(int pin){  //initalizing button based off its pins
  this->pin = pin;
}

void Button::initalize(){
  pinMode(pin, INPUT); //setting the pinmode for our button
}

bool Button::getButtonState(){
  return analogRead(pin) >= 750; //simply returning the state of the button
}