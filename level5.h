#ifndef LEVEL5_H
#define LEVEL5_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "ball.h"
#include "block.h"
#include "player.h"

class Level5 : public QObject
{
    Q_OBJECT

public:
    explicit Level5(QObject *parent = nullptr);
    void setLevel();
    bool levelComplete();
    void nextLevel();

signals:
    void levelCompleteSignal();

private slots:
    void onLevelComplete();

private:
    QGraphicsScene scene;
    QGraphicsView view;
    Player* player;
    Ball* ball;
    Block* block;
    int additionalBallNumber = 20; // Adjust this as needed
};

#endif // LEVEL5_H
