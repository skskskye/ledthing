#include "Paddle.h"
#include "Arduino.h"
#include "Button.h"
#include "Renderer.h"

Paddle::Paddle(Button& upButton, Button& downButton, Renderer& render, int x){
  this->upButton = upButton;
  this->downButton = downButton;
  this->render = render;
  this->x = x;
}
