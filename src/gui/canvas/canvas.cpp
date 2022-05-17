#include "canvas.h"

Canvas::Canvas(Player* player,std::vector<ISubscriber*>& enemies,QWidget *parent) :
    player(player), enemies(enemies), QWidget(parent)
{
    /*int a = (static_cast<Enemy<STUPID>*>(enemies[0]))->getX();
    qDebug() << a;
    a = (static_cast<Enemy<STUPID>*>(enemies[0]))->getY();
    qDebug() << a;*/

    wall_graph = new QImage(":/images/res/wall.png");
    invisible_graph = new QImage(":/images/res/invisible.png");
    enemy_graph = new QImage(":/images/res/skull_transparent.png");

    objects_graph = new QImage*[OBJECT_COUNT];
    objects_graph[ENTRANCE] = new QImage(":/images/res/entrance.png");
    objects_graph[EXIT] = new QImage(":/images/res/exit.png");
    objects_graph[YELLOW] = new QImage(":/images/res/mushroom-big.png");
    objects_graph[PURPLE] = new QImage(":/images/res/mushroom-big.png");
    objects_graph[BONUS] = new QImage(":/images/res/bonus.png");
    objects_graph[CHESTRANGE] = new QImage(":/images/res/lock.png");
    objects_graph[CHESTLIM] = new QImage(":/images/res/lock.png");
}

Canvas::~Canvas(){
    delete wall_graph;
    delete invisible_graph;
    delete enemy_graph;
    for(int i = 0; i < OBJECT_COUNT; ++i){
        delete objects_graph[i];
    }
    delete [] objects_graph;
    //qDebug() << "Canvas is being deleted";
}

void Canvas::paintEvent(QPaintEvent *){
    QPainter* painter = new QPainter(this);
    IIterator* iter = Field::getInstance()->getIterator();
    QImage* img = new QImage(this->width() , this->height() , QImage::Format_RGB32);
    img->fill(qRgb(255, 255, 255));

    int w = iter->getWidth();
    int h = iter->getHeight();

    int side = std::min(width()/w , height()/h);

    for(int i = 0; i <= h; ++i){
        for(int x = 0; x < side*w; ++x){
            img->setPixel(x,  side*i < height() ? side*i : height()-1, qRgb(0, 0, 0));
        }
    }

    for(int i = 0; i <= w; ++i){
        for(int y = 0; y < side*h; ++y){
            img->setPixel(side*i < width() ? i*side : width()-1,  y, qRgb(0, 0, 0));
        }
    }

    painter->drawImage(0, 0, *img);

    int range;
    const Cell* cur = iter->getCurrent();
    do{
        range = player->params->getRange();
        if(iter->getX() > player->getX()+range ||
           iter->getX() < player->getX()-range ||
           iter->getY() > player->getY()+range ||
           iter->getY() < player->getY()-range){
            painter->drawImage(iter->getX()*side+1,
                               iter->getY()*side+1,
                               *invisible_graph, 0, 0,
                               side-1,
                               side-1);
                cur = iter->getNext();
                continue;
        }
        if(!cur->getPassable()){
            painter->drawImage(iter->getX()*side , iter->getY()*side,
                               *wall_graph, 0, 0,
                               side+1,
                               side+1);
        }
        if(cur->getObject()){
            painter->drawImage(iter->getX()*side+1, iter->getY()*side+1,
                               *objects_graph[cur->getObject()->getGraph()], 0, 0,
                               side-1,
                               side-1);
        }
        cur = iter->getNext();
    }while(cur);

    /*painter->drawEllipse(player->getX()*side + side/2,
                         player->getY()*side + side/2,
                         side/2 , side/2);*/
    QColor heroColor = QColor(0xFF, 0x00, 0x00);

    QPen pen(heroColor);
    pen.setWidth(3);
    painter->setPen(pen);
    painter->setBrush(QBrush(heroColor));

    painter->drawEllipse(QPoint(player->getX()*side+side/2,
                                player->getY()*side+side/2),
                         side/3, side/3);
    int x, y;

    for(auto element: enemies){
        y = (static_cast<Enemy<STUPID>*>(element))->getY();
        x = (static_cast<Enemy<STUPID>*>(element))->getX();
        if((abs(player->getX() - x) > range) ||
           (abs(player->getY() - y) > range)) continue;
        painter->drawImage( (x+0.5)*side-20,
                            (y+0.5)*side-20,
                            *enemy_graph);
    }

    delete iter;
    delete img;
    delete painter;
}


/*void Canvas::keyPressEvent(QKeyEvent * event){
    switch(event->key()){
    case Qt::Key_Up:
        this->player->move(0, -1);
        break;
    case Qt::Key_Down:
        this->player->move(0, 1);
        break;
    case Qt::Key_Left:
        this->player->move(-1, 0);
        break;
    case Qt::Key_Right:
        this->player->move(1, 0);
        break;
    }
}*/
