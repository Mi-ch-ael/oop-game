#ifndef IFACTORY_H
#define IFACTORY_H

#include "src/game_objects/igameobject.h"

class IFactory
{
public:
    virtual ~IFactory();
    virtual IGameObject* createObjectA() = 0;
    virtual IGameObject* createObjectB() = 0;
    virtual IGameObject* createObjectC() = 0;
};

#endif // IFACTORY_H
