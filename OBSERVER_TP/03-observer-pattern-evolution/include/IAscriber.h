/**
    File        : IAscriber.h

    Project     : observer-pattern-evolution-refact-02

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/

#ifndef IASCRIBER_H
#define IASCRIBER_H

#include "IObserver.h"

class IAscriber
{
    public:
            virtual  ~IAscriber(){};
            virtual void attach( IObserver* observer) = 0;
            virtual void detach( IObserver* observer) = 0;
};

#endif // IASCRIBER_H
