#ifndef CELL_H
#define CELL_H

#include <QDebug>

#include "src/game_objects/igameobject.h"
#include "src/game_objects/Entrance/entrance.h"
#include "src/game_objects/Exit/exit.h"

#define DEBUG

class Cell
{
public:
    ~Cell();
    void init(char symbol);
    bool getPassable() const;
    void destroyObject();
    void addObject(IGameObject* object);
    IGameObject* getObject();
    IGameObject const * getObject() const;
private:
    bool passable;
    IGameObject* object;
};

#endif // CELL_H
