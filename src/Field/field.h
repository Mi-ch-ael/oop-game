#ifndef FIELD_H
#define FIELD_H

#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#include <QFile>

#include "src/Cell/cell.h"
#include "src/defines.h"
#include "src/Iterator/IteratorBlock/iteratorblock.h"
#include "src/game_objects/YellowMushroom/mushroomfactory.h"
#include "src/game_objects/DungeonFactory/dungeonfactory.h"
#include "src/game_objects/igameobject.h"
#include "src/gui/window/SaveLoad/Exceptions/openerror.h"

using namespace std;

class Field
{
public:
    static Field* getInstance(){
        if(instance == NULL){
            instance = new Field();
        }
        return instance;
    }

    ~Field();
    int getHeight();
    int getWidth();
    bool getPassable(int x, int y);
    IIterator *getIterator();
    Field(const Field& other) = delete;
    Field(Field&& other) = delete;
    Field& operator=(const Field& other) = delete;
    Field& operator=(Field&& other) = delete;
    IGameObject* getObject(int y, int x);
    void destroyObject(int y, int x);
    void getEntranceCrd(int& y, int& x);
    void getExitCrd(int& y, int& x);
    Cell** getArena();
    void replaceArena(Cell** new_arena);
private:
    Field();
    Cell** arena;
    int height;
    int width;
    static Field* instance;
    int entranceX, entranceY;
    int exitX, exitY;
};

#endif // FIELD_H
