#include <Adafruit_NeoPixel.h>
#include "Button.h"
#include "Paddle.h"
#include "Renderer.h"
#include "Ball.h"
#include "LedRow.h"


//the LED pins
#define ROW1_PIN 13
#define ROW2_PIN 12
#define ROW3_PIN 11
#define ROW4_PIN 10
#define ROW5_PIN 9
#define ROW6_PIN 8
#define ROW7_PIN 7
#define ROW8_PIN 6
#define SCORE_ROW_PIN 3

#define button1Pin1 A1
#define button1Pin2 A4

#define button2Pin1 A2 
#define button2Pin2 A3 

//rows and columns for the matrix
#define ROWS 8
#define COL 12

//default rgb
#define R 120
#define B 120
#define G 120

#define MAX_SCORE 5

//all the buttons that will be used
Button button1(button2Pin1);
Button button2(button2Pin2);

Button button3(button1Pin1);
Button button4(button1Pin2);

//all of our rows
LedRow row1(ROW1_PIN, COL, R, B, G);
LedRow row2(ROW2_PIN, COL, R, B, G);
LedRow row3(ROW3_PIN, COL, R, B, G);
LedRow row4(ROW4_PIN, COL, R, B, G);
LedRow row5(ROW5_PIN, COL, R, B, G);
LedRow row6(ROW6_PIN, COL, R, B, G);
LedRow row7(ROW7_PIN, COL, R, B, G);
LedRow row8(ROW8_PIN, COL, R, B, G);

//score row
LedRow scoreRow(SCORE_ROW_PIN, COL, 200, 0, 0);


//array of led row object
LedRow* allLedRows[ROWS] = {&row1, &row2, &row3, &row4, &row5, &row6, &row7, &row8};




Renderer render(ROWS, COL, allLedRows); //creating the renderer

//initalizing paddles, gets given the x position it will be at 
Paddle paddle1(0); 
Paddle paddle2(COL - 1); //col - 1, edge of screen

//initalizing the ball
Ball ball;

void setup() { 
  //starting serial communication
  Serial.begin(9600);

  //starting every button
  button1.initalize();
  button2.initalize();
  button3.initalize();
  button4.initalize();

  //main renderer initalization
  render.initialize();

  //score row initialize
  scoreRow.initialize();
  

}

void loop() {

  //move the paddles, based off button inputs, and display to renderer
  paddle1.movePaddle(button3.getButtonState(), button4.getButtonState(), render); 
  paddle2.movePaddle(button1.getButtonState(), button2.getButtonState(), render);
  ball.tick(render, paddle1, paddle2); //tick the ball, have movement
  
  //score logic, putting the score the player has on screen
  int player1Score = paddle1.score;
  int player2Score = paddle2.score;

  //Serial.println(player1Score);
  for(int player1 = 1; player1 <= player1Score; player1++){
    scoreRow.setLed(player1, 1);
  }

  for(int player2 = 1; player2 <= player2Score; player2++){
    scoreRow.setLed(paddle2.x - player2, 1);
  }

  

  render.sendPixels(); //sending all changes to pixels to the renderer
  scoreRow.showRow(); //showing the score bored

  //check if somebody won the game, if so reset the game
  if(player1Score >= MAX_SCORE || player2Score >= MAX_SCORE){
    paddle1.score = 0;
    paddle2.score = 0;

    scoreRow.setRow(0);
  }

  delay(500); //delay refresh rate
}