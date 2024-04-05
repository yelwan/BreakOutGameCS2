#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include "ball.h"
class Player
{
private:
    QGraphicsRectItem* player;
    Ball *ball;
public:
    Player(QGraphicsRectItem* player);
    ~Player();
    void IncreaseScore();
    void DecreaseScore();
    void keyPressEvent(QKeyEvent * event);
};

#endif // PLAYER_H
