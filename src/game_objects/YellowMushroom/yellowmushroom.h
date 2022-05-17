#ifndef YELLOWMUSHROOM_H
#define YELLOWMUSHROOM_H

#include "src/game_objects/igameobject.h"

class YellowMushroom : public IGameObject, public Publisher
{
public:
    YellowMushroom();
    ~YellowMushroom();
    int getGraph() const;
    void print(std::ostream& out) const;
    void print(QDebug out) const;
    //int getX() const;
    //int getY() const;
    friend std::ostream& operator<<(std::ostream& out, const YellowMushroom& obj);
};

#endif // YELLOWMUSHROOM_H
