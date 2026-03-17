#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QString>

class Calculator : public QMainWindow {
G_OBJECT // macro reqired for Qy signals / slots
public slots: 
void onDigitClicked(); // handles buttons 
void onOperatorClicked(); // handles operators
void OnEqualClicked(); // handles = 
void onClearClicked(); // handles C
}
private:
QLineEdit *display;
QPushButton *digitButtons[10];
QPushButton *addButton;
QPushButton *subButton;
QPushButton *mulButon;
QPushButton *divButton;
QPushButton *equalButton;
QPushButton *clearButton;

double runningTotal; // stores the first number
QString pendingOperator; // stores the operation string
bool waitForNewInput; // flag to to clear display for next entry
};
#endif // calculator_H
