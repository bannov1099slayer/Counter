#include "dialogwindow.h"

//--------------------------------------------------------------------------------------------------------------------
// Реализация внутренностей диалогового окна
//--------------------------------------------------------------------------------------------------------------------
DialogWindow::DialogWindow(QWidget* parent) : QDialog(parent)
{

    dmain_layout = new QVBoxLayout;
    dbtn1 = new QPushButton("Обязательно приду");
    dlb1 = new QLabel("Приходите ещё");

    //dmain_layout->setAlignment(Qt::AlignVCenter);
    dmain_layout->addWidget(dlb1);
    dmain_layout->addWidget(dbtn1);
    setLayout(dmain_layout);
    connect(dbtn1, &QPushButton::clicked, this, &QApplication::quit);
}

