#include "htmlobject.h"
#include <QFile>
#include <QTextStream>

HTMLObject::HTMLObject(QObject *parent) : QObject(parent)
{

}

HTMLObject::HTMLObject(QString fileDirectory, QObject *parent) {
    directory = fileDirectory.append("sources.html");
}


void HTMLObject::setHTMLString(QString htmlString) {
    stringInterpretation = htmlString;
}

QString HTMLObject::getHTMLString() const {
    return stringInterpretation;
}

bool HTMLObject::writeFile() {
    QFile htmlFile(directory);
    if (htmlFile.open(QIODevice::WriteOnly)) {
        QTextStream tStream(&htmlFile);
        tStream << stringInterpretation;
        htmlFile.close();
        return true;
    }
    else {
        return false;
    }

}

