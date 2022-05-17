#include "purplemushroom.h"

PurpleMushroom::PurpleMushroom(): Publisher() {}

PurpleMushroom::~PurpleMushroom(){
    isDeleted = true;
    notify();
}

int PurpleMushroom::getGraph() const { return PURPLE; }

void PurpleMushroom::print(std::ostream &out) const{
    out << (*this);
}

void PurpleMushroom::print(QDebug out) const{
    out << (*this);
}

/*int PurpleMushroom::getX() const{
    qDebug() << "!!! GameObject.getX()";
    return -1;
}

int PurpleMushroom::getY() const{
    qDebug() << "!!! GameObject.getY()";
    return -1;
}*/

std::ostream& operator<<(std::ostream& out, const PurpleMushroom& obj){
    if(!obj.isDeleted){
        out << "PurpleMushroom object has been triggered by player\n";
        out << "Note: player's sight range becomes 0 if his STATE is not IMMUNE."<< std::endl;
        return out;
    }
    out << "PurpleMushroom object is being deleted"<< std::endl;
    return out;
}
