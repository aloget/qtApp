#include "mainwindow.h"
#include <QApplication>
#include "parsersession.h"
#include "dbhelper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
