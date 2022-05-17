#include "mushroomfactory.h"

MushroomFactory::~MushroomFactory() {}

IGameObject* MushroomFactory::createObjectA(){
    return dynamic_cast<IGameObject*>(new YellowMushroom());
}

IGameObject* MushroomFactory::createObjectB(){
    return dynamic_cast<IGameObject*>(new PurpleMushroom());
}

IGameObject* MushroomFactory::createObjectC(){
    return dynamic_cast<IGameObject*>(new Bonus());
}
