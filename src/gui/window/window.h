#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QIntValidator>
#include <QToolBar>
#include <QPushButton>
#include <QMessageBox>
#include <QKeyEvent>

#include "src/gui/canvas/canvas.h"
#include "src/gui/menu/startmenu.h"
#include "src/Observer/Subscriber/isubscriber.h"
#include "src/gui/commands/commandmove.h"
#include "src/gui/commands/commandfinish.h"
#include "src/gui/icommand.h"
#include "src/Logger/Implementations/consolelogimpl.h"
#include "src/Logger/Implementations/filelogimpl.h"
#include "src/Logger/logger.h"
#include "src/gui/window/States/iwindowstate.h"
#include "src/Enemy/enemy.h"
#include "src/gui/window/Memento/imemento.h"
#include "src/gui/window/SaveLoad/saveloadhandler.h"


//class WindowStateStart;
//class IWindowState;

class Window : public QMainWindow
{
    Q_OBJECT
    friend class WindowStatePlayer;
    friend class WindowStateStart;
    friend class WindowStateEnemy;
    friend class Memento;
public:
    Window(QWidget *parent = 0);
    ~Window();
    void keyPressEvent(QKeyEvent *);
    void setState(IWindowState*);

    IMemento* save();
    void restore(IMemento*);
private:
    QLabel* stepsCounter;
    Field* field;
    Player* player;
    IWindowState* state;
    std::vector<ISubscriber*> vec;
    std::vector<ISubscriber*> enemies;
    ICommand *commandUp, *commandDown, *commandLeft, *commandRight;
    ICommand* commandFinish;
    StartMenu* menu;
    void finish();
    SaveLoadHandler* saveloader;

    //test
    IMemento* testMemento;
signals:

private slots:
    void start();
};

#include "src/gui/window/States/windowstatestart.h"
#include "src/gui/window/Memento/memento.h"

#endif // WINDOW_H
