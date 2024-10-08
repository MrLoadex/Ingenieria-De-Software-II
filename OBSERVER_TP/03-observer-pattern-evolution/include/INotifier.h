/**
    File        : INotifier.h

    Project     : observer-pattern-evolution-refact-02

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/

#ifndef INOTIFIER_H
#define INOTIFIER_H

class INotifier
{
    public:
        virtual ~INotifier(void) {}
        virtual void notify( void ) = 0;
};

#endif // INOTIFIER_H
