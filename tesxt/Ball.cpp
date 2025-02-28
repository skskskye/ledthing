#include "Ball.h"
#include "Arduino.h"
#include "Paddle.h"
#include "Renderer.h"
#include <stdlib.h>




void Ball::tick(Renderer& render, Paddle& p1, Paddle& p2){
  int newX = x + veloX;
  int newY = y + veloY;


  bool hit = false;


  

  //wall collision
  if((newY > render.rows - 1 || newY < 0)){
    if(!hit){
      veloY = -veloY;
      newY = y + veloY;
    }
    Serial.println("hit the wall normally");
  }

  //paddles
  if((newX == p1.x && (newY <= p1.y + 2 && newY >= p1.y)) || 
    (newX == p2.x  && (newY <= p2.y + 2 && newY >= p2.y))){
    veloX = -veloX;
    hit = true;
  }
  
  newX = x + veloX;
  newY = y + veloY;

  if(newX > render.col - 1 || newX < 0){
    Serial.println("score");
    veloY = (rand() % 1 ) - 1;
    veloX = (rand() % 1) + 1;
    newX = 2;
    newY = 2;
  }

  render.setPixelGrid(x, y, false);
  render.ledStatus[x][y] == 0;

  render.setPixelGrid(newX, newY, true);
  

  x = newX;
  y = newY;
}

