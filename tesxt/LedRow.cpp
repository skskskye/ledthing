#include "LedRow.h"
#include <Adafruit_NeoPixel.h>

LedRow::LedRow(int pin, int numbPixels, int defaultRed, int defaultBlue, int defaultGreen)
    : row(12, pin, NEO_GRB + NEO_KHZ800) // initialize Adafruit_NeoPixel with 12 pixels on the given pin
{

    //setting all of our values
    this->numbPixels = numbPixels;
    this->rowStatus = new int[numbPixels]; //making an array size of the numb pixels we have

    //default colours
    this->defaultBlue = defaultBlue;
    this->defaultRed = defaultRed;
    this->defaultGreen = defaultGreen;

    //creating array
    for (int i = 0; i < 12; i++) { 
        rowStatus[i] = 0;
    }
}

void LedRow::initialize(){ //initializing our rows
  this->row.begin();
}

void LedRow::showRow(){ //show the rows
  for(int i = 0; i < this->numbPixels; i++){
    if(rowStatus[i] == 1){ //checking if the led is on
      this->row.setPixelColor(i, row.Color(this->defaultRed, this->defaultGreen, this->defaultBlue)); //display if it is
    }else{
      this->row.setPixelColor(i, row.Color(0, 0, 0)); //display if not 
    }
    
  }
  this->row.show(); //show all the updates we have made
}

int LedRow::getSize(){ //returning amount of pixels
  return this->numbPixels;
}

int* LedRow::getRowStatus(){ //returning our led array
  return this->rowStatus;
}

void LedRow::setRow(int value){ //setting row to all one value
  for(int i = 0; i < this->numbPixels; i++){
    this->rowStatus[i] = value;
  }
}

void LedRow::setLed(int index, int value){ //setting an individual led to on/off
  this->rowStatus[index] = value;
}

int LedRow::getLedStatus(int index){ //get the led status of a individual led
  return this->rowStatus[index];
}







