#include "cell.h"

void Cell::init(char symbol){
    switch(symbol){
        case WALL_CHAR:
            this->passable = false;
            this->object = nullptr;
            break;
        case ENTRANCE_CHAR:
            this->passable = true;
            this->object = dynamic_cast<IGameObject*>(new Entrance());
            break;
        case EXIT_CHAR:
            this->passable = true;
            this->object = dynamic_cast<IGameObject*>(new Exit());
            break;
        default:
            this->passable = true;
            this->object = nullptr;
    }
}

bool Cell::getPassable() const{
    return this->passable;
}

Cell::~Cell(){
    delete object;
    object = nullptr;
}

void Cell::destroyObject(){
    delete this->object;
    this->object = nullptr;
}

void Cell::addObject(IGameObject* object){
    if(this->object || !(this->passable) || !object){
        delete object;
        return;
    }
    this->object = object;
    //qDebug() << "Added an object";
}

IGameObject *Cell::getObject() {
    return object;
}

IGameObject const * Cell::getObject() const{
    return object;
}
