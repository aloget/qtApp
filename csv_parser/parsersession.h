#ifndef PARSERSESSION_H
#define PARSERSESSION_H

#include <QObject>

class ParserSession : public QObject
{
    Q_OBJECT
public:
    explicit ParserSession(QObject *parent = 0);

signals:

public slots:
};

#endif // PARSERSESSION_H
