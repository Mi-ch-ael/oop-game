#ifndef IWINDOWSTATE_H
#define IWINDOWSTATE_H

#include <QKeyEvent>

class IWindowState
{
public:
    virtual ~IWindowState();
    virtual void handle(QKeyEvent*) = 0;
    virtual void start() = 0;
};

#endif // IWINDOWSTATE_H
