#ifndef HTMLOBJECT_H
#define HTMLOBJECT_H

#include <QObject>

class HTMLObject : public QObject
{
    Q_OBJECT
private:
    QString directory;
    QString stringInterpretation;
    QString cssRelated;

public:
    explicit HTMLObject(QObject *parent = 0);
    HTMLObject(QString fileDirectory, QObject *parent = 0);

    void setCSSString(QString cssString);
    void setHTMLString(QString htmlString);
    QString getHTMLString() const;
    bool writeFile();
signals:

public slots:
};

#endif // HTMLOBJECT_H
