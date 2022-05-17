#ifndef IITERATOR_H
#define IITERATOR_H

#include "src/Cell/cell.h"

class IIterator
{
public:
    virtual ~IIterator();
    IIterator();
    virtual const Cell* getNext() = 0;
    virtual Cell* getCurrent() = 0;
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual int getHeight() = 0;
    virtual int getWidth() = 0;
};

#endif // IITERATOR_H
