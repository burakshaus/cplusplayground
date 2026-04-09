#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    layout = new QGridLayout(centralWidget);

    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setFixedHeight(50);
    layout->addWidget(display, 0, 0, 1, 4);

    QPushButton *btn7 = new QPushButton("7");
    layout->addWidget(btn7, 1, 0);

    // Connect the button (Optional for this test)
    connect(btn7, &QPushButton::clicked, this, &MainWindow::digitClicked);

    setWindowTitle("Qt Calculator");
    resize(300, 400);
}

void MainWindow::digitClicked() {
    // Just a placeholder for now
    display->setText("7"); 
}
