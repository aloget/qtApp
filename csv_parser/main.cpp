#include "mainwindow.h"
#include <QApplication>
#include "parsersession.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QString csvDir = "/Users/anna/Desktop/Untitled.csv";
    QString htmlDir = "/Users/anna/Desktop/";

    ParserSession* ps = new ParserSession(csvDir, htmlDir);
    if (ps->start()) {
        qDebug() << "success!";
    } else {
        qDebug() << "failure!";
    }

    return a.exec();
}
