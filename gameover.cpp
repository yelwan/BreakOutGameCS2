
#include "gameover.h"
#include <QLabel>
#include <QVBoxLayout>

GameOver::GameOver(QWidget *parent)
    : QDialog(parent)
{
    QLabel *gameOverLabel = new QLabel("Game Over", this);
    QFont font("Arial", 24, QFont::Bold);
    gameOverLabel->setFont(font);
    gameOverLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(gameOverLabel);
    setLayout(layout);
}

GameOver::~GameOver() {}
