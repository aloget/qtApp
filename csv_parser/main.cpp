#include "mainwindow.h"
#include <QApplication>
#include "parsersession.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    ParserSession* ps = new ParserSession();
    if (ps->start()) {
        qDebug() << "success!";
    } else {
        qDebug() << "failure!";
    }

    return a.exec();
}
