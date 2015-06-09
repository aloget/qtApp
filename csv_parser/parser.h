#ifndef PARSER_H
#define PARSER_H

#include <QObject>

#include "csvobject.h"
#include "htmlobject.h"
#include "configuration.h"

class Parser : public QObject
{
    Q_OBJECT
private:
    static QVector<QStringList>* csvToMatrix(CSVObject* csv, Configuration* conf);
    static bool validateSources(QVector<QStringList>* csvMatrix, Configuration* conf);
    static void prepareSources(QVector<QStringList>* csvMatrix, HTMLObject& html, Configuration* conf);
    static QString decoratedList(QVector<QStringList>* sourcesList, Configuration *conf);

public:
    explicit Parser(QObject *parent = 0);

    static bool parse(CSVObject* csv, HTMLObject& html, Configuration* conf);

signals:

public slots:
};

#endif // PARSER_H
