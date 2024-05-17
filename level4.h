#ifndef LEVEL4_H
#define LEVEL4_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "ball.h"
#include "block.h"
#include "player.h"
#include "level5.h"

class Level4 : public QObject
{
    Q_OBJECT

public:
    explicit Level4(QObject *parent = nullptr);
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
    int additionalBallNumber = 15; // Adjust this as needed
};

#endif // LEVEL4_H
