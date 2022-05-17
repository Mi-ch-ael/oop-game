#include "entrance.h"

Entrance::Entrance(): Publisher() {}

Entrance::~Entrance(){
    isDeleted = true;
    notify();
}

int Entrance::getGraph() const { return ENTRANCE; }

void Entrance::print(std::ostream &out) const{
    out << (*this);
}

void Entrance::print(QDebug out) const{
    out << (*this);
}

std::ostream& operator<<(std::ostream& out, const Entrance& obj){
    if(!obj.isDeleted){
        out << "Entrance object has been triggered by player\n";
        out << "Note: nothing happens." << std::endl;
        return out;
    }
    out << "Entrance object is being deleted" << std::endl;
    return out;
}

