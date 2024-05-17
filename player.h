#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include <QTimer>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *)override; // Override the keyPressEvent function
    void decrease();
    void updateText();
    void initializeText(QGraphicsTextItem *textItem, const QString &text, const QColor &color, int x, int y, int T);
    void increase();
    void increaseCoins(int amount);
    void buyWeapon(const QString &weaponName);
    void activateWeapon(const QString &weaponName); // Declaration of the activateWeapon function
    void deactivateWeapon(); // Declaration of the deactivateWeapon function
private:
    int score; // Member variable to store the score
    int coins; // Member variable to store the number of coins
    int playerSpeed; // Member variable to store the speed of the player
    int originalWidth; // Member variable to store the original width of the player
    QGraphicsTextItem *scoreText; // Pointer to a QGraphicsTextItem object to display the score
    QGraphicsTextItem *coinsText; // Pointer to a QGraphicsTextItem object to display the number of coins
    QString activeWeapon; // String to store the name of the active weapon
    QTimer weaponTimer; // Timer to control the duration of the active weapon
};
#endif // PLAYER_H
