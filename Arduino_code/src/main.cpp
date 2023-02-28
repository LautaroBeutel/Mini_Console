#include <Arduino.h>
#include "Buttons.h"

#define BUTTON_1_PIN 2
#define BUTTON_2_PIN 3
#define BUTTON_3_PIN 4
#define BUTTON_4_PIN 5

const int cant_buttons = 4;
int pin_buttons[cant_buttons] = {BUTTON_1_PIN, BUTTON_2_PIN, BUTTON_3_PIN, BUTTON_4_PIN};

Buttons direccion;

void setup() {
  Serial.begin(115200);
  direccion.attachButtons(cant_buttons, pin_buttons);
}

void loop() {
  direccion.readallButtons();
  direccion.print();
  delay(10);
}
