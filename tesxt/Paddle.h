#ifndef PADDLE_H
#define PADDLE_H
#include "Button.h"
#include "Renderer.h"


class Paddle{
  public:
    int x;
    int y = 0;

    // Button& upButton;
    // Button& downButton;
    // Renderer& render;

    Paddle(int x);

    void movePaddle(bool upButton, bool downButton, Renderer& render);
    bool paddleCollision();
};

#endif  // BALL_H
