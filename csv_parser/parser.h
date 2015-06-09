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
    bool validateSources(CSVObject csv);
    QVector<QStringList>* csvToMatrix(CSVObject csv);
    void prepareSources(QVector<QStringList> *matrix);

public:
    explicit Parser(QObject *parent = 0);

    static bool parse(CSVObject csv, HTMLObject& html, Configuration* conf);

signals:

public slots:
};

#endif // PARSER_H
