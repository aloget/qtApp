#include "htmlobject.h"
#include <QFile>
#include <QTextStream>
#include <QTime>

HTMLObject::HTMLObject(QObject *parent) : QObject(parent)
{

}

HTMLObject::HTMLObject(QString fileDirectory, QObject *parent) {
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
    QFile htmlFile(QString("%1sources-%2.html").arg(directory, QTime::currentTime().toString()));
    QFile cssFile(QString("%1sources.css").arg(directory));
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

