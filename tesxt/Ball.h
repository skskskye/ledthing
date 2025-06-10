#ifndef BALL_H
#define BALL_H
#include "Paddle.h"

class Ball{ //our ball class
  public: //all our public vars


    //ball position
    int x = 5; 
    int y = 2;

    
    //ball velocity
    int veloX = 1;
    int veloY = -1;

    void tick(Renderer& render, Paddle& p1, Paddle& p2); //tick function, runs every tick, for change with the ball
};

#endif  // BALL_H
