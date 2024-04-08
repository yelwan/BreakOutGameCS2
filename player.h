#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "ball.h"
class Player : public QGraphicsRectItem, QGraphicsScene {
private:
    QGraphicsTextItem *healthText;
    QGraphicsTextItem* scoreText;
    int health;
    int score;
    QGraphicsRectItem* player;
    Ball *balls;
public:
    Player(QGraphicsRectItem*);
    ~Player();
    void IncreaseScore();
    void DecreaseScore();
    void keyPressEvent(QKeyEvent * event);
};

#endif // PLAYER_H
