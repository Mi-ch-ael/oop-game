#include "windowstatestart.h"

WindowStateStart::WindowStateStart(Window &context): context(context) {}

WindowStateStart::~WindowStateStart(){
    qDebug() << "WindowStateStart is being deleted";
}

void WindowStateStart::handle(QKeyEvent *event){
    if(!(event->modifiers() == Qt::ControlModifier) ||
        (event->key() != Qt::Key_O)) return;

    QString filename = QFileDialog::getOpenFileName(&context, QString("Load game..."),
                                                    QString(),
                                                    QString("*.")+QString(EXT));
    if(!filename.length()){
        if(context.player) context.setState(dynamic_cast<IWindowState*>(new WindowStatePlayer(context)));
        delete this;
        return;
    }

    IMemento* snapshot = context.save();
    try{
        context.saveloader->load(snapshot,filename);
    }
    catch(exception& ex){
        QMessageBox::warning(&context,
                     "Failed to load game",
                     QString("An error occurred while loading, ")+
                     QString("since ")+
                     QString("SaveLoadHandler::load(IMemento*, const QString&)")+
                     QString(" threw an exception.\nwhat(): ")+
                     QString(ex.what()));
        if(context.player){
            context.setState(dynamic_cast<IWindowState*>(new WindowStatePlayer(context)));
            delete this;
        }
        return;
    }

    if(context.player) context.finish();

    try{
        context.restore(snapshot);
    }
    catch(exception&){
        QMessageBox::critical(&context,"Failed to create gamefield",
                              "Make sure file 'blocks.md' exists.");
    }

    delete snapshot;
}

void WindowStateStart::start(){
    QString str = context.menu->steps->text();
    int pos = 0;
    if(context.menu->steps->validator()->validate(str,pos) != QValidator::Acceptable){
        QMessageBox::warning(&context , "Too few steps",
                             "Not enough steps to possibly achieve any tile within the game");
        return;
    }
    try{
        context.field = Field::getInstance();
    }
    catch(OpenError&){
        QMessageBox::critical(&context,"Failed to start game",
                              "Couldn't open file 'blocks.md'. Make sure it exists.");
        return;
    }

    int x, y;
    context.field->getEntranceCrd(y,x);

    context.enemies.push_back(dynamic_cast<ISubscriber*>(new Enemy<WANDERING>(locations[WANDERING].first, locations[WANDERING].second)));
    context.enemies.push_back(dynamic_cast<ISubscriber*>(new Enemy<SEARCHING>(locations[SEARCHING].first, locations[SEARCHING].second)));
    context.enemies.push_back(dynamic_cast<ISubscriber*>(new Enemy<STUPID>(locations[STUPID].first, locations[STUPID].second)));

    context.player = new Player(context.field,context.enemies,y,x,context.menu->range->text().toInt(),context.menu->steps->text().toInt());

    for(auto elem : context.enemies){
        context.player->subscribe(elem);
    }

    for(ISubscriber* elem : context.vec){
            context.player->subscribe(elem);
            for(int y = 0; y < context.field->getHeight(); ++y){
                for(int x = 0; x < context.field->getWidth(); ++x){
                    if(context.field->getObject(y,x)){
                        dynamic_cast<Publisher*>(static_cast<Bonus*>(context.field->getObject(y,x)))->subscribe(elem);
                    }
                }
            }
        }

    //context.player->notify();
    //test
    //dynamic_cast<Publisher*>(static_cast<Bonus*>(Field::getInstance()->getObject(EXIT_Y, EXIT_X)))->getX();

    context.setCentralWidget(new Canvas(context.player, context.enemies, &context));
    context.menu = nullptr;
    context.stepsCounter->setText(QStringLiteral("Turns left: %1").arg(context.player->params->getSteps()));
    context.resize(700,600);
    context.setState(dynamic_cast<IWindowState*>(new WindowStateEnemy(context)));
    delete this;
}
