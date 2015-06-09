#include "parser.h"

Parser::Parser(QObject *parent) : QObject(parent)
{

}

bool Parser::parse(CSVObject* csv, HTMLObject& html, Configuration* conf) {
    QVector<QStringList>* csvMatrix = csvToMatrix(csv, conf);
    if (validateSources(csvMatrix, conf)) {
        prepareSources(csvMatrix, html, conf);
    }
}

bool Parser::validateSources(QVector<QStringList>* csvMatrix,
                             Configuration* conf){

}

QVector<QStringList>* Parser::csvToMatrix(CSVObject* csv, Configuration* conf){

}

void Parser::prepareSources(QVector<QStringList>* csvMatrix, HTMLObject& html,
                            Configuration* conf) {


}

QString Parser::decoratedList(QVector<QStringList>* sourcesList,
                              Configuration* conf) {
    return QString();
}

