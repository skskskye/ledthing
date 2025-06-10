#include "Renderer.h"
#include <Adafruit_NeoPixel.h>
#include "Arduino.h"
#include "LedRow.h"

//renderer creation, with all needed params 
Renderer::Renderer(int rows, int col, LedRow* inputArr[]){
    this->rows = rows;
    this->col = col;
    this->ledRows = new LedRow*[rows];

     for(int r = 0; r < rows; r++){
       this->ledRows[r] = inputArr[r];
     }
    
    // additonal rows if need be
}



//initalizing 
void Renderer::initialize(){ 
  for(int r = 0; r < rows; r++){
    LedRow* currentRow = ledRows[r];
    currentRow->initialize();
  }
}

//set the position in the grid to on or off
void Renderer::setPixelGrid(int x, int y, bool toggle){
  if(toggle){
    ledStatus[y][x] = 1;
  }else{
    ledStatus[y][x] = 0;
  }
}

//set grid based off led row object
void Renderer::setGrid(){ 
  for(int r = 0; r < rows; r++){ //looping through all elements
    LedRow* currentRow = ledRows[r]; //currnet led row, assigned to value at our ledrow array
    for(int c = 0; c < col; c++){
      ledStatus[r][c] = currentRow->getLedStatus(c); //making our matrix the same as the current row attributes
    }
  }
}

//creating any kind of square, with any kind of size
void Renderer::createShape(int x, int y, int sizeX, int sizeY){
  for(int r = 0; r < sizeY; r++){
    for(int c = 0; c < sizeX; c++){
        setPixelGrid(x + c, y + r, true);
    }
  }
}

//checking if a LED is on in the grid
bool Renderer::checkPixelOn(int x, int y){
  if(ledStatus[y][x] == 0){
    return false;
  }else{
    return true;
  }
}

//filling the grid with ON
void Renderer::fill(){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < col; j++){
      ledStatus[i][j] = 1;
    }
  }
}

//sending pixels to the leds
void Renderer::sendPixels(){
  for(int r = 0; r < rows; r++){
    for(int c = 0; c < col; c++){
      ledRows[r]->setLed(c, ledStatus[r][c]); //setting led in the led row to current state of our matrix
    }
    ledRows[r]->showRow(); //showing the row
  }
}

void Renderer::clearByCol(int c){ //clearing led grid based of the column 
  for(int r = 0; r < rows; r++){
    ledStatus[r][c] = 0;     
  }                             
  sendPixels();
}

void Renderer::clear(){ //clearing our led grid
  for(int r = 0; r < rows; r++){
    for(int c = 0; c < col; c++){
      ledStatus[r][c] = 0;
    }                       
  }                             
  sendPixels();     
}

void Renderer::showGrid(){
  for(int r = 0; r < rows; r++){
    for(int c = 0; c < col; c++){
      Serial.print(ledStatus[r][c]);
      Serial.print(" ");
    }
    Serial.println("");
  }
  Serial.println("=========================");
}



