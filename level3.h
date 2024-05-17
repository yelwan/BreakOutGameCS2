#ifndef LEVEL3_H
#define LEVEL3_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "ball.h"
#include "block.h"
#include "player.h"
#include "level4.h"

class Level3 : public QObject
{
    Q_OBJECT

public:
    explicit Level3(QObject *parent = nullptr);
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
    int additionalBallNumber = 10; // Adjust this as needed
};

#endif // LEVEL3_H
