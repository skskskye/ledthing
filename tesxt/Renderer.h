#ifndef RENDERER_H
#define RENDERER_H

#include <Adafruit_NeoPixel.h>
#include "LedRow.h"


class Renderer{
  public:
    int rows; //amount of rows
    int col; //amount of cols

    int ledStatus[8][12] = {0}; //led matrix  **will make it dynamic later if i have time**  
    LedRow** ledRows;
    Renderer(int rows, int cols, LedRow* ledRows[]); //creating our renderer
    void setGrid();
    void clear(); //clear the matrix
    void clearByCol(int col); //clear matrix at a column
    void initialize(); //initializing our matrix
    void setPixelGrid(int x, int y, bool toggle); //set a pixel in our matrix
    void createShape(int x, int y, int sizeX, int sizeY); //creating a shape in our matrix
    bool checkPixelOn(int x, int y); //checking when if a led is on in our matrix
    void fill(); //fill the matrix
    void sendPixels(); //sending out grid states to LEDs
    void showGrid(); //show grid to console
};

#endif  // RENDERER_H
