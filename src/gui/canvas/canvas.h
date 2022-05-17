#ifndef CANVAS_H
#define CANVAS_H

#include <vector>

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>

#include "src/Field/field.h"
#include "src/Player/player.h"
#include "src/Observer/Subscriber/isubscriber.h"
#include "src/Enemy/enemy.h"

class Canvas : public QWidget
{
    Q_OBJECT
public:
    Canvas(Player *player, std::vector<ISubscriber*>& enemies, QWidget *parent = 0);
    ~Canvas();
    void paintEvent(QPaintEvent *);

    QImage* wall_graph;
    QImage* invisible_graph;
    QImage* enemy_graph;
    QImage** objects_graph;
private:
    Player* player;
    vector<ISubscriber*>& enemies;
signals:

public slots:

};

#endif // CANVAS_H
