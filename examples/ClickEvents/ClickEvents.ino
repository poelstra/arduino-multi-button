/**
 * Simple example showing all possible click types.
 *
 * To use this example, connect a switch between pin 5 and GND.
 * (Or simply use a piece of wire.)
 */

#include <PinButton.h>

// Create a new button object, listening on pin 5.
// Note: you can create as many as you like.
PinButton myButton(5);

void setup() {
  // Initialize serial port at 115k2 baud.
  // Use Serial Port Monitor in IDE to see the output.
  Serial.begin(115200);
}

void loop() {
  // Read hardware pin, convert to click events
  myButton.update();

  // Print a message for each type of click.
  // Note that "click" is also generated for the
  // first click of a double-click, but "single"
  // is only generated if it definitely is not
  // going to be a double click.
  if (myButton.isClick()) {
    Serial.println("click");
  }
  if (myButton.isSingleClick()) {
    Serial.println("single");
  }
  if (myButton.isDoubleClick()) {
    Serial.println("double");
  }
  if (myButton.isLongClick()) {
    Serial.println("long");
  }
  if (myButton.isReleased()) {
    Serial.println("up");
  }
}
