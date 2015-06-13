#include "dbhelper.h"

DBHelper::DBHelper(QObject *parent) : QObject(parent)
{
    hostname = "";//localhost
    username = "";//root
    password = "";//

    if (setupDatabase()) {

    }
}

bool DBHelper::setupDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("sources_database");
    db.setHostName(hostname);
    db.setUserName(username);
    db.setPassword(password);

    if (!db.open()) {
        return false;
    }

    QSqlQuery createTableQuery;
    QString queryStr  = "CREATE TABLE IF NOT EXISTS fileHistory ( "
                         "csvDir   VARCHAR(50), "
                         "htmlDir  VARCHAR(50) "
                     ");";

    if (!createTableQuery.exec(queryStr)) {
        return false;
    }

//    QString deleteStr = "DELETE FROM fileHistory;";

//    if (!createTableQuery.exec(deleteStr)) {
//        qDebug() << "Unable to delete from table.";
//    }


    return true;
}

bool DBHelper::insertValues(QString csvDir, QString htmlDir) {
    QSqlQuery insertQuery;
    QString insertString = QString ("INSERT INTO  fileHistory (csvDir, htmlDir) "
                           "VALUES('%1', '%2');").arg(csvDir, htmlDir);

    if (!insertQuery.exec(insertString)) {
        return false;
    }
    return true;
}

QVector <QStringList> DBHelper::getData() {
    QSqlQuery selectQuery;
    QVector<QStringList> records;

    if (!selectQuery.exec("SELECT * FROM fileHistory;")) {
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
