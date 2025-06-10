#include "Ball.h"
#include "Arduino.h"
#include "Paddle.h"
#include "Renderer.h"
#include <stdlib.h>

void Ball::tick(Renderer& render, Paddle& p1, Paddle& p2){
  int newX = x + veloX; //our potential newX
  int newY = y + veloY; //our potential newY

  bool hit = false; //a hit condition, so we know when we hit something

  //wall collision
  if((newY > render.rows - 1 || newY < 0)){ //checking if we hit a wall
    if(!hit){ // weird edge case to see if we hit a paddle, fixed some weird bug doing this, fixed something 

      
      veloY = -veloY; //making our ball move the opposite y direction when hitting wall
      newY = y + veloY; //our new position added with our bounce
    }
  }

  //checking if a paddle has hit the ball
  if((newX == p1.x && (newY <= p1.y + 2 && newY >= p1.y)) || 
    (newX == p2.x  && (newY <= p2.y + 2 && newY >= p2.y))){
    veloX = -veloX; //opposite velocity to what currently is if we did hit one
    hit = true;
  }
  
  //having newX and newY since we hit something, changes our x and y we should be going
  newX = x + veloX;
  newY = y + veloY;


  if(newX > p2.x || newX < p1.x){ //out of bounds check

    //checking which side, give score to whatever side
    if(newX > p2.x){
      p1.increaseScore();
    }else if(newX < p1.x){
      p2.increaseScore();
    }

    //reset the ball velo, with random chance which direction it goes
    veloY = (rand() % 1) - 1;
    veloX = (rand() % 1) + 1;

    //reseting the position
    newX = render.col / 2;
    newY = render.rows / 2;
  }

  //setting the current position led to false, since it moved
  render.setPixelGrid(x, y, false);
    
  //turning on the new position led
  render.setPixelGrid(newX, newY, true);
  
  //after all checks are done, our x/y can now be the new x and new y
  x = newX;
  y = newY;
}

