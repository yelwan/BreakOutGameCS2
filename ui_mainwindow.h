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

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        pushButton = new QPushButton(MainWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 30, 100, 32));
        pushButton_2 = new QPushButton(MainWindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 90, 100, 32));
        pushButton_3 = new QPushButton(MainWindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 180, 100, 32));
        pushButton_4 = new QPushButton(MainWindow);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(170, 30, 100, 32));
        pushButton_5 = new QPushButton(MainWindow);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(180, 100, 100, 32));

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Level1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Level2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Level3", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Level4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Level5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
