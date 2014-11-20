#include "infdevice.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InfDevice w;
    w.show();

    return a.exec();
}
