#ifndef LEVEL2_H
#define LEVEL2_H

#include <QObject> // Include necessary header files
#include <QGraphicsScene>
#include <QGraphicsView>
#include "ball.h"
#include "block.h"
#include "player.h"
#include "level3.h" // Include the header file for Level 3

class Player;
class Block;
class Ball;
class Level2 : public QObject // Declare the Level2 class as a subclass of QObject
{
    Q_OBJECT // Macro required for using signals and slots

public:
    explicit Level2(QObject *parent = nullptr); // Constructor declaration with a QObject pointer as a parameter
    void setLevel(); // Function declaration to set up the level
    bool levelComplete(); // Function declaration to check if the level is complete
    void nextLevel(); // Function declaration to transition to the next level

signals:
    void levelCompleteSignal(); // Signal declaration for when the level is complete

private slots:
    void onLevelComplete(); // Slot declaration for when the level is complete

private:
    QGraphicsScene scene; // Scene for the level
    QGraphicsView view; // View for the level
    Player* player; // Pointer to the Player object
    Ball* ball; // Pointer to the Ball object
    Block* block; // Pointer to the Block object
    int additionalBallNumber = 5; // Variable to adjust the number of additional balls
};

#endif // LEVEL2_H
