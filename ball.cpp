#include <QTimer>
#include <QObject>
#include "ball.h"
#include "player.h"
#include "block.h"
#include <QGraphicsScene>

Ball::Ball() : velocityX(5), velocityY(-5)
{
    QPixmap pix("/Users/daliakadry/Downloads/ball.png");
    setPixmap(pix.scaled(25,25));
    setPos(300,400);
    timer = new QTimer();
    QObject::connect(timer, SIGNAL (timeout()), this, SLOT (move()));
    timer->start(50);
}

void Ball::move()
{
    setPos(x() + velocityX, y() + velocityY);
    QList<QGraphicsItem *> collidingItemsList = collidingItems();
    for (int i = 0; i < collidingItemsList.size(); i++)
    {
        if (typeid(*(collidingItemsList[i])) == typeid(Player))
        {
            velocityX = -velocityX;
            velocityY = -velocityY;
        }
        else if (typeid(*(collidingItemsList[i])) == typeid(Block))
        {
            scene()->removeItem(collidingItemsList[i]);
            delete collidingItemsList[i];
            velocityY = -velocityY;
        }
    }

    if (pos().x() <= 0 || pos().x() + pixmap().width() >= scene()->width())
        velocityX = -velocityX;

    if (pos().y() <= 0 || pos().y() + pixmap().height() >= scene()->height())
        velocityY = -velocityY;
}
