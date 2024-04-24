#include "ball.h"
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>
#include "block.h"
#include "player.h"
#include "gameover.h"
Ball::Ball(Player* player)
    : velocityX(5)
    , velocityY(-5)
{
    QPixmap pix(":/images/vecteezy_table-tennis-racket-and-ball-clipart-design-illustration_9385379.png");
    setPixmap(pix.scaled(25, 25));
    setPos(375, 475);
    this->player= player;
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Ball::move()
{
    setPos(x() + velocityX, y() + velocityY);
    QList<QGraphicsItem *> collidingItemsList = collidingItems();
    for (int i = 0; i < collidingItemsList.size(); i++) {
        if (typeid(*(collidingItemsList[i])) == typeid(Player)) {
            velocityX = -velocityX;
            velocityY = -velocityY;
        } else if (typeid(*(collidingItemsList[i])) == typeid(Block)) {
            scene()->removeItem(collidingItemsList[i]);
            delete collidingItemsList[i];
            velocityY = -velocityY;
            player->increase();
        }
    }

    if (pos().x() <= 0 || pos().x() + pixmap().width() >= scene()->width())
        velocityX = -velocityX;

    if (pos().y() <= 0 || pos().y() + pixmap().height() >= scene()->height()) {
        velocityY = - velocityY;

 }
    if (pos().y() > player->pos().y()) {
     GameOver*g=new GameOver();
        g->show();
     scene()->removeItem(this);
 }
}
