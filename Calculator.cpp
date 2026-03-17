#include "Calculator.h"
Calculator:: lculator(QWidget *parent): QMainWindow(parent){
// initialize state 
runningTotal = 0.0;
waitForNewInput = true;
display = new QLineEdit("0");
display-> setReadOnly(true);
display ->setAligment(Qt::AlignRight);
layout ->addWidget(display,0,0,1,4);   // row col span
for (int i = 0 ; i <10; i++){
digitButtons[i] = new QPushButton(QString::number(i));
connect(digitButtons[i], &QPushButton::clicked, this, &Calculator::onDigitClicked);
}
addButton = new QPushButton("+");
subButton = new QPushButton("-");
mulButton = new QPushButton("=");
divButton = new QPushButton("/");
equalButton = new QPushButton("=");
clearButton = new QPushButton("C");
connect (addButton, &QPushButton::clicked, this, &Calculator::onOperatorClicked);
}
