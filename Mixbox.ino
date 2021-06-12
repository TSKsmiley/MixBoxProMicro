#include "Keyboard.h"

// Change this depending on how many buttons you have
#define BUTTONS_LENGTH 14

class Button{
  private:
    int pin;
    int key;
    int prevState;
  
  public:
    Button(int _pin, int _key) {
      pin = _pin;
      key = _key;
      pinMode(_pin, INPUT_PULLUP);
    }
    
    void CheckKey() {
      // 1 = up
      // 0 = down

      // If the key is up and we previously released
      if ((digitalRead(pin) == 0) && (prevState == 1)) {
        Keyboard.press(key);
        prevState = 0;
      } 
      // If the key is up and we previously pressed
      else if ((digitalRead(pin) == 1) && (prevState == 0)) {
        Keyboard.release(key);
        prevState = 1;
      } 
    }
};

// CREATE YOUR BUTTONS 
// AND CORRESPONDING 
// PINS HERE
Button buttons[] = {Button(A0, 'w'), Button(A1, 'a'), Button(A2, 's'), Button(A3, 'd'), Button(2, 'l'), Button(3, 'h'), Button(4, 'o'), Button(5, 'j'), Button(6, 'k'), Button(7, 'u'), Button(8, 'i'), Button(9, 'y'), Button(10, 0xB1), Button(15, 'z')};


// Loop counter
int i_buttons = 0;

void setup() {
  Keyboard.begin(); // Init keyboard
}

void loop() {
  if (i_buttons == BUTTONS_LENGTH+1) {
      i_buttons = 0;
  }
    
  buttons[i_buttons].CheckKey();
  i_buttons++;
}
