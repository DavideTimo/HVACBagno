/* HEADER FILE (.h)       Author: Davide Timò, 20200101 
Implementazione classe led.



*/

#include "Arduino.h"

class Led
{
    private:
    byte pin;

    public:
    Led(byte pin);
    void init();
    void on();
    void off();
};