include "Calcualtor.h"
Calculator::Calculator(QWidget *parent):QMainWindow(parent){
	runningTotal = 0.0;
	WaitForNewInput = true;
	QWidget *centralWidget = new QWidget(this);
	QGridLayout *layout = new QGridLayout(centralWidget);
	display = new QLineEdit("0");
	display -> setReadOnly(true);
	display->setAlignment(Qt::AlignRight);
	layout->addWidget(display,0,0,1,4);

	for(int i = 0; i<10; i++){
		digitButtons[i] = connect(DigitButton[i],&QPushButton::clicked,this,&Calculator::onDigitClicked);
	}
	addButton = new QPushButton("+");
	subButton = neww QPushButton("-");
	mulButton = new QPushButton("*");
	divButton = new QPushButton("/");
	equalButton = new QPushButton("=");
	clearButton = new QPushButton("C");
	
	connect(addButton,&QPushButton::clicked, this, &Calculator::onOperatorClicked);
	connect(subButton , &QPushButton::clicked, this, &Calculator::onOperatorClicked);
	connect (mulButton, & QPushButton::clicked, this, &Calculator::onOperatorClicked);
	connect(divButton, & QPushButton::clicked,this, &Calculator::onOperatorClicked);
	connect(equalButton, &QPushButton::clicked,this, &Calculator::onEqualClicked);
	connect(clearButton, &QPushButton::clicked, this, &Calculator::onClearClicked);
	setCentralWidget(centralWidget);
}

void Calculator::onDigitClicked(){
QPushButton *clickedButton = gobject_cast<QPushButton *>(sender());
QString digitValue = clickedButton->text();
if(display->text() == "0"){
display->setText(digitValue);
waitForNewInput = false;
}else{
display->setText(display->text()+digitValue);
}

void Calculator::onEqualClicked(){
double secondOperand = display-> text().toDouble;
double result = 0.0;
if(pendingOperator == "+") result = runningTotal+seconOperand;
else if(pendingOperator =="*") result = runningTotal*secondOperand;
else if(pendingOperator == "-") result = runningTotal -secondOperand;
else if(pendingOperator == "/"){
if(secondOperand != 0) result =runningTotal/secondOperand; 
}

}

Calculator::onClearClicked(){
runningTotal = 0.0;
pendingOperator.clear();
display->setText("0");
WaitForNewInput = true;
}

Calculator:: |Calculator(){

}
}
