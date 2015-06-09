#ifndef HTMLOBJECT_H
#define HTMLOBJECT_H

#include <QObject>

class HTMLObject : public QObject
{
    Q_OBJECT
private:
    QString directory;
    QString stringInterpretation;

public:
    explicit HTMLObject(QObject *parent = 0);
    HTMLObject(QString fileDirectory, QString HTMLString, QObject *parent = 0);

    bool writeFile();
signals:

public slots:
};

#endif // HTMLOBJECT_H
