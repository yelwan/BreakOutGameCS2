#include "ball.h" // Include the header file for the Ball class
#include <QGraphicsScene> // Include necessary header files
#include <QObject>
#include <QTimer>
#include "block.h" // Include the header file for the Block class
#include "gameover.h" // Include the header file for the GameOver class
#include "player.h" // Include the header file for the Player class

Ball::Ball(Player *player) // Constructor definition for the Ball class, takes a pointer to a Player object as parameter
    : velocityX(5), // Initialize the horizontal velocity to 5
    velocityY(-5), // Initialize the vertical velocity to -5 (moving upward)
    restartCount(0) // Initialize the restart count to 0
{
    QPixmap pix(":/images/Bullet.png"); // Load the ball image from the resource file
    setPixmap(pix.scaled(25, 25)); // Set the pixmap for the ball and scale it to 25x25 pixels
    setPos(375, 475); // Set the initial position of the ball to the bottom center of the scene
    this->player = player; // Set the player pointer to the provided player object
    timer = new QTimer(); // Create a new QTimer object
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(move())); // Connect the timer timeout signal to the move slot
    timer->start(50); // Start the timer with a timeout interval of 50 milliseconds
}

void Ball::restartGame() // Function definition to restart the game
{
    setPos(375, 475); // Reset the position of the ball to the bottom center of the scene
    velocityX = 5; // Reset the horizontal velocity to 5
    velocityY = -5; // Reset the vertical velocity to -5 (moving upward)
}

void Ball::move() // Slot definition for moving the ball
{
    setPos(x() + velocityX, y() + velocityY); // Move the ball according to its current velocity
    QList<QGraphicsItem *> collidingItemsList = collidingItems(); // Get a list of colliding items

    for (int i = 0; i < collidingItemsList.size(); i++) { // Loop through the list of colliding items
        if (typeid(*(collidingItemsList[i])) == typeid(Player)) { // If the colliding item is the player
            velocityX = -velocityX; // Reverse the horizontal velocity
            velocityY = -velocityY; // Reverse the vertical velocity
        } else if (typeid(*(collidingItemsList[i])) == typeid(Block)) { // If the colliding item is a block
            delete collidingItemsList[i]; // Delete the block
            velocityY = -velocityY; // Reverse the vertical velocity
            player->increase(); // Increase the player's score
        }
    }

    if (pos().x() <= 0 || pos().x() + pixmap().width() >= scene()->width()) // Check if the ball hits the left or right wall
        velocityX = -velocityX; // Reverse the horizontal velocity

    if (pos().y() <= 0 || pos().y() + pixmap().height() >= scene()->height()) // Check if the ball hits the top or bottom wall
        velocityY = -velocityY; // Reverse the vertical velocity

    if (pos().y() > player->pos().y()) { // Check if the ball falls below the player's position
        restartCount++; // Increment the restart count

        if (restartCount >= 3) { // If the restart count exceeds 3
            // Hide the game scene and show the game over screen
            QGraphicsScene *currentScene = scene();
            if (currentScene) {
                currentScene->setSceneRect(0, 0, 0, 0); // Hide the scene
                currentScene->clear(); // Clear the scene content
            }

            GameOver *gameOverScreen = new GameOver; // Create a new GameOver object
            gameOverScreen->show(); // Show the game over screen
        } else {
            restartGame(); // Otherwise, restart the game
        }
    }
}
