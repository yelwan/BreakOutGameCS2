#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QTimer>
#include "ball.h"
#include "block.h"
#include "player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView view;
    QGraphicsScene scene;
    scene.setSceneRect(0, 0, 800, 600);
    Player *player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene.addItem(player);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            qreal blockX = j * 80;
            qreal blockY = i * 20;
            Block *block = new Block(blockX, blockY);
            scene.addItem(block);
        }
    }
    Ball *ball = new Ball();
    scene.addItem(ball);
    view.setScene(&scene);
    view.show();
    return a.exec();
}
