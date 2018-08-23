#ifndef JOYSTICK_SETTINGS_h
#define JOYSTICK_SETTINGS_h

// Constants that map the phyical pins to the joystick buttons.
// buttonMapLength is the number of buttons to be used, and must be the number of pins in the pinToButtonMap array.
const int buttonMapLength = 1;
// pinToButtonMap is an array of the pin numbers to be connected as joystick buttons.
const int pinToButtonMap[buttonMapLength] = {2};

// Constant that sets the delay at the end of the loop.
const int delayValue = 50;

#endif
