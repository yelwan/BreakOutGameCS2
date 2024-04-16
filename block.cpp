#include "block.h"

Block::Block(qreal x, qreal y)
{
    QPixmap pix("/Users/daliakadry/downloads/block.png");
    setPixmap(pix.scaled(25,25));
    setPos(x,y);
}
