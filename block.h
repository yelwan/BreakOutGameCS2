#ifndef BLOCK_H
#define BLOCK_H

#include <QGraphicsRectItem> // Include necessary header files

class Block : public QObject, public QGraphicsPixmapItem // Declare the Block class as a subclass of QObject and QGraphicsPixmapItem
{
    Q_OBJECT // Macro required for using signals and slots

public:
    Block(qreal x, qreal y); // Constructor declaration with x and y coordinates as parameters
};

#endif // BLOCK_H
