/**
    Project     : Observer Example

    Author      : Erich Gamma, Richard Helm, Ralph Johnson and John Vlissides
**/

#include <iostream>

#include "include/ClockTimer.h"
#include "include/AnalogClock.h"
#include "include/DigitalClock.h"

using namespace std;

/*************************************************************************************************/
/**MAIN**/
int main()
{
    ClockTimer* timer = new ClockTimer;

    new AnalogClock(timer);
    new DigitalClock(timer);

    timer->Tick();
    timer->Tick();
    timer->Tick();

    return 0;
}

/********************************************************************************************/
