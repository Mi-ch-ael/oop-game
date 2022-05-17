#ifndef MUSHROOMFACTORY_H
#define MUSHROOMFACTORY_H

#include "src/game_objects/ifactory.h"
#include "src/game_objects/YellowMushroom/yellowmushroom.h"
#include "src/game_objects/PurpleMushroom/purplemushroom.h"
#include "src/game_objects/Bonus/bonus.h"

class MushroomFactory : public IFactory
{
public:
    ~MushroomFactory();
    IGameObject* createObjectA();
    IGameObject* createObjectB();
    IGameObject* createObjectC();
};

#endif // MUSHROOMFACTORY_H
