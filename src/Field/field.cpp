#include "field.h"

Field* Field::instance = NULL;

Field::Field()
{
    height = /*2*WALL_WIDTH + */FIELD_HEIGHT*BLOCK_SIZE;
    width = /*2*WALL_WIDTH + */FIELD_WIDTH*BLOCK_SIZE;

    FILE* counter = fopen(SOURCE, "r");
    if(!counter){
        throw OpenError();
    }

    arena = new Cell* [height]; //[y][x]

    for(int y = 0; y < height; ++y){
        arena[y] = new Cell[width];
    }

    entranceX = ENTR_X;
    entranceY = ENTR_Y;
    exitX = EXIT_X;
    exitY = EXIT_Y;

    int count = 0;
    char str[BLOCK_SIZE*BLOCK_SIZE+BLOCK_SIZE+1];

    srand((unsigned)time(NULL));

    for(;;){
            if (fgets(str, BLOCK_SIZE*BLOCK_SIZE+BLOCK_SIZE+1, counter)){
                ++count;
            }
            else break;
        }

    fclose(counter);

    char chr = ' ';
    IIterator* iter = this->getIterator();
    FILE* f;

    for(int j = 0; j < FIELD_HEIGHT*FIELD_WIDTH; ++j){

        f = fopen(SOURCE, "r");
        for(int k = 0; k < rand()%count; ++k){
            fgets(str, BLOCK_SIZE*BLOCK_SIZE+BLOCK_SIZE+1, f);
        }

        //reading block
        for(int i = 0; i < BLOCK_SIZE*BLOCK_SIZE; ++i){
            while(std::isspace(chr)) chr = fgetc(f);
            if ( (iter->getX() != entranceX || iter->getY() != entranceY) &&
                 (iter->getX()!=exitX || iter->getY() != exitY) ){
                iter->getCurrent()->init(chr);
            }
            if(iter->getX() == exitX && iter->getY() == exitY){
                iter->getCurrent()->init('E');
            }
            if(iter->getX() == entranceX && iter->getY() == entranceY){
                iter->getCurrent()->init('^');
            }
            chr = fgetc(f);
            iter->getNext();
        }

        fclose(f);
    }

    delete iter;

    const int types = 2;
    const int type_mushroom = 0;
    const int type_dungeon = 1;

    IFactory* factory;

    int type = rand()%types;

    switch(type){
    case type_mushroom:
        factory = dynamic_cast<IFactory*>(new MushroomFactory());
        break;
    case type_dungeon:
        factory = dynamic_cast<IFactory*>(new DungeonFactory());
        break;
    }

    int y, x;
    for(int i = 0; i < COUNT; ++i){
        y = rand()%height;
        x = rand()%width;
        arena[y][x].addObject(factory->createObjectA());
        y = rand()%height;
        x = rand()%width;
        arena[y][x].addObject(factory->createObjectB());
        y = rand()%height;
        x = rand()%width;
        arena[y][x].addObject(factory->createObjectC());
    }

    delete factory;
}

int Field::getHeight(){
    return height;
}

int Field::getWidth(){
    return width;
}

Field::~Field(){
    for(int y = 0; y < height; ++y){
        delete [] instance->arena[y];
    }
    delete[] instance->arena;
    instance = nullptr;
}

bool Field::getPassable(int x, int y){
    return arena[y][x].getPassable();
}

IIterator* Field::getIterator(){
    IteratorBlock* ptr = new IteratorBlock(arena, 0, 0, height, width);
    return (IIterator*)ptr;
}

IGameObject* Field::getObject(int y, int x){
    return arena[y][x].getObject();
}

void Field::destroyObject(int y, int x){
    arena[y][x].destroyObject();
}

void Field::getEntranceCrd(int &y, int &x){
    y = entranceY;
    x = entranceX;
}

void Field::getExitCrd(int &y, int &x){
    y = exitY;
    x = exitX;
}

Cell** Field::getArena(){
    return arena;
}

void Field::replaceArena(Cell **new_arena){
    for(int y = 0; y < height; ++y){
        delete [] instance->arena[y];
    }
    delete[] instance->arena;
    arena = new_arena;
}
