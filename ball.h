#ifndef BALL_H
#define BALL_H

#include <QGraphicsEllipseItem> // Include necessary header files
#include <QObject>
#include <QTimer>
#include "player.h" // Include the header file for the Player class

class Ball : public QObject, public QGraphicsPixmapItem // Declare the Ball class as a subclass of QObject and QGraphicsPixmapItem
{
    Q_OBJECT // Macro required for using signals and slots

private:
    QTimer *timer; // Timer object for controlling ball movement
    int velocityX; // Horizontal velocity of the ball
    int velocityY; // Vertical velocity of the ball
    Player *player; // Pointer to the Player object
    int restartCount; // Counter to track the number of times the game has been restarted

public:
    explicit Ball(Player*); // Constructor declaration with a pointer to Player as a parameter
    void restartGame(); // Function declaration to restart the game

public slots:
    void move(); // Slot declaration to handle ball movement
};

#endif // BALL_H
