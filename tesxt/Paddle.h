#ifndef PADDLE_H
#define PADDLE_H
#include "Button.h"
#include "Renderer.h"


class Paddle{
  public:
    int x;
    int y;

    bool upPressed = false;
    bool downPressed = false;

    Button& upButton;
    Button& downButton;
    Renderer& render;

    Paddle(Button& upButton, Button& downButton, Renderer& render, int x);

    void movePaddle();
    bool paddleCollision();
};

#endif  // BALL_H
