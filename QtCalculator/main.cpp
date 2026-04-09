#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) { // Make sure this says argv
    QApplication app(argc, argv); // Fixed 'arv' to 'argv'
    MainWindow window;
    window.show();
    return app.exec();
}
