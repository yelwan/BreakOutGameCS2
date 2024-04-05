#include "ball.h"
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QBrush>
#include "player.h"
#include "block.h"
Ball::Ball() {
    circle = new QGraphicsEllipseItem(80, 80, 40, 40);
    circle->setPos(1,1);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
    scene.addItem(circle);
}
void Ball::move() {
    setPos(x(),y()-10);
    QList <QGraphicsItem *> colliding_items= collidingItems();
    for (int i=0;i<colliding_items.size();i++) {
        if (typeid(*(colliding_items[i]))==typeid(Player)) {
            circle->setPos(-pos.x(),pos.y());
        }
    }
    if (pos().y()+pixmap().height()<0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
