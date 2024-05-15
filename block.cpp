#include "block.h"

Block::Block(qreal x, qreal y)
{
    QPixmap pix(":/images/block.png");
    setPixmap(pix.scaled(20, 20));
    setPos(x, y);
}
