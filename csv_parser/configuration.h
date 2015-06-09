#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QObject>
#include "source.h"

class Configuration : public QObject
{
    Q_OBJECT
private:
    char separator;
    QString htmlSkeleton;//begin list after <body>
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
    QString getHTMLSkeleton() const;
    char getSeparator() const;



signals:

public slots:
};

#endif // CONFIGURATION_H
