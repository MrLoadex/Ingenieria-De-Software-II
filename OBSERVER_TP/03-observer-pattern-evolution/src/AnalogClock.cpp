/**
    File        : AnalogClock.cpp

    Project     : observer-pattern-evolution-refact-01

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/

#include <iostream>
#include <string>
#include "../include/AnalogClock.h"

AnalogClock::AnalogClock(ITimer* timer, IAscriber* ascriber)
{
    m_timer = timer;
    m_ascriber = ascriber;
    m_ascriber->attach(this);
}

AnalogClock::~AnalogClock()
{
    m_ascriber->detach(this);
}

void AnalogClock::update()
{
    m_hours = m_timer->getHours();
    m_minutes = m_timer->getMinutes();
    m_seconds = m_timer->getSeconds();
    draw();
}

void AnalogClock::draw()
{
    std::string hours = std::to_string(m_hours);
    std::string minutes = std::to_string(m_minutes);
    std::string seconds = std::to_string(m_seconds);

    if(hours.size() == 1){hours = "0"+hours;}
    if(minutes.size() == 1){minutes = "0"+minutes;}
    if(seconds.size() == 1){seconds = "0"+seconds;}

    std::cout << "I am Analog: "<< hours <<":"<< minutes <<":"<< seconds << std::endl;
}
