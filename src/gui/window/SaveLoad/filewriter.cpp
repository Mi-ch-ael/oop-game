#include "filewriter.h"

FileWriter::FileWriter(const QString& filename)
{
    file = new QFile(filename);
    if(!file->open(QIODevice::WriteOnly)){
        delete file;
        throw OpenError();
    }
    file->write(PREFIX);
}

FileWriter::~FileWriter(){
    file->close();
    delete file;
}

void FileWriter::write(const char *data, int len){
    file->write(data,len);
}
