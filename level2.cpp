#include "level2.h" // Include the corresponding header file
#include <typeinfo> // Include necessary header files
#include <QDebug>

Level2::Level2(QObject* parent) : QObject(parent) // Constructor definition with QObject pointer as a parameter
{
    view.setFocusPolicy(Qt::StrongFocus); // Set focus policy for the view
    view.setFocus(); // Set focus to the view
    setLevel(); // Call the function to set up the level
    connect(this, &Level2::levelCompleteSignal, this, &Level2::onLevelComplete); // Connect the level complete signal to its slot
}

void Level2::setLevel() // Definition of the function to set up the level
{
    scene.setSceneRect(0, 0, 800, 600); // Set the scene rectangle

    player = new Player(); // Create a new Player object
    player->setFlag(QGraphicsItem::ItemIsFocusable); // Allow the player to receive keyboard focus
    scene.addItem(player); // Add the player to the scene
    player->setFocus(); // Set focus to the player

    for (int i = 0; i < 5 + additionalBallNumber; i++) // Loop to create blocks
    {
        for (int j = 0; j < 10; j++)
        {
            qreal blockX = j * 80; // Calculate x-coordinate for block
            qreal blockY = i * 20; // Calculate y-coordinate for block
            block = new Block(blockX, blockY); // Create a new Block object
            scene.addItem(block); // Add the block to the scene
        }
    }

    ball = new Ball(player); // Create a new Ball object with the player as its parent
    scene.addItem(ball); // Add the ball to the scene

    view.setScene(&scene); // Set the scene for the QGraphicsView
    view.show(); // Show the QGraphicsView
}

bool Level2::levelComplete() // Definition of the function to check if the level is complete
{
    foreach (QGraphicsItem* item, scene.items()) // Iterate through items in the scene
    {
        if (typeid(*item) == typeid(Block)) // Check if the item is a block
        {
            return false; // Return false if there are blocks remaining
        }
    }

    emit levelCompleteSignal(); // Emit the level complete signal
    return true; // Return true if there are no blocks remaining
}

void Level2::nextLevel() // Definition of the function to transition to the next level
{
    scene.clear(); // Clear the scene
    Level3* level3 = new Level3(); // Create a new Level3 object
}

void Level2::onLevelComplete() // Definition of the function to handle level completion
{
    nextLevel(); // Call the function to transition to the next level
}
