#include "block.h" // Include the header file for the Block class

Block::Block(qreal x, qreal y) // Constructor definition for the Block class, takes x and y coordinates as parameters
{
    QPixmap pix(":/images/block.png"); // Load the block image from the resource file
    setPixmap(pix.scaled(25, 25)); // Set the pixmap for the block and scale it to 25x25 pixels
    setPos(x, y); // Set the position of the block to the specified coordinates
}
