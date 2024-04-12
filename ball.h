#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>

class Ball : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QTimer *timer;
    int velocityX;
    int velocityY;

public:
    Ball();
public slots:
    void move();
};

#endif // BALL_H
