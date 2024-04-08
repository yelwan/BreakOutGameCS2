#include "ball.h"
#include <QTimer>
#include <QGraphicsScene>
#include "QGraphicsScene"
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QObject>
#include "player.h"
#include "block.h"
#include <typeinfo>
#include <time.h>
#include <cmath>
Ball::Ball(): velocityX(5), velocityY(-5)  {
    circle = new QGraphicsEllipseItem(80, 80, 40, 40);
    circle->setPos(1,1);
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
    scene()->addItem(circle);
}
void Ball::move() {
    circle->setPos(x()+velocityX,y()+velocityY);
    QList <QGraphicsItem *> colliding_items= collidingItems();
    for (int i=0;i<colliding_items.size();i++) {
        if (typeid(*(colliding_items[i]))==typeid(Player)) {
            velocityX = -velocityX;
            velocityY = -velocityY;
        }
        if (typeid(*(colliding_items[i]))==typeid(Block)) {
                scene()->removeItem(colliding_items[i]);
                delete colliding_items[i];
                velocityY = -velocityY;
        }
    }

    if (pos().x() <= 0 || pos().x() >= scene()->width() - circle->rect().width()) {
        velocityX = -velocityX;
    }
    if (pos().y() <= 0 || pos().y() >= scene()->height() - circle->rect().height()) {
        velocityY = -velocityY;
    }
}
