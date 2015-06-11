#include "parser.h"

#include <QRegExp>
#include <QStringList>
#include <QVector>

#include "sourcepreparator.h"
#include <QDebug>

Parser::Parser(QObject *parent) : QObject(parent)
{

}

bool Parser::parse(CSVObject* csv, HTMLObject* html, Configuration* conf) {
    QVector<QStringList>* csvMatrix = csvToMatrix(csv, conf);

    if (validateSources(csvMatrix, conf)) {
        prepareSources(csvMatrix, html, conf);
        if (html->writeFile()) {
            return true;
        }
    }
    return false;
}

bool Parser::validateSources(QVector<QStringList>* csvMatrix,
                             Configuration* conf){


    for (int i = 0; i < csvMatrix->count(); i++) {
        QStringList sourceInfo = csvMatrix->at(i);
        int sourceType = sourceInfo.at(0).toInt();

        Source source = conf->getSources()->at(sourceType);

        int minNumOfFields = source.getMinNumberOfFields();

        if (sourceInfo.count() < minNumOfFields) {
            return false;
        }

    }

    return true;
}

QVector<QStringList>* Parser::csvToMatrix(CSVObject* csv, Configuration* conf){
    QString csvString = csv->getStringInterpretation();

    QStringList sourcesList = csvString.split("\n", QString::SkipEmptyParts);

    QVector<QStringList> *retMatrix = new QVector <QStringList> ();

    QString separator = conf->getSeparator();

    foreach (QString sourceInfo, sourcesList) {
        QStringList sourceInfoList = sourceInfo.split(QString("%1").arg(separator), QString::SkipEmptyParts);
        retMatrix->append(sourceInfoList);
    }

    return retMatrix;
}

void Parser::prepareSources(QVector<QStringList>* csvMatrix, HTMLObject* html,
                            Configuration* conf) {
//обработка источников по госту
    QVector<QStringList>* preparedSources = gostPrepareSources(csvMatrix);
//оформление списка в html-разметке
    QString listOfSources = decoratedList(preparedSources);
//объединение с глобальным html-ником
    QString result = conf->getHTMLUpperPart().append(listOfSources).append(conf->getHTMLLowerPart());
    //запись в html объект получившейся строки
    html->setHTMLString(result);
    qDebug() << html->getHTMLString();
}

QVector<QStringList>* Parser::gostPrepareSources(QVector<QStringList>* sourcesList) {
    QVector<QStringList>* preparedSources = new QVector <QStringList> ();
    for (int i = 0; i < sourcesList->count(); i++) {
        QStringList source = sourcesList->at(i);
        QStringList preparedSource = SourcePreparator::prepareSource(source);
        preparedSources->append(preparedSource);
    }
    return preparedSources;
}

bool sourceListLessThan(const QStringList& a, const QStringList& b) {
    QString aAuthor = a.at(0);
    QString bAuthor = b.at(0);
    return aAuthor < bAuthor;
}


QString Parser::decoratedList(QVector<QStringList>* sourcesList) {
    //оформление списка в html-разметке
    qSort(sourcesList->begin(), sourcesList->end(), sourceListLessThan);

    QString htmlList;
    for (int i = 0; i < sourcesList->count(); i++) {
        QStringList source = sourcesList->at(i);
        QString author = source.at(0);
        QString rest = source.at(1);
        QString htmlSource = QString("<li><i>%1</i>%2</li>").arg(author, rest);
        htmlList.append(htmlSource);
    }

    return htmlList;
}

