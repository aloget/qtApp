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

    htmlUpperPart = QString("<!DOCTYPE html>"
                            "<html>"
                            "<head lang=\"en\">"
                                "<meta charset=\"UTF-8\">"
                                "<link rel=\"stylesheet\" href=\"sources.css\">"
                                "<title> </title>"
                            "</head>"
                            "<body>"
                                "<h3>Список литературы</h3>"
                                "<ul>");
    htmlLowerPart = QString("</ul>"
                            "</body>"
                            "</html>");

    css = QString("body {"
                  "font-family: georgia;"
                  "width: 960px;"
                  "margin: 0 auto;"
              "}"

              "h3 {"
                  "text-align: center;"
              "}"

              "li {"
                  "list-style-type: none;"
                  "margin-bottom: 30px;"
              "}");

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

QString Configuration::getCSS() const {
    return css;
}


