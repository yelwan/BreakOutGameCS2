#include "player.h"
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>
#include "gameover.h"

// Constructor for the Player class
Player::Player()
    : score(0), playerSpeed(15), coins(0), originalWidth(25) // Initialize original width
{

    QPixmap pix(":/images/Player.png");
    setPixmap(pix.scaled(originalWidth, 25));
    setPos(375, 555);
    // Initialize score text
    scoreText = new QGraphicsTextItem();
    scoreText->setPlainText(QString("Score: ") + QString::number(score));
    scoreText->setDefaultTextColor(Qt::blue);
    scoreText->setPos(0, 300);
    scene()->addItem(scoreText);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    coinsText = new QGraphicsTextItem();
    coinsText->setPlainText(QString("Coins: ") + QString::number(coins));
    coinsText->setDefaultTextColor(Qt::green);
    coinsText->setPos(0, 320);  // Position it below the score text
    scene()->addItem(coinsText); // Add coinsText to the scene

    connect(&weaponTimer, &QTimer::timeout, this, &Player::deactivateWeapon);
}

// Function to increase score and update score text
void Player::increase()
{
    score++;
    scoreText->setPlainText("Score: " + QString::number(score));

    // Example: Earn a coin for every 10 points
    if (score % 10 == 0) {
        increaseCoins(1);
    }
}

// Function to increase coins and update coins text
void Player::increaseCoins(int amount)
{
    coins += amount;
    coinsText->setPlainText("Coins: " + QString::number(coins));
}

// Function to buy a weapon
void Player::buyWeapon(const QString &weaponName)
{
    // Weapon costs 1 coin
    if (coins >= 1) {
        coins -= 1;
        coinsText->setPlainText("Coins: " + QString::number(coins));
        activateWeapon(weaponName);
    }
}

// Function to activate a weapon
void Player::activateWeapon(const QString &weaponName)
{
    activeWeapon = weaponName;
    if (weaponName == "IncreaseWidth") {
        setPixmap(pixmap().scaled(originalWidth * 2, 25)); // Double the width
    }

    weaponTimer.start(10000); // Weapon lasts for 10 seconds
}

// Function to deactivate weapon effects
void Player::deactivateWeapon()
{
    if (activeWeapon == "IncreaseWidth") {
        setPixmap(pixmap().scaled(originalWidth, 25)); // Reset width to original
    }

    activeWeapon.clear();
    weaponTimer.stop();
}

// Key press  handler for the Player class
void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        if (pos().x() > 0) {
            setPos(x() - playerSpeed, y());
        }
    }

    if (event->key() == Qt::Key_Right) {
        if (pos().x() + pixmap().width() < scene()->width()) {
            setPos(x() + playerSpeed, y());
        }
    }

    // Test: Buy and activate "IncreaseWidth" weapon with the "W" key
    if (event->key() == Qt::Key_W) {
        buyWeapon("IncreaseWidth");
    }
    initializeText(scoreText, "Score: ", Qt::blue, 60, 250, score);
    initializeText(coinsText, "Coins: ", Qt::green, 60, 300, coins);
    updateText();
}

// Update the score text item with the current score
void Player::updateText()
{
    scoreText->setPlainText("Score: " + QString::number(score));
    coinsText->setPlainText("Coins: " + QString::number(coins));
}

// Helper function to initialize a QGraphicsTextItem with specified properties
void Player::initializeText(QGraphicsTextItem *textItem, const QString &text, const QColor &color, int x, int y, int T)
{
    textItem->setPlainText(text + QString::number(T));
    textItem->setDefaultTextColor(color);
    textItem->setPos(x, y);
    scene()->addItem(textItem);
}
