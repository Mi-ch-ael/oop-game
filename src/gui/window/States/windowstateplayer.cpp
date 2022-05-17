#include "windowstateplayer.h"

WindowStatePlayer::WindowStatePlayer(Window &context): context(context){}

WindowStatePlayer::~WindowStatePlayer(){
    qDebug() << "WindowStatePlayer is being deleted";
}

void WindowStatePlayer::handle(QKeyEvent *event){
    int moves = context.player->params->getSteps();
    switch(event->key()){
    case Qt::Key_Up:
        context.commandUp->execute(context.player);
        break;
    case Qt::Key_Down:
        context.commandDown->execute(context.player);
        break;
    case Qt::Key_Left:
        context.commandLeft->execute(context.player);
        break;
    case Qt::Key_Right:
        context.commandRight->execute(context.player);
        break;
    case Qt::Key_Escape:
        //test
        //context.testMemento = context.save();
        //context.restore(context.testMemento);
        //end test
        context.setState(dynamic_cast<IWindowState*>(new WindowStateStart(context)));
        context.finish();
        delete this;
        return;
    {case Qt::Key_S:
        if(!(event->modifiers() & Qt::ControlModifier)) return;
        QString filename = QFileDialog::getSaveFileName(&context, QString("Save game..."),
                                                        QString(),
                                                        QString("*.")+QString(EXT));
        if(!filename.length()) return;
        if(filename.indexOf("."EXT) != (filename.size() - 4)){
            filename += QString("."EXT);
        }
        IMemento* snapshot = context.save();
        try{
            context.saveloader->save(snapshot,filename);
        }
        catch(exception& ex){
            QMessageBox::warning(&context,
                         "Failed to save game",
                         QString("An unexpected error occurred while saving.\n")+
                         QString("what(): ")+
                         QString(ex.what()));
        }

        delete snapshot;

            return;}
    {case Qt::Key_O:
        if(!(event->modifiers() & Qt::ControlModifier)) return;
        context.setState(dynamic_cast<IWindowState*>(new WindowStateStart(context)));
        context.state->handle(event);
        delete this;
        return;
    }
    default:
        return;
    }
    context.centralWidget()->repaint();
    context.stepsCounter->setText(QStringLiteral("Turns left: %1").arg(context.player->params->getSteps()));
    int x, y;
    context.field->getExitCrd(y,x);
    if(context.player->getX() == x &&
       context.player->getY() == y &&
            moves > 0){
       QMessageBox::information(&context,"Level passed",context.stepsCounter->text());
       context.setState(dynamic_cast<IWindowState*>(new WindowStateStart(context)));
       context.finish();
       delete this;
    }
    else {
        context.setState(dynamic_cast<IWindowState*>(new WindowStateEnemy(context)));
        delete this;
    }
}

void WindowStatePlayer::start(){}
