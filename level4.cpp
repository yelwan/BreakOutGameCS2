#include "level4.h"
#include <typeinfo>
#include <QDebug>

Level4::Level4(QObject* parent) : QObject(parent)
{
    setLevel();
    connect(this, &Level4::levelCompleteSignal, this, &Level4::onLevelComplete);
}

void Level4::setLevel()
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

bool Level4::levelComplete()
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

void Level4::nextLevel()
{
    scene.clear();
    Level5* level5 = new Level5();
    level5->setLevel();
}

void Level4::onLevelComplete()
{
    qDebug() << "Level 4 complete. Transitioning to Level 5.";
    nextLevel();
}
