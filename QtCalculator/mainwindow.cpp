#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    m_centralWidget = new QWidget(this);
    setCentralWidget(m_centralWidget);
    m_layout = new QGridLayout(m_centralWidget);

    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setFixedHeight(60);
    // Explicit colors: Black text on White background for high visibility
    display->setStyleSheet("font-size: 24pt; padding: 10px; color: black; background-color: white; border: 2px solid #333;");
    m_layout->addWidget(display, 0, 0, 1, 4);

    // Number Buttons 1-9
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

    const char* opLabels[] = {"/", "*", "-", "+"};
    for (int i = 0; i < 4; ++i) {
        QPushButton *btn = new QPushButton(opLabels[i]);
        btn->setMinimumHeight(60);
        btn->setStyleSheet("font-weight: bold; background-color: black;");
        m_layout->addWidget(btn, i + 1, 3);
        connect(btn, &QPushButton::clicked, this, &MainWindow::operatorClicked);
    }

    setWindowTitle("Burak's Full Calc");
    resize(350, 480);
}

void MainWindow::digitClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    // If screen says "0" or "Error", clear it before adding the first real number
    if (display->text() == "0" || display->text() == "Error") {
        display->clear();
    }
    
    // Append the number to the current text
    display->setText(display->text() + button->text());
}

void MainWindow::operatorClicked() {
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    // Don't allow starting with an operator (except maybe minus, but let's keep it simple)
    if (display->text() == "0" || display->text().isEmpty()) return;

    // If there is already an operator, don't add another one
    if (!pendingOp.isEmpty()) return;

    // Save the first number and the operator
    firstNum = display->text().toDouble();
    pendingOp = button->text();

    // Add the operator to the screen (e.g., "4+")
    display->setText(display->text() + pendingOp);
}

void MainWindow::equalClicked() {
    if (pendingOp.isEmpty()) return;

    QString currentText = display->text();
    
    // Find the second number by looking at everything AFTER the operator
    // Example: If text is "4+12", it looks for the string after the "+"
    int opIndex = currentText.indexOf(pendingOp);
    QString secondNumStr = currentText.mid(opIndex + 1);

    if (secondNumStr.isEmpty()) return;

    double secondNum = secondNumStr.toDouble();
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

    // Show the result
    display->setText(QString::number(result, 'g', 15));
    
    // Clear the operator so we can start a new calculation
    pendingOp = "";
}

void MainWindow::clearClicked() {
    display->setText("0");
    firstNum = 0;
    pendingOp = "";
}
