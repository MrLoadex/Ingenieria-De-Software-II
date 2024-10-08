#include "../include/Subject.h"

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
