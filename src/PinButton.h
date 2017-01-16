/**
 * Simple, reliable button with multiple types of click detection.
 *
 * Supports debounced click, singleClick, doubleClick, longPress and
 * release events.
 *
 * This class provides a simple wrapper around the more generic MultiButton,
 * to simply use an Arduino digital pin as a button.
 *
 * Copyright (C) Martin Poelstra
 * MIT License
 */

#pragma once

#include <Arduino.h>
#include <MultiButton.h>

/**
 * Simple wrapper for MultiButton class using an Arduino pin.
 * Assumes a switch is connected between the pin and ground.
 * Make sure to regularly call update() (e.g. from loop()).
 *
 * See MultiButton for all `isXXXClick()` methods etc.
 *
 * Usage example:
 * ```cpp
 * #include <PinButton.h>
 *
 * PinButton myButton(5); // connect a switch between pin 5 and ground
 *
 * void setup() {
 *   Serial.begin(9600);
 * }
 *
 * void loop() {
 *   myButton.update();
 *   if (myButton.isClick()) {
 *     Serial.println("click");
 *   }
 * }
 * ```
 */
class PinButton : public MultiButton {
  public:
    /**
     * Construct a new PinButton using a switch connected between
     * an Arduino pin and ground.
     * The internal pull-up is automatically enabled.
     * 
     * @param pin {int} Arduino pin to use
     */
    PinButton(int pin) : MultiButton(), _pin(pin) {
      pinMode(pin, INPUT_PULLUP);
    }

    /**
     * Read current hardware button state and decode into
     * stable state using isClick() etc.
     *
     * It's recommended to call this method in e.g. loop().
     */
    void update() {
      MultiButton::update(digitalRead(_pin) == 0);
    }

  private:
    int _pin;
};
