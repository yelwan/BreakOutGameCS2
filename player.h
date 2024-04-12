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
    void keyPressEvent(QKeyEvent *event) override;
    int health;
    int score;
    int playerSpeed;
private:
    QGraphicsTextItem *healthText;
    QGraphicsTextItem *scoreText;

};

#endif // PLAYER_H
