#ifndef WINDOWSTATESTART_H
#define WINDOWSTATESTART_H

#include "src/gui/window/States/iwindowstate.h"
#include "src/gui/window/States/windowstateplayer.h"
#include "src/gui/window/window.h"

class WindowStateStart: public IWindowState
{
public:
    WindowStateStart(Window& context);
    ~WindowStateStart();
    void handle(QKeyEvent*);
    void start();
private:
    Window& context;
    map<int,pair<int,int>> locations{
        {WANDERING,pair<int,int>(ENTR_X,EXIT_Y)},
        {SEARCHING,pair<int,int>(EXIT_X, EXIT_Y)},
        {STUPID,pair<int,int>(EXIT_X,ENTR_Y)}
    };
};

#endif // WINDOWSTATESTART_H
