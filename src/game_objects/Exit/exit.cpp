#include "exit.h"

Exit::Exit(): Publisher(){}

Exit::~Exit(){
    isDeleted = true;
    notify();
}

int Exit::getGraph() const { return EXIT; }

void Exit::print(std::ostream &out) const{
    out << (*this);
}

void Exit::print(QDebug out) const{
    out << (*this);
}

std::ostream& operator<<(std::ostream& out, const Exit& obj){
    if(!obj.isDeleted){
        out << "Exit object has been triggered by player\n";
        out << "Note: if player had steps at the BEGINNING of his latest move" <<
               ", level is passed." << std::endl;
        return out;
    }
    out << "Exit object is being deleted" << std::endl;
    return out;
}
