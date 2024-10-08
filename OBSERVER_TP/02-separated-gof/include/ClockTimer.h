#ifndef CLOCKTIMER_H
#define CLOCKTIMER_H

#include "Subject.h"

/*********************************CONCRET CLOCK TIMER************************************/
/**
ClockTimer is a concrete subject for storing and maintaining the time of day. It notifies
its observers every second. ClockTimer provides the interface for retrieving individual time
units such as the hour, minute, and second.
**/
class ClockTimer : public Subject
{
    public:
        ClockTimer();
        ~ClockTimer(){}
        virtual int GetHour();
        virtual int GetMinute();
        virtual int GetSecond();
        void Tick();
    private:
        int m_hours;
        int m_minutes;
        int m_seconds;
};

#endif // CLOCKTIMER_H
