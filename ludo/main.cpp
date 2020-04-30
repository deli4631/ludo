#include "ludo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ludo w;
    w.show();
    return a.exec();
}
