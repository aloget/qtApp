#include "htmlobject.h"

HTMLObject::HTMLObject(QObject *parent) : QObject(parent)
{

}

HTMLObject::HTMLObject(QString fileDirectory, QObject *parent) {
    directory = fileDirectory;
}


void HTMLObject::setHTMLString(QString htmlString) {
    stringInterpretation = htmlString;
}

QString HTMLObject::getHTMLString() const {
    return stringInterpretation;
}
