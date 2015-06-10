#include "csvobject.h"
#include <QTextStream>

CSVObject::CSVObject(QObject *parent) : QObject(parent)
{
    stringInterpretation = QString("0;Иванов А.А., Петров В.П.;Название Книги;Москва;ЭКСМО;2005\n"
                                   "1;Смит Ф.Дж./Smith P.J.;Название Статьи;Название Журнала;2005;2;12-25\n"
                                   "2;Алекс А.В., Джонс Б.Д./Alex A.V., Jones B.D.;Название Статьи;2005;10 декабря;Имя Ресурса;URL;10.12.2005");

}

CSVObject::CSVObject(QString fileDirectory, Configuration* conf, QObject *parent) {//reads file, switches it to strings, validates it as a .csv file
//and if it is valid, initializes stringInterpretation with string,
//otherwise null
    QFile csvFile(fileDirectory);

    if(csvFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream tStream(&csvFile);
        QString maybeCsv = tStream.readAll();
        if (validate(maybeCsv, conf)) {
            stringInterpretation = maybeCsv;
        }

    }
}

QString CSVObject::getStringInterpretation() const {
    return stringInterpretation;
}

bool CSVObject::validate(QString maybeCsvString, Configuration* conf) {
    if (maybeCsvString.contains(conf->getSeparator())) {
        return true;
    }
    else {
        return false;
    }
}


