#ifndef COMMANDMOVE_H
#define COMMANDMOVE_H

#include "src/gui/icommand.h"
#include "src/Player/player.h"

class CommandMove: public ICommand
{
public:
    CommandMove(int x, int y);
    void execute(Player *receiver);
private:
    int shift_x, shift_y;
};

#endif // COMMANDMOVE_H
