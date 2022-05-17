#ifndef OPENERROR_H
#define OPENERROR_H

#include <exception>

class OpenError: public std::exception
{
public:
    const char* what() const noexcept;
};

#endif // OPENERROR_H
