#include "configuration.h"
#include <QVector>

Configuration::Configuration(QObject *parent) : QObject(parent)
{
    separator = ";";

    Source book = Source(Source::BOOK);
    book.setMinNumberOfFields(5);
    Source article = Source(Source::ARTICLE);
    article.setMinNumberOfFields(6);
    Source web = Source(Source::WEB);
    web.setMinNumberOfFields(7);

    sources = new QVector<Source>();
    sources->append(book);
    sources->append(article);
    sources->append(web);

}

QString Configuration::getSeparator() const {
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

