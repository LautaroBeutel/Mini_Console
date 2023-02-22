#include <Arduino.h>

#define BUTTON_1_PIN 2
#define BUTTON_2_PIN 3
#define BUTTON_3_PIN 4
#define BUTTON_4_PIN 5

boolean BUTTON_1_STATE;
boolean BUTTON_2_STATE;
boolean BUTTON_3_STATE;
boolean BUTTON_4_STATE;

boolean debounce_reading(int pin);

void read_buttons();
void print();

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_1_PIN, INPUT);
  pinMode(BUTTON_2_PIN, INPUT);
  pinMode(BUTTON_3_PIN, INPUT);
  pinMode(BUTTON_4_PIN, INPUT);
}

void loop() {
  read_buttons();
  print();
}

boolean debounce_reading(int pin){
  int state;
  state = digitalRead(pin);
  return state;
}

void read_buttons(){
  BUTTON_1_STATE = debounce_reading(BUTTON_1_PIN);
  BUTTON_2_STATE = debounce_reading(BUTTON_2_PIN);
  BUTTON_3_STATE = debounce_reading(BUTTON_3_PIN);
  BUTTON_4_STATE = debounce_reading(BUTTON_4_PIN);
}

void print(){
  String buffer = String(BUTTON_1_STATE) + " " + String(BUTTON_2_STATE) + " " + String(BUTTON_3_STATE) + " " + String(BUTTON_4_STATE);
  Serial.println(buffer);
}