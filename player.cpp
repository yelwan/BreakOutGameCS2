#include "player.h"
#include <QGraphicsPixmapItem>
#include <QTimer>
#include "gameover.h"
Player::Player() : score(0), playerSpeed(10)
{
    QPixmap pix("/Users/daliakadry/Downloads/Rectangle.png");
    setPixmap(pix.scaled(25,25));
    setPos(375,555);
    score = 0; // Initialize score to 0


    // Create QGraphicsTextItem for score
    scoreText = new QGraphicsTextItem();
    scoreText->setPlainText(QString("Score: ") + QString::number(score));
    scoreText->setDefaultTextColor(Qt::blue); // Set text color to blue
    scoreText->setPos(0, 300); // Position below health text
    scene()->addItem(scoreText); // Add to the scene
}

void Player::keyPressEvent(QKeyEvent *event)
{
    initializeText(scoreText, "Score: ", Qt::blue, 60, 80, score);
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
    updateText();
}
void Player::updateText() {
    scoreText->setPlainText("Score: " + QString::number(score));
}

void Player::initializeText(QGraphicsTextItem* textItem, const QString& text, const QColor& color, int x, int y, int T) {
    textItem->setPlainText(text + QString::number(T));
    textItem->setDefaultTextColor(color);
    textItem->setPos(x, y);
    scene()->addItem(textItem);
}


void Player::increase() {
    score++;
    scoreText->setPlainText("Score: " + QString::number(score));
}
