#ifndef _BUTTONS_H_
#define _BUTTONS_H_

#include <Arduino.h>

class Buttons
{
    private:
        int n_buttons;
        int* pin_buttons;
        byte state_buttons;

    public:
        Buttons();
        
        void attachButtons(int n_buttons, int pin_buttons[]);
        void readButtons();
        void readallButtons();
        void print();
        
        boolean readButton(int button);
        boolean getstate(int button);
        ~Buttons();
};

#endif