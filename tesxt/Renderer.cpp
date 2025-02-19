#include "Renderer.h"
#include <Adafruit_NeoPixel.h>
#include "Arduino.h"



void Renderer::Renderer(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6)
  : row1(numbPixels, pin1, NEO_GRB + NEO_KHZ800), row2(numbPixels, pin2, NEO_GRB + NEO_KHZ800), 
  row3(numbPixels, pin3, NEO_GRB + NEO_KHZ800), row4(numbPixels, pin4, NEO_GRB + NEO_KHZ800), 
  row5(numbPixels, pin5, NEO_GRB + NEO_KHZ800), row6(numbPixels, pin6, NEO_GRB + NEO_KHZ800) {
    

  }

}


