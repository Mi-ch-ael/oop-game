#ifndef ISUBSCRIBER_H
#define ISUBSCRIBER_H

#include <iostream>

class Publisher;

class ISubscriber
{
public:
    virtual ~ISubscriber();
    virtual void receive(const Publisher& object) = 0;
};

#endif // ISUBSCRIBER_H
