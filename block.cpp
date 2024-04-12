#include "block.h"

Block::Block(qreal x, qreal y)
{
    QPixmap pix("C:/Users/Yehia/Downloads/block.png");
    setPixmap(pix.scaled(pix.height(),pix.width()));
    setPos(x,y);
}
