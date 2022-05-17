#include "debuglogimpl.h"

DebugLogImpl::DebugLogImpl(){
    file = new QFile();
    file->open(stderr, QIODevice::WriteOnly | QIODevice::Text);
    qDebug() << file->isOpen();
    outstream = new QDebug(
                dynamic_cast<QIODevice*>(dynamic_cast<QFileDevice*>(file)));
    //outstream = new QDebug(
    //  dynamic_cast<QIODevice*>(dynamic_cast<QFileDevice*>(file)));
    //qDebug() << outstream;
    /*outstream = new QDebug(qDebug());
    qDebug() << outstream;*/
}

DebugLogImpl::~DebugLogImpl(){
    file->close();
    delete file;
    delete outstream;
}

void DebugLogImpl::print(const Publisher & obj){
    obj.print(*outstream);
}
