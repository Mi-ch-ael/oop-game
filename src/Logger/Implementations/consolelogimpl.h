#ifndef CONSOLELOGIMPL_H
#define CONSOLELOGIMPL_H

#include <iostream>

#include "src/Logger/iloggerimplementation.h"

class ConsoleLogImpl: public ILoggerImplementation
{
public:
    ConsoleLogImpl();
    ~ConsoleLogImpl();
    void print(const Publisher&);
};

#endif // CONSOLELOGIMPL_H
