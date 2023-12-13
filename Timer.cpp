#include "Timer.h"

Timer::Timer(unsigned long DeltaT, bool AutoRestart) //costruttore
{ 
    _DeltaT = DeltaT;
    _AutoRestart = AutoRestart;
    ResetT();
    StartT();
    
}

bool Timer::Update(){
    _TimeNow = millis();
    if (_Enable)
    {
        if (_TimeNow - _PreviousMillis > _DeltaT)
        {
            if(_AutoRestart) {_PreviousMillis = _TimeNow;}
            return true;
        }
        else
        {
            return false;
        }   
    }
    else
    {
        return false;
    }
}

void Timer::ResetT() //se AutoRestart non è True, bisogna fare reset "manuale" del timer
{
    _TimeNow = millis();
    _PreviousMillis = _TimeNow;
}

void Timer::ChangedeltaT(unsigned long newDeltaT)
{
    _DeltaT = newDeltaT;
    ResetT();
}

bool Timer::IsExpired()
{
    return Update();
}

void Timer::StartT()
{
    _Enable=true;
}

void Timer::StopT()
{
    _Enable=false;
}