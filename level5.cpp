#include "level5.h"
#include <typeinfo>
#include <QDebug>

Level5::Level5(QObject* parent) : QObject(parent)
{
    setLevel();
    connect(this, &Level5::levelCompleteSignal, this, &Level5::onLevelComplete);
}

void Level5::setLevel()
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

bool Level5::levelComplete()
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

void Level5::nextLevel()
{
    qDebug() << "All levels complete!";
    // Logic for when all levels are completed
}

void Level5::onLevelComplete()
{
    qDebug() << "Level 5 complete. All levels completed!";
    nextLevel();
}
