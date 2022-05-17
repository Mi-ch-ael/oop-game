#ifndef ICOMMAND_H
#define ICOMMAND_H

#include "src/Player/player.h"

class ICommand
{
public:
    virtual ~ICommand();
    virtual void execute(Player* receiver) = 0;
};

#endif // ICOMMAND_H
