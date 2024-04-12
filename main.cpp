#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "player.h"
#include "ball.h"
#include "block.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView view;
    QGraphicsScene scene;
    scene.setSceneRect(0,0,800,600);
    Player *player = new Player();
    player->setPixmap(QPixmap("C:/Users/Yehia/Downloads/Rectangle.png"));
    scene.addItem(player);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            Block* block = new Block(j*80,i*20);
            scene.addItem(block);
        }
    }
    Ball *ball = new Ball();
    scene.addItem(ball);
    view.setScene(&scene);
    view.show();
    return a.exec();
}

