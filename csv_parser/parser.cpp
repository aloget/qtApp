#include "parser.h"

#include <QRegExp>
#include <QStringList>
#include <QVector>

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
        int numOfFields = source.getStaticSetsOfFields()->at(source.getSelectedSetOfFields()).count();

        if (sourceInfo.count() != numOfFields) {
            return false;
        }

    }

    return true;
}

QVector<QStringList>* Parser::csvToMatrix(CSVObject* csv, Configuration* conf){
    QString csvString = csv->getStringInterpretation();
    QStringList sourcesList = csvString.split("\n", QString::SkipEmptyParts);

    QVector<QStringList> *retMatrix = new QVector <QStringList> (sourcesList.count());

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
//оформление списка в html-разметке
//объединение с глобальным html-ником (впихнуть в htmlSkeleton после подстроки <body>)

}

QString Parser::decoratedList(QVector<QStringList>* sourcesList,
                              Configuration* conf) {
    //оформление списка в html-разметке
    return QString();
}

