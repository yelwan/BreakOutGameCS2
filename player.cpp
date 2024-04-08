#include "player.h"
#include "ball.h"
#include <QGraphicsRectItem>
#include <QKeyEvent>
Player::Player(QGraphicsRectItem* player) {
    this->player = player;
    this->player->setRect(0, 0, 50, 50);
    this->player->setBrush(Qt::black);
    health = 3; // Initialize health to 3
    score = 0; // Initialize score to 0
    // Create QGraphicsTextItem for health
    healthText = new QGraphicsTextItem();
    healthText->setPlainText(QString("Health: ") + QString::number(health));
    healthText->setDefaultTextColor(Qt::red); // Set text color to red
    scene()->addItem(healthText);
    // Create QGraphicsTextItem for score
    scoreText = new QGraphicsTextItem();
    scoreText->setPlainText(QString("Score: ") + QString::number(score));
    scoreText->setDefaultTextColor(Qt::blue); // Set text color to blue
    scoreText->setPos(0, 20); // Position below health text
    scene()->addItem(scoreText); // Add to the scene
}
void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        if (x() > 0) { // Check if player's position is within the left boundary
            setPos(x() - 10, y()); // Move player left by 10 units
        }

    } else if (event->key() == Qt::Key_Right) {
        if (x() + 100 < 800) { // Check if player's position + width is within the right boundary (assuming player width is 100 and scene width is 800)
            setPos(x() + 10, y()); // Move player right by 10 units
        }
    }
}
