//#include <QCoreApplication>
#include <window.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Window w;
    w.setWindowTitle("This is Counter");
    w.setFixedSize(650,390);
    w.show();

    return a.exec();
}
