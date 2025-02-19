#ifndef RENDERER_H
#define RENDERER_H

#include <Adafruit_NeoPixel.h>



class Renderer{
  public:
    int rows = 6;
    int col = 6;
    int numbPixels = 6;
    int ledStatus[6][6] = {{0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0}
    };
    int x;
    int y;
    Adafruit_NeoPixel row1, row2, row3, row4, row5, row6;
    Renderer(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6);
    void clear();
    void initalize();
    void setPixelGrid(int x, int y, bool toggle);
    void createShape(int x, int y, int sizeX, int sizeY);
    bool checkPixelOn(int x, int y);
    void fill();
    void sendPixels();



    
    

};

#endif  // RENDERER_H
