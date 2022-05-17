#include "window.h"

Window::Window(/*Field *field, Player* player,
               std::vector<ISubscriber*> vec,*/ QWidget *parent) :
    QMainWindow(parent)
{
    player = nullptr;
    field = nullptr;

    state = dynamic_cast<IWindowState*>(new WindowStateStart(*this));

    ILoggerImplementation* concreteLoggerImpl =
            dynamic_cast<ILoggerImplementation*>(new ConsoleLogImpl());
    Logger* logger = new Logger(*concreteLoggerImpl);
    vec.push_back(dynamic_cast<ISubscriber*>(logger));

    ILoggerImplementation* anotherLoggerImpl =
            dynamic_cast<ILoggerImplementation*>(new FileLogImpl((const char*)"log.txt"));
    Logger* anotherLogger = new Logger(*anotherLoggerImpl);
    vec.push_back(dynamic_cast<ISubscriber*>(anotherLogger));

    saveloader = new SaveLoadHandler();

    commandUp = dynamic_cast<ICommand*>(new CommandMove(0, -1));
    commandDown = dynamic_cast<ICommand*>(new CommandMove(0, 1));
    commandLeft = dynamic_cast<ICommand*>(new CommandMove(-1, 0));
    commandRight = dynamic_cast<ICommand*>(new CommandMove(1, 0));

    commandFinish = dynamic_cast<ICommand*>(new CommandFinish());

    this->setWindowTitle("Simple game");

    QToolBar* toolbar = new QToolBar("", this);
    toolbar->setMovable(false);
    stepsCounter = new QLabel("" , this);
    toolbar->addWidget(stepsCounter);
    this->addToolBar(Qt::TopToolBarArea, toolbar);

    finish();
}

Window::~Window(){
    if(player){
        for(auto elem : enemies){
            player->unsubscribe(elem);
        }
    }
    this->commandFinish->execute(player);
    enemies.clear();

    delete state;

    delete commandFinish;
    delete commandUp;
    delete commandDown;
    delete commandLeft;
    delete commandRight;

    delete saveloader;

    for(ISubscriber* cur : vec){
        delete cur;
    }
}

void Window::start(){
    //assert(menu != nullptr);
    state->start();
}

void Window::keyPressEvent(QKeyEvent * event){
    state->handle(event);
}

void Window::setState(IWindowState *newState){
    //delete this->state;
    this->state = newState;
}

void Window::finish(){
    //assert(!menu);
    if(player){
        for(auto elem : enemies){
            player->unsubscribe(elem);
        }
    }
    this->commandFinish->execute(player);
    player = nullptr;
    field = nullptr;
    enemies.clear();
    menu = new StartMenu(this);
    this->setCentralWidget(menu);
    QObject::connect(menu->button, SIGNAL(clicked()), this, SLOT(start()));
    this->stepsCounter->setText("");
    this->resize(350,150);
    //this->stepsCounter->repaint();
}

IMemento* Window::save(){
    Memento* mem = new Memento(player ? this : nullptr);
    return dynamic_cast<IMemento*>(mem);
}

void Window::restore(IMemento *mem){
    Memento* snapshot = static_cast<Memento*>(mem);
    snapshot->getState(this);
}
