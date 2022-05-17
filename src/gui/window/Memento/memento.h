#ifndef MEMENTO_H
#define MEMENTO_H

#include <vector>

#include "src/gui/window/Memento/imemento.h"
#include "src/gui/window/window.h"
#include "src/gui/window/SaveLoad/filewriter.h"
#include "src/Cell/cell.h"

class Memento: public IMemento
{
public:
    Memento(const Window*);
    ~Memento();
    void write(FileWriter*);
    void read(FileReader*);
    void getState(Window*);
private:

    Cell** arena;
    int player_x, player_y, player_range, player_steps;
    int player_state;
    std::vector<std::pair<int,int>> enemy_position;

};

#endif // MEMENTO_H
