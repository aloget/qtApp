#include "htmlobject.h"

HTMLObject::HTMLObject(QObject *parent) : QObject(parent)
{

}

void HTMLObject::setHTMLString(QString htmlString) {
    stringInterpretation = htmlString;
}
