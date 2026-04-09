#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

class MainWindow : public QMainWindow {
    Q_OBJECT // Fixed spelling here

public:
    MainWindow(QWidget *parent = nullptr);

private slots: // Fixed 'slpts' to 'slots'
    void digitClicked();

private:
    QLineEdit *display;
    QWidget *centralWidget;
    QGridLayout *layout;
};

#endif
