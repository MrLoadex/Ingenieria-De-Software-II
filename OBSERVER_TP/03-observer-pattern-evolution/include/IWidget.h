/**
    File        : IWidget.h

    Project     : observer-pattern-evolution-refact-01

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/

#ifndef IWIDGET_H
#define IWIDGET_H

class IWidget
{
    public:
        virtual ~IWidget() {}
        virtual void draw() = 0;
};

#endif // IWIDGET_H
