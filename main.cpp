#include <QApplication> // Include necessary header file for QApplication
#include "mainwindow.h" // Include the header file for the MainWindow class

int main(int argc, char *argv[]) {
    QApplication a(argc, argv); // Create a QApplication object

    MainWindow w; // Instantiate the MainWindow object
    w.show(); // Show the MainWindow

    return a.exec(); // Execute the application event loop
}
