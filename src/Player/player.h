#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "src/Observer/Publisher/ipublisher.h"
#include "src/Observer/Subscriber/isubscriber.h"
#include "src/Field/field.h"
#include "src/defines.h"
#include "src/Player/params.h"
#include "src/Player/States/Normal/statenormal.h"


class Player : public Publisher
{
public:
    Player(Field*,vector<ISubscriber*>&,int y0 = 0, int x0 = 0,
           int range = PLAYER_RANGE_DEFAULT,
           int steps = PLAYER_STEPS_DEFAULT);
    ~Player();
    void move(int shift_x, int shift_y);
    int getX() const;
    int getY() const;
    IState* getState();
    void setState(IState*);
    Params* params;
    void operator+(IGameObject*);
    void operator+(ISubscriber*);
    void print(QDebug out) const;
    void print(std::ostream&) const;

    friend std::ostream& operator<< (std::ostream &out, const Player& player);
    friend QDebug operator<< (QDebug out, const Player& player);
private:
    Field* field; //do not delete
    int y, x;
    IState* state;
    vector<ISubscriber*>& enemies;
};

#include "src/Enemy/enemy.h"

#endif // PLAYER_H
