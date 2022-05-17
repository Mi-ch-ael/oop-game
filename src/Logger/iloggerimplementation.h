#ifndef ILOGGERIMPLEMENTATION_H
#define ILOGGERIMPLEMENTATION_H

#include "src/Observer/Publisher/ipublisher.h"

class ILoggerImplementation
{
public:
    virtual ~ILoggerImplementation();
    virtual void print(const Publisher&) = 0;
};

#endif // ILOGGERIMPLEMENTATION_H
