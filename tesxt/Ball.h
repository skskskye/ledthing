#ifndef BALL_H
#define BALL_H
#include "Paddle.h"

class Ball{
  public:

    int x = 2;
    int y = 2;

    int veloX = 1;
    int veloY = 1;

    void tick(Renderer& render, Paddle& p1, Paddle& p2);
    void reset(Renderer& render);
};

#endif  // BALL_H
