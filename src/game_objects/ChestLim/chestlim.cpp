#include "chestlim.h"

ChestLim::ChestLim(): Publisher() {}

ChestLim::~ChestLim(){
    isDeleted = true;
    notify();
}

int ChestLim::getGraph() const { return CHESTLIM; }

void ChestLim::print(std::ostream &out) const{
    out << (*this);
}

void ChestLim::print(QDebug out) const{
    out << (*this);
}

std::ostream& operator<<(std::ostream& out, const ChestLim& obj){
    if(!obj.isDeleted){
        out << "ChestLim object has been triggered by player\n";
        out << "Note: player loses 5 steps if his STATE is not IMMUNE."<< std::endl;
        return out;
    }
    out << "ChestLim object is being deleted"<< std::endl;
    return out;
}
