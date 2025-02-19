#include "Renderer.h"
#include <Adafruit_NeoPixel.h>
#include "Arduino.h"



Renderer::Renderer(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6)
  : row1(numbPixels, pin1, NEO_GRB + NEO_KHZ800), 
    row2(numbPixels, pin2, NEO_GRB + NEO_KHZ800), 
    row3(numbPixels, pin3, NEO_GRB + NEO_KHZ800), 
    row4(numbPixels, pin4, NEO_GRB + NEO_KHZ800), 
    row5(numbPixels, pin5, NEO_GRB + NEO_KHZ800), 
    row6(numbPixels, pin6, NEO_GRB + NEO_KHZ800) {
    // Additional initialization if needed
}


void Renderer::initalize(){
  row1.begin();
  row2.begin();
  row3.begin();
  row4.begin();
  row5.begin();
  row6.begin();
}

void Renderer::setPixelGrid(int x, int y, bool toggle){
    if(toggle){
      ledStatus[y][x] = 1;
    }else{
      ledStatus[y][x] = 0;
    }
  }

void Renderer::createShape(int x, int y, int sizeX, int sizeY){
  for(int r = 0; r < sizeY; r++){
    for(int c = 0; c < sizeX; c++){
        setPixelGrid(x + c, y + r, true);
    }
  }
}

bool Renderer::checkPixelOn(int x, int y){
  if(ledStatus[y][x] == 0){
    return false;
  }else{
    return true;
  }
}

void Renderer::fill(){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < col; j++){
      ledStatus[i][j] = 1;
    }
  }
}


void Renderer::sendPixels(){
  for(int r = 0; r < rows; r++){
    for(int c = 0; c < col; c++){
      switch(r){
        case 0:
          if(checkPixelOn(c, r)){
            row1.setPixelColor(c, row1.Color(255, 255, 255));
          }else{
            row1.setPixelColor(c, row1.Color(0, 0, 0));
          }
          break;
        case 1:
          if(checkPixelOn(c, r)){
            row2.setPixelColor(c, row2.Color(255, 255, 255));
          }else{
            row2.setPixelColor(c, row2.Color(0, 0, 0));
          }
          break;
        case 2:
          if(checkPixelOn(c, r)){
            row3.setPixelColor(c, row3.Color(255, 255, 255));
          }else{
            row3.setPixelColor(c, row3.Color(0, 0, 0));
          }
          break;
        case 3:
          if(checkPixelOn(c, r)){
            row4.setPixelColor(c, row4.Color(255, 255, 255));
          }else{
            row4.setPixelColor(c, row4.Color(0, 0, 0));
          }
          break;
        case 4: 
          if(checkPixelOn(c, r)){
            row5.setPixelColor(c, row5.Color(255, 255, 255));
          }else{
            row5.setPixelColor(c, row5.Color(0, 0, 0));
          }
          break;

        case 5: 
          if(checkPixelOn(c, r)){
            row6.setPixelColor(c, row6.Color(255, 255, 255));
          }else{
            row6.setPixelColor(c, row6.Color(0, 0, 0));
          }
          break;

        default:
          Serial.println("error");
          break;
      }
      Serial.print(ledStatus[r][c]);
    }
    Serial.println("");
  }
  Serial.println("---");
  row1.show();
  row2.show();
  row3.show();
  row4.show();
  row5.show();
  row6.show();
}


void Renderer::clear(){
  for(int r = 0; r < rows; r++){
    for(int c = 0; c < col; c++){
      ledStatus[r][c] = 0;  
    }                       
  }                             
  sendPixels();     
}





