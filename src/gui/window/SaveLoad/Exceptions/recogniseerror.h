#ifndef RECOGNISEERROR_H
#define RECOGNISEERROR_H

#include <exception>

class RecogniseError: public std::exception
{
public:
    const char* what() const noexcept;
};

#endif // RECOGNISEERROR_H
