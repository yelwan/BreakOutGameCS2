// level1.cpp
#include "level1.h"
#include <typeinfo>
#include <QDebug>

Level1::Level1(QObject* parent) : QObject(parent)
{
    setLevel();
    connect(this, &Level1::levelCompleteSignal, this, &Level1::onLevelComplete);
}

void Level1::setLevel()
{
    // Set the scene rectangle (dimensions of the scene)
    scene.setSceneRect(0, 0, 800, 600);

    // Create a new Player object
    player = new Player();

    // Allow the player item to receive keyboard focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);

    // Set focus to the player item
    player->setFocus();

    // Add the player item to the scene
    scene.addItem(player);

    // Loop to create blocks (5 rows x 10 columns)
    for (int i = 0; i < 5 + additionalBallNumber; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            qreal blockX = j * 80;  // Calculate x-coordinate for block
            qreal blockY = i * 20;  // Calculate y-coordinate for block
            block = new Block(blockX, blockY); // Create a new Block object
            scene.addItem(block);   // Add the block to the scene
        }
    }

    // Create a new Ball object with the player as its parent
    ball = new Ball(player);

    // Add the ball to the scene
    scene.addItem(ball);

    // Set the scene for the QGraphicsView
    view.setScene(&scene);

    // Show the QGraphicsView
    view.show();
}

bool Level1::levelComplete()
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

void Level1::nextLevel()
{
    scene.clear();
    Level2* level2 = new Level2();
}

void Level1::onLevelComplete()
{
    nextLevel();
}
