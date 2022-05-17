#include "ipublisher.h"

Publisher::Publisher(): isDeleted(false){
    curSubscribers = std::vector<ISubscriber*>();
}

Publisher::~Publisher() {}

void Publisher::notify(){
    for(ISubscriber* cur : curSubscribers){
        cur->receive(*this);
    }
}

void Publisher::subscribe(ISubscriber *subscriber){
    curSubscribers.push_back(subscriber);
}

void Publisher::unsubscribe(ISubscriber *subscriber){
    for(unsigned int i = 0; i < curSubscribers.size(); ++i){
        if(curSubscribers[i] == subscriber){
            curSubscribers.erase(curSubscribers.begin()+i);
            --i;
        }
    }
}

int Publisher::getX() const {
    return -1;
}

int Publisher::getY() const {
    return -1;
}
