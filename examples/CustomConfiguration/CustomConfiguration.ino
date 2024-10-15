/**
 * Example for external dynamic configuration
 * On long click will increase long click delay with 300 ms increments until it
 * is over 3s. After that the long click delay will reset to 300ms.
 *
 * To use this example, connect a switch between pin 2 and GND for external
 * dynamic configuration, and/or connect a switch between pin 5 and GND for
 * default configuration.
 */

#include <Arduino.h>
#include <PinButton.h>

#define DYNAMIC_BTN_PIN 2
#define DEFAULT_BTN_PIN 5

MultiButtonConfig buttonConfig = {50, 200, 600};
PinButton configurableButton = PinButton(DYNAMIC_BTN_PIN, &buttonConfig);
PinButton defaultButton = PinButton(DEFAULT_BTN_PIN);

void setup() {
    Serial.begin(57600);
    while (!Serial) {
    }
}

void loop() {
    configurableButton.update();

    if (configurableButton.isDoubleClick()) {
        Serial.println("Configurable button DoubleClick");
    }
    if (configurableButton.isLongClick()) {
        Serial.print("Configurable button LongClick, next delay is ");
        if (buttonConfig.longClickDelay >= 3000) {
            buttonConfig.longClickDelay = 300;
        } else {
            buttonConfig.longClickDelay = buttonConfig.longClickDelay + 300;
        }
        Serial.println(buttonConfig.longClickDelay);
    }
    if (configurableButton.isSingleClick()) {
        Serial.println("Configurable button SingleClick");
    }

    defaultButton.update();
    if (defaultButton.isDoubleClick()) {
        Serial.println("Default button DoubleClick");
    }
    if (defaultButton.isLongClick()) {
        Serial.println("Default button LongClick");
    }
    if (defaultButton.isSingleClick()) {
        Serial.println("Default button SingleClick");
    }
}
