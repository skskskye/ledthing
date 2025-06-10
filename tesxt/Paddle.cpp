#include "Paddle.h"
#include "Arduino.h"
#include "Button.h"
#include "Renderer.h"

Paddle::Paddle(int x){ //creating our paddle object
  this->x = x; //our x is the spot our paddle will be on
}

void Paddle::movePaddle(bool upButton, bool downButton, Renderer& render){ //moving paddle logic
    if(upButton){ //checking if it moves up
      y++; //making the paddle go up
      if(y > render.rows - 3){ //the max height that it can be given the size of the paddle, checking if its past that
          y = render.rows - 3; //setting it back wehre it should be
      }else{
        render.clearByCol(x); //clear only when we arent at our max heights, dont need to clear if not
      }
    }else if(downButton){ //checking if button is being held down
      y--; //making paddle go down
      Serial.println(y);
      if(y < 0){ //min height reach, set to min height to not go out of bounds
        y = 0;
      }else{
        render.clearByCol(x); //clearing the col only when we dont reach our min height
      }
    }
  render.createShape(x, y, 1, 3); //creating our paddle shape
}

void Paddle::increaseScore(){ //increase score function
  score++;
}