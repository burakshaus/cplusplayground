#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QMainWİndow>
#include <QPushButton>
#include <QPLineEdit>
#include <QGridLayout>
#include <QString>

class Calculator: public QMainWindow{
Q_OBJECT

public :
Calculator(QWidget *parent = nullpointer);
~Calculator();

private slots: 
	void onDigitClicked();
	void onOperatorClicked();
	void EqualClicked();
	void onClearClicked();
private :
	QLineEdit *display;
	QPushButton *digitButtons[10];
	QPushButton *addButton;
	QPushButton *subButton;
	QPushButton *mulButton;
	QPushButton *divButton;
	QPushButton *equalButton;
	QPushButton *clearButton;
	double runningTotal; 
	QString pendingOperator;
	bool WaitForNewInput;
};
#endif
