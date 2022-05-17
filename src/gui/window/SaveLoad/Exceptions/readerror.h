#ifndef READERROR_H
#define READERROR_H

#include <exception>

class ReadError: public std::exception
{
public:
    const char* what() const noexcept;
};

#endif // READERROR_H
