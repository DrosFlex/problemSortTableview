#include "mytableview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyTableView t;
    t.show();
    return a.exec();
}
