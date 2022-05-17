#ifndef SAVELOADHANDLER_H
#define SAVELOADHANDLER_H

#include <cassert>

#include <QDebug>
#include <QFile>
#include <QString>

#include "src/gui/window/Memento/imemento.h"
#include "src/gui/window/SaveLoad/filewriter.h"
#include "src/gui/window/SaveLoad/filereader.h"

class SaveLoadHandler
{
public:
    SaveLoadHandler() = default;
    ~SaveLoadHandler();
    void save(IMemento*, const QString &name);
    void load(IMemento*snapshot, const QString &filename);
};

#endif // SAVELOADHANDLER_H
