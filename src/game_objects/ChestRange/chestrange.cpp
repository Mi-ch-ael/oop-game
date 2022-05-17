#include "chestrange.h"

ChestRange::ChestRange(): Publisher() {}

ChestRange::~ChestRange(){
    isDeleted = true;
    notify();
}

int ChestRange::getGraph() const { return CHESTRANGE; }

void ChestRange::print(std::ostream &out) const{
    out << (*this);
}

void ChestRange::print(QDebug out) const{
    out << (*this);
}

std::ostream& operator<<(std::ostream& out, const ChestRange& obj){
    if(!obj.isDeleted){
        out << "ChestRange object has been triggered by player\n";
        out << "Note: player gains 5 steps if he still had any before opening a chest."<< std::endl;
        return out;
    }
    out << "ChestRange object is being deleted"<< std::endl;
    return out;
}
