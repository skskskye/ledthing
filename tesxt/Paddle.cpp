#include "Paddle.h"
#include "Arduino.h"
#include "Button.h"
#include "Renderer.h"

Paddle::Paddle(int x){
  this->x = x;
}

void Paddle::movePaddle(bool upButton, bool downButton, Renderer& render){
    if(upButton){
      y++;
      if(y > 3){
          y = 3;
      }else{
        render.clearByCol(x);
      }
    }else if(downButton){
      y--;
      Serial.println(y);
      if(y < 0){
        y = 0;
      }else{
        render.clearByCol(x);
      }
    }
  
  render.createShape(x, y, 1, 3);
}
