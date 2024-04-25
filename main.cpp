#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QTimer>
#include "ball.h"
#include "block.h"
#include "player.h"

// Main function
int main(int argc, char *argv[])
{
    // Create a QApplication object
    QApplication a(argc, argv);

    // Create a QGraphicsView object
    QGraphicsView view;

    // Create a QGraphicsScene object
    QGraphicsScene scene;

    // Set the scene rectangle (dimensions of the scene)
    scene.setSceneRect(0, 0, 800, 600);

    // Create a new Player object
    Player *player = new Player();

    // Allow the player item to receive keyboard focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);

    // Set focus to the player item
    player->setFocus();

    // Add the player item to the scene
    scene.addItem(player);

    // Loop to create blocks (5 rows x 10 columns)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            qreal blockX = j * 80;  // Calculate x-coordinate for block
            qreal blockY = i * 20;  // Calculate y-coordinate for block
            Block *block = new Block(blockX, blockY); // Create a new Block object
            scene.addItem(block);   // Add the block to the scene
        }
    }

    // Create a new Ball object with the player as its parent
    Ball *ball = new Ball(player);

    // Add the ball to the scene
    scene.addItem(ball);

    // Set the scene for the QGraphicsView
    view.setScene(&scene);

    // Show the QGraphicsView
    view.show();

    // Start the application event loop
    return a.exec();
}
