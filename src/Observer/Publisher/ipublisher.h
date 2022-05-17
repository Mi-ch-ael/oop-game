#ifndef IPUBLISHER_H
#define IPUBLISHER_H

#include <vector>

#include <QDebug>

#include "src/Observer/Subscriber/isubscriber.h"

class Publisher
{
public:
    Publisher();
    virtual ~Publisher();
    void notify();
    void subscribe(ISubscriber* subscriber);
    void unsubscribe(ISubscriber* subscriber);
    virtual void print(QDebug out) const = 0;
    virtual void print(std::ostream& out) const = 0;
    virtual int getX() const;
    virtual int getY() const;
protected:
    bool isDeleted;
    std::vector<ISubscriber*> curSubscribers;
};

#endif // IPUBLISHER_H
