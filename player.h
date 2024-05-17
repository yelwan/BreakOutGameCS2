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
    void keyPressEvent(QKeyEvent *event);
    void decrease();
    void updateText();
    void initializeText(QGraphicsTextItem *textItem, const QString &text, const QColor &color, int x, int y, int T);
    void increase();
    void increaseCoins(int amount);
    void buyWeapon(const QString &weaponName);
    void activateWeapon(const QString &weaponName);
    void deactivateWeapon();

private:
    int score;
    int coins; // Added coins variable
    int playerSpeed;
    int originalWidth;
    QGraphicsTextItem *scoreText;
    QGraphicsTextItem *coinsText; // Added coinsText variable
    QString activeWeapon;
    QTimer weaponTimer;
};

#endif // PLAYER_H
