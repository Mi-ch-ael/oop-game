#include "igameobject.h"

IGameObject::~IGameObject() {}

std::ostream& operator<<(std::ostream& out, const IGameObject& obj){
    out << obj.getGraph() << "\n";
    return out;
}

QDebug operator<< (QDebug out, const IGameObject& obj){
    out << obj.getGraph();
    return out;
}
