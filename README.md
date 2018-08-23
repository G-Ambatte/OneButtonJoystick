# OneButtonJoystick
Code for a one button joystick using an Arduino Micro.

Uses the Joystick library by Matthew Heironimus, and cribs heavily from his examples.


## Instructions

1. Download and install Matthew Heironimus' Arduino Joystick library. This is as simple as running the appropriate deployment script in the download.

2. Clone/Download this repository.

2.a. (Optional) Modify the settings in Joystick_Settings.h to suit your particular system.

3. Upload the Sketch to your Arduino Micro.

4. Connect a switch between each of the button pins (as set in step 3; pin 2 by default) and ground.

4.a. Use a footswitch or pedal as the switch for hands-free operation. If these devices are unsuitable, any device capable of creating an open/closed circuit should be able to be used.