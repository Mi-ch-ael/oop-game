#ifndef CHESTLIM_H
#define CHESTLIM_H

#include "src/game_objects/igameobject.h"

class ChestLim : public IGameObject, public Publisher
{
public:
    ChestLim();
    ~ChestLim();
    int getGraph() const;
    void print(std::ostream& out) const;
    void print(QDebug out) const;
    friend std::ostream& operator<<(std::ostream& out, const ChestLim& obj);
};

#endif // CHESTLIM_H
