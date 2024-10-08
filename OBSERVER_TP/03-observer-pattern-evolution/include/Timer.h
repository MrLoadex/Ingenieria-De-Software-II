/**
    File        : Timer.h

    Project     : observer-pattern-evolution-refact-05

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/

#ifndef TIMER_H
#define TIMER_H

#ifdef __unix__
    #include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
#endif // defined

#include <ctime>

#include <iostream>
#include "ITimer.h"
#include "INotifier.h"

class Timer : public ITimer
{
    public:
        // Timer(INotifier* notifier);
        Timer();
        virtual ~Timer();

        void setNotifier(INotifier* notifier);

        int getHours();
        int getMinutes();
        int getSeconds();

        void start();
        void stop();

    private:
        bool m_startState;
        void m_delay(int milliseconds);
        int m_hours;
        int m_minutes;
        int m_seconds;
        void m_tick();


        INotifier* m_notifier;

};

#endif // TIMER_H
