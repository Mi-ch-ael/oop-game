#include "dungeonfactory.h"

DungeonFactory::DungeonFactory() {}

DungeonFactory::~DungeonFactory() {}

IGameObject* DungeonFactory::createObjectA(){
    return dynamic_cast<IGameObject*>(new ChestRange());
}

IGameObject* DungeonFactory::createObjectB(){
    return dynamic_cast<IGameObject*>(new ChestLim());
}

IGameObject* DungeonFactory::createObjectC(){
    return dynamic_cast<IGameObject*>(new Bonus());
}
