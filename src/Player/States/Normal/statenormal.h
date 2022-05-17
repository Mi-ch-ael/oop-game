#ifndef STATENORMAL_H
#define STATENORMAL_H

#include "src/Player/States/istate.h"
#include "src/Player/params.h"
#include "src/Player/States/Immune/stateimmune.h"

class StateNormal : public IState
{
public:
    StateNormal(Params* params);
    ~StateNormal();
    IState* handle(IGameObject*);
    int getLabel();
private:
    Params* params;
};

#endif // STATENORMAL_H
