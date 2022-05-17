#include "commandmove.h"

CommandMove::CommandMove(int x, int y): shift_x(x), shift_y(y)
{}

void CommandMove::execute(Player* receiver){
    receiver->move(shift_x, shift_y);
}
