#ifndef BALL_H
#define BALL_H
#include "QGraphicsItem"
class Ball : QGraphicsItem, QObject
{
private:
    QGraphicsEllipseItem *circle;
    int velocityX;
    int velocityY;
public:
    Ball();
public slots:
    void move();
};

#endif // BALL_H
