#include "configuration.h"

Configuration::Configuration(QObject *parent) : QObject(parent)
{

}

char Configuration::getSeparator() const {
    return separator;
}

QVector<Source>* Configuration::getSources() const {
    return sources;
}

QString Configuration::getHTMLUpperPart() const {
    return htmlUpperPart;
}

QString Configuration::getHTMLLowerPart() const {
    return htmlLowerPart;
}

