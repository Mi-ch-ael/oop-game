#include "logger.h"

Logger::Logger(ILoggerImplementation &impl): impl(impl) {}

Logger::~Logger(){
    delete &impl;
}

void Logger::receive(const Publisher &object){
    impl.print(object);
}
