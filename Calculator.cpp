#include "Calculator.h"

Calculator::Calculator(QWidget *parent) : QMainWindow(parent) {
    // 1. Initialize State
    runningTotal = 0.0;
    waitForNewInput = true;

    // 2. Setup UI Layout
    QWidget *centralWidget = new QWidget(this);
    QGridLayout *layout = new QGridLayout(centralWidget);

    display = new QLineEdit("0");
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    layout->addWidget(display, 0, 0, 1, 4); // Row 0, Col 0, Span 1x4

    // 3. Create & Map Digit Buttons
    for (int i = 0; i < 10; ++i) {
        digitButtons[i] = new QPushButton(QString::number(i));
        connect(digitButtons[i], &QPushButton::clicked, this, &Calculator::onDigitClicked);
    }

    // 4. Create Operator Buttons
    addButton = new QPushButton("+");
    subButton = new QPushButton("-");
    mulButton = new QPushButton("*");
    divButton = new QPushButton("/");
    equalButton = new QPushButton("=");
    clearButton = new QPushButton("C");

    // 5. Connect Operator Slots
    connect(addButton, &QPushButton::clicked, this, &Calculator::onOperatorClicked);
    connect(subButton, &QPushButton::clicked, this, &Calculator::onOperatorClicked);
    connect(mulButton, &QPushButton::clicked, this, &Calculator::onOperatorClicked);
    connect(divButton, &QPushButton::clicked, this, &Calculator::onOperatorClicked);
    connect(equalButton, &QPushButton::clicked, this, &Calculator::onEqualClicked);
    connect(clearButton, &QPushButton::clicked, this, &Calculator::onClearClicked);

    // 6. Finalize Layout
    // (Logic for adding buttons to grid goes here...)
    setCentralWidget(centralWidget);
}

void Calculator::onDigitClicked() {
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString digitValue = clickedButton->text();

    if (display->text() == "0" || waitForNewInput) {
        display->setText(digitValue);
        waitForNewInput = false;
    } else {
        display->setText(display->text() + digitValue);
    }
}

void Calculator::onOperatorClicked() {
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    runningTotal = display->text().toDouble();
    pendingOperator = clickedButton->text();
    waitForNewInput = true;
}

void Calculator::onEqualClicked() {
    double secondOperand = display->text().toDouble();
    double result = 0.0;

    if (pendingOperator == "+") result = runningTotal + secondOperand;
    else if (pendingOperator == "-") result = runningTotal - secondOperand;
    else if (pendingOperator == "*") result = runningTotal * secondOperand;
    else if (pendingOperator == "/") {
        if (secondOperand != 0.0) result = runningTotal / secondOperand;
    }

    display->setText(QString::number(result));
    runningTotal = result;
    waitForNewInput = true;
}

void Calculator::onClearClicked() {
    runningTotal = 0.0;
    pendingOperator.clear();
    display->setText("0");
    waitForNewInput = true;
}

Calculator::~Calculator() {
    // Qt handles deletion of child widgets automatically
}
