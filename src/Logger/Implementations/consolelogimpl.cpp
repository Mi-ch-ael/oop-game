#include "consolelogimpl.h"

ConsoleLogImpl::ConsoleLogImpl() {}

ConsoleLogImpl::~ConsoleLogImpl(){
    std::cout.flush();
}

void ConsoleLogImpl::print(const Publisher &obj){
    obj.print(std::cout);
}
