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

    directory = fileDirectory;
}

void HTMLObject::setCSSString(QString cssString) {
    cssRelated = cssString;
}

void HTMLObject::setHTMLString(QString htmlString) {
    stringInterpretation = htmlString;
}

QString HTMLObject::getHTMLString() const {
    return stringInterpretation;
}

bool HTMLObject::writeFile() {

    QFile htmlFile(QString("%1/sources-%2.html").arg(directory, QTime::currentTime().toString("hh.mm.ss.zzz")));
    QFile cssFile(QString("%1/sources.css").arg(directory));
    if (htmlFile.open(QIODevice::WriteOnly) && cssFile.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
        QTextStream hStream(&htmlFile);
        hStream << stringInterpretation;
        QTextStream cStream(&cssFile);
        cStream << cssRelated;
        htmlFile.close();
        cssFile.close();
        return true;
    }
    else {
        return false;
    }

}

