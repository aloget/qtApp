#ifndef CSVOBJECT_H
#define CSVOBJECT_H

#include <QObject>

class CSVObject : public QObject
{
    Q_OBJECT
public:
    explicit CSVObject(QObject *parent = 0);

signals:

public slots:
};

#endif // CSVOBJECT_H
