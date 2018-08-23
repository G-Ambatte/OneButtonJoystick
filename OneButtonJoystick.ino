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
#include "Joystick_Settings.h"

// Last state of the button(s)
int lastButtonState[buttonMapLength] = {};

Joystick_ Joystick;

void setup() {
  // Initialize Button Pins
  for (int index = 0; index < buttonMapLength; index++) {
    pinMode(pinToButtonMap[index], INPUT_PULLUP);
    lastButtonState[index] = 0;
  }

  // Set Joystick Range Values
  Joystick.setXAxisRange(-127, 127);
  Joystick.setYAxisRange(-127, 127);
  Joystick.setZAxisRange(-127, 127);
  Joystick.setRxAxisRange(0, 360);
  Joystick.setRyAxisRange(360, 0);
  Joystick.setRzAxisRange(0, 720);
  Joystick.setThrottleRange(0, 255);
  Joystick.setRudderRange(255, 0);

  // Set Joystick values
  Joystick.setXAxis(0);
  Joystick.setYAxis(0);
  Joystick.setZAxis(0);
  Joystick.setRxAxis(180);
  Joystick.setRyAxis(180);
  Joystick.setRzAxis(360);
  Joystick.setThrottle(128);
  Joystick.setRudder(128);

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

