#include "dbhelper.h"
#include <QDebug>

DBHelper::DBHelper(QObject *parent) : QObject(parent)
{
    hostname = "localhost";
    username = "root";
    password = "mobigear";

    if (setupDatabase()) {
        qDebug() << "DB OK!";
    }
}

bool DBHelper::setupDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("sources_database");
    db.setHostName(hostname);
    db.setUserName(username);
    db.setPassword(password);

    if (!db.open()) {
        qDebug() << "Cannot open database:" << db.lastError();
        return false;
    }

    QSqlQuery createTableQuery;
    QString queryStr  = "CREATE TABLE IF NOT EXISTS fileHistory ( "
                         "csvDir   VARCHAR(50), "
                         "htmlDir  VARCHAR(50) "
                     ");";

    if (!createTableQuery.exec(queryStr)) {
        qDebug() << "Unable to create a table.";
        return false;
    }

    QString deleteStr = "DELETE FROM fileHistory;";

    if (!createTableQuery.exec(deleteStr)) {
        qDebug() << "Unable to delete from table.";
    }


    return true;
}

bool DBHelper::insertValues(QString csvDir, QString htmlDir) {
    QSqlQuery insertQuery;
    QString insertString = QString ("INSERT INTO  fileHistory (csvDir, htmlDir) "
                           "VALUES('%1', '%2');").arg(csvDir, htmlDir);

    if (!insertQuery.exec(insertString)) {
        qDebug() << "Unable to do insert opeation";
        return false;
    }
    return true;
}

QVector <QStringList> DBHelper::getData() {
    QSqlQuery selectQuery;
    QVector<QStringList> records;

    if (!selectQuery.exec("SELECT * FROM fileHistory;")) {
        qDebug() << "Unable to execute query - exiting";
        return records;
    }

    QSqlRecord record = selectQuery.record();
    int num = 1;
    QString csvDir = "";
    QString htmlDir = "";


    while (selectQuery.next()) {

        csvDir = selectQuery.value(record.indexOf("csvDir")).toString();
        htmlDir = selectQuery.value(record.indexOf("htmlDir")).toString();

        QStringList parseRecord = QStringList();
        parseRecord.append(QString("%1").arg(num));
        parseRecord.append(csvDir);
        parseRecord.append(htmlDir);

        records.append(parseRecord);

        num++;
    }

    return records;
}
