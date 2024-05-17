#include "level2.h"
#include <typeinfo>
#include <QDebug>

Level2::Level2(QObject* parent) : QObject(parent)
{
    setLevel();
    connect(this, &Level2::levelCompleteSignal, this, &Level2::onLevelComplete);
}

void Level2::setLevel()
{
    scene.setSceneRect(0, 0, 800, 600);

    player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene.addItem(player);

    for (int i = 0; i < 5 + additionalBallNumber; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            qreal blockX = j * 80;
            qreal blockY = i * 20;
            block = new Block(blockX, blockY);
            scene.addItem(block);
        }
    }

    ball = new Ball(player);
    scene.addItem(ball);

    view.setScene(&scene);
    view.show();
}

bool Level2::levelComplete()
{
    foreach (QGraphicsItem* item, scene.items())
    {
        if (typeid(*item) == typeid(Block))
        {
            return false;
        }
    }

    emit levelCompleteSignal();
    return true;
}

void Level2::nextLevel()
{
    scene.clear();
    Level3* level3 = new Level3();
    level3->setLevel();
}

void Level2::onLevelComplete()
{
    nextLevel();
}
