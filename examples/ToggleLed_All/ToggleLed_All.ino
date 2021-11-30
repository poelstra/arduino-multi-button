/**
   Аn example that shows how to use all the functions in this library..

   To use this example, connect a switch between pin 7 and VDD.
   (Don't forget to add pull-down resistor)
*/

#include <PinButton.h>

#define BUTTON_PIN            (7)

#define CLICK_LED_PIN         (8)
#define SINGLE_CLICK_LED_PIN  (9)
#define DOUBLE_CLICK_LED_PIN  (10)
#define LONG_CLICK_LED_PIN    (11)

// Create a new button object, listening on pin 7.
// You can have as many buttons as you like.
PinButton myButton(BUTTON_PIN, INPUT);

void setup() {
  pinMode(CLICK_LED_PIN, OUTPUT);
  pinMode(SINGLE_CLICK_LED_PIN, OUTPUT);
  pinMode(DOUBLE_CLICK_LED_PIN, OUTPUT);
  pinMode(LONG_CLICK_LED_PIN, OUTPUT);
}

void loop() {
  // Read hardware pin, convert to click events
  myButton.update();

  if (myButton.isClick()) {
    digitalWrite(CLICK_LED_PIN, !digitalRead(CLICK_LED_PIN));
  }
  if (myButton.isSingleClick()) {
    digitalWrite(SINGLE_CLICK_LED_PIN, !digitalRead(SINGLE_CLICK_LED_PIN));
  }
  if (myButton.isDoubleClick()) {
    digitalWrite(DOUBLE_CLICK_LED_PIN, !digitalRead(DOUBLE_CLICK_LED_PIN));
  }
  if (myButton.isLongClick()) {
    digitalWrite(LONG_CLICK_LED_PIN, !digitalRead(LONG_CLICK_LED_PIN));
  }

}
