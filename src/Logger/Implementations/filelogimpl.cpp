#include "filelogimpl.h"

FileLogImpl::FileLogImpl(const char *filename){
    out.open(filename);
}

FileLogImpl::~FileLogImpl(){
    out.close();
}

void FileLogImpl::print(const Publisher &obj){
    obj.print(out);
}
