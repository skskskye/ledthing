#ifndef BUTTON_H
#define BUTTON_H


class Button{ //button class
  public: //all our public var
    int pin;
    Button(int pin);  // Constructor declaration
    void initalize();  // Method to initialize the button pin
    bool getButtonState();  // Method to get button state
};

#endif  // BUTTON_H
