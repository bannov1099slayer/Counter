#ifndef DIALOGWINDOW_H
#define DIALOGWINDOW_H
#include <QDialog>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QApplication>
#include <QDebug>
#include <QCloseEvent>
#include <QMessageBox>

class DialogWindow: public QDialog {
    Q_OBJECT
public:
    DialogWindow(QWidget* parent = 0);
    QPushButton   *dbtn1;                   // кнопка «Обязательно приду»
    QLabel        *dlb1;                    // лейбл с надписью
    QVBoxLayout   *dmain_layout;
};

#endif // DIALOGWINDOW_H
