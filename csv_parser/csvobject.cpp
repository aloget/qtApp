#include "csvobject.h"

CSVObject::CSVObject(QObject *parent) : QObject(parent)
{
    stringInterpretation = QString("0;Иванов А.А., Петров В.П.;Название Книги;Москва;ЭКСМО;2005\n1;Смит Ф.Дж./Smith P.J.;Название Статьи;Название Журнала;2005;2;12-25\n2;Алекс А.В., Джонс Б.Д./Alex A.V., Jones B.D.;Название Статьи;2005;10 декабря;Имя Ресурса;URL;10.12.2005");

}

CSVObject::CSVObject(QString fileDirectory, QObject *parent) {//reads file, switches it to strings, validates it as a .csv file
//and if it is valid, initializes stringInterpretation with string,
//otherwise null
}

QString CSVObject::getStringInterpretation() const {
    return stringInterpretation;
}
