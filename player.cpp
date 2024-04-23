#include "player.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <iostream>
using namespace std;
Player::Player() :  health(3), score(0), playerSpeed(10)
{
    QPixmap pix("/Users/daliakadry/Downloads/Rectangle.png");
    setPixmap(pix.scaled(25,25));
   setPos(375,555);
    health = 3; // Initialize health to 3
    score = 0; // Initialize score to 0
    // Create QGraphicsTextItem for health
    healthText = new QGraphicsTextItem();
    healthText->setPlainText(QString("Health: ") + QString::number(health));
    healthText->setDefaultTextColor(Qt::red); // Set text color to red
    scene()->addItem(healthText); // Add to the scene

    // Create QGraphicsTextItem for score
    scoreText = new QGraphicsTextItem();
    scoreText->setPlainText(QString("Score: ") + QString::number(score));
    scoreText->setDefaultTextColor(Qt::blue); // Set text color to blue
    scoreText->setPos(0, 20); // Position below health text
    scene()->addItem(scoreText); // Add to the scene
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() > 0)
        {
            setPos(x() - playerSpeed, y());
        }
    }
    if (event->key() == Qt::Key_Right)
    {

        if (pos().x() + pixmap().width() < scene()->width())
        {
            setPos(x() + playerSpeed, y());
        }
    }
}
