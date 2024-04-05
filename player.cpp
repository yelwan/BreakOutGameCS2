#include "player.h"
#include <QGraphicsRectItem>
Player::Player(QGraphicsRectItem* player) {
    this->player = player;
    this->player->setRect(0, 0, 50, 50);
    this->player->setBrush(Qt::black);
    health = 3; // Initialize health to 3
    score = 0; // Initialize score to 0
    ball = new ball();
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
Player::keyPressEvent(QKeyEvent *event) {
    // *******  Event Handling for the Player ********
    if(event->key()== Qt::Key_Left)
    {
        if(x()>0) // to prevent the player from getting out of the screen
        {
            setPos(x()-10,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(x()+100<800) // to prevent the player from getting out of the screen
            setPos(x()+10,y());
    }

}
