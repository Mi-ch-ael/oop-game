#include "openerror.h"

const char* OpenError::what() const noexcept{
    return "Failed to open file";
}
