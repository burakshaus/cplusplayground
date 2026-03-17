#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QString>

class Calculator: public QMainWindow{
Q_OBJECT

public :
Calculator(QWidget *parent = nullptr);
~Calculator();

private slots: 
	void onDigitClicked();
	void onOperatorClicked();
	void onEqualClicked();
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
