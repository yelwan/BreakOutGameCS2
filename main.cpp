#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QTimer>
#include "ball.h"
#include "block.h"
#include "player.h"
#include "mainwindow.h"
// Main function
int main(int argc, char *argv[])
{
    // Create a QApplication object
    QApplication a(argc, argv);
    MainWindow m;
    m.show();
    // Start the application event loop
    return a.exec();
}
