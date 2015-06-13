#include "htmlobject.h"
#include <QFile>
#include <QTextStream>
#include <QTime>

HTMLObject::HTMLObject(QObject *parent) : QObject(parent)
{

}

HTMLObject::HTMLObject(QString fileDirectory, QObject *parent) {
    if (fileDirectory.endsWith("/")) {//при сохранении в корень
        fileDirectory.remove(fileDirectory.length() - 1, 1);
    }

    htmlDirectory = QString("%1/sources-%2.html").arg(fileDirectory, QTime::currentTime().toString("hh.mm.ss.zzz"));
    cssDirectory = QString("%1/sources.css").arg(fileDirectory);
}

void HTMLObject::setCSSString(QString cssString_) {
    cssString = cssString_;
}

void HTMLObject::setHTMLString(QString htmlString_) {
    htmlString = htmlString_;
}


QString HTMLObject::getHTMLString() const {
    return htmlString;
}

QString HTMLObject::getHTMLDirectory() const {
    return htmlDirectory;
}


bool HTMLObject::writeFile() {

    QFile htmlFile(htmlDirectory);
    QFile cssFile(cssDirectory);
    if (htmlFile.open(QIODevice::WriteOnly) && cssFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
        QTextStream hStream(&htmlFile);
        hStream << htmlString;
        QTextStream cStream(&cssFile);
        cStream << cssString;
        htmlFile.close();
        cssFile.close();
        return true;
    }
    else {
        return false;
    }

}

