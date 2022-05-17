#include "readerror.h"

const char* ReadError::what() const noexcept{
    return "Invalid file format or incomplete data";
}
