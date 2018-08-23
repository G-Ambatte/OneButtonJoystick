// One Button Joystick
// G.Ambatte, August 2018
//
// Uses the Joystick library by Matthew Heironimus
// and cribs heavily from his examples
//
// Connect a switch between the selected pin and 
// ground.
// Default values:
//     buttonMapLength = 1
//     pinToButtonMap = 2
//     delayValue = 50
//
//--------------------------------------------------------------------

#include <Joystick.h>
#include "Joystick_Settings.h"

// Last state of the button(s)
int lastButtonState[buttonMapLength] = {};

// Create a joystick and DISABLE ALL THE THINGS - except the buttons we want
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK,
  buttonMapLength, 0,    // Button Count, Hat Switch Count
  false, false, false,   // No X, Y, or Z Axes
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

void setup() {
  // Initialize Buttons
  for (int index = 0; index < buttonMapLength; index++) {
    pinMode(pinToButtonMap[index], INPUT_PULLUP);
    lastButtonState[index] = 0;
  }

  // Initialize Joystick Library
  Joystick.begin();
}

void loop() {

  // Read pin values
  
  for (int index = 0; index < buttonMapLength; index++ ) {
    int currentButtonState = !digitalRead(pinToButtonMap[index]);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }

  delay(delayValue);
}

