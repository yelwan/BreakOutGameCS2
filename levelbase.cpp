#include "levelbase.h"

LevelBase::LevelBase(QObject *parent) : QObject(parent)
{
    // Initialize member variables
    scene = new QGraphicsScene(this); // Create a new QGraphicsScene
    view = new QGraphicsView(scene);  // Create a new QGraphicsView with the scene

    // Set up the view
    view->setRenderHint(QPainter::Antialiasing); // Enable antialiasing for smoother graphics
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // Disable horizontal scroll bar
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // Disable vertical scroll bar

    // Set the view's background color (optional)
    scene->setBackgroundBrush(Qt::black); // Set the background color to black
}

LevelBase::~LevelBase()
{
    // Clean up allocated resources
    delete view;
    delete scene;
}

QGraphicsScene* LevelBase::getScene() const
{
    return scene;
}

QGraphicsView* LevelBase::getView() const
{
    return view;
}
