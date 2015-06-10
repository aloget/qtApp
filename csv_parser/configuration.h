#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QObject>
#include "source.h"

class Configuration : public QObject
{
    Q_OBJECT
private:
    QString separator;
    QString htmlUpperPart;
    QString htmlLowerPart;
    QVector<Source>* sources;


public:
    explicit Configuration(QObject *parent = 0);//parse .ini file and init sources array

//    static Configuration& getInstance();//singleton
//    /*static S  instance; // Guaranteed to be destroyed.
//                            // Instantiated on first use.
//      return instance;*/

//    Configuration(Configuration const&);
//    void operator=(Configuration const&);

    QVector<Source>* getSources() const;
    QString getHTMLUpperPart() const;
    QString getHTMLLowerPart() const;
    QString getSeparator() const;



signals:

public slots:
};

#endif // CONFIGURATION_H
