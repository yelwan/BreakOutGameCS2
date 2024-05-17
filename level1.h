#ifndef LEVEL1_H
#define LEVEL1_H
#include "ball.h"
#include "player.h"
#include "block.h"
#include "levelbase.h"
#include "gameover.h"
#include <QGraphicsView>
#include <QGraphicsScene>
class Level1 : public LevelBase
{
public:
    explicit Level1( QObject *parent = nullptr);
    void initializeLevel() override;
private:
    Player* player;
    Ball* ball;
    Block* block;
    int blocknumber = 0;
};

#endif // LEVEL1_H
