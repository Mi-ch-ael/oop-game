#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QFile>
#include <QString>

#include "src/defines.h"
#include "src/gui/window/SaveLoad/Exceptions/openerror.h"

class FileWriter
{
public:
    FileWriter(const QString &filename);
    ~FileWriter();
    void write(const char* data, int len);
private:
    QFile* file;
};

#endif // FILEWRITER_H
