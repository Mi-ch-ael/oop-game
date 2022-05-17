#ifndef DEBUGLOGIMPL_H
#define DEBUGLOGIMPL_H

#include <QDebug>
#include <QFile>
#include <cstdio>

#include "src/Logger/iloggerimplementation.h"

class DebugLogImpl : public ILoggerImplementation
{
public:
    DebugLogImpl();
    ~DebugLogImpl();
    void print(const Publisher&);
private:
    QDebug* outstream;
    QFile* file;
};

#endif // DEBUGLOGIMPL_H
