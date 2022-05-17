#ifndef ISTATE_H
#define ISTATE_H

#include "src/game_objects/igameobject.h"

#define NORMAL 0
#define IMMUNE 1

class IState
{
public:
    virtual ~IState();
    virtual IState* handle(IGameObject*) = 0;
    virtual int getLabel() = 0;
};

#endif // ISTATE_H
