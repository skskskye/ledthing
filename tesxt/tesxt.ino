#include <Adafruit_NeoPixel.h>
#include "Button.h"

#define ROW1_PIN 7
#define ROW2_PIN 2
#define ROW3_PIN 3
#define ROW4_PIN 4
#define ROW5_PIN 5
#define ROW6_PIN 6

#define NUMBPIXELS 6

const int rows = 6;
const int col = 6;



Adafruit_NeoPixel row1(NUMBPIXELS, ROW1_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel row2(NUMBPIXELS, ROW2_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel row3(NUMBPIXELS, ROW3_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel row4(NUMBPIXELS, ROW4_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel row5(NUMBPIXELS, ROW5_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel row6(NUMBPIXELS, ROW6_PIN, NEO_GRB + NEO_KHZ800);

int ledStatus[rows][col] = {{0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0}
};

Button button1(9);

void setup() { 
  button1.initalize();

  
  
  row1.begin();
  row2.begin();
  row3.begin();
  row4.begin();
  row5.begin();
  row6.begin();

  Serial.begin(9600);

}

void loop() {

  Serial.println(button1.getButtonState());
  
  

  // createShape(1, 2, 2, 2);


  
  
  //createShape(0, 0, 1, 3);
  for(int i = 0; i < 4; i++){
    createShape(5, i, 1, 3);
    createShape(0, i, 1, 3);
    sendPixels();
    delay(500);
    clear();
  }
  delay(500);               
}                           
                            
void clear(){               
  for(int r = 0; r < rows; r++){
    for(int c = 0; c < col; c++){
      ledStatus[r][c] = 0;  
    }                       
  }                             
  sendPixels();                 
}

void setPixelGrid(int x, int y, bool toggle){
  if(toggle){
    ledStatus[y][x] = 1;
  }else{
    ledStatus[y][x] = 0;
  }
}



void createShape(int x, int y, int sizeX, int sizeY){
  for(int r = 0; r < sizeY; r++){
    for(int c = 0; c < sizeX; c++){
        setPixelGrid(x + c, y + r, true);
    }
  }
}

bool checkPixelOn(int x, int y){
  if(ledStatus[y][x] == 0){
    return false;
  }else{
    return true;
  }
}

void fill(){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < col; j++){
      ledStatus[i][j] = 1;
    }
  }
}

void sendPixels(){
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
      //Serial.print(ledStatus[r][c]);
    }
    //Serial.println("");
  }

  //Serial.println("---");
  row1.show();
  row2.show();
  row3.show();
  row4.show();
  row5.show();
  row6.show();
}



