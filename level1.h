// level1.h
#ifndef LEVEL1_H
#define LEVEL1_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "ball.h"
#include "block.h"
#include "player.h"
#include "level2.h"

class Level1 : public QObject
{
    Q_OBJECT

public:
    explicit Level1(QObject *parent = nullptr);
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
    int additionalBallNumber = 0; // Adjust this as needed
};

#endif // LEVEL1_H
