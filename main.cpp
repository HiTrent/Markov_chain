#include "markov.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Markov w;
    w.show();

    return a.exec();
}
