/* HEADER FILE (.h)       Author: Davide Timò, 20200101 
Implementazione classe pulsante.

*/
#ifndef Button_h
#define Button_h
#include "Arduino.h"

class Button 
{
    public:
        Button(byte pin); //costruttore
        void init();
        void update();

        byte getState();
        bool isPressed();

    private:
        byte pin;
        byte state;
        byte lastReading;
        byte newReading;

        unsigned long lastDebounceTime = 0;
        unsigned long debounceDelay = 50;
    

};

#endif