#include "QGraphicsView"
#include <QApplication>
#include "player.h"
#include "ball.h"
#include "block.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create the View
    QGraphicsView view;
    view.setFixedSize(800, 600);

    // Create the Scene
    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 800, 600);

    // Create and add Score Text Item
    QGraphicsTextItem *scoreText = new QGraphicsTextItem();
    scoreText->setFont(QFont("times", 16));
    scoreText->setDefaultTextColor(Qt::blue);
    scoreText->setPlainText("Score: " + QString::number(0));
    scoreText->setPos(700, 10);
    scene.addItem(scoreText);

    // Create Player
    QGraphicsRectItem* play = new QGraphicsRectItem();
    Player *player = new Player(play);
    scene.addItem(player);

    // Ball
    QGraphicsEllipseItem* circle= new QGraphicsEllipseItem();
    Ball *ball= new Ball(circle);
    QGraphicsRectItem* blocks = new QGraphicsRectItem();
    // Blocks
    for (qreal i = 0; i < 5; ++i) {
        for (qreal j = 0; j < 10; ++j) {
            Block *block = new Block(j,i,blocks);
            block->setPos(j * 80, i * 20); // Adjust position as needed
            scene.addItem(block);
        }
    }

    view.setScene(&scene);
    view.show();

    return a.exec();
}
