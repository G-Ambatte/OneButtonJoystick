// One Button Joystick
// G.Ambatte, August 2018
//
// Uses the Joystick library by Matthew Heironimus
// and cribs heavily from his examples
//
// Connect a switch between the selected pin and 
// ground.
// Default values:
//     pinToButtonMap = 9
//     delayValue = 50
//
//--------------------------------------------------------------------

#include <Joystick.h>
#include <Joystick_Settings.h>

// Last state of the button(s)
int lastButtonState[len(pinToButtonMap)] = {};

Joystick_ Joystick;

void setup() {
  // Initialize Button Pins
  for (int index = 0; index < len(pinToButtonMap); index++) {
    pinMode(pinToButtonMap(index) INPUT_PULLUP);
    lastButtonState[index] = 0;
  }

  // Initialize Joystick Library
  Joystick.begin();
}

void loop() {

  // Read pin values
  
  for (int index = 0; index < len(pinToButtonMap); index++ ) {
    int currentButtonState = !digitalRead(pinToButtonMap[index]);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(delayValue);
}

