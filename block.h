#ifndef BLOCK_H
#define BLOCK_H
#include "QGraphicsItem"
#include <QGraphicsRectItem>
class Block : public QGraphicsRectItem
{
private:
    qreal BLOCK_WIDTH;
    qreal BLOCK_HEIGHT;
    QGraphicsRectItem  * blocks= new QGraphicsRectItem();
public:
    Block(qreal x, qreal y, QGraphicsItem* parent);

};

#endif // BLOCK_H
