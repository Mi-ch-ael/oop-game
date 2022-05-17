#ifndef ENTRANCE_H
#define ENTRANCE_H

#include "src/game_objects/igameobject.h"
//#include "src/defines.h"

class Entrance : public IGameObject, public Publisher
{
public:
    Entrance();
    ~Entrance();
    int getGraph() const;
    void print(std::ostream& out) const;
    void print(QDebug out) const;
    friend std::ostream& operator <<(std::ostream& out, const Entrance& object);
};

#endif // ENTRANCE_H
