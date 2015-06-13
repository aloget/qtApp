#ifndef DBHELPER_H
#define DBHELPER_H

#include <QObject>
#include <QtSql>
#include <QStringList>
#include <QVector>

class DBHelper : public QObject
{
    Q_OBJECT

private:
    QSqlDatabase db;
    QString hostname;
    QString username;
    QString password;

    bool setupDatabase();

public:
    explicit DBHelper(QObject *parent = 0);


    bool insertValues(QString csvDir, QString htmlDir);
    QVector <QStringList>  getData();

signals:

public slots:
};

#endif // DBHELPER_H
