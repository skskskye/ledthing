#ifndef PADDLE_H
#define PADDLE_H
#include "Button.h"
#include "Renderer.h"


class Paddle{ //class
  public: //public vars

    //paddle position
    int x;
    int y = 0; //value 
    
    //score for the paddle
    int score = 0;

    Paddle(int x); //initalizing paddle 

    void movePaddle(bool upButton, bool downButton, Renderer& render); //moving paddle function
    void increaseScore(); //increase score function
};

#endif  // BALL_H
