#include "player.h"

Player::Player(Field* field, vector<ISubscriber *> &enemies, int y0, int x0, int range, int steps):
Publisher(), y(y0) , x(x0) ,field(field), enemies(enemies)
{
    params = new Params(range, steps);
    state = dynamic_cast<IState*>(new StateNormal(params));
}

Player::~Player(){
    isDeleted = true;
    notify();
    delete params;
    delete state;
}

void Player::move(int shift_x, int shift_y){
    if(x + shift_x >= 0 && x + shift_x < field->getWidth()
       && y + shift_y >= 0 && y + shift_y <field->getHeight()){
        if(field->getPassable(x+shift_x,y+shift_y)){
            x += shift_x;
            y += shift_y;
        }
    }
    if(params->getSteps()) this->params->addSteps(-1);
    //-----
    for(ISubscriber* elem: enemies){
        *this + elem;
    }
    if(field->getObject(y,x)){
        dynamic_cast<Publisher*>(static_cast<Bonus*>(field->getObject(y,x)))->notify();
    }
    *this + field->getObject(y,x);
    //this->notify();

}

void Player::operator +(IGameObject* object){
    IState* newState = state->handle(object);
    if(newState){
        setState(newState);
    }
    if(field->getObject(y,x) &&
            field->getObject(y,x)->getGraph() != ENTRANCE &&
            field->getObject(y,x)->getGraph() != EXIT){
        field->destroyObject(y,x);
    }
}

void Player::operator +(ISubscriber* enemy){
   if((static_cast<Enemy<STUPID>*>(enemy)->getX() == x) &&
      (static_cast<Enemy<STUPID>*>(enemy)->getY() == y)){
       int entr_y, entr_x;
       Field::getInstance()->getEntranceCrd(entr_y,entr_x);
       //if((entr_x-x)||(entr_y-y)) move(entr_x-x,entr_y-y);
       x = entr_x;
       y = entr_y;
   }
}

int Player::getX() const{
    return x;
}

int Player::getY() const{
    return y;
}

IState* Player::getState(){
    return state;
}

void Player::setState(IState* newState){
    delete state;
    state = newState;
}


std::ostream& operator<< (std::ostream &out, const Player& player){
    if(!player.isDeleted){
        out << "Player now at (" << player.x << ";"
        << player.y << "); player has "
        << player.params->getSteps() << " steps left; "
        << "current sight range is "
        << player.params->getRange() << "." << std::endl;
    }
    else{
        out << "Player is being deleted" << std::endl;
    }
    return out;
}

QDebug operator<< (QDebug out, const Player& player){
    out << "Player now at (" << player.x << ";" << player.y << ")";
    return out;
}

void Player::print(std::ostream &out) const{
    out << (*this);
}

void Player::print(QDebug out) const{
    out << (*this);
}
