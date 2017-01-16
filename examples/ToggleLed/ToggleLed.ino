/**
 * Simple example showing how to toggle a led on click.
 *
 * To use this example, connect a switch between pin 5 and GND.
 * (Or simply use a piece of wire.)
 */

#include <PinButton.h>

// Create a new button object, listening on pin 5.
// You can have as many buttons as you like.
PinButton myButton(5);

bool ledOn = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Read hardware pin, convert to click events
  myButton.update();

  // Toggle the built-in led of the Arduino on each click.
  // You can also try e.g. isDoubleClick, isLongClick and
  // isSingleClick.
  if (myButton.isClick()) {
    ledOn = !ledOn;
    digitalWrite(LED_BUILTIN, ledOn);
  }
}
