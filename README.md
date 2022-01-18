# Introduction

Simple, reliable button with multiple types of click detection.

Supports debounced click, singleClick, doubleClick, longPress and release
events.

Provides a generic MultiButton class that can handle any type of input, and
the PinButton wrapper to simply use an Arduino digital pin as a button.

Please Star the project on GitHub if you like it!

# Installing the library

In the Arduino IDE, click `Sketch` > `Include Library` > `Manage Libraries...`.
Then, search for `MultiButton` and click `Install`.

# Using in your own code

In the Arduino IDE, click `Sketch` > `Include Library` > `MultiButton`.

# Using the examples

In the Arduino IDE, click `File` > `Examples` > `MultiButton` and choose an example.
Connect a switch (or use a piece of wire) between pin 5 and ground (GND).

# Example: toggle a led

```cpp
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
```

# Example: detect single and double click

```cpp
#include <PinButton.h>

// Create a new button object, listening on pin 5.
PinButton myButton(5);

void setup() {
  // Initialize serial port at 115k2 baud.
  // Use Serial Port Monitor in IDE to see the output.
  Serial.begin(115200);
}

void loop() {
  // Read hardware pin, convert to click events
  myButton.update();

  if (myButton.isSingleClick()) {
    // Only triggers on a single, short click (i.e. not
    // on the first click of a double-click, nor on a long click).
    Serial.println("single");
  }

  if (myButton.isDoubleClick()) {
    Serial.println("double");
  }
}
```

See the included `ClickEvents` example for more types.

# Documentation

All classes and public methods are documented in the source code of the library:
* [MultiButton.h](https://github.com/poelstra/arduino-multi-button/blob/master/src/MultiButton.h)
* [PinButton.h](https://github.com/poelstra/arduino-multi-button/blob/master/src/PinButton.h)

# Changelog

1.2.0 (2022-01-18):
- Support STM32duino boards (thanks to @mixaz).

1.1.0 (2021-11-30):
- Support switch to Vcc with pull-down resistor (thanks to @BerranRemzi).

1.0.0 (2017-01-16):
- Initial version.

# License

The MIT license.
