#ifndef CHESTRANGE_H
#define CHESTRANGE_H

#include "src/game_objects/igameobject.h"

class ChestRange : public IGameObject, public Publisher
{
public:
    ChestRange();
    ~ChestRange();
    int getGraph() const;
    void print(std::ostream& out) const;
    void print(QDebug out) const;
    friend std::ostream& operator<<(std::ostream& out, const ChestRange& obj);
};

#endif // CHESTRANGE_H
