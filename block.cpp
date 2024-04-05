#include "block.h"
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <ball.h>
Block::Block(qreal x, qreal y, QGraphicsItem* parent = nullptr) : QGraphicsRectItem(x, y, BLOCK_WIDTH, BLOCK_HEIGHT, parent) {
    blocks->setBrush(Qt::green);
}
void Block::collisions() {
    QList <QGraphicsItem *> colliding_items= collidingItems();
    for (int i=0;i<colliding_items.size();i++) {
        if (typeid(*(colliding_items))==typeid(Ball)) {
            scene()->removeItem(this);
        }
    }
}
