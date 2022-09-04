#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent)
{

    qDebug() << "constructor";

    init();
    connect(btn1, SIGNAL(clicked()), this, SLOT (startx()));
    connect(btn2, SIGNAL(clicked()), this, SLOT (stopx()));
    connect(btn3, SIGNAL(clicked()), this, SLOT (cleaner()));

    //connect(btn1, &QPushButton::clicked, qApp, &QApplication::quit);
//--------------------------------------------------------------------------------------------------------------------
    // первичная генерация числа
    num_of_clicks = 1 + rand() % 6;// диапазон от 1 до 6
    qDebug() << "from constructor" << num_of_clicks;
//--------------------------------------------------------------------------------------------------------------------
}

void Window::init()
{
//--------------------------------------------------------------------------------------------------------------------
// Реализация самой формы
//--------------------------------------------------------------------------------------------------------------------
    first  = new QGroupBox(tr("КНОПКИ"),this);
    second = new QGroupBox(tr("число кликов, которое надо сделать"),this);
    third  = new QGroupBox(tr("счетчики правильных и неправильных ответов"),this);

    main_layout = new QHBoxLayout(this);//горизонтальный компоновщик, где будут располагаться групбоксы

    main_layout->addWidget(first);
    main_layout->addWidget(second);
    main_layout->addWidget(third);
//--------------------------------------------------------------------------------------------------------------------
    QGridLayout *grid_layout = new QGridLayout(first);//компоновщик сетка в первой панели с кнопками

    int row_index_f = 0;//счётчик строк в компоновщике
    btn1 = new QPushButton(this);
    btn2 = new QPushButton(this);
    btn3 = new QPushButton(this);

    btn1->setText("СТАРТ");
    btn2->setText("СТОП");
    btn3->setText("ОЧИСТИТЬ");

    grid_layout->addWidget(btn1, row_index_f, 0);
    row_index_f++;
    grid_layout->addWidget(btn2, row_index_f, 0);
    row_index_f++;
    grid_layout->addWidget(btn3, row_index_f, 0);

//--------------------------------------------------------------------------------------------------------------------
    QGridLayout *grid_layout_s = new QGridLayout(second);//компоновщик сетка для кнопок

    int row_index_s = 0;//счётчик строк в компоновщике
    le2 = new QLineEdit(this);
    le3 = new QLineEdit(this);

    le2->setReadOnly(true);
    le3->setReadOnly(true);

    grid_layout_s->addWidget(le2, row_index_s, 0);
    row_index_s++;
    grid_layout_s->addWidget(le3, row_index_s, 0);
//--------------------------------------------------------------------------------------------------------------------
    QGridLayout *grid_layout_t = new QGridLayout(third);//компоновщик сетка для кнопок

    int row_index_t = 0;//счётчик строк в компоновщике

    le4 = new QLineEdit(this);
    le5 = new QLineEdit(this);

    le4->setStyleSheet("color: blue; background-color: green");
    le5->setStyleSheet("color: blue; background-color: red");

    le4->setDisabled(true);
    le5->setDisabled(true);

    l1 = new QLabel(this);
    l2 = new QLabel(this);

    l1->setText("правильно");
    l2->setText("не правильно");

    grid_layout_t->addWidget(l1, row_index_t, 0);
    grid_layout_t->addWidget(le4, row_index_t, 1);

    row_index_t++;
    grid_layout_t->addWidget(l2, row_index_t, 0);
    grid_layout_t->addWidget(le5, row_index_t, 1);
//--------------------------------------------------------------------------------------------------------------------
    qDebug() << "init";
}

void Window::startx()
{
    qDebug() << "start";
    m_timer = new QTimer(this);
   // m_timer_f = new QTimer(this); //таймер для первичной отработки алгоритма

    std::stringstream ss;
    ss << num_of_clicks;
    std::string ns = ss.str();
    le2->setText(QString::fromStdString(ns));//число кликов, которое нужно прокликать

//--------------------------------------------------------------------------------------------------------------------
    m_timer->start(2000); // Таймер будет срабатывать каждые 2 секунды

    connect(m_timer, SIGNAL(timeout()), this, SLOT(setRandomBackgroundColor()));
    connect(m_timer, SIGNAL(timeout()), this, SLOT(check()));
    connect(m_timer, SIGNAL(timeout()), this, SLOT(changeNumber()));
}

void Window::stopx()
{
    qDebug() << "stop";
    int remaining = m_timer->remainingTime();
    m_timer->stop();
    m_timer->setInterval(remaining);
}

void Window::setRandomBackgroundColor()
{
    t = t + 1 + rand()%6;

    if(t == 1) {
       le2->setStyleSheet("color: blue; background-color: magenta");
    }
    if(t == 2) {
       le2->setStyleSheet("color: blue; background-color: yellow");
    }
    if(t == 3) {
       le2->setStyleSheet("color: blue; background-color: green");
    }
    if(t == 4) {
       le2->setStyleSheet("color: black; background-color: cyan");
    }
    if(t == 5) {
       le2->setStyleSheet("color: blue; background-color: red");
    }
    if(t == 6) {
       le2->setStyleSheet("color: blue; background-color: gray");
    }
    t = 0;
}

void Window::changeNumber() //смена числа кликов
{
    qDebug() << "changeNumber";
    num_of_clicks = 1 + rand() % 6;// диапазон от 1 до 6
    qDebug() << num_of_clicks;
    std::stringstream ss;
    ss << num_of_clicks;
    std::string ns = ss.str();
    le2->setText(QString::fromStdString(ns));//число кликов, которое нужно прокликать

    ns.clear();//чистим строку
    ss.str("");//чистим stringstream
}

void Window::check()
{
    qDebug() << "check";
    std::stringstream ss;
    qDebug() << "count" << count;
    qDebug() << "num_of_clicks" << num_of_clicks;

    if (count == num_of_clicks)
    {
        qDebug() << "counter_match" << counter_match;
        counter_match++;
        qDebug() << "c m" << counter_match;
        ss << counter_match;
        std::string ns = ss.str();
        ns = ss.str();
        le4->setText(QString::fromStdString(ns));//успели прокликать столько, сколько нужно
    }
    if (count != num_of_clicks && count != 0)
    {
        qDebug() << "counter_mismatch" << counter_mismatch;
        counter_mismatch++;
        qDebug() << "c mm" << counter_mismatch;
        ss << counter_mismatch;
        std::string ns1 = ss.str();
        ns1 = ss.str();
        le5->setText(QString::fromStdString(ns1));//не успели
    }
    count = 0;//счётчик сделанных кликов обнуляется
    le3->clear();
}

void Window::cleaner()//чистит форму и обнуляет счётчики
{
    qDebug() << "clear";
    le2->clear();
    le3->clear();
    le4->clear();
    le5->clear();

    count = 0;           //обнуляем счётчик нажатий мыши
    qDebug() << count;
    counter_match = 0;   //обнуляем счётчик сопадений
    qDebug() << counter_match;
    counter_mismatch = 0;//обнуляем счётчик несовпадений
    qDebug() << counter_mismatch;
    le2->setStyleSheet("background-color: white");
}

void Window::mousePressEvent(QMouseEvent *)// обработка нажатия кнопок мыши
{
    //qDebug() << "pressed";
    count++;

    std::stringstream ss1;
    ss1 << count;
    std::string ns1 = ss1.str();
    le3->setText(QString::fromStdString(ns1));// в лайн эдите выводится количество кликов
}

void Window::closeEvent(QCloseEvent *)// вызов диалогового окна при попытке закрыть основное окно
{
    DialogWindow m_d_eks;
    m_d_eks.exec();
}

