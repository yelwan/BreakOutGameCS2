#ifndef BALL_H
#define BALL_H
#include "QGraphicsItem"
class Ball :  QGraphicsEllipseItem, QObject
{
private:
    QGraphicsEllipseItem *circle;
    int velocityX;
    int velocityY;
public:
    Ball(QGraphicsEllipseItem *circle);
public slots:
    void move();
};

#endif // BALL_H
