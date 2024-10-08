/**
    File        : ChangeManager.cpp

    Project     : observer-pattern-evolution-refact-02

    Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>

    Licensed under The MIT License
    For full copyright and license information, please see the LICENSE.txt
    Redistributions of files must retain the above copyright notice.

    @copyright     Copyright (c) Gabriel Nicolás González Ferreira
    @license       http://www.opensource.org/licenses/mit-license.php
**/

#include "../include/ChangeManager.h"

ChangeManager* ChangeManager::m_instance = 0;

ChangeManager::ChangeManager()
{
    //ctor
}

ChangeManager::~ChangeManager()
{
    //dtor
}

ChangeManager* ChangeManager::getInstance()
{
    if(m_instance == 0)
    {
        m_instance = new ChangeManager();
    }
    return m_instance;
}

void ChangeManager::attach(IObserver* observer)
{
    m_observersList.push_front(observer);
}

void ChangeManager::detach(IObserver* observer)
{
    m_observersList.remove(observer);
}

void ChangeManager::notify( void )
{
    std::list<IObserver*>::iterator it;

    for (it =  m_observersList.begin() ; it !=  m_observersList.end(); ++it)
    {
       (*it)->update();
    }
}
