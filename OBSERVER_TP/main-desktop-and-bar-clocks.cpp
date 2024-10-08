/**
    Project     : Observer Example

    Authors     : Erich Gamma, Richard Helm, Ralph Johnson and John Vlissides

    Implementer : Gabriel Nicolás González Ferreira
**/
#include <sstream>
#define TO_STRING( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

#include <iostream>
#include <list>
#include <string>

using namespace std;

/**********************************OBSERVER INTERFACE************************************/
/**An abstract class defines the Observer interface:**/
class Subject;
class Observer
{
    public:
        virtual ~Observer(){};
        virtual void Update(Subject* theChangedSubject) = 0;
    protected:
        Observer(){};
};
/*****************************************************************************************/

/*********************************SUBJECT ABSTRACT CLASS**********************************/
/**Similarly, an abstract class defines the Subject interface:**/
class Subject
{
    public:
        virtual ~Subject(){}
        virtual void Attach(Observer*);
        virtual void Detach(Observer*);
        virtual void Notify();
    protected:
        Subject(){};
    private:
        list<Observer*> _observers;
};

void Subject::Attach (Observer* o)
{
    _observers.push_front(o);
}

void Subject::Detach (Observer* o)
{
    _observers.remove(o);
}

void Subject::Notify ()
{
    list<Observer*>::iterator it;

    for (it =  _observers.begin() ; it !=  _observers.end(); ++it)
    {
       (*it)->Update(this);
    }
}
/*****************************************************************************************/

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
        int GetHour();
        int GetMinute();
        int GetSecond();
        void Tick();
    private:
        int m_hours;
        int m_minutes;
        int m_seconds;
};

ClockTimer::ClockTimer()
{
        m_hours = 0;
        m_minutes = 0;
        m_seconds = 0;
}

int ClockTimer::GetHour( void )
{
    return this->m_hours;
}

int ClockTimer::GetMinute( void )
{
    return this->m_minutes;
}

int ClockTimer::GetSecond( void )
{
    return this->m_seconds;
}

void ClockTimer::Tick ()
{
    // No update internal time-keeping state, only a demo.
    // ...
    m_seconds++;
    if(m_seconds == 60)
    {
        m_seconds = 0;
        m_minutes++;
        if(m_minutes == 60)
        {
            m_seconds = 0;
            m_minutes = 0;
            m_hours++;
            if(m_hours == 24)
            {
                m_seconds = 0;
                m_minutes = 0;
                m_hours = 0;
            }
        }
    }
    Notify();
}
/*************************************************************************************************/

/****************************************WIDGET INTERFACE********************************/
class Widget
{
    public:
        virtual ~Widget() {}
        virtual void Draw() = 0;
};


/****************************************CONCRETE DIGITAL CLOCK********************************/
/**Now we can define a class DesktopClock that displays the time. It inherits its graphical functionality from a
Widget class provided by a user interface toolkit. The Observer interface is mixed into the DesktopClock
interface by inheriting from Observer.**/
class DesktopClock: public Widget, public Observer
{
    public:
        DesktopClock(ClockTimer* s);
        virtual ~DesktopClock();
        virtual void Update(Subject*);
        // overrides Observer operation
        virtual void Draw();
        // overrides Widget operation;
        // defines how to draw the digital clock

    private:
        ClockTimer* _subject;
};

DesktopClock::DesktopClock(ClockTimer* s)
{
    _subject = s;
    _subject->Attach(this);
}

DesktopClock::~DesktopClock ()
{
    _subject->Detach(this);
}

void DesktopClock::Update (Subject* theChangedSubject)
{
    if (theChangedSubject == _subject)
    {
        Draw();
    }
}

void DesktopClock::Draw ()
{
    // get the new values from the subject
    string hours = to_string(_subject->GetHour());
    string minutes = to_string(_subject->GetMinute());
    string seconds = to_string(_subject->GetSecond());

    // draw the digital clock
    if(hours.size() == 1){hours = "0"+hours;}
    if(minutes.size() == 1){minutes = "0"+minutes;}
    if(seconds.size() == 1){seconds = "0"+seconds;}

    cout <<"I am Desktop Clock: "<< hours<<":"<<minutes<<":"<<seconds<<endl;
}
/*************************************************************************************************/


/****************************************CONCRETE ANALOG CLOCK***********************************/
/**An BarClock class can be defined in the same way.**/
class BarClock: public Widget, public Observer
{
    public:
        BarClock(ClockTimer*);
        virtual ~BarClock();

        // overrides Observer operation
        virtual void Update(Subject*);

        // overrides Widget operation;
        // defines how to draw the digital clock
        virtual void Draw();

    private:
        ClockTimer* _subject;
};

BarClock::BarClock (ClockTimer* s)
{
    _subject = s;
    _subject->Attach(this);
}

BarClock::~BarClock ()
{
    _subject->Detach(this);
}

void BarClock::Update (Subject* theChangedSubject)
{
    if (theChangedSubject == _subject)
    {
        Draw();
    }
}

void BarClock::Draw ()
{
    // get the new values from the subject
    string hours = to_string(_subject->GetHour());
    string minutes = to_string(_subject->GetMinute());
    string seconds = to_string(_subject->GetSecond());

    if(hours.size() == 1){hours = "0"+hours;}
    if(minutes.size() == 1){minutes = "0"+minutes;}
    if(seconds.size() == 1){seconds = "0"+seconds;}

    // draw the digital clock
    cout <<"I am Bar Clock: "<< hours<<":"<<minutes<<":"<<seconds<<endl;
}


/*************************************************************************************************/
/**MAIN**/
int main()
{
    ClockTimer* timer = new ClockTimer;
    new BarClock(timer);
    new DesktopClock(timer);

    timer->Tick();
    timer->Tick();
    timer->Tick();
    timer->Tick();
    timer->Tick();
    timer->Tick();

    return 0;
}

/********************************************************************************************/
