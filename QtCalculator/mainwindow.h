#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QString>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private slots:
    void digitClicked();
    void operatorClicked();
    void equalClicked();
    void clearClicked();

private:
    // UI Elements
    QLineEdit *display;
    QWidget *m_centralWidget;
    QGridLayout *m_layout;

    // Logic Variables
    double firstNum = 0;
    QString pendingOp = "";
    bool waitingForSecondNum = false;
};

#endif // MAINWINDOW_H
