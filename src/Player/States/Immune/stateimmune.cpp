#include "stateimmune.h"

StateImmune::StateImmune(Params *params): params(params) {}

StateImmune::~StateImmune() {}

IState* StateImmune::handle(IGameObject* object){
    if(!object) return nullptr;
    int type = object->getGraph();
    switch(type){
    case YELLOW:
        if(params->getRange() < 2) params->addRange(1);
        break;
    case CHESTRANGE:
        if(params->getSteps()) params->addSteps(5);
        break;
    }
    return nullptr;
}

int StateImmune::getLabel(){
    return IMMUNE;
}
