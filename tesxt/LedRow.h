#ifndef LEDROW_H
#define LEDROW_H

#include <Adafruit_NeoPixel.h>

class LedRow{ //class
  public: //public vars
    int* rowStatus; // a dynamic array for our led row
    int numbPixels; //numb pixels in our array

    //default colours
    int defaultRed; 
    int defaultBlue;
    int defaultGreen;

    Adafruit_NeoPixel row; //adafruit library row 

    LedRow(int pin, int numbPixels, int defaultRed, int defaultBlue, int defaultGreen); //constructor
    void initialize(); //initialize 
    void showRow(); //show the row
    void setLed(int index, int value); //set led 
    //void setColour(int index, int r, int g, int b); 
    void setRow(int value); //set a whole row to one value
    int getSize(); //size of our array
    int* getRowStatus(); //returning our led array
    int getLedStatus(int index); //get status of led 
};

#endif  // LEDROW_H
