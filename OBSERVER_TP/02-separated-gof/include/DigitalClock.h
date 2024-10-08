#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

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

/****************************************CONCRETE DIGITAL CLOCK********************************/
/**Now we can define a class DigitalClock that displays the time. It inherits its graphical functionality from a
Widget class provided by a user interface toolkit. The Observer interface is mixed into the DigitalClock
interface by inheriting from Observer.**/
class DigitalClock: public Widget, public Observer
{
    public:
        DigitalClock(ClockTimer* s);
        virtual ~DigitalClock();
        virtual void Update(Subject*);
        // overrides Observer operation
        virtual void Draw();
        // overrides Widget operation;
        // defines how to draw the digital clock

    private:
        ClockTimer* _subject;
};

#endif // DIGITALCLOCK_H
