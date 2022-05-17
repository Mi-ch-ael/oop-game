#ifndef EXIT_H
#define EXIT_H

#include "src/game_objects/igameobject.h"
//#include "src/defines.h"

class Exit : public IGameObject, public Publisher
{
public:
    Exit();
    ~Exit();
    int getGraph() const;
    void print(std::ostream& out) const;
    void print(QDebug out) const;
    friend std::ostream& operator<<(std::ostream& out, const Exit& obj);
};

#endif // EXIT_H
