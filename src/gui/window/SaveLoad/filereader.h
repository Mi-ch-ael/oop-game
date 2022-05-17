#ifndef FILEREADER_H
#define FILEREADER_H

#include <climits>

#include <vector>

#include <QFile>
#include <QString>
#include <QTextStream>

#include "src/defines.h"
#include "src/gui/window/SaveLoad/Exceptions/recogniseerror.h"
#include "src/gui/window/SaveLoad/Exceptions/readerror.h"
#include "src/gui/window/SaveLoad/Exceptions/openerror.h"
#include "src/Field/field.h"

class FileReader
{
public:
    FileReader(const QString &filename);
    ~FileReader();
    void checkPrefix();
    std::vector<int> *readPlayer();
    std::vector<int>* readEnemies();
    Cell** readArena();
private:
    QFile* file;
    QTextStream instream;
};

#endif // FILEREADER_H
