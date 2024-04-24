#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include <QTimer>
class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    int health;
    int score;
    int playerSpeed;
    void keyPressEvent(QKeyEvent *event);
    void decreaseHealth();

private:
    QGraphicsTextItem *healthText;
    QGraphicsTextItem *scoreText;
};

#endif // PLAYER_H
