#ifndef BALL_H
#define BALL_H

class Ball
{
private:
    QGraphicsEllipseItem *circle;
public:
    Ball();
public slots:
    void move();
};

#endif // BALL_H
