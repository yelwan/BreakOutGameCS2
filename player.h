#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QKeyEvent>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    int health;
    int score;
    int playerSpeed;
public:
    void keyPressEvent(QKeyEvent *event) ;
private:
    QGraphicsTextItem *healthText;
    QGraphicsTextItem *scoreText;

};

#endif // PLAYER_H
