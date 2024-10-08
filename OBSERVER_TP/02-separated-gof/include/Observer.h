#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include "Subject.h"

using namespace std;
class Subject;
/**********************************OBSERVER INTERFACE************************************/
/**An abstract class defines the Observer interface:**/
class Observer
{
    public:
        virtual ~Observer(){};
        virtual void Update(Subject* theChangedSubject) = 0;
    protected:
        Observer(){};
};
/*****************************************************************************************/


#endif // OBSERVER_H
