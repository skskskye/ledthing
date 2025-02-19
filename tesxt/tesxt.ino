#include <Adafruit_NeoPixel.h>
#include "Button.h"
#include "Renderer.h"

#define ROW1_PIN 7
#define ROW2_PIN 2
#define ROW3_PIN 3
#define ROW4_PIN 4
#define ROW5_PIN 5
#define ROW6_PIN 6



Button button1(9);
Renderer render(ROW1_PIN, ROW2_PIN, ROW3_PIN, ROW4_PIN, ROW5_PIN, ROW6_PIN);

void setup() { 
  button1.initalize();
  render.initalize();

  Serial.begin(9600);

}

void loop() {
  render.createShape(0, 4, 4, 1);
  render.sendPixels();
  delay(500);

}                           
                            




