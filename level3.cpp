#include "level3.h"
#include <typeinfo>
#include <QDebug>

Level3::Level3(QObject* parent) : QObject(parent)
{
    setLevel();
    connect(this, &Level3::levelCompleteSignal, this, &Level3::onLevelComplete);
}

void Level3::setLevel()
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

bool Level3::levelComplete()
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

void Level3::nextLevel()
{
    scene.clear();
    Level4* level4 = new Level4();
    level4->setLevel();
}

void Level3::onLevelComplete()
{
    nextLevel();
}
