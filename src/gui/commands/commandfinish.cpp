#include "commandfinish.h"

CommandFinish::CommandFinish()
{}

void CommandFinish::execute(Player *receiver){
    if(!receiver) return;
    //if(!Field::getInstance()) return;
    Field* field = Field::getInstance();
    //field->destroyObject(EXIT_Y, EXIT_X); //???
    //field->destroyObject(ENTR_Y, ENTR_X);
    delete field;
    field = nullptr;
    delete receiver;
    receiver = nullptr;
}
