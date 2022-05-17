#ifndef ITERATORBLOCK_H
#define ITERATORBLOCK_H

#include "src/Iterator/iiterator.h"
#include "src/defines.h"

class IteratorBlock: IIterator
{
public:
    IteratorBlock(Cell **arena, int y, int x, int height, int width);
    ~IteratorBlock();
    const Cell *getNext();
    Cell *getCurrent();
    int getY();
    int getX();
    int getHeight();
    int getWidth();

private:
    Cell** collection;
    int y;
    int x;
    int height;
    int width;
};

#endif // ITERATORBLOCK_H
