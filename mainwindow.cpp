#include "mainwindow.h" // Include the header file for the MainWindow class
#include "ui_mainwindow.h" // Include the header file for the UI class
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow) { // Constructor definition
    ui->setupUi(this); // Setup the UI
}

MainWindow::~MainWindow() { // Destructor definition
    delete ui; // Delete the UI object
}

void MainWindow::on_pushButton_clicked() { // Function definition for button click event
    // Instantiate Level1 object and hide the current window
    Level1* level1 = new Level1();
    hide();
}

// Similar function definitions for other button click events
void MainWindow::on_pushButton_2_clicked() {
    Level2* level2 = new Level2();
    hide();
}

void MainWindow::on_pushButton_3_clicked() {
    Level3* level3 = new Level3();
    hide();
}

void MainWindow::on_pushButton_4_clicked() {
    Level4* level4 = new Level4();
    hide();
}

void MainWindow::on_pushButton_5_clicked() {
    Level5* level5 = new Level5();
    hide();
}
