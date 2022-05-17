#ifndef LOGGER_H
#define LOGGER_H

#include "src/Observer/Subscriber/isubscriber.h"
#include "src/Logger/iloggerimplementation.h"

class Logger: public ISubscriber
{
public:
    Logger(ILoggerImplementation&);
    ~Logger();
    void receive(const Publisher& object);
private:
    ILoggerImplementation& impl;
};

#endif // LOGGER_H
