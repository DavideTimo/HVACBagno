/*   HEADER FILE              Author: Davide Timò, 20200101 
Timer.h   
Clase che crea dei timer. Il timer può essere controllato tramite la funzione CheckT() che restituisce True se
è trascorso il tempo DeltaT dal momento della creazione del Timer.
Il timer può essere disabilitato mettendo a 0 il suo attributo "Enable", in questo modo restituirà sempre False e
non farà nessun check sul tempo trascorso fino a che non torna l'abilitazione.
Il timer può essere resettato tramite la funzione ResetT(), che riazzera il conteggio 
(lo fa riportando _PreviousMillis = _TimeNow).
Si può inoltre cambiare il DeltaT del timer anche dopo averlo creato, tramite il suo metodo ChangedeltaT(), che provoca anche 
un reset del timer.
Se Autorestart è impostato a 1 al momento della creazione del Timer, il Timer dopo aver raggiunto il deltaT si autoresetta e riparte il ciclo successivo.



*/

#ifndef Timer_h
#define Timer_h
#include "Arduino.h"

class Timer
{
    public:
        Timer(unsigned long DeltaT, bool Autorestart); //Constructor       
        void ResetT(); //Resetta il timer  
        void ChangedeltaT(unsigned long newDeltaT); //cambia il DeltaT del Timer
        bool IsExpired();
        void StartT();
        void StopT();

    private:
        bool Update(); //Controlla se tempo deltaT è trascorso 
        unsigned long _DeltaT; //delta tempo dopo il quale il timer restituirà TRUE.
        
        bool _Enable; //abilita/disabilita il timer
        bool _AutoRestart;
        unsigned long _TimeNow;
        unsigned long _PreviousMillis;
        

};



#endif