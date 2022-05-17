#ifndef DUNGEONFACTORY_H
#define DUNGEONFACTORY_H

#include "src/game_objects/ifactory.h"
#include "src/game_objects/Bonus/bonus.h"
#include "src/game_objects/ChestRange/chestrange.h"
#include "src/game_objects/ChestLim/chestlim.h"

class DungeonFactory : public IFactory
{
public:
    DungeonFactory();
    ~DungeonFactory();
    IGameObject* createObjectA();
    IGameObject* createObjectB();
    IGameObject* createObjectC();
};

#endif // DUNGEONFACTORY_H
