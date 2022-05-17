#include "saveloadhandler.h"

SaveLoadHandler::~SaveLoadHandler(){
    qDebug() << "SaveLoadHandler is being deleted";
}

void SaveLoadHandler::save(IMemento *snapshot, const QString& filename){
    FileWriter* writer = new FileWriter(filename);
    try{
        snapshot->write(writer);
    }
    catch(OpenError&){
        delete writer;
        throw OpenError();
    }

    delete writer;
}

void SaveLoadHandler::load(IMemento *snapshot, const QString& filename){
    FileReader* reader = new FileReader(filename);
    try{
        reader->checkPrefix();
        snapshot->read(reader);
    }
    catch(OpenError&){
        delete reader;
        throw OpenError();
    }
    catch(RecogniseError&){
        delete reader;
        throw RecogniseError();
    }
    catch(ReadError&){
        delete reader;
        throw ReadError();
    }

    delete reader;
}
