#include "iteratorblock.h"

IteratorBlock::IteratorBlock(Cell** arena, int y, int x, int height, int width):
    x(x), y(y), height(height), width(width)
{
    //current = &(arena[y][x]);
    collection = arena;
}

Cell* IteratorBlock::getCurrent(){
    return &(collection[y][x]);
}

const Cell *IteratorBlock::getNext(){
    // processing a block
    if((x+1) % BLOCK_SIZE) return &(collection[y][++x]);
    if((y+1) % BLOCK_SIZE) return &(collection[++y][(x=x-BLOCK_SIZE+1)]);

    // finished a block
    if(x != width-1) return &(collection[(y=y-BLOCK_SIZE+1)][++x]);
    if(y != height-1) return &(collection[++y][(x=0)]);
    return NULL;
}

int IteratorBlock::getX(){
    return x;
}

int IteratorBlock::getY(){
    return y;
}

int IteratorBlock::getHeight(){
    return height;
}

int IteratorBlock::getWidth(){
    return width;
}

IteratorBlock::~IteratorBlock() {}
