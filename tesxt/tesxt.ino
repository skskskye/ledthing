#include <Adafruit_NeoPixel.h>
#include "Button.h"
#include "Renderer.h"

#define ROW1_PIN 7
#define ROW2_PIN 2
#define ROW3_PIN 3
#define ROW4_PIN 4
#define ROW5_PIN 5
#define ROW6_PIN 6



Button button1(8);
Button button2(9);
Button button3(10);
Button button4(11);

Renderer render(ROW1_PIN, ROW2_PIN, ROW3_PIN, ROW4_PIN, ROW5_PIN, ROW6_PIN);

void setup() { 
  button1.initalize();
  button2.initalize();
  button3.initalize();
  button4.initalize();
  
  render.initalize();

  Serial.begin(9600);

}

int y = 0;

void loop() {
  
  render.createShape(0, y, 1, 3);




  render.sendPixels(); //end of all logic, we are SENDING IT TO ITTT
  delay(250);

}                           
                            




