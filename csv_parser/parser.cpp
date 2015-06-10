#include "parser.h"

#include <QRegExp>
#include <QStringList>
#include <QVector>

#include "sourcepreparator.h"

Parser::Parser(QObject *parent) : QObject(parent)
{

}

bool Parser::parse(CSVObject* csv, HTMLObject& html, Configuration* conf) {
    QVector<QStringList>* csvMatrix = csvToMatrix(csv, conf);
    if (validateSources(csvMatrix, conf)) {
        prepareSources(csvMatrix, html, conf);
        return true;
    }
    else {
        return false;
    }
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

    QVector<QStringList> *retMatrix = new QVector <QStringList> (sourcesList.count() + 1);

    foreach (QString sourceInfo, sourcesList) {
        char separator = conf->getSeparator();
        QStringList sourceInfoList = sourceInfo.split(QString("%1").arg(separator), QString::SkipEmptyParts);
        retMatrix->append(sourceInfoList);
    }
    return retMatrix;
}

void Parser::prepareSources(QVector<QStringList>* csvMatrix, HTMLObject& html,
                            Configuration* conf) {
//обработка источников по госту
    QVector<QStringList>* preparedSources = gostPrepareSources(csvMatrix);
//оформление списка в html-разметке
    QString listOfSources = decoratedList(preparedSources);
//объединение с глобальным html-ником
    QString result = conf->getHTMLUpperPart().append(listOfSources).append(conf->getHTMLLowerPart());
    //запись в html объект получившейся строки
    html.setHTMLString(result);
}

QVector<QStringList>* Parser::gostPrepareSources(QVector<QStringList>* sourcesList) {
    QVector<QStringList>* preparedSources = new QVector <QStringList> (sourcesList->count() + 1);
    for (int i = 0; i < sourcesList->count(); i++) {
        QStringList source = sourcesList->at(i);
        QStringList preparedSource = SourcePreparator::prepareSource(source);
        preparedSources->append(preparedSource);
    }
    return preparedSources;
}


QString Parser::decoratedList(QVector<QStringList>* sourcesList) {
    //оформление списка в html-разметке
    QString htmlList;
    for (int i = 0; i < sourcesList->count(); i++) {
        QStringList source = sourcesList->at(i);
        QString author = source.at(0);
        QString rest = source.at(1);
        QString htmlSource = QString("<p><i>%1</i>%2</p>").arg(author, rest);
        htmlList.append(htmlSource);
    }

    return htmlList;
}

