#ifndef LEVEL2_H
#define LEVEL2_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "ball.h"
#include "block.h"
#include "player.h"
#include "level3.h"

class Level2 : public QObject
{
    Q_OBJECT

public:
    explicit Level2(QObject *parent = nullptr);
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
    int additionalBallNumber = 5; // Adjust this as needed
};

#endif // LEVEL2_H
