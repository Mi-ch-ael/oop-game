#ifndef BONUS_H
#define BONUS_H

#include "src/game_objects/igameobject.h"

class Bonus : public IGameObject, public Publisher
{
public:
    Bonus();
    ~Bonus();
    int getGraph() const;
    void print(std::ostream& out) const;
    void print(QDebug out) const;
    friend std::ostream& operator<<(std::ostream& out, const Bonus& obj);
    //friend QDebug operator<< (QDebug out, const Bonus& object);
};

#endif // BONUS_H
