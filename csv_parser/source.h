#ifndef SOURCE_H
#define SOURCE_H

#include "configuration.h"

class Source
{
private:
    Configuration::SourceType type;
    QVector<QStringList> *staticSetsOfFields;
    int selectedSetOfFields;

    //need to implement ordering as well

public:
    Source(Configuration::SourceType type_, QVector<QStringList> *staticSetsOfFields_,
           int selectedSetOfFields);

    QVector<QStringList>* getStaticSetsOfFields() const;
    int getSelectedSetOfFields() const;

};

#endif // SOURCE_H
