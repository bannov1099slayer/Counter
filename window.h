#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QApplication>
#include <QTimer>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGroupBox>
#include <QTimer>
#include <QRandomGenerator>
#include <sstream>
#include <QCloseEvent>
#include <QMessageBox>
#include "dialogwindow.h"

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

    QHBoxLayout *main_layout;

    QGroupBox   *first,
                *second,
                *third;

    QPushButton   *btn1,
                  *btn2,
                  *btn3;
    QLineEdit     *le1,
                  *le2,
                  *le3,
                  *le4,
                  *le5;
    QLabel        *l1,
                  *l2;
    int  count = 0;                             // счётчик нажатий кнопок мыши
    int  counter_match = 0;                     // счётчик совпадений
    int  counter_mismatch = 0;                  // счётчик несовпадений
    int num_of_clicks = 0;

    void init();                                // Реализация самой формы

    virtual void mousePressEvent(QMouseEvent*); // Обработка нажатия кнопок мыши
    virtual void closeEvent(QCloseEvent *event);// Обработка закрытия формы (вызов диалогового окна при попытке закрыть основное окно)
public slots:
    void setRandomBackgroundColor();            // Смена фона лайнэдитов для индикации смены числа кликов, которые нужно прокликать
    void changeNumber();                        // Смена числа кликов
    void cleaner();                             // Чистит форму и обнуляет счётчики
    void startx();                              // Старт игры, запуск таймера
    void stopx();                               // Остановка таймера
    void check();                               // Проверка совпадения числа кликов
private:
    int t = 0;// для смены фона/"сигнализации" о смене числа
    QTimer *m_timer;

};

#endif // WINDOW_H
