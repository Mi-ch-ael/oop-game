#ifndef WINDOWSTATEPLAYER_H
#define WINDOWSTATEPLAYER_H

#include <QFileDialog>

#include "src/gui/window/States/iwindowstate.h"
#include "src/gui/window/States/windowstatestart.h"
#include "src/gui/window/States/windowstateenemy.h"
#include "src/gui/window/window.h"

class WindowStatePlayer: public IWindowState
{
public:
    WindowStatePlayer(Window &context);
    ~WindowStatePlayer();
    void handle(QKeyEvent *);
    void start();
private:
    Window& context;
};

#endif // WINDOWSTATEPLAYER_H
