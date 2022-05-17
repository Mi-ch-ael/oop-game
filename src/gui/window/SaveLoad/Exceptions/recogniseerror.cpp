#include "recogniseerror.h"

const char* RecogniseError::what() const noexcept{
    return "File hasn't been recognised as a 'saved game' file";
}
