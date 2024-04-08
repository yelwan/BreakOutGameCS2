#ifndef BLOCK_H
#define BLOCK_H
#include "QGraphicsItem"
#include <QGraphicsRectItem>
class Block : QGraphicsItem, QGraphicsRectItem
{
private:
    int BLOCK_WIDTH;
    int BLOCK_HEIGHT;
    QGraphicsRectItem  * blocks= new QGraphicsRectItem();
public:
    Block(qreal x, qreal y, QGraphicsItem* parent = nullptr);

};

#endif // BLOCK_H
