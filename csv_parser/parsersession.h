#ifndef PARSERSESSION_H
#define PARSERSESSION_H

#include <QObject>

#include "configuration.h"
#include "csvobject.h"
#include "htmlobject.h"
#include "parser.h"

class ParserSession : public QObject
{
    Q_OBJECT

private:

    Configuration *configuration;
    CSVObject *csv;
    HTMLObject *html;

public:
    explicit ParserSession(QObject *parent = 0);
    ParserSession(QString csvDir, QString htmlDir, QObject *parent = 0);

    bool start(); //implements parsing and returns success/failure


signals:

public slots:
};

#endif // PARSERSESSION_H
