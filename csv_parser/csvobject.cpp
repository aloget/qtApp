#include "csvobject.h"

CSVObject::CSVObject(QObject *parent) : QObject(parent)
{

}


QString CSVObject::getStringInterpretation() const {
    return stringInterpretation;
}
