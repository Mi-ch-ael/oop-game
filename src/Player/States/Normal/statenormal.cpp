#include "statenormal.h"

StateNormal::StateNormal(Params *params): params(params) {}

StateNormal::~StateNormal() {}

IState* StateNormal::handle(IGameObject* object){
    if(!object) return nullptr;
    int type = object->getGraph();
    switch(type){
    case YELLOW:
        if(params->getRange() < 2) params->addRange(1);
        break;
    case PURPLE:
        params->setRange(0);
        break;
    case BONUS:
        return dynamic_cast<IState*>(new StateImmune(params));
    case CHESTRANGE:
        if(params->getSteps()) params->addSteps(5);
        break;
    case CHESTLIM:
        params->getSteps() - 5 < 0 ? params->setSteps(0) : params->addSteps(-5);
        break;
    }
    return nullptr;
}

int StateNormal::getLabel(){
    return NORMAL;
}
