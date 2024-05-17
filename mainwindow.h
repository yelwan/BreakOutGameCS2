#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget> // Include necessary header file for QWidget

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget {
    Q_OBJECT // Macro to enable the use of signals and slots in the class

public:
    explicit MainWindow(QWidget *parent = nullptr); // Constructor declaration
    ~MainWindow(); // Destructor declaration

private slots:
    void on_pushButton_clicked(); // Slot declaration for button click event
    void on_pushButton_2_clicked(); // Slot declaration for button click event
    void on_pushButton_3_clicked(); // Slot declaration for button click event
    void on_pushButton_4_clicked(); // Slot declaration for button click event
    void on_pushButton_5_clicked(); // Slot declaration for button click event

private:
    Ui::MainWindow *ui; // Pointer to the UI object
};

#endif // MAINWINDOW_H
