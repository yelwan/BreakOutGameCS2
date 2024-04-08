#include "Player.h"
#include "ball.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsScene>

Player::Player(QGraphicsRectItem *parent) : QGraphicsRectItem(parent), health(3), score(0) {
    // Initialize player rectangle
    player = parent;
    player->setRect(0, 0, 50, 50);
    player->setBrush(Qt::black);

    // Add player to the scene
    scene()->addItem(this);

    // Create QGraphicsTextItem for health
    healthText = new QGraphicsTextItem();

    scene()->addItem(healthText);

    // Create QGraphicsTextItem for score
    scoreText = new QGraphicsTextItem();

    scoreText->setPos(0, 20); // Position below health text
    scene()->addItem(scoreText);
}

void Player::keyPressEvent(QKeyEvent *event) {
    int playerSpeed = 10; // Adjust as needed

    if (event->key() == Qt::Key_Left) {
        // Move player left
        if (x() > 0) {
            setPos(x() - playerSpeed, y());
        }
    } else if (event->key() == Qt::Key_Right) {
        // Move player right
        if (x() + player->rect().width() < scene()->width()) {
            setPos(x() + playerSpeed, y());
        }
    }
}


