#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // 1. Setup the Central Widget and Layout
    m_centralWidget = new QWidget(this);
    setCentralWidget(m_centralWidget);
    m_layout = new QGridLayout(m_centralWidget);

    // 2. Display Setup
    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setFixedHeight(60);
    // STYLESHEET: Force white background and black text so it's visible on Mint
    display->setStyleSheet("font-size: 26pt; padding: 10px; color: black; background-color: white; border: 2px solid #555;");
    m_layout->addWidget(display, 0, 0, 1, 4);

    // 3. Numbers 1-9
    const char* numLabels[3][3] = {
        {"7", "8", "9"},
        {"4", "5", "6"},
        {"1", "2", "3"}
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            QPushButton *btn = new QPushButton(numLabels[i][j]);
            btn->setMinimumHeight(60);
            m_layout->addWidget(btn, i + 1, j);
            connect(btn, &QPushButton::clicked, this, &MainWindow::digitClicked);
        }
    }

    // 4. Bottom Row (C, 0, =)
    QPushButton *btnC = new QPushButton("C");
    QPushButton *btn0 = new QPushButton("0");
    QPushButton *btnEq = new QPushButton("=");
    
    btnC->setMinimumHeight(60);
    btn0->setMinimumHeight(60);
    btnEq->setMinimumHeight(60);

    m_layout->addWidget(btnC, 4, 0);
    m_layout->addWidget(btn0, 4, 1);
    m_layout->addWidget(btnEq, 4, 2);

    connect(btnC, &QPushButton::clicked, this, &MainWindow::clearClicked);
    connect(btn0, &QPushButton::clicked, this, &MainWindow::digitClicked);
    connect(btnEq, &QPushButton::clicked, this, &MainWindow::equalClicked);

    // 5. Operators (+, -, *, /)
    const char* opLabels[] = {"/", "*", "-", "+"};
    for (int i = 0; i < 4; ++i) {
        QPushButton *btn = new QPushButton(opLabels[i]);
        btn->setMinimumHeight(60);
        // Style operators differently so they stand out
        btn->setStyleSheet("font-weight: bold; background-color: #f0f0f0;");
        m_layout->addWidget(btn, i + 1, 3);
        connect(btn, &QPushButton::clicked, this, &MainWindow::operatorClicked);
    }

    setWindowTitle("Burak's Calculator");
    resize(350, 480);
}

// Slot for 0-9
void MainWindow::digitClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString digitValue = button->text();

    // If the display currently shows "0" or an operator, replace it with the number
    if (display->text() == "0" || waitingForSecondNum) {
        display->setText(digitValue);
        waitingForSecondNum = false;
    } else {
        display->setText(display->text() + digitValue);
    }
}

// Slot for +, -, *, /
void MainWindow::operatorClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    // If there was a previous math operation waiting (e.g. 5 + 5 +), calculate it first
    if (!pendingOp.isEmpty() && !waitingForSecondNum) {
        equalClicked();
    }

    firstNum = display->text().toDouble();
    pendingOp = button->text();
    
    // Show the operator on the screen so the user knows it's clicked
    display->setText(pendingOp); 
    waitingForSecondNum = true;
}

// Slot for =
void MainWindow::equalClicked() {
    if (pendingOp.isEmpty()) return;

    double secondNum = display->text().toDouble();
    double result = 0;

    if (pendingOp == "+") result = firstNum + secondNum;
    else if (pendingOp == "-") result = firstNum - secondNum;
    else if (pendingOp == "*") result = firstNum * secondNum;
    else if (pendingOp == "/") {
        if (secondNum != 0) result = firstNum / secondNum;
        else {
            display->setText("Error");
            pendingOp = "";
            return;
        }
    }

    // Show result
    display->setText(QString::number(result, 'g', 15));
    
    // Reset for next calculation
    pendingOp = "";
    waitingForSecondNum = true; 
}

void MainWindow::clearClicked() {
    display->setText("0");
    firstNum = 0;
    pendingOp = "";
    waitingForSecondNum = false;
}
