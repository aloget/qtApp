#include "sourcepreparator.h"
#include "source.h"

SourcePreparator::SourcePreparator()
{

}

QStringList SourcePreparator::prepareSource(QStringList sourceInfo) {
    int sourceType = sourceInfo.at(0).toInt();
    QStringList preparedSourceInfo;
    switch(sourceType) {
    case Source::BOOK:
        preparedSourceInfo = prepareBook(sourceInfo);
        break;
    case Source::ARTICLE:
        preparedSourceInfo = prepareArticle(sourceInfo);
        break;
    case Source::WEB:
        preparedSourceInfo = prepareWeb(sourceInfo);
        break;
    }
    return preparedSourceInfo;
}

QString SourcePreparator::prepareAuthor(QString unpreparedAuthor) {
    QString preparedAuthor = unpreparedAuthor;
    QStringList foreign = unpreparedAuthor.split("/"); // если автор(ы) иностранный, его оригинальное имя (имена) записывается через слеш
    if (foreign.count() > 1) {//is foreign, has original
        QString cyrillic = foreign.at(0);
        QString original = foreign.at(1);
        QString preparedOriginal = QString("[%1]").arg(original);
        preparedAuthor = cyrillic + preparedOriginal;
    }
    return preparedAuthor;
}


QStringList SourcePreparator::prepareBook(QStringList bookInfo) {
    QStringList preparedBook;

    QString author = bookInfo.at(1);
    QString name = bookInfo.at(2);
    QString publishingLocation = bookInfo.at(3);
    QString publishingHouse = bookInfo.at(4);
    QString publishingYear = bookInfo.at(5);

    QString preparedAuthor = prepareAuthor(author);

    preparedBook.append(preparedAuthor);//автора присоединяем отдельной строкой, чтобы потом по ней отсортировать
    preparedBook.append(QString(" %1. %2: %3, %4.").arg(name, publishingLocation, publishingHouse, publishingYear));

    return preparedBook;
}

QStringList SourcePreparator::prepareArticle(QStringList articleInfo) {
    QStringList preparedArticle;

    QString author = articleInfo.at(1);
    QString name = articleInfo.at(2);
    QString sourceName = articleInfo.at(3);
    QString publishingYear = articleInfo.at(4);
    QString issueNumber = articleInfo.at(5);
    QString pages = articleInfo.at(6);

    QString preparedAuthor = prepareAuthor(author);


    preparedArticle.append(preparedAuthor);
    preparedArticle.append(QString(" %1 // %2. %3. N %4. C. %5.").arg(name, sourceName, publishingYear, issueNumber, pages));

    return preparedArticle;

}


QStringList SourcePreparator::prepareWeb(QStringList webInfo) {
    QStringList preparedWeb;

    QString author = webInfo.at(1);
    QString name = webInfo.at(2);
    QString publishingYear = webInfo.at(3);
    QString publishingDayAndMonth = webInfo.at(4);
    QString resourceName = webInfo.at(5);
    QString URL = webInfo.at(6);
    QString accessDate = webInfo.at(7);

    QString preparedAuthor = prepareAuthor(author);

    preparedWeb.append(preparedAuthor);
    preparedWeb.append(QString(" %1 [Электронный ресурс] // %2. %3. %4. URL: %5 (дата обращения: %6).").arg(name, resourceName, publishingYear,
                                                                                                           publishingDayAndMonth, URL, accessDate));
    return preparedWeb;
}
