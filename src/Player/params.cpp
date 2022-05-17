#include "params.h"

Params::Params(int range, int steps): range(range), steps(steps){}

Params::~Params() {}

int Params::getRange(){
    return range;
}

int Params::getSteps(){
    return steps;
}

void Params::setRange(int range){
    this->range = range;
}

void Params::setSteps(int steps){
    this->steps = steps;
}

void Params::addSteps(int steps_to_add){
    steps += steps_to_add;
}

void Params::addRange(int range_to_add){
    range += range_to_add;
}
