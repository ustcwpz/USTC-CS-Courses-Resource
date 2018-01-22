#include "zevin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    zevin w;
    w.show();

    return a.exec();
}
