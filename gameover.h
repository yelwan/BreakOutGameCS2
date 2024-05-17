#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog> // Include necessary header files
#include <QLabel>

namespace Ui {
class GameOver;
}

class GameOver : public QDialog // Declare the GameOver class as a subclass of QDialog
{
    Q_OBJECT // Macro required for using signals and slots

public:
    explicit GameOver(QWidget *parent = nullptr); // Constructor declaration with a QWidget pointer as a parameter

private:
    QLabel *gameOverLabel; // Pointer to the QLabel object for displaying "Game Over"
};

#endif // GAMEOVER_H
