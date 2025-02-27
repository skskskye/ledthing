#include "Ball.h"
#include "Arduino.h"
#include "Paddle.h"
#include "Renderer.h"


void Ball::reset(Renderer& render){
  x = 2;
  y = 2;
  render.clear();
}


void Ball::tick(Renderer& render, Paddle& p1, Paddle& p2){
  int newX = x + veloX;
  int newY = y + veloY;


  

  //paddles
  if((newX == p1.x && (newY <= p1.y + 2 && newY >= p1.y)) || 
    (newX == p2.x  && (newY <= p2.y + 2 && newY >= p2.y))){
    veloX = -veloX;
    veloY = -veloY;
  }

  //wall collision
  if(newY > render.rows - 1 || newY < 0){
    veloY = -veloY;
  }

  if(newX > render.col - 1 || newX < 0){
    Serial.println("score!");
  }

  newX = x + veloX;
  newY = y + veloY;

  render.clearByCol(x);
  render.setPixelGrid(newX, newY, true);

  x = newX;
  y = newY;
}

