#include "yellowmushroom.h"

YellowMushroom::YellowMushroom() : Publisher() {}

YellowMushroom::~YellowMushroom(){
    isDeleted = true;
    notify();
}

int YellowMushroom::getGraph() const { return YELLOW; }

void YellowMushroom::print(std::ostream &out) const{
    out << (*this);
}

void YellowMushroom::print(QDebug out) const{
    out << (*this);
}

/*int YellowMushroom::getX() const{
    qDebug() << "!!! GameObject.getX()";
    return -1;
}

int YellowMushroom::getY() const{
    qDebug() << "!!! GameObject.getY()";
    return -1;
}*/

std::ostream& operator<<(std::ostream& out, const YellowMushroom& obj){
    if(!obj.isDeleted){
        out << "YellowMushroom object has been triggered by player\n";
        out << "Note: player's sight range increases by 1 if it's less than 2."<< std::endl;
        return out;
    }
    out << "YellowMushroom object is being deleted"<< std::endl;
    return out;
}
