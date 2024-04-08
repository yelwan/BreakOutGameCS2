#include "block.h"
#include <QGraphicsRectItem>
#include <QBrush>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <ball.h>
Block::Block(qreal x, qreal y, QGraphicsItem* parent) : QGraphicsRectItem(x, y,  BLOCK_WIDTH,  BLOCK_HEIGHT, parent=nullptr) {
    blocks->setBrush(Qt::green);
}

