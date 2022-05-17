#ifndef FILELOGIMPL_H
#define FILELOGIMPL_H

#include <iostream>
#include <fstream>

#include "src/Logger/iloggerimplementation.h"

class FileLogImpl: public ILoggerImplementation
{
public:
    FileLogImpl(const char* filename);
    ~FileLogImpl();
    void print(const Publisher&);
private:
    std::ofstream out;
};

#endif // FILELOGIMPL_H
