#ifndef ENEMY_H
#define ENEMY_H

#include <cstdlib>
#include <ctime>

#include "src/Enemy/dirs.h"
#include "src/Observer/Publisher/ipublisher.h"
#include "src/Field/field.h"
#include "src/Player/player.h"

template<int behaviour>
class Enemy: public ISubscriber
{
public:
    Enemy(int x, int y): x(x) , y(y){
        field = Field::getInstance();
    }
    ~Enemy(){}

    bool check(int shift_x, int shift_y){
        if(x + shift_x >= 0 && x + shift_x < field->getWidth()
           && y + shift_y >= 0 && y + shift_y <field->getHeight()){
            if(field->getPassable(x+shift_x,y+shift_y)) return true;
        }
        return false;
    }

    void receive(const Publisher& object) {}

    void move(int shift_x, int shift_y){
        if(!check(shift_x,shift_y)) return;
        x += shift_x;
        y += shift_y;
    }

    void operator+(Player* player){
        *player + dynamic_cast<ISubscriber*>(this);
    }

    int getX() const{
        return x;
    }

    int getY() const{
        return y;
    }

private:
    int x;
    int y;
    Field* field;
    map<int,pair<int,int>> Shifts = {
        {LEFT,pair<int,int>(-1,0)},
        {RIGHT,pair<int,int>(1,0)},
        {UP,pair<int,int>(0,-1)},
        {DOWN,pair<int,int>(0,1)}
    };
};

template<>
void Enemy<SEARCHING>::receive(const Publisher &object);

template<>
void Enemy<WANDERING>::receive(const Publisher &object);

template<>
void Enemy<STUPID>::receive(const Publisher &object);


#endif // ENEMY_H
