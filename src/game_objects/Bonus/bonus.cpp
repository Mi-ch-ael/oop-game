#include "bonus.h"

Bonus::Bonus(): Publisher() {}

Bonus::~Bonus(){
    isDeleted = true;
    notify();
}

int Bonus::getGraph() const { return BONUS; }

void Bonus::print(std::ostream &out) const{
    out << (*this);
}

void Bonus::print(QDebug out) const{
    out << (*this);
}

std::ostream& operator<<(std::ostream& out, const Bonus& obj){
    if(!obj.isDeleted){
        out << "Bonus object has been triggered by player\n";
        out << "Note: player's STATE is now guaranteed to be IMMUNE." << std::endl;
        return out;
    }
    out << "Bonus object is being deleted" << std::endl;
    return out;
}
