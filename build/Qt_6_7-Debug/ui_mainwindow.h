/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(413, 300);
        pushButton = new QPushButton(MainWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 200, 100, 32));
        pushButton_2 = new QPushButton(MainWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 230, 100, 32));
        pushButton_3 = new QPushButton(MainWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 260, 100, 32));
        pushButton_4 = new QPushButton(MainWindow);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(110, 200, 100, 32));
        pushButton_5 = new QPushButton(MainWindow);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(110, 230, 100, 32));
        plainTextEdit = new QPlainTextEdit(MainWindow);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(40, 10, 261, 141));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Level 1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Level 2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Level 3", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Level 4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Level 5", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("MainWindow", "Welcome to the Breakout Game! Here's the scoop: for every 10 points you earn, you'll snag yourself a shiny coin. And guess what? Each coin you collect rewards you with an extra 10 seconds of wider paddle goodness. Just hit 'W' to activate this perk and keep the momentum going! ENJOY!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
