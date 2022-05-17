#ifndef PURPLEMUSHROOM_H
#define PURPLEMUSHROOM_H

#include "src/game_objects/igameobject.h"

class PurpleMushroom : public IGameObject, public Publisher
{
public:
    PurpleMushroom();
    ~PurpleMushroom();
    int getGraph() const;
    void print(std::ostream& out) const;
    void print(QDebug out) const;
    //int getX() const;
    //int getY() const;
    friend std::ostream& operator<<(std::ostream& out, const PurpleMushroom& obj);
};

#endif // PURPLEMUSHROOM_H
