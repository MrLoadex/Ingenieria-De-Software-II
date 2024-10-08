#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H

#include <sstream>
#define TO_STRING( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

#include <iostream>
#include <string>

#include "Widget.h"
#include "Observer.h"
#include "Subject.h"
#include "ClockTimer.h"

using namespace std;
/****************************************CONCRETE ANALOG CLOCK***********************************/
/**An AnalogClock class can be defined in the same way.**/
class AnalogClock : public Widget, public Observer
{
    public:
        AnalogClock(ClockTimer*);
        virtual ~AnalogClock();

        // overrides Observer operation
        virtual void Update(Subject*);

        // overrides Widget operation;
        // defines how to draw the digital clock
        virtual void Draw();

    private:
        ClockTimer* _subject;
};
#endif // ANALOGCLOCK_H
