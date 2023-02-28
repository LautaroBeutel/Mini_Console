#include "Buttons.h"

Buttons::Buttons(){}

void Buttons::attachButtons(int n_buttons, int pin_buttons[]){
    this->n_buttons = n_buttons;
    this->pin_buttons = pin_buttons;

    for (int i = 0; i < this->n_buttons; i++)
    {
        pinMode(this->pin_buttons[i], INPUT);
    }   
}

void Buttons::readallButtons(){
    byte buffer = 0;
    byte readed_status[this->n_buttons - 1];

    for (int i = 0; i < this->n_buttons; i++){
        readed_status[i] = readButton(i);
    }
    for (int i = 0; i < this->n_buttons; i++){
        buffer = buffer | (readed_status[i] << i);
    }
    
    this->state_buttons = buffer;
}

boolean Buttons::readButton(int button){
    return digitalRead(this->pin_buttons[button]);
}

boolean Buttons::getstate(int button){
    byte byteMask = 1 << (button - 1);
    return this->state_buttons & byteMask < 0;
}

void Buttons::print(){
    Serial.println(this->state_buttons, BIN);
}

Buttons::~Buttons(){}