#include "windowstateenemy.h"

WindowStateEnemy::WindowStateEnemy(Window &context):
context(context)
{
    this->context.player->notify();
    context.centralWidget()->repaint();
}

WindowStateEnemy::~WindowStateEnemy(){
    qDebug() << "WindowStateEnemy is being deleted";
}

void WindowStateEnemy::handle(QKeyEvent *event){
    context.setState(dynamic_cast<IWindowState*>(new WindowStatePlayer(context)));
    context.state->handle(event);
    delete this;
}

void WindowStateEnemy::start() {}
