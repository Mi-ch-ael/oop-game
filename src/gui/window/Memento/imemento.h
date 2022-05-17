#ifndef IMEMENTO_H
#define IMEMENTO_H

#include <QString>

class FileWriter;
class FileReader;

class IMemento
{
public:
    virtual ~IMemento() = default;
    virtual void write(FileWriter*) = 0;
    virtual void read(FileReader*) = 0;
};

#endif // IMEMENTO_H
