#include <Adafruit_NeoPixel.h>
#include "Button.h"
#include "Paddle.h"
#include "Renderer.h"
#include "Ball.h"

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

Paddle paddle1(0);
Paddle paddle2(5);
Ball ball;

void setup() { 
  button1.initalize();
  button2.initalize();
  button3.initalize();
  button4.initalize();

  
  render.initalize();

  Serial.begin(9600);

}

void loop() {
  paddle1.movePaddle(button3.getButtonState(), button4.getButtonState(), render);
  paddle2.movePaddle(button1.getButtonState(), button2.getButtonState(), render);
  ball.tick(render, paddle1, paddle2);
  render.sendPixels(); 
  delay(50);
}