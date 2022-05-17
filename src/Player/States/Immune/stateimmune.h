#ifndef STATEIMMUNE_H
#define STATEIMMUNE_H

#include "src/Player/States/istate.h"
#include "src/Player/params.h"

class StateImmune : public IState
{
public:
    StateImmune(Params* params);
    ~StateImmune();
    IState* handle(IGameObject*);
    int getLabel();
private:
    Params* params;
};

#endif // STATEIMMUNE_H
