#ifndef SOURCEPREPARATOR_H
#define SOURCEPREPARATOR_H

#include <QObject>
#include <QStringList>

class SourcePreparator
{
private:
    static QString prepareAuthor(QString unpreparedAuthor);

    static QStringList prepareBook(QStringList bookInfo);
    static QStringList prepareArticle(QStringList articleInfo);
    static QStringList prepareWeb(QStringList webInfo);
public:
    SourcePreparator();

    static QStringList prepareSource(QStringList sourceInfo);
};

#endif // SOURCEPREPARATOR_H
