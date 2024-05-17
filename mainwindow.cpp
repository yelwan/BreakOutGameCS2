#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    Level1* level1 = new Level1();
    hide();
}


void MainWindow::on_pushButton_2_clicked()
{
    Level2* level2 = new Level2();
    hide();
}


void MainWindow::on_pushButton_3_clicked()
{
    Level3* level3 = new Level3();
    hide();
}


void MainWindow::on_pushButton_4_clicked()
{
    Level4* level4= new Level4();
    hide();
}


void MainWindow::on_pushButton_5_clicked()
{
    Level5* level5 = new Level5();
    hide();
}

