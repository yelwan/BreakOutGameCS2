#include "gameover.h" // Include the header file for the GameOver class
#include <QLabel> // Include necessary header files
#include <QVBoxLayout>

GameOver::GameOver(QWidget *parent) // Constructor definition for the GameOver class, takes a QWidget pointer as parameter
    : QDialog(parent) // Call the base class constructor with the provided parent
{
    QLabel *gameOverLabel = new QLabel("Game Over", this); // Create a new QLabel object with text "Game Over" and set the parent to this dialog
    QFont font("Arial", 24, QFont::Bold); // Create a QFont object with specified font family, size, and weight
    gameOverLabel->setFont(font); // Set the font of the QLabel
    gameOverLabel->setAlignment(Qt::AlignCenter); // Set the text alignment of the QLabel to center

    QVBoxLayout *layout = new QVBoxLayout(this); // Create a new QVBoxLayout object with this dialog as parent
    layout->addWidget(gameOverLabel); // Add the gameOverLabel to the layout
    setLayout(layout); // Set the layout of the dialog to the QVBoxLayout
}
