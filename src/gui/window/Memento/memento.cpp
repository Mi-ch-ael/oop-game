#include "memento.h"

Memento::Memento(const Window* model){
    if(!model){
        this->arena = nullptr;
        return;
    }
    Enemy<STUPID>* tmp = nullptr;
    for(ISubscriber* elem : model->enemies){
        tmp = static_cast<Enemy<STUPID>*>(elem);
        this->enemy_position.push_back(std::pair<int,int>(tmp->getX(),tmp->getY()));
    }
    this->player_state = model->player->getState()->getLabel();
    this->arena = Field::getInstance()->getArena();
    this->player_range = model->player->params->getRange();
    this->player_steps = model->player->params->getSteps();
    this->player_x = model->player->getX();
    this->player_y = model->player->getY();

    qDebug() << "Created memento:";
    qDebug() << "Player at (" << player_x << ";" << player_y << ")";
    qDebug() << "with range" << player_range << "and" << player_steps << "steps.";
    qDebug() << "Searching enemy at" << enemy_position.at(0).first << ";" <<
                enemy_position.at(0).second;
}
Memento::~Memento() {}

void Memento::write(FileWriter *writer){
    QString str;
    str = QString("\n%1 %2 %3 %4 %5\n").arg(player_x).arg(player_y).arg(
                player_range).arg(player_steps).arg(player_state);
    writer->write(str.toLocal8Bit().data(),str.length());
    //x y range steps state
    for(pair<int,int> elem: enemy_position){
        str = QString("%1 %2 ").arg(elem.first).arg(elem.second);
        writer->write(str.toLocal8Bit().data(),str.length());
    }
    writer->write("\n",1);

    char cur_cell;
    int obj_type;
    Field* field = Field::getInstance();

    for(int y = 0; y < BLOCK_SIZE*FIELD_HEIGHT; ++y){
        for(int x = 0; x < BLOCK_SIZE*FIELD_WIDTH; ++x){
            if(field->getPassable(x,y)){
                if(field->getObject(y,x)){
                    obj_type = field->getObject(y,x)->getGraph();
                    switch(obj_type){
                    case ENTRANCE:
                        cur_cell = ENTRANCE_CHAR;
                        break;
                    case EXIT:
                        cur_cell = EXIT_CHAR;
                        break;
                    case BONUS:
                        cur_cell = BONUS_CHAR;
                        break;
                    case YELLOW:
                        cur_cell = YELLOW_CHAR;
                        break;
                    case PURPLE:
                        cur_cell = PURPLE_CHAR;
                        break;
                    case CHESTLIM:
                        cur_cell = CHESTLIM_CHAR;
                        break;
                    case CHESTRANGE:
                        cur_cell = CHESTRANGE_CHAR;
                        break;
                    }
                }
                else cur_cell = SPARE_CHAR;
            }
            else cur_cell = WALL_CHAR;
            writer->write(const_cast<const char*>(&cur_cell),1);
        }
    }
}

void Memento::read(FileReader *reader){
    this->enemy_position.clear();
    std::vector<int>* data;
    data = (reader->readPlayer());
    assert(data->size() == SAVED_PLAYER_PARAMS);
    this->player_x = data->at(0);
    this->player_y = data->at(1);
    this->player_range = data->at(2);
    this->player_steps = data->at(3);
    this->player_state = data->at(4);
    //qDebug() << player_x << player_y;
    delete data;

    data = (reader->readEnemies());
    assert(data->size() == SAVED_ENEMY_PARAMS);

    for(int i = 0; i < SAVED_ENEMY_PARAMS/2; ++i){
        /*this->enemy_position[i].first = data->at(2*i);
        this->enemy_position[i].second = data->at(2*i+1);*/
        this->enemy_position.push_back(pair<int,int>(data->at(2*i),data->at(2*i+1)));
    }
    qDebug() << enemy_position[WANDERING].first << enemy_position[WANDERING].second;

    delete data;

    arena = reader->readArena();
}

void Memento::getState(Window* model){
    //finish(), если нужен, обеспечивается состоянием окна
    model->field = Field::getInstance();
    model->field->replaceArena(this->arena);

    model->enemies.push_back(dynamic_cast<ISubscriber*>(new Enemy<WANDERING>(
                                             enemy_position.at(WANDERING).first,
                                             enemy_position.at(WANDERING).second)));
    model->enemies.push_back(dynamic_cast<ISubscriber*>(new Enemy<SEARCHING>(
                                             enemy_position.at(SEARCHING).first,
                                             enemy_position.at(SEARCHING).second)));
    model->enemies.push_back(dynamic_cast<ISubscriber*>(new Enemy<STUPID>(
                                             enemy_position.at(STUPID).first,
                                             enemy_position.at(STUPID).second)));

    model->player = new Player(model->field,model->enemies,
                               this->player_y,this->player_x,
                               this->player_range,
                               this->player_steps);
    IState* state = nullptr;
    switch(this->player_state){
    case NORMAL:
        state = dynamic_cast<IState*>(new StateNormal(model->player->params));
        break;
    case IMMUNE:
        state = dynamic_cast<IState*>(new StateImmune(model->player->params));
        break;
    }
    assert(state);

    model->player->setState(state);

    for(auto elem : model->enemies){
        model->player->subscribe(elem);
    }

    for(ISubscriber* elem : model->vec){
            model->player->subscribe(elem);
            for(int y = 0; y < model->field->getHeight(); ++y){
                for(int x = 0; x < model->field->getWidth(); ++x){
                    if(model->field->getObject(y,x)){
                        dynamic_cast<Publisher*>(static_cast<Bonus*>(model->field->getObject(y,x)))->subscribe(elem);
                    }
                }
            }
     }

    model->setCentralWidget(new Canvas(model->player, model->enemies, model));
    model->menu = nullptr;
    model->stepsCounter->setText(QStringLiteral("Turns left: %1").arg(model->player->params->getSteps()));
    model->resize(700,600);
    model->setState(dynamic_cast<IWindowState*>(new WindowStatePlayer(*model)));

}
