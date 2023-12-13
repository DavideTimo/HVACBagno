#include <stdio.h>
#include "Timer.h"
#include "Led.h"
#include "Button.h"

// pin definition
const byte Puls1Pin = 4;
const byte Puls2Pin = 5;
const byte elevalvo1Pin = 7;
const byte elevalvo2Pin = 8;
const byte fan1Pin = 9;
const byte fan2Pin = 10;
const byte Led1Pin = 3;

//dichiaro oggetti pulsanti
Button Puls1(Puls1Pin);
Button Puls2(Puls2Pin);

Led Led1(Led1Pin);

//dichiaro oggetti Timer
Timer Timer1(900000,true); //timer 15min tempo che la valvola1 sta chiusa
Timer Timer2(900000,true);  //time  15min tempo che la valvola2 sta chiusa
Timer Timer3(30000,true);  //time 30s tempo che la valvola1 sta aperta
Timer Timer4(30000,true);  //time 30s tempo che la valvola2 sta aperta
Timer Timer5(8000,true);   //timer 8s ritardo accensione ventola per permettere apertura valvola
Timer Timer6(8000,true);   //timer 8s ritardo accensione ventola per permettere apertura valvola

//dichiaro variabile stato macchina
byte machineState1 = 0;        // variabile di stato della prima macchina valvola+ventilatore
byte machineState2 = 0;        // variabile di stato della prima macchina valvola+ventilatore
byte previousMachineState1 = 0;
byte previousMachineState2 = 0;

void setup(){
    //inizializzo i digital pin di input (pulsanti)
    pinMode(Puls1Pin,INPUT_PULLUP);
    pinMode(Puls2Pin,INPUT_PULLUP);

    pinMode(elevalvo1Pin,OUTPUT);
    pinMode(elevalvo2Pin,OUTPUT);
    pinMode(fan1Pin,OUTPUT);
    pinMode(fan2Pin,OUTPUT);
}

void loop(){
    previousMachineState1 = machineState1;
    previousMachineState2 = machineState2;
    switch (machineState1)
    {
    case 0:
        stato0();
        break;
    
    default:
        stato1();
        break;
    }

    switch (machineState2)
    {
    case 0:
        stato2();
        break;
    
    default:
        stato3();
        break;
    }
   uscite1();
   uscite2();
}

void stato0()
{
    if (Timer1.IsExpired() || Puls1.isPressed())
    {
        machineState1 = 1;
        Timer2.ResetT();

    }    
}

void stato1()
{
    if (Timer2.IsExpired())
    {
        machineState1 = 0;
        Timer1.ResetT();
        Timer5.ResetT();
    } 
}

void stato2()
{
    if (Timer3.IsExpired() || Puls2.isPressed())
    {
        machineState2 = 1;
        Timer4.ResetT();
    }    
}

void stato3()
{
    if (Timer4.IsExpired())
    {
        machineState2 = 0;
        Timer3.ResetT();
        Timer6.IsExpired();
    } 
    
}

void uscite1()
{
    switch (machineState1)
    {
    case 0:
        digitalWrite(elevalvo1Pin,LOW);
        digitalWrite(fan1Pin,LOW);
        break;
    
    case 1:
        digitalWrite(elevalvo1Pin,HIGH);
        if (Timer5.IsExpired())
        {
            digitalWrite(fan1Pin,HIGH);
        }
        
        break;
    }
}

void uscite2()
{
    switch (machineState1)
    {
    case 0:
        digitalWrite(elevalvo2Pin,LOW);
        digitalWrite(fan2Pin,LOW);
        break;
    
    case 1:
        digitalWrite(elevalvo2Pin,HIGH);
        if (Timer6.IsExpired())
        {
            digitalWrite(fan2Pin,HIGH);
        }      
        break;
    }
}