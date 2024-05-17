#ifndef LEVEL5_H
#define LEVEL5_H

#include <QObject> // Include necessary header files
#include <QGraphicsScene>
#include <QGraphicsView>
#include "ball.h"
#include "block.h"
#include "player.h"

class Player;
class Block;
class Ball;
class Level5 : public QObject // Declare the Level5 class as a subclass of QObject
{
    Q_OBJECT // Macro required for using signals and slots

public:
    explicit Level5(QObject *parent = nullptr); // Constructor declaration with a QObject pointer as a parameter
    void setLevel(); // Function declaration to set up the level
    bool levelComplete(); // Function declaration to check if the level is complete

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
    int additionalBallNumber = 20; // Variable to adjust the number of additional balls
};

#endif // LEVEL5_H
