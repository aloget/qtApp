#ifndef CSVOBJECT_H
#define CSVOBJECT_H

#include <QObject>
#include <QFile>

class CSVObject : public QObject
{
    Q_OBJECT
private:
//    QFile file;
    QString directory;
    QString stringInterpretation;

    bool validate();

public:
    explicit CSVObject(QObject *parent = 0);
    CSVObject(QString fileDirectory, QObject *parent = 0);//reads file, switches it to strings, validates it as a .csv file
    //and if it is valid, initializes stringInterpretation with string,
    //otherwise null

signals:

public slots:
};

#endif // CSVOBJECT_H
