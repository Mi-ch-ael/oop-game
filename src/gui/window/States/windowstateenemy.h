#ifndef WINDOWSTATEENEMY_H
#define WINDOWSTATEENEMY_H

#include "src/gui/window/States/iwindowstate.h"
#include "src/gui/window/States/windowstateplayer.h"
#include "src/gui/window/window.h"

class WindowStateEnemy: public IWindowState
{
public:
    WindowStateEnemy(Window &context);
    ~WindowStateEnemy();
    void handle(QKeyEvent *);
    void start();
private:
    Window& context;
};

#endif // WINDOWSTATEENEMY_H
