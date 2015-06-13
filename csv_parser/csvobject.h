#ifndef CSVOBJECT_H
#define CSVOBJECT_H

#include "configuration.h"

#include <QObject>
#include <QFile>

class CSVObject : public QObject
{
    Q_OBJECT
private:
//    QFile file;
    QString directory;
    QString stringInterpretation;

    bool validate(QString maybeCsvString, Configuration* conf);

public:
    explicit CSVObject(QObject *parent = 0);
    CSVObject(QString fileDirectory, Configuration* conf, QObject *parent = 0);//reads file, switches it to string, validates it as a .csv file
    //and if it is valid, initializes stringInterpretation with string,
    //otherwise null

    QString getStringInterpretation() const;
    QString getDirectory() const;

signals:

public slots:
};

#endif // CSVOBJECT_H
