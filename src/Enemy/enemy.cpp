#include "enemy.h"

template<>
void Enemy<SEARCHING>::receive(const Publisher &object){
    const Player& player = static_cast<const Player&>(object);
    int x = player.getX();
    int y = player.getY();

    for(;;){
        if( (x < this->x) && check(-1,0) ){
            move(-1,0);
            break;
        }
        if( (x > this->x) && check(1,0)){
            move(1,0);
            break;
        }
        if( (y < this->y) && check(0,-1)){
            move(0,-1);
            break;
        }
        if( (y > this->y) && check(0,1)){
            move(0,1);
            break;
        }
        if((y <= this->y) &&check(0,-1)){
            move(0,-1);
            break;
        }
        if((x <= this->x) && check(-1,0)){
            move(-1,0);
            break;
        }
        if((y >= this->y) && check(0,1)){
            move(0,1);
            break;
        }
        if((x >= this->x) && check(1,0)){
            move(1,0);
            break;
        }
        move(0,1);
        break;
    }

    *this + static_cast<Player*>(const_cast<Publisher*>(&object));
}


template<>
void Enemy<STUPID>::receive(const Publisher &object){
    time_t cur_time = time(nullptr);
    srand(cur_time);
    int num = rand()%4;
    move(Shifts[num].first, Shifts[num].second);

    *this + static_cast<Player*>(const_cast<Publisher*>(&object));
}

template<>
void Enemy<WANDERING>::receive(const Publisher &object){

    time_t cur_time = time(nullptr);
    srand(cur_time);

    for(int i = 0;i < 10; ++i){
        int num = rand()%4;
        if(!check(Shifts[num].first, Shifts[num].second)) continue;
        else{
            move(Shifts[num].first, Shifts[num].second);
            break;
        }
    }
    *this + static_cast<Player*>(const_cast<Publisher*>(&object));
}
