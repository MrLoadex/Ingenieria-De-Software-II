#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <list>

#include "Observer.h"

using namespace std;
class Observer;
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
/*****************************************************************************************/

#endif // SUBJECT_H
