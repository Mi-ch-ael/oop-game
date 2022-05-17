#ifndef COMMANDFINISH_H
#define COMMANDFINISH_H

#include <cassert>

#include "src/gui/icommand.h"
#include "src/Player/player.h"
#include "src/Field/field.h"

class CommandFinish: public ICommand
{
public:
    CommandFinish();
    void execute(Player* receiver);
};

#endif // COMMANDFINISH_H
