#ifndef PARAMS_H
#define PARAMS_H

class Params
{
public:
    Params(int range,
           int steps);
    ~Params();
    int getRange();
    int getSteps();
    void setRange(int);
    void setSteps(int);
    void addSteps(int);
    void addRange(int);
private:
    int range;
    int steps;
};

#endif // PARAMS_H
