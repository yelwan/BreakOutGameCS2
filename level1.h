#ifndef LEVEL1_H
#define LEVEL1_H

#include <QObject> // Include necessary header files
#include <QGraphicsScene>
#include <QGraphicsView>
#include "ball.h"
#include "block.h"
#include "player.h"
#include "level2.h" // Include the header file for Level 2

class Player;
class Block;
class Ball;
class Level1 : public QObject // Declare the Level1 class as a subclass of QObject
{
    Q_OBJECT // Macro required for using signals and slots

public:
    explicit Level1(QObject *parent = nullptr); // Constructor declaration with a QObject pointer as a parameter
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
    int additionalBallNumber = 0; // Variable to adjust the number of additional balls
};

#endif // LEVEL1_H
