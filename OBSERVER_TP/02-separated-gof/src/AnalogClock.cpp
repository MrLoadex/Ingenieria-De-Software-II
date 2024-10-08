#include "../include/AnalogClock.h"

AnalogClock::AnalogClock (ClockTimer* s)
{
    _subject = s;
    _subject->Attach(this);
}

AnalogClock::~AnalogClock ()
{
    _subject->Detach(this);
}

void AnalogClock::Update (Subject* theChangedSubject)
{
    if (theChangedSubject == _subject)
    {
        Draw();
    }
}

void AnalogClock::Draw ()
{
    // get the new values from the subject
    string hours = TO_STRING(_subject->GetHour());
    string minutes = TO_STRING(_subject->GetMinute());
    string seconds = TO_STRING(_subject->GetSecond());

    if(hours.size() == 1){hours = "0"+hours;}
    if(minutes.size() == 1){minutes = "0"+minutes;}
    if(seconds.size() == 1){seconds = "0"+seconds;}

    // draw the digital clock
    cout <<"I am Analog: "<< hours<<":"<<minutes<<":"<<seconds<<endl;
}
