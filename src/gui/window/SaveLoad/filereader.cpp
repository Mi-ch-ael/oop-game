#include "filereader.h"

FileReader::FileReader(const QString &filename){
    file = new QFile(filename);
    if(!file->open(QIODevice::ReadOnly)){
        delete file;
        throw OpenError();
    }
    instream.setDevice(dynamic_cast<QIODevice*>(file));
}

FileReader::~FileReader(){
    file->close();
    delete file;
}

void FileReader::checkPrefix(){
    QString line = instream.readLine();
    if(line != QString("LVL")){
        throw RecogniseError();
    }
}

std::vector<int>* FileReader::readPlayer(){
    std::vector<int>* result = new std::vector<int>();
    QString line = instream.readLine();
    qDebug() << "Player data:" << line;
    QTextStream playerData(&line);
    int tmp;
    for(int i = 0; i < SAVED_PLAYER_PARAMS; ++i){
        if(playerData.atEnd()){
            qDebug() << "Unexpected EOL!";
            throw ReadError();
        }
        //tmp = INT_MIN;
        playerData >> tmp;
        qDebug() << tmp;
        if(tmp < 0) throw ReadError();
        if(playerData.status() != QTextStream::Ok){
            qDebug() << "Stream not ok!";
            throw ReadError();
        }
        result->push_back(tmp);
    }
    return result;
}

std::vector<int> *FileReader::readEnemies(){
    std::vector<int>* result = new std::vector<int>();
    QString line = instream.readLine();
    qDebug() << "Enemy data:" << line;
    QTextStream enemyData(&line);
    int tmp;
    for(int i = 0; i < SAVED_ENEMY_PARAMS; ++i){
        if(enemyData.atEnd()){
            qDebug() << "Unexpected EOL!";
            throw ReadError();
        }
        //tmp = INT_MIN;
        enemyData >> tmp;
        qDebug() << tmp;
        if(tmp < 0) throw ReadError();
        if(enemyData.status() != QTextStream::Ok){
            qDebug() << "Stream not ok!";
            throw ReadError();
        }
        result->push_back(tmp);
    }
    return result;
}

Cell** FileReader::readArena(){
    QString line = instream.readLine();
    if(instream.status() != QTextStream::Ok){
        throw ReadError();
    }
    const char* source = line.toLocal8Bit().data();

    int height = FIELD_HEIGHT*BLOCK_SIZE;
    int width = FIELD_WIDTH*BLOCK_SIZE;
    IGameObject* savedObject = nullptr;
    Cell** arena = new Cell* [height]; //[y][x]
    for(int y = 0; y < height; ++y){
        arena[y] = new Cell[width];
    }

    for(int i = 0; i < width*height; ++i){
        if(!source[i]){
            throw ReadError();
        }
        savedObject = nullptr;
        arena[i/width][i%width].init(source[i]);
        switch(source[i]){
        case BONUS_CHAR:
            savedObject = dynamic_cast<IGameObject*>(new Bonus());
            break;
        case CHESTLIM_CHAR:
            savedObject = dynamic_cast<IGameObject*>(new ChestLim());
            break;
        case CHESTRANGE_CHAR:
            savedObject = dynamic_cast<IGameObject*>(new ChestRange());
            break;
        case YELLOW_CHAR:
            savedObject = dynamic_cast<IGameObject*>(new YellowMushroom());
            break;
        case PURPLE_CHAR:
            savedObject = dynamic_cast<IGameObject*>(new PurpleMushroom());
            break;
        }
        if(savedObject) arena[i/width][i%width].addObject(savedObject);
    }

    return arena;
}
