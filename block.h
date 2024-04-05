#ifndef BLOCK_H
#define BLOCK_H

class Block
{
public:
    Block(qreal x, qreal y, QGraphicsItem* parent = nullptr);
    void collisions();
};

#endif // BLOCK_H
